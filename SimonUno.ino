#include "Button.h"
#include "Keyboard.h"
#include "PeizoBuzzer.h"

PeizoBuzzer buzzer(19);

constexpr Button redButton(18, 0);
constexpr Button greenButton(8, 1);
constexpr Button blueButton(6, 2);
constexpr Button yellowButton(4, 3);
const int buttonCount = 4;
constexpr Button buttonList[buttonCount] = {
  redButton, greenButton, blueButton, yellowButton
};

Keyboard keyboard(buttonList, buttonCount);
const Button* buttonLastPressed = NULL;

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  buzzer.begin();
  keyboard.begin();
}

void loop() {
  keyboard.scan();
  const Button* buttonPressed = keyboard.getButtonPressed();
  if (buttonPressed != buttonLastPressed) {
    if (buttonLastPressed != NULL) {
      Serial.println("Released");
      buzzer.turnOff();
    }
    buttonLastPressed = buttonPressed;
    if (buttonPressed) {
      Serial.print("Button ");
      Serial.print(buttonPressed->getId(), DEC);
      Serial.print(" Pressed - ");
      buzzer.turnOn();
    }
  }
}

