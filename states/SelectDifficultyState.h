
#pragma once
#include "game/GameData.h"
#include "GameState.h"

struct SelectDifficultyState
    : public GameState
{
  explicit SelectDifficultyState(IGame *game);

  void run() override;
};