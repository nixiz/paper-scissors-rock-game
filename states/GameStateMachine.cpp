#include "GameState.h"
#include "data/game_data.h"
#include "console/GameConsole.h"
#include "GameStateMachine.h"

extern std::shared_ptr<GameConsole> console;


GameStateMachine::GameStateMachine(const std::shared_ptr<GameState>& initialState) 
  : currentState(initialState)
{ }

GameStateMachine::~GameStateMachine() = default;

void GameStateMachine::setState(const std::shared_ptr<GameState>& newState) {
  currentState = newState;
}

void GameStateMachine::step() {
  currentState->run();
  currentState = currentState->getNextState();
}

bool GameStateMachine::gameOver() const {
  return !currentState; 
}
