#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <Arduino.h>
#include "Button.h"
#include "EventTimer.h"

class Keyboard {
  private:
    const static unsigned int debounceInterval_ = 5; // Amount of time in milliseconds between reading buttons
    const static unsigned int debounceCount_ = 10;   // Number of consequtive consistent reads before we declare a button state change
    const static unsigned int maxButtonCount_ = 4;   // Maximum number of buttons we can keep track of
    
    const int buttonCount_;
    const Button* const buttonList_;
    bool buttonState_[maxButtonCount_];

    EventTimer eventTimer_;
    bool stateBuffer_[maxButtonCount_][debounceCount_];
    byte stateBufferIndex_;

  public:
    Keyboard(const Button* const buttonList, const int buttonCount);
    void begin() const;
    void scan();
    const Button* const getButtonPressed() const;
};

#endif /* KEYBOARD_H */
