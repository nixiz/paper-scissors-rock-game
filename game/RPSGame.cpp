#include "RPSGame.h"
#include "console/language_support.h"
#include "game/GameData.h"
#include "utils/CommandLineParser.h"
#include "states/GameStateMachine.h"
#include "states/GameEnterState.h"

RPSGame::RPSGame()
{
  game_state = std::make_unique<GameStateMachine>(std::make_shared<GameEnterState>(this));
}

RPSGame::~RPSGame() = default;

int RPSGame::run()
{
  while (!game_state->gameOver())
  {
    game_state->step();
  }
  game_over = true;
  return 0;
}
