#pragma once
#include <string>
#include <iostream>
#include "console/GameConsole.h"

struct Selection
{
  enum type : int
  {
    none = 0,
    paper,
    rock,
    scissors,
    done
  };
  Selection() = default;
  virtual ~Selection() {}
  virtual bool wins(const Selection &oth) const = 0;
  virtual type getType() const = 0;
  virtual std::string getName() const = 0;
};

struct Paper final
    : public Selection
{
  type getType() const override { return type::paper; }
  bool wins(const Selection &oth) const override
  {
    // paper beats (wraps) rock
    return oth.getType() == type::rock;
  }
  std::string getName() const override
  {
    return console->getPaperName();
  }
};

struct Rock final
    : public Selection
{
  type getType() const override { return type::rock; }
  bool wins(const Selection &oth) const override
  {
    // rock beats (blunts) scissors
    return oth.getType() == type::scissors;
  }
  std::string getName() const override
  {
    return console->getRockName();
  }
};

struct Scissors final
    : public Selection
{
  type getType() const override { return type::scissors; }
  bool wins(const Selection &oth) const override
  {
    // scissors beats (cuts) paper
    return oth.getType() == type::paper;
  }
  std::string getName() const override
  {
    return console->getScissorsName();
  }
};

struct GameOver final
    : public Selection
{
  type getType() const override { return type::done; }
  bool wins(const Selection &oth) const override
  {
    return false;
  }
  std::string getName() const override
  {
    return "Game Over";
  }
};