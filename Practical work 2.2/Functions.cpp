#include "Functions.h"
#include <windows.h>
#include <iostream>

enum colors
{
    BLACK = 0,
    BLUE  = 1,
    GREEN = 2,
    RED   = 4,
    WHITE = 15
};

enum buttons
{
    ENTER       = 13,
    ESC         = 27,
    SPACE       = 32,
    ARROW_UP    = 72, // ↑ (24)
    ARROW_LEFT  = 75, // ← (27)
    ARROW_RIGHT = 77, // → (26)
    ARROW_DOWN  = 80  // ↓ (25)
};

void fullscreen()
{
    ShowWindow(GetForegroundWindow(), SW_SHOWMAXIMIZED);
}
void setColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void drawMenu(int id)
{
    char menu[][60] = {
        "[                          Exit                         ]",
        "[                  Enter count of items                 ]",
        "[                Enter the items yourself               ]",
        "[ Inserting, deleting, exchanging and receiving an item ]"};

    for (int i = 0; i < 4; i++)
    {
        if (i == id && id == 0) setColor(BLACK, RED);

    }
}

void mainMenu()
{
    bool isEnable = true;
    int id = 0;

    while (isEnable)
    {
        switch (id)
        {

        }
    }
}