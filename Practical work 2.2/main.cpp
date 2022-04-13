#include "Functions.h"
#include "List.h"
#include <iostream>

int main()
{
	//fullscreen();
	//mainMenu();

    List L;

    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

    // Добавляем элементы, стоящие на четных индексах, в голову,
    // на нечетных - в хвост
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            L.addHead(a[i]);
        else
            L.addTail(a[i]);

    // Распечатка списка
    std::cout << "List L:\n";
    L.print();

    std::cout << std::endl;

}