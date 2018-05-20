#include "PeizoBuzzer.h"

void PeizoBuzzer::begin() const {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void PeizoBuzzer::turnOn() const {
  Serial.println(" - PeizoBuzzer on");
  digitalWrite(pin_, HIGH);
}

void PeizoBuzzer::turnOff() const {
  Serial.println(" - PeizoBuzzer off");
  digitalWrite(pin_, LOW);
}

