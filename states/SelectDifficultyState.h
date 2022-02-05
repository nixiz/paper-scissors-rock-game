
#pragma once
#include "data/game_data.h"
#include "GameState.h"

struct SelectDifficultyState 
  : public GameState 
{
  explicit SelectDifficultyState(IGame *game);

  void run() override;
};