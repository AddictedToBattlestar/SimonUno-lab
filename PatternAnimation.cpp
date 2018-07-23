#include "PatternAnimation.h"

PatternAnimation::PatternAnimation(const SimonPattern& pattern, const Button* const buttons, const int buttonCount) : pattern_(pattern), patternIdx_(0), buttons_(buttons), buttonCount_(buttonCount) {}

void PatternAnimation::reset() {
  patternIdx_ = 0;
  on_ = true;
}

const bool PatternAnimation::nextFrame() {
  if (on_) {
    on_ = false;
    return true;
  } else {
    if (patternIdx_ < (pattern_.getSize()-1)) {
      patternIdx_++;
      on_ = true;
      return true;
    } else {
      return false;
    }
  }
}

const Color& PatternAnimation::getFrameLedColor(unsigned int led) {
  if (on_) {
    const Color& color = pattern_.getStepColor(patternIdx_);
    for (int i=0; i<buttonCount_; i++) {
      if (buttons_[i].getColor() == color && buttons_[i].getId() == led) {
        return color;
      }
    }
  }
  return COLORS::OFF;
}

const unsigned int PatternAnimation::getFrameInterval() {
  if (on_) {
    return 500;
  } else {
    return 200;
  }
}

