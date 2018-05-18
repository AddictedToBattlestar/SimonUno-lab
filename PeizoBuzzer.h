#ifndef PEIZOBUZZER_H
#define PEIZOBUZZER_H

#include <Arduino.h>

class PeizoBuzzer {
  private:
    const int pin_;

  public:
    constexpr PeizoBuzzer(const int pin) : pin_(pin) {};

    void begin() const;
    void turnOn() const;
    void turnOff() const;
};

#endif // PEIZOBUZZER_H
