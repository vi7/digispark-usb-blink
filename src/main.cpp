#include <Arduino.h>

/*
 * LED blink for the Digispark ATiny85 clone
 */

#define LED 1

void setup() {
  pinMode(LED, OUTPUT);
  // digitalWrite(LED, LOW);
}

void loop() {

  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(1000);
}
