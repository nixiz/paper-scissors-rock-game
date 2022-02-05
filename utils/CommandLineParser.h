#pragma once
#include "console/GameConsole.h"
#include <memory>

class CommandLineParser {
  const char** args;
  int total_args;
  int current_arg_index;
  std::shared_ptr<GameConsole> console;
public:
  CommandLineParser(int argc, const char* argv[]);
  std::shared_ptr<GameConsole> getConsole() const noexcept;

private:
  void parse();
  void parseLanguage(std::string_view lang);
  bool done() const noexcept;
  std::string_view next() noexcept;
};
