//////////////////////////////////
//        BRIDGE SENSORS        //
//////////////////////////////////

#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

struct DEV_TempSensor : Service::TemperatureSensor {      

  // reference to the Current Temperature Characteristic
  SpanCharacteristic *temp;                                       

  // constructor() method
  DEV_TempSensor() : Service::TemperatureSensor() {      

    // start dhttemp Object
    dht.begin();                                    

    temp = new Characteristic::CurrentTemperature(-10.0);     
    temp->setRange(-50, 100);                                 

    Serial.print("Configuring Temperature Sensor");           
    Serial.print("\n");

  } // end constructor

  void loop() {

    // the temperature refreshes every 10 seconds by the elapsed time
    if (temp->timeVal() > 10000) {
      // read temperature from sensor dht22
      float temperature = dht.readTemperature();        
      // set the new temperature; this generates an Event Notification and also resets the elapsed time
      temp->setVal(temperature);                            

      LOG1("Temperature Update: ");
      LOG1(temperature);
      LOG1(" ; ");
    }
  } // loop
};

////////////////////////////////////
// HUMIDITY SENSOR
struct DEV_HumSensor : Service::HumiditySensor {     

  // reference to the Current Humidity Characteristic
  SpanCharacteristic *hum;                                  

  // constructor() method
  DEV_HumSensor() : Service::HumiditySensor() {      

    // start dhthum Object
    dht.begin();                                  

    // instantiate the Current Temperature Characteristic
    hum = new Characteristic::CurrentRelativeHumidity(50);
    // expand the range to 30%-100% 
    hum->setRange(30, 100);                                

    // initialization message
    Serial.print("Configuring Humidity Sensor");           
    Serial.print("\n");

  } // end constructor

  void loop() {

    // the humidity refreshes every 10 seconds by the elapsed time
    if (hum->timeVal() > 10000) {
      // read humidity from sensor dht22
      float humidity = dht.readHumidity();  
      // set the new humidity; this generates an Event Notification and also resets the elapsed time        
      hum->setVal(humidity);                            

      LOG1("Humidity Update: ");
      LOG1(humidity);
      LOG1(" ; ");
    }
  } // loop
};

//////////////////////////////////
// MOTION SENSOR
struct DEV_MotionSensor : Service::MotionSensor {                       // Motion sensor

  SpanCharacteristic *movement;                                         // reference to the MotionDetected Characteristic
  int sensorPin;                                                        // pin number of the sensor

  // constructor() method
  DEV_MotionSensor(int sensorPin) : Service::MotionSensor() {
    this->sensorPin = sensorPin;
    pinMode(sensorPin, INPUT);
    boolean motion = digitalRead(sensorPin);
    movement = new Characteristic::MotionDetected(motion);               // instantiate the MotionDetected Characteristic            
  } // end constructor

  void loop() {

    if (movement->timeVal() > 200) {
      boolean motion = digitalRead(sensorPin);
      if (motion != movement->getVal()) {
        movement->setVal(motion);
        if (motion == HIGH) {
          char c[64];
          sprintf(c, "Motion was detected\n");
          LOG1(c);
        }
      }
    }
  }
};

//////////////////////////////////
// CONTACT SENSOR
struct DEV_ContactSensor : Service::ContactSensor {

  SpanCharacteristic *contact;
  int contactPin;

  // constructor() method
  DEV_ContactSensor(int contactPin) : Service::ContactSensor(){
    this->contactPin = contactPin;
    pinMode(contactPin, INPUT);
    uint8_t contacted = digitalRead(contactPin);
    contact = new Characteristic::ContactSensorState(contacted);
  }// end constructor

  void loop() {
      uint8_t contacted = digitalRead(contactPin);
      if (contacted != contact->getVal()) {
        contact->setVal(contacted);
        if (contacted == HIGH){
          char c[64];
          sprintf(c, "Contact was detected\n");
          LOG1(c);
        }
      }
  }
};