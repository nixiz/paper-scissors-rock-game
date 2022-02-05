#pragma once
#include <random>
#include "GameStrategy.h"
#include "game/Selections.h"

struct HardStrategy
    : public GameStrategy
{
  Selection::type selection = Selection::none;

  HardStrategy()
  {
    srand(time(NULL));
  }

  std::unique_ptr<Selection> play() override
  {
    selection = static_cast<Selection::type>((selection % Selection::scissors) + 1);
    switch (selection)
    {
    case Selection::paper:
      return std::make_unique<Paper>();
    case Selection::rock:
      return std::make_unique<Rock>();
    case Selection::scissors:
      return std::make_unique<Scissors>();
    default:
      std::cout << "There is an internal problem with Game AI. Game will stop.\n";
      return std::make_unique<GameOver>();
    }
  }

  std::string getDifficultyName() const override
  {
    return console->getHardString();
  }
};