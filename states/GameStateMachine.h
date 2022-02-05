#pragma once
#include <memory>

struct GameState;
struct GameStateMachine
{
  std::shared_ptr<struct GameState> currentState;

  explicit GameStateMachine(const std::shared_ptr<GameState>& initialState);
  ~GameStateMachine();
  
  void setState(const std::shared_ptr<GameState>& newState);
  void step();
  bool gameOver() const;
};