#include <iostream>
#include "game/Selections.h"
#include "console/GameConsole.h"
#include "GamePlayingState.h"
#include "GameOverState.h"

extern std::shared_ptr<GameConsole> console;

std::unique_ptr<Selection> getPlayerSelection()
{
  std::unique_ptr<Selection> selection;
  while (!selection)
  {
    std::string selection_str;
    std::getline(std::cin, selection_str);
    if (selection_str == "r" || selection_str == "rock")
    {
      selection.reset(new Rock);
    }
    else if (selection_str == "p" || selection_str == "paper")
    {
      selection.reset(new Paper);
    }
    else if (selection_str == "s" || selection_str == "scissors")
    {
      selection.reset(new Scissors);
    }
    else if (selection_str == "q" || selection_str == "quit")
    {
      selection.reset(new GameOver);
    }
    else
    {
      std::cout << "You entered wrong choise. Please enter one of r, p or s\n";
    }
  }
  return selection;
}

ScoreResults defineStepWinner(const Selection &p1, const Selection &p2)
{
  if (p1.wins(p2))
    return ScoreResults::p1_wins;
  else if (p2.wins(p1))
    return ScoreResults::p2_wins;
  else
    return ScoreResults::no_win;
}

GamePlayingState::GamePlayingState(IGame *game)
    : GameState(game)
{
}

void GamePlayingState::run()
{
  std::cout
      << "\t~~Round: " << round++ << "~~\n"
      << "(r)ock, (p)aper, (s)cissors, to quit please enter (q)uit\n"
      << "Please enter your choise: ";
  std::unique_ptr<Selection> selection_p1 = game->getStrategy()->play();
  std::unique_ptr<Selection> selection_p2 = getPlayerSelection();
  if (selection_p2->getType() == Selection::done)
  {
    this->setNextState(std::make_shared<GameOverState>(game));
    return;
  }
  else
  {
    this->setNextState(shared_from_this());
  }

  std::cout
      << game->player_one.player_name << " choise: " << selection_p1->getName() << "\n"
      << game->player_two.player_name << " choise: " << selection_p2->getName() << "\n";

  auto winner = defineStepWinner(*selection_p1, *selection_p2);
  switch (winner)
  {
  case ScoreResults::p1_wins:
    game->player_one.score++;
    std::cout << game->player_one.player_name << " Wins!\n";
    break;
  case ScoreResults::p2_wins:
    game->player_two.score++;
    std::cout << game->player_two.player_name << " Wins!\n";
    break;
  case ScoreResults::no_win:
    std::cout << "Its a tie!\n";
    break;
  }
  std::cout
      << "Score table: \n"
      << game->player_one.player_name << ": " << game->player_one.score << "\t"
      << game->player_two.player_name << ": " << game->player_two.score << "\n";
}
