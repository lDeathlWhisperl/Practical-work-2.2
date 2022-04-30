#pragma once
#include <iostream>

struct node 
{
	int data;
	node* next;
	node* prev;
};

class List
{
private:
	node* head, * tail;
	int size;
public:
	List(); 

	~List();

	int getSize();

	node* getElem(int);

	void erase();

	void del(int);

	void insert(int, int);

	void addTail(int);

	void addHead(int);

	void print();

	void print(int);

	void swap(int, int);
};