#pragma once
#ifndef STACK_H
#define STACK_H

class StackItem {
public:
	string name, id;
	StackItem* next;
	StackItem();
	StackItem(string item_name, string item_id);
};

class Stack {
	StackItem* top;
public:
	Stack();
	void push(string name, string id);
	string peek_name();
	string peek_id();
	string pop();
	bool isEmpty();
	bool isFull();
	void ShowList();
	void clean();
	bool isAvailable(string n);
};
#endif // !STACK_H
