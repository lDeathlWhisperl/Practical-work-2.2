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
	//erase();
}

int List::getSize()
{
	return size;
}

node* List::getElem(int index)
{
	index++;
	error(index, size);

	node* temp = head;
	int i = 1;

	while (i < index && temp)
	{
		temp = temp->next;
		i++;
	}

	if (!temp) return 0;
	else return temp;
}

void List::del(int index)
{
	index++;
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

void List::insert(int index)
{
	index++;
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
	index_1++, index_2++;
	error(index_1, size);
	error(index_2, size);
	index_1--, index_2--;

	node* first = getElem(index_1);
	node* second = getElem(index_2);

	node
		* f_prev = first->prev,
		* f_next = first->next,
		* s_prev = second->prev,
		* s_next = second->next;

	if(abs(index_1 - index_2) == 1)
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
		if (first != head) f_prev->next = second;
		if (second != head) s_prev->next = first;

		second->next = f_next;
		first->next  = s_next;

		second->prev = f_prev;
		first->prev  = s_prev;

		if (s_next != NULL) s_next->prev = first;
		if (f_next != NULL) f_next->prev = second;
	}

	//std::cout << *reinterpret_cast<int*>((((first->prev)->prev)->prev)->prev) << ' ' << *reinterpret_cast<int*>(((first->prev)->prev)->prev) << ' ' << *reinterpret_cast<int*>((first->prev)->prev) << ' ' << *reinterpret_cast<int*>(first->prev) << ' ' << *reinterpret_cast<int*>(first) << '\n';// << ' ' << *reinterpret_cast<int*>(first->next);

}
/*
node* List::swap(int index_1, int index_2)
{
	// ¬озвращает новый корень списка
	node*lst1 = getElem(index_1), 
		*lst2 = getElem(index_2);

	node* prev1, * prev2, * next1, * next2;
	prev1 = lst1->prev;  // узел предшествующий lst1
	prev2 = lst2->prev;  // узел предшествующий lst2
	next1 = lst1->next; // узел следующий за lst1
	next2 = lst2->next; // узел следующий за lst2
	if (lst2 == next1)  // обмениваютс€ соседние узлы
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		if (next2 != NULL)
			next2->prev = lst1;
		if (lst1 != head)
			prev1->next = lst2;
	}
	else if (lst1 == next2)  // обмениваютс€ соседние узлы
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		if (next1 != NULL)
			next1->prev = lst2;
		if (lst2 != head)
			prev2->next = lst1;
	}
	else  // обмениваютс€ отсто€щие узлы
	{
		if (lst1 != head)  // указатель prev можно установить только дл€ элемента,
			prev1->next = lst2; // не €вл€ющегос€ корневым
		lst2->next = next1;
		if (lst2 != head)
			prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		if (next2 != NULL) // указатель next можно установить только дл€ элемента,
			next2->prev = lst1; // не €вл€ющегос€ последним
		lst1->prev = prev2;
		if (next1 != NULL)
			next1->prev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}*/
/*
*     1  2  3
* [4, 2, 0, 1, 3]
* 
* 
*		if (first != head)   
			f_prev->next = second;  

		second->next = f_next;

		if (second != head)
			s_prev->next = first;

		first->next = s_next;
		second->prev = f_prev;

		if (s_next != NULL)  
			s_next->prev = first;  

		first->prev = s_prev;

		if (f_next != NULL)
			f_next->prev = second;
*/