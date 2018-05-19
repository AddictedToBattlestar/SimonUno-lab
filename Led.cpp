#include "Led.h"

void Led::begin() const {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, HIGH);
}

void Led::turnOn() const {
  digitalWrite(pin_, LOW);
}

void Led::turnOff() const {
  digitalWrite(pin_, HIGH);
}

