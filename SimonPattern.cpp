#include "SimonPattern.h"

SimonPattern::SimonPattern(const Color* const colorList, const unsigned int colorCount) : colorList_(colorList), colorCount_(colorCount) {
  clear();
}

void SimonPattern::clear() {
  randomSeed(analogRead(A0));
  patternSize_ = 0;
  addStep();
}

bool SimonPattern::addStep() {
  if (patternSize_ < MAX_PATTERN_LENGTH) {
    pattern_[patternSize_] = colorList_[random(colorCount_)];
    patternSize_++;
    return true;
  }
  return false;
}

const unsigned int SimonPattern::getSize() const {
  return patternSize_;
}

const Color& SimonPattern::getStepColor(const unsigned int step) const {
  if (step < patternSize_) {
    return pattern_[step];
  } else {
    return COLORS::OFF;
  }
}

