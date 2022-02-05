#pragma once

#ifdef _WIN32
#include <conio.h>
#else

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#endif

#include <iostream>
#include <string>
#include <cctype>

namespace kb_utils
{

#ifndef _WIN32

  namespace detail
  {
    static struct termios oldt, newt;
    struct termios_changer
    {
      explicit termios_changer()
      {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      }
      ~termios_changer()
      {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      }
    };
  }

  static struct termios orig_termios;
  static void disableRawMode()
  {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
  }

  static void enableRawMode()
  {
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
  }

// it is changing terminal setting if kbhit is used at least once
// and repairing terminal settings at the exit of application
#define TERMINAL_GUARD static detail::termios_changer term_guard__
  static int kbhit__(void)
  {
    TERMINAL_GUARD;
    struct timeval tv;
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
  }
#endif

  static auto readKey__(bool echo = false)
  {
    int readChar;
#ifndef _WIN32
    readChar = getchar();
#else
    readChar = getch();
#endif
    if (echo)
    {
      putchar(readChar);
    }
    return readChar;
  }

  static auto readString__(bool echo = false)
  {
    std::string str;
    int readChar = readKey__(echo);
    while (readChar != '\n')
    {
      str += (char)readChar;
      readChar = readKey__(echo);
    }
    return str;
  }

}

class key
{
  int readChar;

public:
  key(int readChar_)
      : readChar(readChar_) {}

  bool isControlKey() const
  {
    return iscntrl(readChar);
  }
};
