#include<iostream>
using namespace std;
#include "Queue.h"
#include "Consumer.h"

//Node Class; member functions
Node::Node()
{
	next = NULL;
}
Node::Node(Consumer val)
{
	this->value = val;
	this->next = NULL;
}

//LLQueue Class' member functions
LLQueue::LLQueue()
{
	front = rear = NULL;
}
bool LLQueue::isEmpty()
{
	if (front)
		return false;
	return true;
}
bool LLQueue::isFull()
{
	Node* check = new Node();
	if (check)
		return false;
	delete check;
	check = NULL;
	return true;
}
void LLQueue::Enqueue(Consumer val)
{
	if (isFull())
		cout << "Queue is Full" << endl;
	else
	{
		if (front == NULL)
			rear = front = new Node(val);
		else
		{
			Node* ins = new Node(val);
			rear->next = ins;
			rear = ins;
		}
	}
}
Consumer LLQueue::Dequeue()
{
	if (!isEmpty())
	{
		Node* delte = front;
		Consumer del = front->value;
		front = front->next;
		delete delte;
		return del;
	}
	else
		cout << "Queue is Empty" << endl;
}

