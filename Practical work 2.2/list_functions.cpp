#include "list_functions.h"
#include <iostream>

doubleLinkedList* createList(unsigned Length)
{
    doubleLinkedList
        *Curr = 0,
        *Next = 0;
    
    for (unsigned i = 1; i <= Length; ++i)
    {
        Curr = new doubleLinkedList;

        Curr->tail = Next;

        if (Next) Next->head = Curr;

        Next = Curr;
    }

    Curr->head = 0;

    return Curr;
}

doubleLinkedList* getItem(doubleLinkedList* beg, unsigned index, bool errMsg)
{
	while (beg && (index--))
		beg = beg->tail;
	
	//if (errMsg && !beg) std::cout << "Ёлемент списка отсутствует \n";

	return beg;
}

unsigned size(doubleLinkedList* beg)
{
	unsigned length = 0;

	while (beg)
	{
		length++;
		beg = beg->tail;
	}
	return length;
}

void erase(doubleLinkedList*& Beg, unsigned Index)
{
	if (Index >= size(Beg))
		return;

	doubleLinkedList* Item;

	if (!Index)
	{
		Item = Beg->tail;
		delete Beg;
		Beg = Item;
		Beg->head = 0;
		return;
	}

	Item = getItem(Beg, Index - 1, 0);
	doubleLinkedList* DItem = Item->tail;
	if (DItem->tail)
	{
		Item->tail = DItem->tail;
		Item->tail->head = Item;
	}
	else
		Item->tail = 0;
	delete DItem;
}

void fillList(doubleLinkedList* List)
{
	doubleLinkedList* Curr = List;

	while (Curr)
	{
		std::cin >> Curr->data;
		Curr = Curr->tail;
	}
}

void displayList(doubleLinkedList* List)
{
	doubleLinkedList *Curr = List;
	while (Curr)
	{
		std::cout << Curr->data << " ";
		Curr = Curr->tail;
	}
	std::cout << '\n';
}

void Delete(doubleLinkedList*& Beg)
{
	doubleLinkedList* Next;  

	while (Beg)
	{
		Next = Beg->tail;
		delete Beg;
		Beg = Next;
	}
}

doubleLinkedList* insert(doubleLinkedList*& Beg, unsigned Index)
{
	doubleLinkedList* Item = new doubleLinkedList;
	if (!Index || !Beg)
	{
		Beg->head = Item;
		Item->head = 0;
		Item->tail = Beg;
		Beg = Item;
		return Item;
	}
	doubleLinkedList* PredItem = Beg;
	--Index;
	while (PredItem->tail && (Index--))
		PredItem = PredItem->tail;
	Item->head = PredItem;
	Item->tail->head = Item;
	Item->tail = PredItem->tail;
	PredItem->tail = Item;
	return Item;
}

doubleLinkedList* swap(doubleLinkedList* lst1, doubleLinkedList* lst2, doubleLinkedList* head)
{
	// ¬озвращает новый корень списка
	doubleLinkedList* prev1, * prev2, * next1, * next2;

	prev1 = lst1->head;  // узел предшествующий lst1
	prev2 = lst2->head;  // узел предшествующий lst2
	next1 = lst1->tail; // узел следующий за lst1
	next2 = lst2->tail; // узел следующий за lst2

	if (lst2 == next1)  // обмениваютс€ соседние узлы
	{
		lst2->tail = lst1;
		lst2->head = prev1;
		lst1->tail = next2;
		lst1->head = lst2;

		if (next2 != NULL) next2->head = lst1;
		if (lst1 != head) prev1->tail = lst2;
	}
	else if (lst1 == next2)  // обмениваютс€ соседние узлы
	{
		lst1->tail = lst2;
		lst1->head = prev2;
		lst2->tail = next1;
		lst2->head = lst1;

		if (next1 != NULL) next1->head = lst2;
		if (lst2 != head) prev2->tail = lst1;
	}
	else  // обмениваютс€ отсто€щие узлы
	{
		if (lst1 != head)  // указатель prev можно установить только дл€ элемента,
			prev1->tail = lst2; // не €вл€ющегос€ корневым
		lst2->tail = next1;
		if (lst2 != head)
			prev2->tail = lst1;
		lst1->tail = next2;
		lst2->head = prev1;

		if (next2 != NULL) next2->head = lst1; // указатель next можно установить только дл€ элемента, не €вл€ющегос€ последним
		lst1->head = prev2;
		if (next1 != NULL) next1->head = lst2;
	}

	if (lst1 == head) return(lst2);
	if (lst2 == head) return(lst1);
	return(head);
}