#include "FlashAnimation.h"

FlashAnimation::FlashAnimation(const Color& color, unsigned int flashCount, unsigned int onTime, unsigned int offTime) :
  color_(color), flashCount_(flashCount), onTime_(onTime), offTime_(offTime), state_(LED_ON) {}

void FlashAnimation::reset() {
  Serial.println("FlashAnimation.reset() -> state LED_ON");
  state_ = LED_ON;
  displayedCount_ = 0;
}

const bool FlashAnimation::nextFrame() {
  bool success = true;
  switch(state_) {
    case LED_ON:
      state_ = LED_OFF;
      break;
      
    case LED_OFF:
      displayedCount_++;
      if (displayedCount_ == flashCount_) {
        state_ = FINAL_DELAY;
      } else {
        state_ = LED_ON;
      }
      break;

    case FINAL_DELAY:
      success = false;
      break;
  }
  return success;
}

const Color& FlashAnimation::getFrameLedColor(unsigned int led) {
  if (state_ == LED_ON) {
    return color_;
  } else {
    return COLORS::OFF;
  }
}

const unsigned int FlashAnimation::getFrameInterval() {
  switch (state_) {
    case LED_ON:
      return onTime_;

    case LED_OFF:
      return offTime_;

    case FINAL_DELAY:
      return 250;
  }
}

