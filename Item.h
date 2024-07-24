#pragma once
class Item {
public:
	int quantity;
	string name;
	string id;
	double weight;
	double price;
	int discount;
public:
	Item();
	Item(int no, string id, string name, double weight, double price);
	Item(const Item* temp);
	void updte_stock(int q);
	bool operator>(Item item);
	bool operator<(Item item);
	bool operator==(Item item);
	void operator<<(ostream& out);
};