#ifndef LEDDISPLAY_H
#define LEDDISPLAY_H

#include <Arduino.h>
#include "EventTimer.h"
#include "Led.h"
#include "RgbControl.h"

class LedDisplay {
  private:
    static const unsigned int maxLedCount_ = 4;

    const int ledCount_;
    const Led* const ledList_;
    const RgbControl& rgbControl_;

    EventTimer eventTimer_;
    Color colorRam_[maxLedCount_];
    int activeLed_ = 0;
    
  public:
    LedDisplay(const Led* const leds, const int ledCount, const RgbControl& rgbControl, const int refreshInterval);

    void begin();
    void update();
    void turnLedOn(const int ledIndex, const Color& color);
    void turnLedOff(const int ledIndex);
};

#endif /* LEDDISPLAY_H */
