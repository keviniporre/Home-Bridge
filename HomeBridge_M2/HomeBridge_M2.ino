//INCLUDE LIBRARIES
#include "HomeSpan.h"
#include "DEV_Identify.h"      
#include "DEV_Sensors.h"
#include "DEV_Relay.h"

// PIN CONFIGURATION
int controlPin = 13;  // reset wifi settings
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
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
