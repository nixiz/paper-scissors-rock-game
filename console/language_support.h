#pragma once
#include <iostream>
#include "GameConsole.h"
#include "game/GameData.h"

struct En
{
  static constexpr const char *welcome_str = "Welcome to Paper Rock Scissors Game\n";
  static constexpr const char *menu_str = "menu_str\n";
  static constexpr const char *please_select = "Please select ";
  static constexpr const char *game_difficulty_str = "Difficulty";
  static constexpr const char *easy_str = "Easy ";
  static constexpr const char *hard_str = "Hard ";
  static constexpr const char *prompt_player_name = "Please enter your name: ";
  static constexpr const char *game_is_starting = "Game is starting ";
  static constexpr const char *player = "Player ";
  static constexpr const char *press_enter_to_start = "Press Enter to start.";
  static constexpr const char *game_over_msg = "Game is over!";
};

struct Nl
{
  static constexpr const char *welcome_str = "Welcome to Paper Rock Scissors Game\n";
  static constexpr const char *menu_str = "menu_str\n";
  static constexpr const char *please_select = "Please select ";
  static constexpr const char *game_difficulty_str = "Difficulty";
  static constexpr const char *easy_str = "Easy ";
  static constexpr const char *hard_str = "Hard ";
  static constexpr const char *prompt_player_name = "Please enter your name: ";
  static constexpr const char *game_is_starting = "Game is starting ";
  static constexpr const char *player = "Player ";
  static constexpr const char *press_enter_to_start = ". Press Enter to start.";
  static constexpr const char *game_over_msg = "Game is over!";
};

struct Tr
{
  static constexpr const char *welcome_str = "Welcome to Paper Rock Scissors Game\n";
  static constexpr const char *menu_str = "menu_str\n";
  static constexpr const char *please_select = "Please select ";
  static constexpr const char *game_difficulty_str = "Difficulty";
  static constexpr const char *easy_str = "Easy ";
  static constexpr const char *hard_str = "Hard ";
  static constexpr const char *prompt_player_name = "Please enter your name: ";
  static constexpr const char *game_is_starting = "Game is starting ";
  static constexpr const char *player = "Player ";
  static constexpr const char *press_enter_to_start = ". Press Enter to start.";
  static constexpr const char *game_over_msg = "Game is over!";
};

template <typename Lang>
struct GameLanguage
    : public GameConsole
{
  void printWelcomeScreen() override
  {
    std::cout << Lang::welcome_str;
  }

  void printMenu() override
  {
    std::cout << Lang::menu_str;
  }

  void promtPlayerName() override
  {
    std::cout << Lang::prompt_player_name;
  }

  void promtGameDifficulty(IGame *game) override
  {
    std::cout << "Hi " << game->player_two.player_name << "\n";
    std::cout << Lang::please_select << Lang::game_difficulty_str << "\n"
              << "1. " << Lang::easy_str << "\n"
              << "2. " << Lang::hard_str << "\n";
  }

  void printGameAboutToStart(IGame *game) override
  {
    std::cout << Lang::game_is_starting << "\n"
              << Lang::player << game->player_one.player_name
              << " VS " << game->player_two.player_name
              << "\n"
              << Lang::game_difficulty_str << ": " << game->getStrategy()->getDifficultyName() << "\n"
              << Lang::press_enter_to_start << "\n";
  }

  void printGameOverMessage() override
  {
    std::cout
        << Lang::game_over_msg << "\n";
  }

  void printWinnerMessage(const std::string &winner) override
  {
    std::cout << "The Winner is " << winner << "\n";
  }

  void printTieMessage() override
  {
    std::cout << "This game is tie!\n";
  }
};
