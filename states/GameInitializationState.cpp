#include "console/GameConsole.h"
#include "GameInitializationState.h"
#include "SelectDifficultyState.h"
#include <iostream>
#include <string>

GameInitializationState::GameInitializationState(IGame *game)
    : GameState(game)
{
  this->setNextState(std::make_shared<SelectDifficultyState>(game));
}

void GameInitializationState::run()
{
  game->player_one.player_name = "Computer";
  console->promtPlayerName();
  std::getline(std::cin, game->player_two.player_name);
}