#include "SimonGame.h"

SimonGame::SimonGame(const Color* const colorList, const int colorCount) : pattern_(colorList, colorCount), state_(GAME_IDLE), patternIdx_(0) {}

const SimonGame::GameState SimonGame::getState() {
  const SimonGame::GameState retState = state_;
  if (state_ == ROUND_SUCCESS) {
    patternIdx_ = 0;
    pattern_.addStep();
    state_ = DISPLAY_PATTERN;
  } else if (state_ == GAME_FAILED || state_ == GAME_SUCCESS) {
    pattern_.clear();
    patternIdx_ = 0;
    state_ = GAME_IDLE;
  } else if (state_ == DISPLAY_PATTERN) {
    state_ = WAITING_FOR_INPUT;
  }
  return retState;
}

const SimonPattern& SimonGame::getPattern() {
  return pattern_;
}

const SimonGame::GameState SimonGame::buttonPressed(const Color& buttonColor) {
  switch (state_) {
    case GAME_IDLE:
      pattern_.clear();
      patternIdx_ = 0;
      state_ = DISPLAY_PATTERN;
      break;

    case WAITING_FOR_INPUT:
      if (buttonColor == pattern_.getStepColor(patternIdx_)) {
        patternIdx_++;
        if (patternIdx_ == pattern_.getSize()) {
          if (pattern_.getSize() == pattern_.MAX_PATTERN_LENGTH) {
            state_ = GAME_SUCCESS;
          } else {
            state_ = ROUND_SUCCESS;
          }
        } 
      } else {
        state_ = GAME_FAILED;
      }
      break;

    default:
      break;
  }
  return state_; 
}

