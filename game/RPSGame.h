#pragma once
#include "GameData.h"

class RPSGame : public IGame
{
private:
  std::unique_ptr<struct GameStateMachine> game_state;

public:
  RPSGame();
  ~RPSGame();

  int run();
};
