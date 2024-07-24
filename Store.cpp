#include<iostream>
#include <fstream>

using namespace std;
#define sections 6
#include "Store.h"
#include "Item.h"
#include "Cart.h"
#include "Consumer.h"
#include "Section.h"
#include "Queue.h"
#include "Stack.h"
#include "HelpingFunctions.cpp"

string filename[6] = { "grocery.txt", "garment.txt", "cosmetics.txt","sports.txt","fruits.txt" ,"frozen.txt", };

Store::Store()
{
	sectionno = 0;
	section = NULL;
}
Store::Store(int sectionno)
{
	this->sectionno = sectionno;
	section = new Section[sections];
}
Item Store::search(string id, int index) {
	return section[index].search(id);
}
//these functions are for initial set stock data very first
Item* Store::GetGroccery()
{
	Item* item = new Item[6];
	item[0] = Item(5, "G-0001", "potato", 1, 119.99);
	item[1] = Item(3, "G-0010", "carrot", 1, 99.99);
	item[2] = Item(5, "G-0200", "onions", 1, 149.99);
	item[3] = Item(15, "G-0003", "ponam rice", 1, 39.99);
	item[4] = Item(1, "G-0003", "ponia rice", 1, 39.99);
	item[5] = Item(5, "G-0003", "cabbage", 1, 39.99);
	return item;
}
Item* Store::GetSports()
{
	Item* item = new Item[6];
	item[0] = Item(5, "S-0001", "bat", 1, 1199.99);
	item[1] = Item(3, "S-0010", "ball", 1, 99.99);
	item[2] = Item(5, "S-0200", "football", 1, 1049.99);
	item[3] = Item(15, "S-0003", "basketball", 1, 1139.99);
	item[4] = Item(5, "S-0003", "tennis", 1, 1139.99);
	item[5] = Item(1, "S-0003", "badminton", 1, 1139.99);
	return item;

}
Item* Store::GetGarment()
{
	Item* item = new Item[6];
	item[0] = Item(5, "Ga-0001", "underwear", 1, 119.99);
	item[1] = Item(3, "Ga-0010", "gloves", 1, 99.99);
	item[2] = Item(5, "Ga-0200", "socks", 1, 149.99);
	item[3] = Item(15, "Ga-0003", "tshirt", 1, 39.99);
	item[4] = Item(15, "Ga-0030", "pants", 1, 39.99);
	item[5] = Item(15, "Ga-0020", "trousers", 1, 39.99);
	return item;

}
Item* Store::GetCosmetics()
{
	Item* item = new Item[6];
	item[0] = Item(5, "C-0001", "lipstick", 1, 119.99);
	item[1] = Item(3, "C-0010", "earring", 1, 99.99);
	item[2] = Item(5, "C-0200", "eyelashes", 1, 149.99);
	item[3] = Item(15, "C-0003", "necklace", 1, 39.99);
	item[4] = Item(15, "C-0004", "necklace", 1, 39.99);
	item[5] = Item(15, "C-0100", "necklace", 1, 39.99);

	return item;

}
Item* Store::GetFruits()
{
	Item* item = new Item[6];
	item[0] = Item(5, "F-0001", "strawberry", 1, 119.99);
	item[1] = Item(3, "F-0010", "banana", 1, 99.99);
	item[2] = Item(5, "F-0200", "apple", 1, 149.99);
	item[3] = Item(15, "F-0003", "orange", 1, 39.99);
	item[4] = Item(15, "F-0030", "apricot", 1, 39.99);
	item[5] = Item(15, "F-0020", "blueberry", 1, 39.99);
	return item;

}
Item* Store::GetFrozen()
{
	Item* item = new Item[6];
	item[0] = Item(5, "G-0001", "paratha", 1, 119.99);
	item[1] = Item(3, "G-0010", "chocolates", 1, 99.99);
	item[2] = Item(5, "G-0200", "spaghetti", 1, 149.99);
	item[3] = Item(15, "G-0003", "cheese", 1, 1299.99);
	item[4] = Item(15, "G-0030", "pizza", 1, 1299.99);
	item[5] = Item(15, "G-0020", "sandwich", 1, 1299.99);
	return item;

}
void Store::setDefaultStock()
{
	section = new Section[sections];
	this->sectionno = sections;
	Item* items = GetGroccery();
	section[0].SetProductsStock(items, 6, "Grocery");
	items = GetGarment();
	section[1].SetProductsStock(items, 6, "Garments");
	items = GetCosmetics();
	section[2].SetProductsStock(items, 6, "Cosmetics");
	items = GetSports();
	section[3].SetProductsStock(items, 6, "Sports");
	items = GetFruits();
	section[4].SetProductsStock(items, 6, "Fruits");
	items = GetFrozen();
	section[5].SetProductsStock(items, 6, "Frozen");

	ofstream f1;
	for (int i = 0; i < sections; i++)
	{
		f1.open("TextFiles/" + filename[i], ios::out | ios::binary);
		Item* t1 = new Item[section[i].items];
		section[i].extractItems(t1);
		for (int i = 0; i < section[i].items; i++)
		{
			f1.write((char*)&t1[i], sizeof(Item));
		}
		f1.close();
	}

}

void Store::bill_counter(Cart* c11, Consumer* cc1) {
	Cart ct;
	float total_price = 0;
	Item temp;
	cout << "============================" << endl;
	cout << "\t\t\t\tCustomer BILL" << endl;
	cout << "============================" << endl;
	cout << "Item ID \t Item Name \t Item Price \t Quantity \t TotalPrice" << endl;
	while (!c11->isEmpty()) {
		Item  ci = c11->front();

		cout << ci.id << "\t\t  " << ci.name << " \t\t" << ci.price << "\t\t  " << ci.quantity << "\t\t" << ci.price * ci.quantity << endl;
		total_price = total_price + (ci.price * ci.quantity);
		c11->pop();
	}
	int opt;
	if (cc1->get_balance_amount() < total_price) {
		cout << "your current balance is not enough" << endl;
		cout << "1.for add balance" << endl;
		cin >> opt;
		if (opt == 1) {
			float am;
			cout << "how much amount you want to add: " << endl;
			cin >> am;
			cc1->set_balance_amount(am);
		}
	}
	cc1->update_balance_amount(total_price);
	cout << "==============================================" << endl;

	cout << "ID: " << cc1->getID() << endl;
	cout << "Name: " << cc1->getName() << endl;
	cout << "total bill : " << total_price << endl;
	cout << "Your current balance: " << cc1->get_balance_amount() << endl;
	cout << "==============================================" << endl;

	return;
}
void Store::Open()
{
	//reading data from file of different sections and load into the STOCK
	ifstream f1;
	f1.open("TextFiles/" + filename[0], ios::in | ios::binary);
	if (!f1.is_open()) {
		f1.close();
		setDefaultStock();

		welcomepage(*this);
		exit(0);
	}
	else {
		f1.close();//to close previously opened file
		Item t1;
		section = new Section[sections];
		for (int i = 0; i < sections; i++)
		{
			f1.open("TextFiles/" + filename[i], ios::in | ios::binary);
			while (f1.read((char*)&t1, sizeof(Item)))
			{
				section[i].setProduct(t1);
				if (f1.eof())
					break;
			}
			f1.close();
		}

		welcomepage(*this);
		exit(0);
	}
}
void Store::Shopping(Consumer& cc1)
{
	Cart c1;
	int opt;
	while (1)
	{
		system("pause");
		system("cls");
		cout << "Want to 'see section list' OR 'search item by name'" << endl;
		cout << "1.Section List" << endl;
		cout << "2.Search item" << endl;
		cout << "3.Exit" << endl;
		cin >> opt;
		int flag;
		int batao, cont, hn;

		switch (opt)
		{
		case 1:
			ShowSectionList();
			cin >> batao;
			DisplaySectionProducts(batao - 1);
			cout << "Want to buy(1/0) " << endl;
			cin >> cont;
			if (cont == 1)
			{
				cout << "Enter product id you want to buy : " << endl;
				string id;
				cin >> id;
				//search item by id//
				Item t1 = search(id, batao - 1);

				c1.add_to_cart(&t1);
				c1.show();
				system("pause");
			}
			else
			{
				cout << "Want to go to the billing counter or another section:" << endl;
				cout << "1.Billing counter" << endl;
				cout << "2.Proceed to Shopping" << endl;
				cin >> hn;
				if (hn == 2) {
					continue;
				}
				else {
					//billing counter working
					bill_counter(&c1, &cc1);
					break;
				}
			}
			break;
		case 2:
			SEO();
			cout << "Want to buy(1/0) " << endl;
			cin >> cont;
			if (cont == 1)
			{
				cout << "Enter the id of product you want to buy : " << endl;
				string id;
				cin >> id;
				//search item by id//
				Item t1;
				for (int i = 0; i < sections; i++)
				{
					t1 = search(id, i);
					if (t1.id == " " && t1.name == " ")
						continue;
					else
						break;
				}
				c1.add_to_cart(&t1);
			}
			else
			{
				cout << "Want to go to the billing counter or another section: (1/0)" << endl;
				cout << "1.Billing counter" << endl;
				cout << "2.Proceed to Shopping" << endl;
				cin >> hn;
				if (hn == 2) {
					continue;
				}
				else {
					//billing counter working
					bill_counter(&c1, &cc1);
					break;
				}
			}
			break;
		case 3:
			cout << "Did You Buy Something(1 for yes/0 for no)" << endl;
			cin >> hn;
			if (hn == 1) {
				bill_counter(&c1, &cc1);
			}
			Close(cc1);
			exit(0);
			break;
		default:
			break;
		}
	}
}
void Store::DisplaySectionProducts(int i)
{
	system("cls");
	section[i].DisplayStock();
}
void Store::update_stock(int i, int q, string id) {
	section[i].update(id, q);
}
void Store::ShowSectionList()
{
	system("cls");
	cout << "1.Grocery" << endl;
	cout << "2.Garments" << endl;
	cout << "3.Cosmetics" << endl;
	cout << "4.Sports" << endl;
	cout << "5.Fruits" << endl;
	cout << "6.Frozen" << endl;
}
void Store::Close(Consumer c1)
{
	//writing updated data of store items
	ofstream f1;
	for (int i = 0; i < sections; i++)
	{
		f1.open("Files/" + filename[i], ios::out | ios::binary);
		Item* t1 = new Item[section[i].items];
		section[i].extractItems(t1);
		for (int i = 0; i < section[i].items; i++)
		{
			f1.write((char*)&t1[i], sizeof(Item));
		}
		f1.close();
	}
	f1.close();
	//writing updated data of consumer doing shopping using QUEUE data structure
	LLQueue q1;
	ifstream f2;
	f2.open("Consumer.txt", ios::in | ios::binary);
	Consumer c2;
	while (f2.read((char*)&c2, sizeof(c2)))
	{
		if (c1 == c2)
		{
			q1.Enqueue(c1);
		}
		else
		{
			q1.Enqueue(c2);
		}
	}
	f2.close();

	ofstream f3;
	f3.open("Consumer.txt", ios::binary | ios::app);
	while (!q1.isEmpty())
	{
		Consumer temp = q1.Dequeue();
		f3.write((char*)&temp, sizeof(temp));

	}
	f3.close();
}

void Store::PatternMatchBackSpace(Stack& undo, Stack& l1, Stack& l2)
{
	if (l1.isEmpty())
	{
		while (!undo.isEmpty())
		{
			string id = undo.peek_id();
			l2.push(undo.pop(), id);
		}
	}
	else
	{
		while (!undo.isEmpty())
		{
			string id = undo.peek_id();
			l1.push(undo.pop(), id);
		}
	}
}
//function extracting items from sections to any of the lists
//or from one list to another list also to undo stack(if not match)
void Store::PatternMatchingCharacter(Stack& undo, Stack& l1, Stack& l2, char* ch)
{
	if (l1.isEmpty() && l2.isEmpty())
	{
		for (int i = 0; i < sections; i++)
		{
			section[i].GetMatch1(l1, undo, ch);
		}
		return;
	}
	else if (l1.isEmpty())
	{
		while (!l2.isEmpty())
		{
			string id = l2.peek_id();
			string name = l2.peek_name();
			if (HashMatch(name, ch))
				l1.push(name, id);
			else
				undo.push(name, id);
			l2.pop();
		}
	}
	else if (l2.isEmpty())
	{
		while (!l1.isEmpty())
		{
			string id = l1.peek_id();
			string name = l1.peek_name();
			if (HashMatch(name, ch))
				l2.push(name, id);
			else
				undo.push(name, id);
			l1.pop();
		}
	}
}
void Store::PatternMatchingNewCharacter(Stack& undo, Stack& l, char* ch)
{
	int flag = 0;
	while (!undo.isEmpty())
	{
		string name = undo.peek_name();
		string id = undo.peek_id();
		if (HashMatch(name, ch))
		{
			flag = 1;
			l.push(name, id);
		}
		undo.pop();
	}
	if (flag != 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < sections; i++)
		{
			section[i].GetMatch2(l, undo, ch);
		}

		return;
	}
}

void Store::SEO()
{
	cout << "This search algorithm continues Until you press enter" << endl;
	cout << "If you found your search item, press enter and then enter id of your item" << endl;
	Stack list1, list2;
	Stack* undo = new Stack[15];
	char ch[15]{ '\0' };
	int i = 0;
	int cnt_history = -1;
	bool cnt_backspace = 0;
	while ((ch[i] = _getch()) != 13 && i < 15)
	{
		system("cls");
		//if person presses backspace
		if (ch[i] == 8)
		{
			if (cnt_history < 0)
			{
				continue;
			}
			else
			{
				//this extract from undo to list "that is not empty"
				cnt_backspace = true;
				if (cnt_history > 0)
				{
					PatternMatchBackSpace(undo[cnt_history], list1, list2);
				}
				else
				{
					cnt_backspace = false;
					list1.clean();
					list2.clean();
				}
				ch[i] = '\0';
				cnt_history--;
			}
			i -= 2;
		}

		else
		{
			if (cnt_backspace == false)
			{
				PatternMatchingCharacter(undo[++cnt_history], list1, list2, ch);
			}
			else
			{
				if (list1.isEmpty())
				{
					PatternMatchingNewCharacter(undo[++cnt_history], list2, ch);
					PatternMatchingCharacter(undo[cnt_history], list1, list2, ch);
				}
				else
				{
					PatternMatchingNewCharacter(undo[++cnt_history], list1, ch);
					PatternMatchingCharacter(undo[cnt_history], list1, list2, ch);
				}

			}
		}
		//showing list
		if (list1.isEmpty())
		{
			list2.ShowList();
		}
		else
		{
			list1.ShowList();
		}
		//printing characters
		for (int j = 0; j <= i; j++)
		{
			cout << ch[j];
		}
		i++;
	}
}
