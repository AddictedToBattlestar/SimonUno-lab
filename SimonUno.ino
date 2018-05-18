#include "Button.h"
#include "PeizoBuzzer.h"

constexpr Button redButton(18);
PeizoBuzzer buzzer(19);

bool lastPressed = false;

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  buzzer.begin();
  redButton.begin();
}

void loop() {
  bool pressed = redButton.readState();
  if(pressed != lastPressed) {
    lastPressed = pressed;
    if (pressed) {
      Serial.println("Button Pressed");
      buzzer.turnOn();
    } else {
      Serial.println("Button Released");
      buzzer.turnOff();
    }
  }
}

