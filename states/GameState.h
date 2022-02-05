#pragma once
#include "game/GameData.h"
#include <memory>

struct GameState
{
  explicit GameState(IGame *playing_game);
  virtual ~GameState();

  virtual void run() = 0;

  std::shared_ptr<struct GameState> getNextState();
  void setNextState(const std::shared_ptr<struct GameState> &);

protected:
  IGame *game;

private:
  std::shared_ptr<struct GameState> next_state;
};