#include "Button.h"
#include "Keyboard.h"
#include "PeizoBuzzer.h"
#include "Led.h"
#include "RgbControl.h"
#include "LedDisplay.h"
#include "Animator.h"
#include "FlashAnimation.h"
#include "PatternAnimation.h"

// Setup buttons and its related keyboard
constexpr Button redButton(18, 0, COLORS::RED);
constexpr Button greenButton(8, 1, COLORS::GREEN);
constexpr Button blueButton(6, 2, COLORS::BLUE);
constexpr Button yellowButton(4, 3, COLORS::YELLOW);
const int buttonCount = 4;
constexpr Button buttonList[buttonCount] = {
  redButton, greenButton, blueButton, yellowButton
};

// Setup LEDs
constexpr Led redButtonLed(13);
constexpr Led greenButtonLed(12);
constexpr Led blueButtonLed(7);
constexpr Led yellowButtonLed(5);
const int ledCount = 4;
constexpr Led ledList[ledCount] = { redButtonLed, greenButtonLed, blueButtonLed, yellowButtonLed };

const int colorCount = 4;
constexpr Color colors[colorCount] = {COLORS::RED, COLORS::GREEN, COLORS::BLUE, COLORS::YELLOW};

// Setup internal components
PeizoBuzzer buzzer(19);
RgbControl rgbControl(11,10,9);
Keyboard keyboard(buttonList, buttonCount);
LedDisplay ledDisplay(ledList, ledCount, rgbControl, 4);
Animator animator(ledDisplay);

SimonPattern pattern(colors, colorCount);
PatternAnimation animation(pattern);

const Button* buttonLastPressed = NULL;

void setup() {
  // Initialize the serial port so we can see things happening
  Serial.begin(115200);

  buzzer.begin();
  rgbControl.begin();
  keyboard.begin();
  ledDisplay.begin();
}

void loop() {
  animator.update();
  ledDisplay.update();
  keyboard.scan();
  if (!animator.isActive()) {
      const Button* buttonPressed = keyboard.getButtonPressed();
      if (buttonPressed != buttonLastPressed) {
        if (buttonPressed) {
          pattern.clear();
          pattern.addStep();
          pattern.addStep();
          pattern.addStep();
          animator.playAnimation(animation);
        }
        buttonLastPressed = buttonPressed;
      }
  }
}

