#include <iostream>
#include "game/Selections.h"
#include "console/GameConsole.h"
#include "GamePlayingState.h"
#include "GameOverState.h"

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
      console->printWrongChoice();
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
  console->printRoundEntry(round++);
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

  console->clearScreen();
  console->printPlayerChoice(game->player_one.player_name, selection_p1->getName());
  console->printPlayerChoice(game->player_two.player_name, selection_p2->getName());

  auto winner = defineStepWinner(*selection_p1, *selection_p2);
  switch (winner)
  {
  case ScoreResults::p1_wins:
    game->player_one.score++;
    console->printWinnerOfRound(game->player_one.player_name);
    break;
  case ScoreResults::p2_wins:
    game->player_two.score++;
    console->printWinnerOfRound(game->player_two.player_name);
    break;
  case ScoreResults::no_win:
    game->player_one.score++;
    game->player_two.score++;
    console->printItsTieMessage();
    break;
  }
  console->printScoreTable(game);
}
