#include "Functions.h"
#include "List.h"
#include <iostream>

int main()
{
	//fullscreen();
	//mainMenu();
    
    List L;

    const int n = 5;
    int a[n] = { 0,1,2,3,4 };

    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            L.addHead(a[i]);
        else
            L.addTail(a[i]);

    std::cout << "\n";
    L.print();
    std::cout << "\n";
    L.swap(0, 4); //std::cout << "   ";
    L.print();// std::cout << L.getSize();
    return 0;
}