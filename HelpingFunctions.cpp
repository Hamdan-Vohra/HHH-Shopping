#include<iostream>
#include<fstream>
#include <conio.h> 
using namespace std;

#include "Store.h"
#include "Consumer.h"


bool HashMatch(string name, char* input)
{
	int a = int(name.length());
	int b = int(strlen(input));
	if (b > a)
		return false;
	float power = float(b) - 1;
	double hash1 = 0;
	double hash2 = 0;
	for (int i = 0; i < b && i < a; i++)
	{
		hash1 += (name[i] * pow(10, power));
		hash2 += (input[i] * pow(10, power));
		power--;
	}

	if (hash1 == hash2)
	{
		return true;

	}
	return false;
}


void welcomepage(Store& st);
void signup(Store& st);
void signin(Store& st);
//main shopping function
void customer(Store &st) {

	while (1)
	{
		int opt = 0;
		cout << "1-SignIn()" << endl;
		cout << "2-SignUp()" << endl;
		cout << "3-Back()" << endl;
		cin >> opt;
		system("cls");
		switch (opt)
		{
		case 1:
			signin(st);
			break;
		case 2:

			signup(st);

			break;
		case 3:

			return;
		default:

			continue;
		}
	}
}
void signup(Store& st)
{
	string nam, pass, id = "CUS-0000";
	cout << "Enter name : ";
	cin >> nam;

	cout << "Enter paswword : ";
	cin >> pass;

	ifstream file1;
	Consumer s1;
	if (!file1.eof())
	{
		file1.open("TextFiles/Consumer.txt", ios::app | ios::binary);
		int size = sizeof(Consumer);
		file1.seekg(-size, ios::end);
		file1.read((char*)&s1, sizeof(s1));
		id = s1.getID();
		cout << id << endl;
	}
	file1.close();

	Consumer c1(id, nam, pass, 1000);
	c1.display();
	ofstream file2;
	file2.open("TextFiles/Consumer.txt", ios::binary | ios::app);
	file2.write((char*)&c1, sizeof(Consumer));
	file2.close();
	system("pause");
	st.Shopping(c1);
}
void signin(Store& st)
{
	string nam, id, pass;
	cout << "Enter ID : ";
	cin >> id;
	cout << "Enter paswword : ";
	cin >> pass;
	bool flag = 0;
	ifstream file1;
	file1.open("TextFiles/Consumer.txt", ios::binary | ios::app);
	Consumer s1;
	while (!file1.eof()) {
		file1.read((char*)&s1, sizeof(s1));
		if (s1.getID() == id && s1.getPass() == pass)
		{
			flag = 1;
			cout << "\n\n\n\t\t\t\tWELCOME TO GHG" << endl;
			st.Shopping(s1);
		}
	}
	file1.close();
	if (flag != 1)
	{
		cout << "Invalid ID or Password" << endl;
		cout << "Please sign up first if you not signedup " << endl;
		customer(st);
	}
}

void welcomepage(Store& st) {
	system("cls");
	int opt;
	cout << "1-Admin" << endl;
	cout << "2-Consumer" << endl;
	cout << "3-Exit" << endl;
	cin >> opt;
	switch (opt)
	{
	case 1:
		admin(st);
		break;
	case 2:
		customer(st);
		break;
	case 3:
		exit(0);
		break;
	default:
		break;
	}
	welcomepage(st);
}

void admin(Store& st)
{
	char ch;
	string username;
A:
	cout << "Enter Username: ";
	cin >> username;
	if (username == "admin123") {
	B:
		string password;
		cout << "enter the password" << endl;
		ch = _getch();
		while (ch != 13) {
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		if (password == "vohra123") {
			cout << endl << "Enter successfully" << endl;
			system("pause");
		}
		else {
			cout << endl << "Incorrect Password" << endl;
			cout << "pasword: " << password << endl;
			ch = NULL;
			goto B;
		}
	}
	else {
		cout << "Incorrect Username! " << endl;
		goto A;
	}
	int opt1;
	string idd;
	while (1)
	{
		cout << " what you want: " << endl;
		cout << "1-Add Stock" << endl;
		cout << "2-Show Data" << endl;
		cout << "3-Back" << endl;
		cin >> opt1;
		system("cls");
		switch (opt1) {
		case 1:
			int opt2, q;
			st.ShowSectionList();
			cout << "enter the section no: " << endl;
			cin >> opt2;
			st.DisplaySectionProducts(opt2 - 1);
			cout << "enter the id of the item you want to update: " << endl;
			cin >> idd;
			cout << "enter the quantity you want to add: " << endl;
			cin >> q;
			st.update_stock(opt2 - 1, q, idd);
			break;
		case 2:
			int opt;
			st.ShowSectionList();
			cin >> opt;
			st.DisplaySectionProducts(opt - 1);
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
		system("pause");
	}

}