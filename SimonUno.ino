#include "PeizoBuzzer.h"

PeizoBuzzer buzzer(19);

constexpr byte BEEP_COUNT = 5;
byte beeps_sounded = 0;

void setup() {
  buzzer.begin();
}

void loop() {
  if (beeps_sounded < BEEP_COUNT) {
    buzzer.turnOn();
    delay(250);
    buzzer.turnOff();
    delay(500);
    beeps_sounded++;
  }
}

