#pragma once
#include "game/GameData.h"
#include "GameState.h"

struct GameInitializationState
    : public GameState
{
public:
  explicit GameInitializationState(IGame *game);
  void run() override;
};