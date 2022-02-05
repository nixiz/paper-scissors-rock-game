#include "GameConsole.h"

namespace colorconsole
{

#ifdef _WIN32
#include <Windows.h>
  class ConsoleColorManager
  {
  public:
    enum Color
    {
      _default = 0,
      fg_blue = FOREGROUND_BLUE,
      fg_green = FOREGROUND_GREEN,
      fg_red = FOREGROUND_RED,
      fg_intensified = FOREGROUND_INTENSITY,
      bg_blue = BACKGROUND_BLUE,
      bg_green = BACKGROUND_GREEN,
      bg_red = BACKGROUND_RED,
      bg_intensified = BACKGROUND_INTENSITY,
    };

    ConsoleColorManager()
    {
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      if (hConsole == NULL /*nullptr*/)
      {
        return;
      }
      /* Save current attributes */
      if (!GetConsoleScreenBufferInfo(hConsole, &consoleInfo))
        return;
      saved_attributes = consoleInfo.wAttributes;
      bInitialized = true;
    }

    ~ConsoleColorManager()
    {
      /* Restore original attributes */
      if (hConsole)
        SetConsoleTextAttribute(hConsole, saved_attributes);
      //printf("Back to normal");
    }

    bool SetConsoleColor(unsigned short color = Color::_default)
    {
      if (!bInitialized)
        return false;
      return SetConsoleTextAttribute(hConsole, color) > 0;
    }

    void reset()
    {
      SetConsoleTextAttribute(hConsole, saved_attributes);
    }

    ConsoleColorManager(const ConsoleColorManager &) = delete;
    ConsoleColorManager &operator=(const ConsoleColorManager &) = delete;

  private:
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    HANDLE hConsole;
    bool bInitialized = false;
  };
#else
  class ConsoleColorManager
  {
    /*
        foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
*/
    const char *RESET = "\033[0m";
    const char *BLACK = "\033[30m";
    const char *RED = "\033[31m";
    const char *GREEN = "\033[32m";
    const char *YELLOW = "\033[33m";
    const char *BLUE = "\033[34m";
    const char *MAGENTA = "\033[35m";
    const char *CYAN = "\033[36m";
    const char *WHITE = "\033[37m";
    const char *BG_BLACK = "\033[40m";
    const char *BG_RED = "\033[41m";
    const char *BG_GREEN = "\033[42m";
    const char *BG_YELLOW = "\033[43m";
    const char *BG_BLUE = "\033[44m";
    const char *BG_MAGENTA = "\033[45m";
    const char *BG_CYAN = "\033[46m";
    const char *BG_WHITE = "\033[47m";

  public:
    void SetConsoleColor(unsigned short color)
    {

      if ((color & console_default))
      {
        printf("%s", RESET);
        return;
      }
      else if ((color & fg_blue))
      {
        printf("%s", BLUE);
      }
      else if ((color & fg_green))
      {
        printf("%s", GREEN);
      }
      else if ((color & fg_red))
      {
        printf("%s", RED);
      }

      if ((color & bg_blue))
      {
        printf("%s", BG_BLUE);
      }
      else if ((color & bg_green))
      {
        printf("%s", BG_GREEN);
      }
      else if ((color & bg_red))
      {
        printf("%s", BG_GREEN);
      }
    }
    void reset()
    {
      printf("%s", RESET);
    }
  };
#endif
}

static colorconsole::ConsoleColorManager consoleColorManager;

void GameConsole::setConsoleColor(unsigned int newColor)
{
  consoleColorManager.SetConsoleColor(newColor);
}

void GameConsole::resetConsoleColor()
{
  consoleColorManager.reset();
}

void GameConsole::clearScreen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
