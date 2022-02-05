#include "GameState.h"
#include "game/GameData.h"
#include "console/GameConsole.h"
#include "GameStateMachine.h"


GameStateMachine::GameStateMachine(const std::shared_ptr<GameState> &initialState)
    : currentState(initialState)
{
}

GameStateMachine::~GameStateMachine() = default;

void GameStateMachine::setState(const std::shared_ptr<GameState> &newState)
{
  currentState = newState;
}

void GameStateMachine::step()
{
  currentState->run();
  currentState = currentState->getNextState();
}

bool GameStateMachine::gameOver() const
{
  return !currentState;
}
