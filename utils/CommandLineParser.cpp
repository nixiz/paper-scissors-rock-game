#include "CommandLineParser.h"
#include "console/language_support.h"

CommandLineParser::CommandLineParser(int argc, const char *argv[])
    : total_args(argc), args(argv), current_arg_index(0)
{
  // TODO(oguzhank): default language can be determined by localization of running host
  console.reset(new GameLanguage<En>);
  parse();
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
      std::exit(0);
    }
  }
}

void CommandLineParser::parseLanguage(std::string_view lang)
{
  if (lang == "en")
  {
    console.reset(new GameLanguage<En>);
  }
  else if (lang == "nl")
  {
    console.reset(new GameLanguage<Nl>);
  }
  else if (lang == "tr")
  {
    console.reset(new GameLanguage<Tr>);
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
