//////////////////////////////////
//        BRIDGE RELAY          //
//////////////////////////////////

struct DEV_Relay : Service::Switch {

int touchPin;       // Digital pin connected to the touch sensor
int relayPin;          // Digital pin connected to the relay
SpanCharacteristic *power;    // Reference to the Switch On Characteristic

DEV_Relay(int relayPin, int touchPin) : Service::Switch(){      // constructor() method
    power = new Characteristic::On();
    this->touchPin = touchPin;
    this->relayPin = relayPin;
    pinMode(touchPin, INPUT);
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH);
} // end constructor

boolean update() {      // update() method
  if(power->getNewVal())
      turnON();
  else
      turnOFF();
return(true);
} // end update

void turnON(){digitalWrite(relayPin, LOW);} 
void turnOFF(){digitalWrite(relayPin, HIGH);}

void loop(){
  if(digitalRead(touchPin)==HIGH){
      if(power->getVal()){
        turnOFF();
        power->setVal(0);
      }
      else {
        turnON();
        power->setVal(1);
      }
      while (digitalRead(touchPin)==HIGH) { delay(20); }
  }
} // end loop

};