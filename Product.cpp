//Product as a node class for AVL Tree
#include<iostream>
using namespace std;
#include "Product.h"
#include "Item.h"
#include "Stack.h"
#include "HelpingFunctions.cpp"

Product::Product(Item item1)
{
	this->item = item1;
	left = right = NULL;
}
int Product::getHeight()
{
	if (!this)
		return 0;
	int left = this->left->getHeight();
	int right = this->right->getHeight();
	if (left > right)
		return left + 1;
	else
		return right + 1;
}
//PART (e)
int Product::getSize()
{
	if (!this)
		return 0;
	return this->left->getSize() + this->right->getSize() + 1;
}
int Product::getBalanceFactor()
{
	if (!this)
	{
		if (!this->left && !this->right)
			return 0;

		return this->left->getHeight() - this->right->getHeight();
	}
	return 0;
}
Product* Product::rotateleft()
{
	Product* newnode = this->right;
	Product* left = newnode->left;
	newnode->left = this;
	this->right = left;
	return newnode;
}
Product* Product::rotateright()
{
	Product* newnode = this->left;
	Product* right = newnode->right;
	newnode->right = this;
	this->left = right;
	return newnode;
}
//insertion function
Product* Product::add_to_stock(Item item1)
{
	if (!this)
		return new Product(item1);
	if (this->item == item1)
	{
		return this;
	}
	else if (this->item > item1)
	{
		this->left = this->left->add_to_stock(item1);
	}
	else if (this->item < item1)
	{
		this->right = this->right->add_to_stock(item1);
	}
	int bf = getBalanceFactor();

	//rotations
	if (bf > 1 && item1 < this->left->item)
	{
		return this->rotateright();
	}
	if (bf < -1 && item1 > this->right->item)
	{
		return this->rotateleft();

	}
	if (bf > 1 && item1 > this->left->item)
	{
		this->left = this->left->rotateleft();
		return this->rotateright();
	}
	if (bf < -1 && item1 < this->right->item)
	{
		this->right = this->right->rotateright();
		return this->rotateleft();
	}

	return this;

}
//deletions functions
Product* Product::findpre()
{
	Product* temp = this;
	temp = temp->left;
	Product* prev = NULL;
	while (temp->right != NULL)
	{
		prev = temp;
		temp = temp->right;
	}
	if (prev)
		prev->right = NULL;
	return temp;
}
Product* Product::Remove_from_stock(Item item1)
{
	if (this)
	{
		if (this->item == item1)
		{
			//flag = 1;
			Product* ret = NULL;
			if (!this->right && !this->left)
			{
				delete this;
				return ret;
			}
			if (!this->right)
			{
				ret = this->left;
			}
			else if (!this->left)
			{
				ret = this->right;
			}
			else {
				ret = this->findpre();
				//link the right of deleted node to the right of predecessor node
				ret->right = this->right;

				//setting the left of deleted node to the most left of the predecessor node
				Product* iter = ret;
				if (iter != this->left)
				{
					while (iter->left != NULL)
					{
						iter = iter->left;
					}
					iter->left = this->left;
				}
			}
			delete this;
			return ret;
		}
		//recursive calls
		if (this->item > item1)
			this->left = this->left->Remove_from_stock(item1);
		else if (this->item < item1)
			this->right = this->right->Remove_from_stock(item1);
	}


	//rotations
	int left_bf = this->left->getBalanceFactor();
	int right_bf = this->right->getBalanceFactor();
	int bf = this->getBalanceFactor();
	if (bf > 1 && left_bf < 0) {
		this->left = this->left->rotateleft();
		return this->rotateright();
	}
	else if (bf < 1 && right_bf>0) {
		this->right = this->right->rotateright();
		return this->rotateleft();
	}
	else if (bf > 1) {
		return this->rotateright();
	}
	else if (bf < -1) {
		return this->rotateleft();
	}
	return this;
}
void Product::extract_stock()
{
	if (!this)
		return;
	this->left->extract_stock();
	this->item << cout;
	this->right->extract_stock();
}
void Product::fillItemList(Item* item1, int& index)
{
	if (this)
	{
		this->left->fillItemList(item1, index);
		item1[index++] = this->item;
		this->right->fillItemList(item1, index);
	}
	return;
}
Item Product::search(string id) {
	Item* temp = new Item();
	if (this) {
		if (this->item.id == id) {
			if (this->item.quantity <= 0) {
				return temp;
			}

			int quant = 0;
			Item* temp = new Item(this->item);
			cout << "Item Details : " << endl;
			this->item << cout;
			while (1)
			{
				cout << "Enter No of quantity You want : " << endl;
				cin >> quant;
				if (quant > this->item.quantity)
				{
					cout << "Enough Quantity !" << endl;
					continue;

				}
				this->item.quantity = this->item.quantity - quant;
				temp->quantity = quant;
				break;
			}
			return temp;
		}
		else if (this->item.id > id) {
			return this->left->search(id);
		}
		else
		{
			return this->right->search(id);
		}
	}
	return temp;
}
void Product::searching(string id, int q) {
	if (this) {
		if (this->item.id == id) {
			this->item.quantity += q;

		}
		else if (this->item.id > id) {
			this->left->searching(id, q);
		}
		else
		{
			this->right->searching(id, q);
		}
	}
}
void Product::GetMatch1(Stack& l, Stack& undo, char* ch)
{
	if (!this)
		return;
	if (HashMatch(this->item.name, ch))
	{
		l.push(this->item.name, this->item.id);
		undo.push(this->item.name, this->item.id);
	}
	this->left->GetMatch1(l, undo, ch);
	this->right->GetMatch1(l, undo, ch);
}
void Product::GetMatch2(Stack& l, Stack& undo, char* ch)
{
	if (!this)
		return;
	if (HashMatch(this->item.name, ch))
	{
		if (!l.isAvailable(this->item.name))
		{
			l.push(this->item.name, this->item.id);
			undo.push(this->item.name, this->item.id);
		}
	}
	this->left->GetMatch2(l, undo, ch);
	this->right->GetMatch2(l, undo, ch);
}