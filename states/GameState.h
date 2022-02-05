#pragma once
#include "data/game_data.h"
#include <memory>

struct GameState {
  explicit GameState(IGame *playing_game);
  virtual ~GameState();
  
  virtual void run() = 0;
  virtual void onKey(int key) { }

  std::shared_ptr<struct GameState> getNextState();
  void setNextState(const std::shared_ptr<struct GameState>&);

protected:
  IGame *game;
private:
  std::shared_ptr<struct GameState> next_state;
};