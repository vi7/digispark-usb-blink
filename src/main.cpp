#include <Arduino.h>

/**********
 *  MAIN  *
 **********/

void setup() {

  // For Digispark ATTiny85 dtiny core TinyDebugSerial overrides Serial and uses PB3 pin as TX
  Serial.begin(9600);
  Serial.println("\n******* Hello! Board is up. *******");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  Serial.println("****************");
  Serial.println("Loop start");
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED is on");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED is off");
  delay(2000);
}
