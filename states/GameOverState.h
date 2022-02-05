#pragma once
#include "GameState.h"

struct GameOverState 
  : public GameState 
{
  explicit GameOverState(struct IGame *game);
  void run() override;
private:
  ScoreResults getGameResults();
};