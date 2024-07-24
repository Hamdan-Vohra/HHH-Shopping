#pragma once
//section as an AVL TREE for LOG(N) search for product
class Section {
public:
	int items;
	string name;
	Product* product;

	Section();
	Section(string name);
	Section(int items, string name);
	//this function is for setting product's data after reading from file(updated data)
	void SetProductsStock(Item* item, int items, string name);
	void setProduct(Item item1);
	void DisplayStock();
	void extractItems(Item* item);
	void update(string id, int q);
	Item search(string id);
	void GetMatch1(Stack& l, Stack& undo, char* ch);
	void GetMatch2(Stack& l, Stack& undo, char* ch);
};