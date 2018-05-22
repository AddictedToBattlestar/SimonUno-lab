#ifndef FLASH_ANIMATION_H
#define FLASH_ANIMATION_H

#include <Arduino.h>
#include "Animation.h"

class FlashAnimation: public Animation {
  private:
    typedef enum {
      LED_ON,
      LED_OFF,
      FINAL_DELAY
    } FlashState;

    const Color color_;
    const unsigned int flashCount_;
    const unsigned int onTime_;
    const unsigned int offTime_;

    unsigned int displayedCount_;
    FlashState state_;
    
  public:
    FlashAnimation(const Color& color, unsigned int flashCount, unsigned int onTime, unsigned int offTime);

    void reset();
    const bool nextFrame();
    const Color& getFrameLedColor(unsigned int led);
    const unsigned int getFrameInterval();
};

#endif /* FLASH_ANIMATION_H */
