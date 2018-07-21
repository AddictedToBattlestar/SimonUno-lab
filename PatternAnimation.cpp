#include "PatternAnimation.h"

PatternAnimation::PatternAnimation(const SimonPattern& pattern) : pattern_(pattern), patternIdx_(0) {}

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
    return pattern_.getStepColor(patternIdx_);
  } else {
    return COLORS::OFF;
  }
}

const unsigned int PatternAnimation::getFrameInterval() {
  if (on_) {
    return 500;
  } else {
    return 200;
  }
}

