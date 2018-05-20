#ifndef COLOR_H
#define COLOR_H

class Color {
  private:
    byte red_;
    byte green_;
    byte blue_;

  public:
    constexpr Color() : red_(0), green_(0), blue_(0) {};
    constexpr Color(byte red, byte green, byte blue) : red_(red), green_(green), blue_(blue) {};
    
    inline byte red() const {
      return red_;
    }
    inline byte green() const {
      return green_;
    }
    inline byte blue() const {
      return blue_;
    }

    Color & operator=(const Color &rhs) {
      if (this != &rhs) {
        red_ = rhs.red_;
        green_ = rhs.green_;
        blue_ = rhs.blue_;
      }
      return *this;
    }

    bool operator==(const Color &other) const {
      return (red_ == other.red_) && (blue_ == other.blue_) && (green_ == other.green_);
    }

    bool operator!=(const Color &other) const {
      return !(*this == other);
    }
};

namespace COLORS {
  constexpr Color OFF       = Color(  0,   0,   0);
  constexpr Color BLACK     = Color(  0,   0,   0);
  constexpr Color RED       = Color(128,   0,   0);
  constexpr Color GREEN     = Color(  0, 128,   0);
  constexpr Color BLUE      = Color(  0,   0, 128);
  constexpr Color YELLOW    = Color(128, 128,   0);
  constexpr Color PURPLE    = Color(128,   0, 128);
  constexpr Color BLUEGREEN = Color(  0, 196,  76);
  constexpr Color WHITE     = Color(128, 128,  76);
}

#endif /* COLOR_H */
