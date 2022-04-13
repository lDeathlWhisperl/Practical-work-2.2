#include "List.h"
#include <iostream>

void error(int index, int size)
{
	while (index < 1 || index > size)
	{
		std::cout << "Incorrect index, try again: ";
		std::cin >> index;
	}
}

List::List()
{
	head = tail = NULL;
	size = 0;
}

List::~List()
{
	erase();
}

int List::getSize()
{
	return size;
}

node* List::getElem(int index)
{
	node* temp = head;

	error(index, size);

	int i = 1;

	while (i < index && temp)
	{
		temp = temp->next;
		i++;
	}

	if (!temp) return 0;
	else return temp;
}

void List::delElem(int index)
{
	error(index, size);

	int i = 1;

	node* del = head;

	while (i < index)
	{
		del = del->next;
		i++;
	}

	node* PrevDel = del->prev;
	node* AfterDel = del->next;

	if (PrevDel != 0 && size != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && size != 1)
		AfterDel->prev = PrevDel;

	if (index == 1)
		head = AfterDel;
	if (index == size)
		tail = PrevDel;

	delete del;
	size--;
}

void List::erase()
{
	while (size != 0) delElem(1);
}

void List::addTail(int num)
{
	node* temp = new node;
	temp->next = 0;
	temp->data = num;
	temp->prev = tail;

	if (tail != 0)
		tail->next = temp;

	if (size == 0)
		head = tail = temp;
	else
		tail = temp;
	size++;
}

void List::addHead(int num)
{
	node* temp = new node;

	temp->prev = 0;
	temp->data = num;
	temp->next = head;

	if (head != 0)
		head->prev = temp;

	if (size == 0)
		head = tail = temp;
	else
		head = temp;
	size++;
}

void List::insert(int index)
{
	error(index, size + 1);

	if (index == size + 1)
	{
		int data;
		std::cout << "Input new number: ";
		std::cin >> data;

		addTail(data);
		return;
	}
	else if (index == 1)
	{
		int data;
		std::cout << "Input new number: ";
		std::cin >> data;

		addHead(data);
		return;
	}

	node* insert = head;

	for (int i = 0; i < index; i++)
		insert = insert->next;

	node* prevIns = insert->prev;

	node* temp = new node;

	std::cout << "Input new number: ";
	std::cin >> temp->data;

	if (prevIns != 0 && size != 1)
		prevIns->next = temp;

	temp->next = insert;
	temp->prev = prevIns;
	insert->prev = temp;

	size++;
}

void List::print()
{
	if (size)
	{
		node* temp = head;
		std::cout << "[";
		while (temp->next != 0)
		{
			std::cout << temp->data << ", ";
			temp = temp->next;
		}
		std::cout << temp->data << "]\n";
	}
}

void List::print(int index)
{
	index++;
	error(index, size);
	node* temp;

	if (index <= size / 2)
	{
		temp = head;
		int i = 1;

		for(int i = 1; i < index; i++)
			temp = temp->next;
	}
	else
	{
		temp = tail;
		int i = 1;

		for (int i = 1; i < size - index; i++)
			temp = temp->prev;
	}

	std::cout << index << " element: ";
	std::cout << temp->data << '\n';
}

void List::swap(int index_1, int index_2)
{

}