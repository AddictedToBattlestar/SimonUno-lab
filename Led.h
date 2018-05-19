#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  private:
    const int pin_;
    
  public:
    constexpr Led(const int pin) : pin_(pin) {};

    void begin() const;
    void turnOn() const;
    void turnOff() const;
  
};

#endif /* LED_H */
