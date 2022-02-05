#include "console/GameConsole.h"
#include "game/GameData.h"
#include "GameOverState.h"
#include <iostream>

extern std::shared_ptr<GameConsole> console;

GameOverState::GameOverState(IGame *game)
    : GameState(game)
{
}

ScoreResults GameOverState::getGameResults()
{
  if (game->player_one.score > game->player_two.score)
  {
    return ScoreResults::p1_wins;
  }
  else if (game->player_two.score > game->player_one.score)
  {
    return ScoreResults::p2_wins;
  }
  else
  {
    return ScoreResults::no_win;
  }
}

void GameOverState::run()
{
  console->printGameOverMessage();
  auto results = getGameResults();
  switch (results)
  {
  case ScoreResults::p1_wins:
  case ScoreResults::p2_wins:
    console->printWinnerMessage((results == ScoreResults::p1_wins) ? game->player_one.player_name : game->player_two.player_name);
    break;
  case ScoreResults::no_win:
    console->printTieMessage();
    break;
  }
}