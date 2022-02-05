#include "CommandLineParser.h"
#include "console/language_support.h"

CommandLineParser::CommandLineParser(int argc, const char *argv[])
    : total_args(argc), args(argv), current_arg_index(0)
{
  // TODO(oguzhank): default language can be determined by localization of running host
  console = std::shared_ptr<GameConsole>(new GameLanguage<En>);
  parse();
}

std::shared_ptr<GameConsole> CommandLineParser::getConsole() const noexcept
{
  return console;
}

void CommandLineParser::parse()
{
  while (!done())
  {
    auto arg = next();
    if (arg == "-l" || arg == "--language")
    {
      if (auto lang = next();
          !lang.empty())
      {
        parseLanguage(lang);
      }
    }
    else if (arg == "-h" || arg == "--help")
    {
      console->printMenu();
      std::terminate();
    }
  }
}

void CommandLineParser::parseLanguage(std::string_view lang)
{
  if (lang == "en")
  {
    console = std::make_shared<GameLanguage<En>>();
  }
  else if (lang == "nl")
  {
    console = std::make_shared<GameLanguage<Nl>>();
  }
  else if (lang == "tr")
  {
    console = std::make_shared<GameLanguage<Tr>>();
  }
  else
  {
    // do nothing
  }
}

bool CommandLineParser::done() const noexcept
{
  return current_arg_index >= total_args;
}

std::string_view CommandLineParser::next() noexcept
{
  if (done())
  {
    return std::string_view{};
  }
  return std::string_view{args[current_arg_index++]};
}
