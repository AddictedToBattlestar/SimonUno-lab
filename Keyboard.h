#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>
#include "Button.h"

class Keyboard {
  private:
    const static unsigned int maxButtonCount_ = 4;
    const int buttonCount_;
    const Button* const buttonList_;
    bool buttonState_[maxButtonCount_];

  public:
    Keyboard(const Button* const buttonList, const int buttonCount);
    void begin() const;
    void scan();
    const Button* const getButtonPressed() const;
};

#endif /* KEYBOARD_H */
