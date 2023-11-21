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
// ACCESSORIES
//////////////////////////////////////////////////////////
//Creating the HAP Accessory Attribute Database
  new SpanAccessory();       // Instantiating a new SpanAccessory object
    new DEV_Identify("HomeKit Bridge","IPSOL Industries","M1-HKB01","Homekit Bridge M1","0.2",3);   // Identify(name,manufacturer,serialNumber,model,version,nBlinks)  
    new Service::HAPProtocolInformation();    // XXXXX************ PENDING INFO ****************************XXXXX
    new Characteristic::Version("1.1.0");
}
//////////////////////////////////////////////////////////

void loop() {
  homeSpan.poll();
}
