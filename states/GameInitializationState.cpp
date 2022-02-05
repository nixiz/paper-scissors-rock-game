#include "console/GameConsole.h"
#include "GameInitializationState.h"
#include "SelectDifficultyState.h"
#include "utils/keyboard_helper.hpp"

extern std::shared_ptr<GameConsole> console;

GameInitializationState::GameInitializationState(IGame *game)
  : GameState(game)
{
  this->setNextState(std::make_shared<SelectDifficultyState>(game));
}

void GameInitializationState::run() {
  game->player_one.player_name = "Computer";
  console->promtPlayerName();
  std::getline(std::cin, game->player_two.player_name);
}