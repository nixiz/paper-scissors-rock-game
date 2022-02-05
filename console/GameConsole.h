#pragma once
#include <string>
#include <memory>

enum ConsoleColor : unsigned int
{
  console_default = 0,
  fg_blue = 1,
  fg_green = 2,
  fg_red = 4,
  bg_blue = 16,
  bg_green = 32,
  bg_red = 64,
};

struct GameConsole
{
  void setConsoleColor(unsigned int newColor);
  void resetConsoleColor();
  void clearScreen();
  virtual std::string getRockName() const = 0;
  virtual std::string getPaperName() const = 0;
  virtual std::string getScissorsName() const = 0;
  virtual void printWelcomeScreen() = 0;
  virtual void printMenu() = 0;
  virtual void promtPlayerName() = 0;
  virtual void promtGameDifficulty(struct IGame *game) = 0;
  virtual void printGameAboutToStart(struct IGame *game) = 0;
  virtual void printGameOverMessage() = 0;
  virtual void printWinnerMessage(const std::string &winner) = 0;
  virtual void printTieMessage() = 0;
  virtual void printItsTieMessage() = 0;
  virtual void printWinnerOfRound(const std::string& winner) = 0;
  virtual void printRoundEntry(int round) = 0;
  virtual void printPlayerChoice(const std::string& player, const std::string& choice) = 0;
  virtual void printScoreTable(struct IGame* game) = 0;
  virtual void printWrongChoice() = 0;
};

extern std::shared_ptr<GameConsole> console;
