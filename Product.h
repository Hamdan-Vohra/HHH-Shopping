#pragma once
//Product as a node class for AVL Tree
class Product {
public:
	Item item;
	Product* left;
	Product* right;

	Product(Item item1);
	int getHeight();
	//PART (e)
	int getSize();
	int getBalanceFactor();
	Product* rotateleft();
	Product* rotateright();
	Product* add_to_stock(Item item1);
	void extract_stock();
	Product* findpre();
	Product* Remove_from_stock(Item item1);
	void fillItemList(Item* item1, int& index);
	Item search(string id);
	void searching(string id, int q);
	void GetMatch1(Stack& l, Stack& undo, char* ch);
	void GetMatch2(Stack& l, Stack& undo, char* ch);
};