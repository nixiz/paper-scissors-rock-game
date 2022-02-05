#pragma once
#include "data/game_data.h"
#include "GameState.h"

struct GameInitializationState 
  : public GameState 
{
public:
  explicit GameInitializationState(IGame *game);
  void run() override;
};