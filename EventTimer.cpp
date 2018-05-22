#include "EventTimer.h"

EventTimer::EventTimer(unsigned long interval) : interval_(interval), nextFire_(millis() + interval) {};

bool EventTimer::hasEventFired() {
  unsigned long currentTime = millis();
  if ((int32_t)(currentTime - nextFire_) >= 0) {
    reset();
    return true;
  } else {
    return false;
  }
}

void EventTimer::reset() {
  nextFire_ = millis() + interval_;
}

void EventTimer::setInterval(unsigned long interval) {
  interval_ = interval;
  reset();
}

