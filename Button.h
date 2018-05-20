#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "Color.h"

class Button {
  private:
    const int pin_;
    const int id_;
    const Color color_;

  public:
    constexpr Button(const int pin, const int id, const Color& color) : 
    pin_(pin), id_(id), color_(color) {};

    void begin() const;
    bool readState() const;
    int getId() const;
    const Color& getColor() const;
};

#endif /* BUTTON_H */
