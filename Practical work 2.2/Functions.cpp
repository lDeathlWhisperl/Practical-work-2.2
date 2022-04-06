#include "Functions.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

#define PRINT(Expression)\
     std::cout << "{" #Expression "}: " << (Expression) <<\
     		std::endl;

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
    system("cls");

    char menu[][60] = {
        "[                          Exit                         ]",
        "[                  Enter count of items                 ]",
        "[                Enter the items yourself               ]",
        "[ Inserting, deleting, exchanging and receiving an item ]"};

    for (int i = 0; i < 4; i++)
    {
        if (i == id) std::cout << "   ";
        if (i == id && id != 0) setColor(BLACK, GREEN);
        else if (i == id && id == 0) setColor(BLACK, RED);

        std::cout << menu[i] << '\n';
        setColor(WHITE, BLACK);
    }
}

void setListSize()
{

}

void mainMenu()
{
    bool isEnable = true;
    int id = 0;

    while (isEnable)
    {
        drawMenu(id);
        switch (_getch())
        {
        case 'w':
            if (id != 0) id--;
            else id = 3;
            break;
        case 's':
            if (id != 3) id++;
            else id = 0;
            break;
        case SPACE:
            if (id == 0) isEnable = false;
            //else if (id = 1)
            //else if (id = 2)
            //else if (id = 3)
            break;
        }
    }
}