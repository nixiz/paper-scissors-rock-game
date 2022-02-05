#pragma once
#include "console/GameConsole.h"
#include <memory>

class CommandLineParser
{
  const char **args;
  int total_args;
  int current_arg_index;

public:
  CommandLineParser(int argc, const char *argv[]);

private:
  void parse();
  void parseLanguage(std::string_view lang);
  bool done() const noexcept;
  std::string_view next() noexcept;
};
