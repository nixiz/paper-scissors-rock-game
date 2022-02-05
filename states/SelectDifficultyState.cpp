#include "console/GameConsole.h"
#include "SelectDifficultyState.h"
#include "GamePlayingState.h"
#include "strategies/GameStrategy.h"
#include "strategies/BasicStrategy.h"
#include "strategies/HardStrategy.h"
#include <string>
#include <iostream>

SelectDifficultyState::SelectDifficultyState(IGame *game)
    : GameState(game)
{
  this->setNextState(std::make_shared<GamePlayingState>(game));
}

void SelectDifficultyState::run()
{
  std::unique_ptr<GameStrategy> game_difficulty;
  while (!game_difficulty)
  {
    console->clearScreen();
    console->promtGameDifficulty(game);
    std::string difficulty;
    std::getline(std::cin, difficulty);
    if (difficulty == "1" || difficulty == "easy")
    {
      game_difficulty.reset(new BasicStrategy);
    }
    else if (difficulty == "2" || difficulty == "hard")
    {
      game_difficulty.reset(new HardStrategy);
    }
  }
  game->setStrategy(std::move(game_difficulty));
  console->printGameAboutToStart(game);
}