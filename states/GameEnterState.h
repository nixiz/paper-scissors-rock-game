#pragma once
#include "game/GameData.h"
#include "GameState.h"

struct GameEnterState
    : public GameState
{
  explicit GameEnterState(IGame *game);

  void run() override;
};