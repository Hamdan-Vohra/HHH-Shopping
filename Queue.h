#pragma once
class Node {
public:
	Consumer value;
	Node* next;
	Node();
	Node(Consumer val);
};
class LLQueue {
public:
	Node* front, * rear;
	LLQueue();
	bool isEmpty();
	bool isFull();
	void Enqueue(Consumer val);
	Consumer Dequeue();
};
