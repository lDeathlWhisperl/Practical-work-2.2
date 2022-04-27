#include "List.h"
#include <iostream>

List::List()
{
	head = tail = NULL;
	size = 0;
}

int List::getSize()
{
	return size;
}

node* List::getElem(int index)
{
	node* temp = head;

	for(int i = 0; i < index; i++)
		temp = temp->next;

	if (!temp) return 0;
	else return temp;
}

void List::del(int index)
{
	node* del = getElem(index);

	node* PrevDel = del->prev;
	node* AfterDel = del->next;

	if (PrevDel != 0 && size != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && size != 1)
		AfterDel->prev = PrevDel;

	if (index == 0)
		head = AfterDel;
	if (index == size-1)
		tail = PrevDel;

	delete del;
	size--;
}

void List::erase()
{
	while (size != 0) del(0);
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

void List::insert(int index, int data)
{
	if (index == size)
	{
		addTail(data);
		return;
	}
	else if (index == 0)
	{
		addHead(data);
		return;
	}

	node* insert = getElem(index);

	node* prevIns = insert->prev;

	node* temp = new node;

	temp->data = data;

	if (prevIns != 0 && size != 1)
		prevIns->next = temp;

	temp->next = insert;
	temp->prev = prevIns;
	insert->prev = temp;

	size++;
}

void List::print()
{
	node* p = tail;
	while (p->prev != NULL)
		p = p->prev;
	do {
		std::cout << p->data << ' ';
		p = p->next;
	} while (p != NULL);
}

void List::print(int index)
{
	index++;
	node* temp;

	if (index <= size / 2)
	{
		temp = head;
		int i = 1;

		for (int i = 1; i < index; i++)
			temp = temp->next;
	}
	else
	{
		temp = tail;
		int i = 1;

		for (int i = 1; i < size - index; i++)
			temp = temp->prev;
	}

	std::cout << '[' << index - 1 << "] element: ";
	std::cout << temp->data << '\n';
}

void List::swap(int index_1, int index_2)
{
	node* first = getElem(index_1);
	node* second = getElem(index_2);

	node
		* f_prev = first->prev,
		* f_next = first->next,
		* s_prev = second->prev,
		* s_next = second->next;

	if (abs(index_1 - index_2) == 1)
	{
		second->prev = f_prev;
		second->next = first;

		first->prev = second;
		first->next = s_next;

		if (s_next != NULL) s_next->prev = first;
		if (first != head) f_prev->next = second;
	}
	else
	{
		if (first != head)  f_prev->next = second;
		if (second != head) s_prev->next = first;
		
		second->next = f_next;
		first->next = s_next;

		second->prev = f_prev;
		first->prev = s_prev;

		if (s_next != NULL) s_next->prev = first;
		if (f_next != NULL) f_next->prev = second;
	}

	while (head->prev) head = head->prev;
	while (tail->next) tail = tail->next;
}