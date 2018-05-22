#include "LedDisplay.h"

LedDisplay::LedDisplay(const Led* const ledList, const int ledCount, const RgbControl& rgbControl, const int refreshInterval) : 
ledList_(ledList), ledCount_(ledCount), rgbControl_(rgbControl), eventTimer_(EventTimer(refreshInterval)) {};

void LedDisplay::begin() {
  for (int ledIndex = 0; ledIndex<ledCount_; ledIndex++) {
    ledList_[ledIndex].begin();
  }
}

void LedDisplay::blank() {
    for (int ledIndex = 0; ledIndex<ledCount_; ledIndex++) {
    colorRam_[ledIndex] = COLORS::OFF;
  }
}

void LedDisplay::update() {
  // update is ran at the beginning of each loop and 
  if(eventTimer_.hasEventFired()) {
    ledList_[activeLed_].turnOff();
    activeLed_++;
    if (activeLed_ >= ledCount_) {
      activeLed_ = 0;
    }

    rgbControl_.setColor(colorRam_[activeLed_]);
    if (colorRam_[activeLed_] != COLORS::OFF) {
      ledList_[activeLed_].turnOn();
    }
  }
}

void LedDisplay::turnLedOn(const int ledIndex, const Color& color) {
  /* 
    Serial.print(" - LED ");
    Serial.print(ledIndex, DEC);
    Serial.println(" on");
   */
  colorRam_[ledIndex] = color;
}

void LedDisplay::turnLedOff(const int ledIndex) {
  /*
    Serial.print(" - LED ");
    Serial.print(ledIndex, DEC);
    Serial.println(" off");
   */
  colorRam_[ledIndex] = COLORS::OFF;
}

unsigned int LedDisplay::getLedCount() const {
  return ledCount_;
}

