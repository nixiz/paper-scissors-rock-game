#pragma once
#include <memory>
#include <string>
#include "strategies/GameStrategy.h"

enum class ScoreResults {
  p1_wins,
  p2_wins,
  no_win, // tie
};

struct Player
{
  std::string player_name;
  int score {0};
};

struct IGame
{
  Player player_one;
  Player player_two;
  bool game_over {false};
  std::unique_ptr<GameStrategy> game_strategy;
  
  auto getStrategy() const {
    return game_strategy.get();
  }

  void setStrategy(std::unique_ptr<GameStrategy> gs) {
    game_strategy = std::move(gs);
  }
};