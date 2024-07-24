#pragma once
#include "Store.h"
#include "Item.h"
#include "Cart.h"
#include "Consumer.h"
#include "Section.h"
#include "Queue.h"
#include "Stack.h"
class Store {
public:
	int sectionno;
	//section as a starting vertex of graph(source)
	Section* section;

	Store();
	Store(int sectionno);
	Item search(string id, int index);
	//these functions are for initial set stock data very first
	Item* GetGroccery();
	Item* GetSports();
	Item* GetGarment();
	Item* GetCosmetics();
	Item* GetFruits();
	Item* GetFrozen();
	void setDefaultStock();

	void bill_counter(Cart* c11, Consumer* cc1);
	void Open();
	void Shopping(Consumer& cc1);
	void DisplaySectionProducts(int i);
	void update_stock(int i, int q, string id);
	void ShowSectionList();
	void Close(Consumer c1);

	void PatternMatchBackSpace(Stack& undo, Stack& l1, Stack& l2);
	//function extracting items from sections to any of the lists
	//or from one list to another list also to undo stack(if not match)
	void PatternMatchingCharacter(Stack& undo, Stack& l1, Stack& l2, char* ch);
	void PatternMatchingNewCharacter(Stack& undo, Stack& l, char* ch);

	void SEO();
};
