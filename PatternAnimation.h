#ifndef PATTERN_ANIMATION_H
#define PATTERN_ANIMATION_H

#include <Arduino.h>
#include "Animation.h"
#include "Button.h"
#include "SimonPattern.h"

class PatternAnimation : public Animation {
  private:
    const SimonPattern& pattern_;
    const int buttonCount_;
    const Button* const buttons_;
    
    unsigned int patternIdx_;
    bool on_;

  public:
    PatternAnimation(const SimonPattern& pattern, const Button* const buttons, const int buttonCount);

    void reset();
    const bool nextFrame();
    const Color& getFrameLedColor(unsigned int led);
    const unsigned int getFrameInterval();
    
};

#endif /* PATTERN_ANIMATION_H */

