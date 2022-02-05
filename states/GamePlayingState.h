#pragma once
#include "data/game_data.h"
#include "GameState.h"
#include <memory>

struct GamePlayingState 
  : public GameState 
  , public std::enable_shared_from_this<GamePlayingState>
{
  explicit GamePlayingState(IGame *game);
  void run() override;
private:
  int round {0};
};

