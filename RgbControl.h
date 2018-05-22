#ifndef RGBCONTROL_H
#define RGBCONTROL_H

#include <Arduino.h>
#include "Color.h"

class RgbControl {
  private:
    const int redPin_;
    const int greenPin_;
    const int bluePin_;
    
  public:
    constexpr RgbControl(const int redPin, const int greenPin, const int bluePin) : 
    redPin_(redPin), greenPin_(greenPin), bluePin_(bluePin) {};

    void begin() const {
      pinMode(redPin_, OUTPUT);
      pinMode(greenPin_, OUTPUT);
      pinMode(bluePin_, OUTPUT);
      setColor(COLORS::OFF);
    }

    void setColor(const Color &color) const {
//      Serial.print(" - set color (red:");
//      Serial.print(color.red(), DEC);
//      Serial.print(", green:");
//      Serial.print(color.green(), DEC);
//      Serial.print(", blue:");
//      Serial.print(color.blue(), DEC);
//      Serial.println(")");
      analogWrite(redPin_, color.red());
      analogWrite(greenPin_, color.green());
      analogWrite(bluePin_, color.blue());
    }
};

#endif /* RGBCONTROL_H */
