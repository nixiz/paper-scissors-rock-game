#include "console/GameConsole.h"
#include "GameEnterState.h"
#include "GameInitializationState.h"

extern std::shared_ptr<GameConsole> console;

GameEnterState::GameEnterState(IGame *game) 
  : GameState(game) {
  this->setNextState(std::make_shared<GameInitializationState>(game));
}

void GameEnterState::run() {
  console->clearScreen();
  console->printWelcomeScreen();
}