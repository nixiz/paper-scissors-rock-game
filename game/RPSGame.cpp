#include "RPSGame.h"
#include "console/language_support.h"
#include "game/GameData.h"
#include "utils/keyboard_helper.hpp"
#include "utils/CommandLineParser.h"
#include "states/GameStateMachine.h"
#include "states/GameEnterState.h"

RPSGame::RPSGame()
{
  // kb_events_thread = std::thread(&RPSGame::receiveKeyboardEvents, this);
  game_state = std::make_unique<GameStateMachine>(std::make_shared<GameEnterState>(this));
}

RPSGame::~RPSGame()
{
  // kb_events_thread.join();
}

int RPSGame::run()
{
  while (!game_state->gameOver())
  {
    game_state->step();
  }
  game_over = true;
  return 0;
}
