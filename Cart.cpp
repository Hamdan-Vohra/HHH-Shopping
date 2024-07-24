#include<iostream>
using namespace std;
#include "Cart.h"
#include "Item.h"
#define maxcart 4

//due to real time experience we implement stack on on our cart class
//also we have a weight variable in cart class that is max_weight


Cart_Item::Cart_Item() {
	nxt_item = NULL;
}
Cart_Item::Cart_Item(Item it) {
	this->id = it;
	nxt_item = NULL;
}

Cart::Cart() {
	weight = 0;
	top = NULL;
}
bool Cart::isFull(float w8)
{
	if (weight + w8 > maxcart)
		return true;
	return false;
}

bool Cart::isEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

void Cart::add_to_cart(Item* t1)
{
	if (isFull(t1->weight)) {
		cout << "Your shopping cart is full" << endl;
		return;
	}
	else {
		if (t1->quantity == 0) {
			cout << "Product is out of stock" << endl;
			return;
		}
		else {
			weight = weight + t1->weight;
			Cart_Item* temp = new Cart_Item(t1);
			if (top == NULL) {
				top = temp;
			}
			else {
				temp->nxt_item = top;
				top = temp;
			}
		}

	}
	show();
}
int Cart::pop() {
	if (isEmpty()) {
		cout << "your cart is empty" << endl;
		return NULL;
	}
	else {
		Cart_Item* temp = top;
		top = top->nxt_item;
		int value = temp->id.price;
		//delete [] temp;
		temp = NULL;
		return value;
	}
}
Item Cart::front() {
	return top->id;
}
void Cart::show() {
	cout << endl << "Your stack contain: " << endl;
	Cart_Item* temp = top;
	while (temp != NULL) {
		temp->id << cout;
		cout << endl;
		temp = temp->nxt_item;
	}
}
