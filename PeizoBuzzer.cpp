#include "PeizoBuzzer.h"

void PeizoBuzzer::begin() const {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void PeizoBuzzer::turnOn() const {
  digitalWrite(pin_, HIGH);
}

void PeizoBuzzer::turnOff() const {
  digitalWrite(pin_, LOW);
}

