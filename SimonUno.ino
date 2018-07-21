#include "Button.h"
#include "Keyboard.h"
#include "PeizoBuzzer.h"
#include "Led.h"
#include "RgbControl.h"
#include "LedDisplay.h"
#include "Animator.h"
#include "FlashAnimation.h"
#include "PatternAnimation.h"
#include "SimonGame.h"

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
constexpr Color colorList[colorCount] = {COLORS::RED, COLORS::GREEN, COLORS::BLUE, COLORS::YELLOW};

// Setup internal components
PeizoBuzzer buzzer(19);
RgbControl rgbControl(11,10,9);
Keyboard keyboard(buttonList, buttonCount);
LedDisplay ledDisplay(ledList, ledCount, rgbControl, 4);
Animator animator(ledDisplay);
SimonGame game(colorList, colorCount);

PatternAnimation patternAnimation(game.getPattern(), buttonList, buttonCount);
FlashAnimation successGameAnimation(COLORS::GREEN, 2, 100, 100);
FlashAnimation failGameAnimation(COLORS::RED, 4, 300, 150);
FlashAnimation gameCompletionAnimation(COLORS::GREEN, 6, 300, 50);

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
  ledDisplay.update();
  keyboard.scan();
  const Button* buttonPressed = keyboard.getButtonPressed();
    
  if (buttonPressed != buttonLastPressed) {
    if (buttonLastPressed != NULL) {
      ledDisplay.turnLedOff(buttonLastPressed->getId());
      game.buttonPressed(buttonLastPressed->getColor());
    }
    if (buttonPressed != NULL) {
      ledDisplay.turnLedOn(buttonPressed->getId(), buttonPressed->getColor());
    }
    buttonLastPressed = buttonPressed;
  }

  switch (game.getState()) {
    case SimonGame::DISPLAY_PATTERN:
      animator.playAnimation(patternAnimation);
      break;

    case SimonGame::GAME_FAILED:
      animator.playAnimation(failGameAnimation);
      break;

    case SimonGame::ROUND_SUCCESS:
      animator.playAnimation(successGameAnimation);
      break;

    case SimonGame::GAME_SUCCESS:
      animator.playAnimation(gameCompletionAnimation);
      break;
  }

  while (animator.isActive()) {
    animator.update();
    ledDisplay.update();
  }
}

