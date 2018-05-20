#include "Button.h"

void Button::begin() const {
  pinMode(pin_, INPUT_PULLUP);  
}

bool Button::readState() const {
  return digitalRead(pin_) == LOW;  
}

int Button::getId() const {
  return id_;
}

const Color& Button::getColor() const {
  return color_;
}

