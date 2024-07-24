#include<iostream>
using namespace std;
#include "Stack.h"

//StackItem Class' member functions
StackItem::StackItem()
{
	next = NULL;
}
StackItem::StackItem(string item_name, string item_id)
{
	this->name = item_name;
	this->id = item_id;
	this->next = NULL;
}

//Stack Class' member functions

Stack::Stack()
{
	top = NULL;
}
void Stack::push(string name, string id)
{
	StackItem* insert = new StackItem(name, id);
	if (!top)
	{
		top = insert;
	}
	else
	{
		insert->next = top;
		top = insert;
	}
}
string Stack::peek_name()
{
	if (isEmpty())
		return "";
	return top->name;
}
string Stack::peek_id()
{
	if (isEmpty())
		return "";
	return top->id;
}
string Stack::pop()
{
	string ret_name = top->name;
	top = top->next;
	return ret_name;
}
bool Stack::isEmpty()
{
	if (!top)
		return 1;
	return 0;
}
bool Stack::isFull()
{
	if (new StackItem())
		return 0;
	return 1;
}
void Stack::ShowList()
{
	if (top == NULL)
	{
		cout << "No Such Item Present in Our Store Sorry for Inconvenience!" << endl;
		return;
	}
	StackItem* iter = top;
	while (iter)
	{
		cout << iter->name << " (" << iter->id << ")" << endl;
		iter = iter->next;
	}
	cout << endl;
}
void Stack::clean()
{
	delete top;
	top = NULL;
}
bool Stack::isAvailable(string n)
{
	StackItem* iter = top;
	while (iter)
	{
		if (iter->name == n)
			return true;
		iter = iter->next;
	}
	return false;
}