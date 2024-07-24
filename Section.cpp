#include<iostream>
using namespace std;
#include "Section.h"
#include "Product.h"
#include "Item.h"
#include "Stack.h"

Section::Section()
{
	items = 0;
	name = " ";
	product = NULL;

}
Section::Section(string name)
{
	this->items = 0;
	this->name = name;
	product = NULL;

}
Section::Section(int items, string name)
{
	this->items = items;
	this->name = name;
	product = NULL;

}
//this function is for setting product's data after reading from file(updated data)
void Section::SetProductsStock(Item* item, int items, string name)
{
	this->items = items;
	this->name = name;
	for (int i = 0; i < items; i++)
	{
		product = product->add_to_stock(item[i]);
	}
}
void Section::setProduct(Item item1)
{
	if (product)
		product = product->add_to_stock(item1);
	else
		product = new Product(item1);
	items++;
}
void Section::DisplayStock()
{
	product->extract_stock();
}
void Section::extractItems(Item* item)
{
	int i = 0;
	product->fillItemList(item, i);
}
void Section::update(string id, int q) {
	product->searching(id, q);

}
Item Section::search(string id) {
	return product->search(id);
}
void Section::GetMatch1(Stack& l, Stack& undo, char* ch)
{
	product->GetMatch1(l, undo, ch);
}
void Section::GetMatch2(Stack& l, Stack& undo, char* ch)
{
	product->GetMatch2(l, undo, ch);
}
