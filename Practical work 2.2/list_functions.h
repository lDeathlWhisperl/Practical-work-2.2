#pragma once
#include <iostream>

struct doubleLinkedList
{
    int data{};
	doubleLinkedList* head = 0;
	doubleLinkedList* tail = 0;
};

doubleLinkedList* createList(unsigned Length);

doubleLinkedList* getItem(doubleLinkedList* beg, unsigned index, bool errMsg = true);

unsigned size(doubleLinkedList* beg);

void erase(doubleLinkedList*& Beg, unsigned Index);

void fillList(doubleLinkedList* List);

void displayList(doubleLinkedList* List);

void Delete(doubleLinkedList*& Beg);

doubleLinkedList* insert(doubleLinkedList*& Beg, unsigned Index);

doubleLinkedList* swap(doubleLinkedList*, doubleLinkedList*, doubleLinkedList*);