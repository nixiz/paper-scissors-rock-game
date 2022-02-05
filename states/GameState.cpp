#include "GameState.h"

GameState::GameState(IGame *playing_game) 
  : game(playing_game) { }

GameState::~GameState() = default;

std::shared_ptr<GameState> GameState::getNextState() {
  return next_state;
}

void GameState::setNextState(const std::shared_ptr<GameState>& state) {
  next_state = state;
}