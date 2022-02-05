#pragma once
#include <iostream>
#include "GameConsole.h"
#include "game/GameData.h"

struct En
{
  static constexpr const char* rock_str = "Rock";
  static constexpr const char* paper_str = "Paper";
  static constexpr const char* scissors_str = "Scissors";
  static constexpr const char *welcome_str = "Welcome to Paper Rock Scissors Game\n";
  static constexpr const char *menu_str = "RockPaperScissorsGame command line interface:\n"
                                          "-l, --language: Select game language for playing. Default: en\n"
                                          "                Supporting languages: en, nl, tr\n"
                                          "\n"
                                          "-h, --help:     Prints this message.\n";
  static constexpr const char *please_select = "Please select ";
  static constexpr const char *game_difficulty_str = "Difficulty";
  static constexpr const char *easy_str = "Easy ";
  static constexpr const char *hard_str = "Hard ";
  static constexpr const char *prompt_player_name = "Please enter your name: ";
  static constexpr const char *game_is_starting = "Game is starting ";
  static constexpr const char *player = "Player ";
  static constexpr const char *press_enter_to_start = "Press Enter to start.";
  static constexpr const char *game_over_msg = "Game is over!";
  static constexpr const char *the_winner_is = "The Winner is";
  static constexpr const char *this_game_is_tie = "This game is tie!";
  static constexpr const char *round_str = "Round: ";
  static constexpr const char *round_msg = "(r)ock, (p)aper, (s)cissors, to quit please enter (q)uit\n"
                                           "Please enter your choice: ";
  static constexpr const char* its_a_tie = "Its a tie!";
  static constexpr const char* score_table = "Score Table";
  static constexpr const char* wins = "wins";
  static constexpr const char* choice = "choice";
  static constexpr const char* wrong_choice = "You entered wrong choise. Please enter one of r, p or s";
};

struct Nl
{
  static constexpr const char* rock_str = "Steen";
  static constexpr const char* paper_str = "Papier";
  static constexpr const char* scissors_str = "Schaar";
  static constexpr const char *welcome_str = "Welkom bij Paper Rock Scissors Game\n";
  static constexpr const char *menu_str = "RockPaperScissorsGame opdrachtregelinterface:\n"
                                          "-l, --language: Selecteer de speltaal om te spelen. Standaard: en\n"
                                          "                Ondersteunende talen: en, nl, tr\n"
                                          "\n"
                                          "-h, --help:     Drukt dit bericht af.\n";
  static constexpr const char *please_select = "Selecteer alstublieft ";
  static constexpr const char *game_difficulty_str = "Moeilijkheidsgraad";
  static constexpr const char *easy_str = "Eenvoudig ";
  static constexpr const char *hard_str = "Moeilijk ";
  static constexpr const char *prompt_player_name = "Voer je naam in: ";
  static constexpr const char *game_is_starting = "Spel begint ";
  static constexpr const char *player = "Speler ";
  static constexpr const char *press_enter_to_start = ". Druk op Enter om te beginnen.";
  static constexpr const char *game_over_msg = "Spel is over!";
  static constexpr const char *the_winner_is = "De winnaar is";
  static constexpr const char *this_game_is_tie = "Dit spel is gelijkspel!";
  static constexpr const char *round_str = "Ronde: ";
  static constexpr const char *round_msg = "(r)ock, (p)aper, (s)cissors, om te stoppen, voer (q)uit in\n"
                                           "Gelieve uw keuze in te vullen: ";
  static constexpr const char* its_a_tie = "Het is een gelijkspel!";
  static constexpr const char* score_table = "Score Tabel";
  static constexpr const char* wins = "wint";
  static constexpr const char* choice = "keuze";
  static constexpr const char* wrong_choice = "U heeft een verkeerde keuze ingevoerd. Voer een van r, p of s in";
};

struct Tr
{
  static constexpr const char* rock_str = "Taş";
  static constexpr const char* paper_str = "Kağıt";
  static constexpr const char* scissors_str = "Makas";
  static constexpr const char *welcome_str = "Taş Kağıt Makas Oyununa Hoşgeldiniz\n";
  static constexpr const char *menu_str = "RockPaperScissorsGame komut satırı özellikleri:\n"
                                          "-l, --language: Oyun dilini belirler. Varsayılan: en\n"
                                          "                Desteklenen diller: en, nl, tr\n"
                                          "\n"
                                          "-h, --help:     Bu mesajı yazdırır.";
  static constexpr const char *please_select = "Lütfen seçin ";
  static constexpr const char *game_difficulty_str = "Zorluk Derecesi";
  static constexpr const char *easy_str = "Kolay ";
  static constexpr const char *hard_str = "Zor ";
  static constexpr const char *prompt_player_name = "Lütfen adınızı girin: ";
  static constexpr const char *game_is_starting = "Oyunu başlıyor ";
  static constexpr const char *player = "Oyuncu ";
  static constexpr const char *press_enter_to_start = ". Başlamak için Enter basın.";
  static constexpr const char *game_over_msg = "Oyun Bitti!";
  static constexpr const char *the_winner_is = "Kazanan";
  static constexpr const char *this_game_is_tie = "Oyun berabere!";
  static constexpr const char *round_str = "Tur: ";
  static constexpr const char *round_msg = "(r)ock, (p)aper, (s)cissors, oyundan çıkmak için (q)uit yazın\n"
                                           "Lütfen seçiminizi girin: ";
  static constexpr const char* its_a_tie = "Berabere!";
  static constexpr const char* score_table = "Skor Tablosu";
  static constexpr const char* wins = "kazandı";
  static constexpr const char* choice = "seçimi";
  static constexpr const char* wrong_choice = "Yanlış giriş yaptınız. Lütfen r, p or s seçeneklerinden birini girin";
};

template <typename Lang>
struct GameLanguage
    : public GameConsole
{
  std::string getRockName() const override 
  {
    return Lang::rock_str;
  }

  std::string getPaperName() const override
  {
    return Lang::paper_str;
  }
  
  std::string getScissorsName() const override
  {
    return Lang::scissors_str;
  }

  void printWelcomeScreen() override
  {
    std::cout << Lang::welcome_str;
  }

  void printMenu() override
  {
    std::cout << Lang::menu_str;
  }

  void promtPlayerName() override
  {
    std::cout << Lang::prompt_player_name;
  }

  void promtGameDifficulty(IGame *game) override
  {
    std::cout << "Hi " << game->player_two.player_name << "\n";
    std::cout << Lang::please_select << Lang::game_difficulty_str << "\n"
              << "1. " << Lang::easy_str << "\n"
              << "2. " << Lang::hard_str << "\n";
  }

  void printGameAboutToStart(IGame *game) override
  {
    std::cout << Lang::game_is_starting << "\n"
              << Lang::player << game->player_one.player_name
              << " VS " << game->player_two.player_name
              << "\n"
              << Lang::game_difficulty_str << ": " << game->getStrategy()->getDifficultyName() << "\n"
              << Lang::press_enter_to_start << "\n";
  }

  void printGameOverMessage() override
  {
    std::cout
        << Lang::game_over_msg << "\n";
  }

  void printWinnerMessage(const std::string &winner) override
  {
    std::cout << Lang::the_winner_is << " " << winner << "\n";
  }

  void printTieMessage() override
  {
    std::cout << Lang::this_game_is_tie << "\n";
  }
  
  void printItsTieMessage() override
  {
    std::cout << Lang::its_a_tie << "\n";
  }

  void printWinnerOfRound(const std::string& winner) override
  {
    std::cout << winner << " " << Lang::wins << "!\n";
  }

  void printRoundEntry(int round) override
  {
    std::cout
        << "\t~~" << Lang::round_str << round << "~~\n"
        << Lang::round_msg;
  }

  void printPlayerChoice(const std::string& player, const std::string& choice) override
  {
    std::cout << player << " " << Lang::choice << ": " << choice << "\n";
  }

  void printScoreTable(IGame* game) override
  {
    std::cout
      << Lang::score_table << ":\n"
      << game->player_one.player_name << ": " << game->player_one.score << "\t"
      << game->player_two.player_name << ": " << game->player_two.score << "\n";
  }

  void printWrongChoice() override
  {
    std::cout << Lang::wrong_choice << "\n";
  }

};
