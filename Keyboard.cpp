#include "Keyboard.h"

Keyboard::Keyboard(const Button* const buttonList, const int buttonCount) : 
  buttonList_(buttonList), 
  buttonCount_((buttonCount < maxButtonCount_) ? buttonCount : maxButtonCount_),
  eventTimer_(EventTimer(debounceInterval_))
  {};

void Keyboard::begin() const {
  for (int buttonIndex = 0; buttonIndex < buttonCount_; buttonIndex++) {
    buttonList_[buttonIndex].begin();
  }
}

void Keyboard::scan() {
  if (eventTimer_.hasEventFired()) {

    for (int buttonIndex = 0; buttonIndex < buttonCount_; buttonIndex++) {
      stateBuffer_[buttonIndex][stateBufferIndex_] = buttonList_[buttonIndex].readState();
    }

    stateBufferIndex_++;
    if (stateBufferIndex_ >= debounceCount_) { stateBufferIndex_ = 0; }
    
    for (int buttonIndex = 0; buttonIndex < buttonCount_; buttonIndex++) {
      bool isConsistent = true;
      bool isButtonPressed = stateBuffer_[buttonIndex][0];
      for (int bufferIndex = 0; isConsistent && bufferIndex < debounceCount_; bufferIndex++) {
        isConsistent = (isButtonPressed == stateBuffer_[buttonIndex][bufferIndex]);
      }
      if (isConsistent) {
        buttonState_[buttonIndex] = isButtonPressed;
      }
    }
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

