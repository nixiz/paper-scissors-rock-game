#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <thread>
#include <functional>
#include <chrono>
#include "console/language_support.h"
#include "data/game_data.h"
#include "utils/keyboard_helper.hpp"
#include "utils/CommandLineParser.h"
#include "states/GameStateMachine.h"
#include "states/GameEnterState.h"

// global game language since there would be no second language on game.
std::shared_ptr<GameConsole> console;

class RPSGame
    : public IGame
{
private:
  std::thread kb_events_thread;
  std::unique_ptr<GameStateMachine> game_state;

public:
  ~RPSGame()
  {
    // kb_events_thread.join();
  }

  RPSGame()
  {
    // kb_events_thread = std::thread(&RPSGame::receiveKeyboardEvents, this);
    game_state = std::make_unique<GameStateMachine>(std::make_shared<GameEnterState>(this));
  }

  int run()
  {
    while (!game_state->gameOver())
    {
      game_state->step();
    }
    game_over = true;
    return 0;
  }

private:
  // void receiveKeyboardEvents()
  // {
  //   using namespace std::chrono_literals;
  //   while (1) {
  //     if (!kb_utils::kbhit()) {
  //       std::this_thread::sleep_for(5ms); continue;
  //     }
  //     key k = kb_utils::readKey(true);
  //   }
  // }
};

int main(int argc, const char *argv[])
{
  CommandLineParser cli(argc, argv);
  console = cli.getConsole();
  RPSGame game;
  return game.run();
}