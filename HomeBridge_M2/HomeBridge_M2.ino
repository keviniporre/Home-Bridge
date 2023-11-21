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

  Serial.begin(115200);   // Start the Serial interface
  homeSpan.setPairingCode("11144333");  // set pairing code
  homeSpan.setQRID("111-44-333");       // set QR pairing format

  homeSpan.setControlPin(controlPin);   // set push button pin to reset wifi settings
  homeSpan.setStatusPin(2);    // set onboard status LED for control pin

  homeSpan.begin(Category::Bridges,"HomeSpan Bridge");      // Initialize HomeSpan

}
//////////////////////////////////////////////////////////

void loop() {
  homeSpan.poll();
}
