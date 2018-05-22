#ifndef ANIMATION_H
#define ANIMATION_H

#include <Arduino.h>
#include "Color.h"

class Animation {
  public:
    virtual void reset() = 0;
    virtual const bool nextFrame() = 0;
    virtual const Color& getFrameLedColor(unsigned int led) = 0;
    virtual const unsigned int getFrameInterval() = 0;  
};

#endif /* ANIMATION_H */
