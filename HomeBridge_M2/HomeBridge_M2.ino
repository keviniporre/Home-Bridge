//INCLUDE LIBRARIES
#include "HomeSpan.h"
#include "DEV_Identify.h"      
#include "DEV_Sensors.h"
#include "DEV_Relay.h"

// PIN CONFIGURATION
int controlPin = 13;  // reset wifi settings
int statusPin = 2;    // onboard status LED
// SENSORS INPUT SIGNAL PIN
int contactPin = 27;  // main door
int motionPin = 26;   // main door
int dhtPin = 4;       // main control
// RELAYS OUTPUT SIGNAL PIN
int relayPin1 = 16;   // main light
int relayPin2 = 17;   // second light
int relayPin3 = 18;   // outside light
int relayPin4 = 19;   // bar light
int relayPin5 = 21;   // TV light
// TOUCH INPUT SIGNAL PIN
int touchPin1 = 25;   // main light
int touchPin2 = 23;   // second light
int touchPin3 = 32;   // outside light
int touchPin4 = 35;   // bar light
int touchPin5 = 34;   // TV light

void setup() {

//////////////////////////////////////////////////////////
// BASIC SETUP
//////////////////////////////////////////////////////////

  Serial.begin(115200);   // Start the Serial interface
  homeSpan.setPairingCode("11144333");  // set pairing code
  homeSpan.setQRID("111-44-333");       // set QR pairing format

  homeSpan.setControlPin(controlPin);   // set push button pin to reset wifi settings
  homeSpan.setStatusPin(statusPin);    // set onboard status LED for control pin

  homeSpan.begin(Category::Bridges,"HomeSpan Bridge");      // Initialize HomeSpan

//////////////////////////////////////////////////////////
// ACCESSORIES SETUP
//////////////////////////////////////////////////////////

//Creating the HAP Accessory Attribute Database
  new SpanAccessory();       // Instantiating a new SpanAccessory object
    new DEV_Identify("HomeKit Bridge","IPSOL Industries","M1-HKB01","Homekit Bridge M1","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)  
    new Service::HAPProtocolInformation();    // XXXXX************ PENDING INFO ****************************XXXXX
    new Characteristic::Version("1.1.0");

//TEMPERATURE SENSOR      
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Temperature Sensor","IPSOL Industries","M1-TS01","Smart DHT22","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)                                            
    new DEV_TempSensor();   // Create a Temperature Sensor (see DEV_Sensors.h for definition)
        
//HUMIDITY SENSOR
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Humidity Sensor","IPSOL Industries","M1-HS01","Smart DHT22","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_HumSensor();    // Create a Humidity Sensor (see DEV_Sensors.h for definition)

//MOTION SENSOR
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    //new Service::AccessoryInformation();    // XXXXX************ PENDING INFO ****************************XXXXX
    new DEV_Identify("Motion Sensor","IPSOL Industries","M1-MS01","Smart PIR","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_MotionSensor(motionPin);        // Create a Motion Sensor (see DEV_Sensors.h for definition)

//CONTACT SENSOR #1

//RELAY SWITCH #1
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Switch 1","IPSOL Industries","M1-SSR01","Smart SSR","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_Relay(relayPin1, touchPin1);    // Create a Relay Switch (see DEV_Relay.h for definition)

//RELAY SWITCH #2
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Switch 2","IPSOL Industries","M1-SSR02","Smart SSR","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_Relay(relayPin2, touchPin2);    // Create a Relay Switch (see DEV_Relay.h for definition)

//RELAY SWITCH #3
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Switch 3","IPSOL Industries","M1-SSR03","Smart SSR","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_Relay(relayPin3, touchPin3);    // Create a Relay Switch (see DEV_Relay.h for definition)

//RELAY SWITCH #4
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Switch 4","IPSOL Industries","M1-SSR04","Smart SSR","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_Relay(relayPin4, touchPin4);    // Create a Relay Switch (see DEV_Relay.h for definition)

//RELAY SWITCH #5
  new SpanAccessory();      // Instantiating a new SpanAccessory object
    new DEV_Identify("Switch 5","IPSOL Industries","M1-SSR05","Smart SSR","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)
    new DEV_Relay(relayPin5, touchPin5);    // Create a Relay Switch (see DEV_Relay.h for definition)

//////////////////////////////////////////////////////////
}

void loop() {
  homeSpan.poll();
}
