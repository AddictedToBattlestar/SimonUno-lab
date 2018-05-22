#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Arduino.h>
#include "Animation.h"
#include "EventTimer.h"
#include "LedDisplay.h"

class Animator {
  private:
    LedDisplay& ledDisplay_;
    Animation* activeAnimation_;
    EventTimer eventTimer_;

    void displayAnimationFrame();

  public:
    Animator(LedDisplay& ledDisplay);

    void update();
    bool isActive();
    void playAnimation(Animation& animation);
};

#endif /* ANIMATOR_H */
