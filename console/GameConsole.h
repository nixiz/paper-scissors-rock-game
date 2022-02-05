#pragma once
#include <string>

enum ConsoleColor : unsigned int {
  console_default = 0,
  fg_blue = 1,
  fg_green = 2,
  fg_red = 4,
  bg_blue = 16,
  bg_green = 32,
  bg_red = 64,
};

struct GameConsole {
  void setConsoleColor(unsigned int newColor);
  void resetConsoleColor();
  void clearScreen();
  virtual void printWelcomeScreen() = 0;
  virtual void printMenu() = 0;
  virtual void promtPlayerName() = 0;
  virtual void promtGameDifficulty(struct IGame *game) = 0;
  virtual void printGameAboutToStart(struct IGame *game) = 0;
  virtual void printGameOverMessage() = 0;
  virtual void printWinnerMessage(const std::string& winner) = 0;
  virtual void printTieMessage() = 0;
};