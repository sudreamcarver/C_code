#pragma once
#include "Input.hpp"
#include <algorithm>
#include <asm-generic/ioctls.h>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

inline auto
GetWinSZ ()
{
    struct winsize w;

    if (ioctl (STDOUT_FILENO, TIOCGWINSZ, &w) == -1)
        {
            perror ("ioctl failed");
        }
    return w;
}

namespace Color
{
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";
}

class UIManager
{

  private:
    struct winsize w = GetWinSZ ();
    const int WIDTH = static_cast<int> (w.ws_col);
    const int HEIGHT = static_cast<int> (w.ws_row);
    const int LogHeight{};
    std::vector<std::string> combatLogs{};

    void
    ClearSreen () const
    {
        std::cout << "\033[2J\033[H";
    }

    void
    MoveCursor (int row, int col) const
    {
        printf ("\033[%d;%dH", row, col);
    }

    void
    DrawLargestBox () const
    {
        ClearSreen ();

        MoveCursor (1, 1);
        // line one
        std::cout << "+" << std::string (static_cast<size_t> (WIDTH - 2), '-')
                  << "+";

        for (int i = 2; i <= HEIGHT; i++)
            {
                MoveCursor (i, 1);
                std::cout << "|";
                MoveCursor (i, WIDTH);
                std::cout << "|";
            }

        this->MoveCursor (HEIGHT, 1);
        std::cout << "+" << std::string (static_cast<size_t> (WIDTH - 2), '-')
                  << "+";
        std::cout.flush ();
    }

    void
    DrawInstrucktor () const
    {
        MoveCursor (HEIGHT - 2, 2);
        std::cout << std::string (static_cast<size_t> (WIDTH - 2), '-');
        MoveCursor (HEIGHT - 1, 2);
        DrawCenteredText ("[A] Attack    [Q] Back/quit    [B]Bag",
                          Color::RESET);
    }

    void
    DrawCenteredText (const std::string &text, std::string color) const
    {
        int textLen = static_cast<int> (text.length ());
        int padding = WIDTH - 2 - textLen;
        int leftPad = padding / 2;
        int rightPad = padding - leftPad;

        MoveCursor (2, 2);

        std::cout << "|"
                  << std::string (static_cast<size_t> (leftPad - 1), ' ')
                  << color << text << Color::RESET
                  << std::string (static_cast<size_t> (rightPad - 1), ' ')
                  << "|" << std::endl;
    }

    std::string
    GetHPBar (float current, float max, float length = 20) const
    {
        float percent = current / max;
        int filled = static_cast<int> (percent * length);
        filled = std::max (0, std::min (filled, static_cast<int> (length)));

        std::string bar = "[";
        std::string color
            = (percent > 0.5) ? Color::GREEN
                              : ((percent > 0.2) ? Color::YELLOW : Color::RED);

        bar += color;
        bar += std::string (static_cast<size_t> (filled), '#');
        bar += std::string (
            static_cast<size_t> (static_cast<int> (length) - filled), '.');
        bar += Color::RESET;
        bar += "]";

        return bar;
    }

  public:
    UIManager ()
    {
        combatLogs.reserve (static_cast<size_t> (LogHeight));
        if (combatLogs.size () > static_cast<size_t> (LogHeight))
            {
                combatLogs.erase (combatLogs.begin ());
            }

        setupConsole ();

        DrawLargestBox ();
        DrawInstrucktor ();
    }
};
