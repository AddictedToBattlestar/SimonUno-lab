#include "Button.h"

void Button::begin() const {
  pinMode(pin_, INPUT_PULLUP);  
}

bool Button::readState() const {
  return digitalRead(pin_) == LOW;  
}
