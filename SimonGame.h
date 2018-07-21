#ifndef SIMON_GAME_H
#define SIMON_GAME_H

#include <Arduino.h>
#include "Color.h"
#include "EventTimer.h"
#include "SimonPattern.h"

class SimonGame {
  public:
      typedef enum {
        GAME_IDLE,
        DISPLAY_PATTERN,
        WAITING_FOR_INPUT,
        GAME_FAILED,
        ROUND_SUCCESS,
        GAME_SUCCESS
      } GameState;

  private:
    SimonPattern pattern_;
    unsigned int patternIdx_;
    GameState state_;

  public:
    SimonGame(const Color* const colorList, const int colorCount);

    void reset();
    const GameState getState();
    const SimonPattern& getPattern();
    const GameState buttonPressed(const Color& buttonColor);
};

#endif /* SIMON_GAME_H */

