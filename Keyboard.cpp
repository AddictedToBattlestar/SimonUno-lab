#include "Keyboard.h"

Keyboard::Keyboard(const Button* const buttonList, const int buttonCount) : 
  buttonList_(buttonList), 
  buttonCount_((buttonCount < maxButtonCount_) ? buttonCount : maxButtonCount_) 
  {};

void Keyboard::begin() const {
  for (int buttonIndex = 0; buttonIndex < buttonCount_; buttonIndex++) {
    buttonList_[buttonIndex].begin();
  }
}

void Keyboard::scan() {
  for (int buttonIndex = 0; buttonIndex < buttonCount_; buttonIndex++) {
    buttonState_[buttonIndex] = buttonList_[buttonIndex].readState();
  }
}

const Button* const Keyboard::getButtonPressed() const {
  for (int buttonIndex = 0; buttonIndex < buttonCount_; buttonIndex++) {
    if (buttonState_[buttonIndex]) {
      return &buttonList_[buttonIndex];
    }
  }
  return NULL;
}

