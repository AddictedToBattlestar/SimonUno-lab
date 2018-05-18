#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    const int pin_;
    const int id_;

  public:
    constexpr Button(const int pin, const int id) : pin_(pin), id_(id) {};

    void begin() const;
    bool readState() const;
    int getId() const;
};

#endif /* BUTTON_H */
