#include "refueler.h"
void setup() {
  pinModeSetup();

}

void loop() {
  digitalWrite(RLY2,HIGH);
  delay(50);
  digitalWrite(RLY2,LOW);
  delay(100);
  digitalWrite(RLY3,HIGH);
  delay(50);
  digitalWrite(RLY3,LOW);
  delay(300);


}
void pinModeSetup() {
  // Inputs
  pinMode(DEMAND, INPUT);

  // Power
  pinMode(ESTOP_BREAK, OUTPUT);
  digitalWrite(ESTOP_BREAK, HIGH);

  pinMode(LED_PWR, OUTPUT);
  digitalWrite(LED_PWR, HIGH);
  pinMode(31, OUTPUT);
  digitalWrite(31, 0);
  pinMode(12, OUTPUT);
  digitalWrite(12, 0);
  pinMode(TRACO_24VDC, OUTPUT);
  digitalWrite(TRACO_24VDC, HIGH);

  pinMode(RLY2, OUTPUT);
  digitalWrite(RLY2, LOW);

  pinMode(RLY3, OUTPUT);
  digitalWrite(RLY3, LOW);
}
