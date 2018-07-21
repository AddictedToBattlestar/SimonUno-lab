#ifndef SIMON_PATTERN_H
#define SIMON_PATTERN_H

#include <Arduino.h>
#include "Color.h"

class SimonPattern {
  private:
    static const unsigned int MAX_PATTERN_LENGTH = 20;

    const unsigned int colorCount_;
    const Color* const colorList_;

    Color pattern_[MAX_PATTERN_LENGTH];
    unsigned int patternSize_;

  public:
    SimonPattern(const Color* const colorList, const unsigned int colorCount);

    void clear();
    bool addStep();
    const unsigned int getSize() const;
    const Color& getStepColor(const unsigned int step) const;
};

#endif /* SIMON_PATTERN_H */
