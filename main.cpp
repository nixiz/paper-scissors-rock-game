#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <thread>
#include <functional>
#include <chrono>
#include "console/language_support.h"
#include "utils/CommandLineParser.h"
#include "game/RPSGame.h"

std::shared_ptr<GameConsole> console;

int main(int argc, const char *argv[])
{
  CommandLineParser cli(argc, argv);
  RPSGame game;
  return game.run();
}