#pragma once
#include <string>

struct GameStrategy
{
  virtual std::unique_ptr<struct Selection> play() = 0;
  virtual std::string getDifficultyName() const = 0;
};