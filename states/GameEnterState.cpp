#include "console/GameConsole.h"
#include "GameEnterState.h"
#include "GameInitializationState.h"


GameEnterState::GameEnterState(IGame *game) 
  : GameState(game) {
  this->setNextState(std::make_shared<GameInitializationState>(game));
}

void GameEnterState::run() {
  console->clearScreen();
  console->printWelcomeScreen();
}