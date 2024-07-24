#pragma once

//due to real time experience we implement stack on on our cart class
//also we have a weight variable in cart class that is max_weight
class Cart_Item {
public:
	Item id;
	Cart_Item* nxt_item;

	Cart_Item();
	Cart_Item(Item it);
};

class Cart {
	float weight;
	Cart_Item* top;
public:
	Cart();
	bool isFull(float w8);
	bool isEmpty();
	void add_to_cart(Item* t1);
	int pop();
	Item front();
	void show();
};