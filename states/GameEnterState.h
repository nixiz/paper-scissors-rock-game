#pragma once
#include "data/game_data.h"
#include "GameState.h"

struct GameEnterState 
  : public GameState 
{
  explicit GameEnterState(IGame *game);

  void run() override;
};