#include<iostream>
using namespace std;
#include "Item.h"

	Item::Item()
	{
		quantity = 0;
		name = id = " ";
		weight = price = 0;
		discount = 0;
	}
	Item::Item(int no, string id, string name, double weight, double price)
	{
		this->quantity = no;
		this->name = name;
		this->id = id;
		this->weight = weight;
		this->price = price;
		this->discount = 0;
	}
	Item::Item(const Item* temp) {
		this->discount = temp->discount;
		this->id = temp->id;
		this->weight = temp->weight;
		this->price = temp->price;
		this->name = temp->name;
		this->quantity = temp->quantity;
	}
	void Item::updte_stock(int q) {
		this->quantity += q;
	}
	bool Item::operator>(Item item)
	{
		if (this->id > item.id)
			return true;
		return false;
	}
	bool Item::operator<(Item item)
	{
		if (this->id < item.id)
			return true;
		return false;
	}
	bool Item::operator==(Item item)
	{
		if (this->id == item.id)
			return true;
		return false;
	}
	void Item::operator<<(ostream& out)
	{
		out << "\t=============================" << endl;
		out << "\tItem_Id : " << this->id << endl;
		out << "\tItem_Name : " << this->name << endl;
		out << "\tQuantity : " << this->quantity << endl;
		out << "\tPrice per Quantity : " << this->price << endl;
		out << "\tWeight per Quantity : " << this->weight << endl;
		out << "\tDiscount : " << this->discount << "%" << endl;
		out << "\t=============================" << endl;
	}
