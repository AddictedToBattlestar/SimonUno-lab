#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    const int pin_;

  public:
    constexpr Button(const int pin) : pin_(pin) {};

    void begin() const;
    bool readState() const;
};

#endif /* BUTTON_H */
