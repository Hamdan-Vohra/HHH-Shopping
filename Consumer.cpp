#include<iostream>
using namespace std;
#include "Consumer.h"

Consumer::Consumer() {
	current_balance = 0;
	id = "CUS-0000";
	password = name = "customer";
}
Consumer::Consumer(string id, string name, string pass, double balance = 1000) {
	this->id = "CUS-0000";
	this->password = pass;
	this->name = name;
	this->current_balance = balance;
	setid(id);
}
bool Consumer::operator==(const Consumer c1)
{
	if (this->id == c1.id && this->name == c1.name)
		return true;
	else
		return false;
}
void Consumer::setname(string nam)
{
	this->name = nam;
}
float Consumer::get_balance_amount() {
	return current_balance;
}
void Consumer::set_balance_amount(float m) {
	this->current_balance += m;
}
void Consumer::update_balance_amount(float m) {
	this->current_balance -= m;
}
void Consumer::setid(string ID)
{
	int val = 0;
	int pos = 1;
	for (int i = 7; i >= 4; i--)
	{
		val = (ID[i] - 48) * pos + val;
		pos *= 10;
	}
	val++;
	for (int i = 7; i >= 4; i--)
	{
		id[i] = (val % 10) + 48;
		val /= 10;
	}
}
void Consumer::setpassword(string nam)
{
	this->password = nam;
}
string Consumer::getID()
{
	return id;
}
string Consumer::getName()
{
	return name;
}
string Consumer::getPass()
{
	return password;
}
void Consumer::display()
{
	cout << "CUSTOMER DETAILS" << endl;
	cout << "ID -->" << id << endl;
	cout << "Name -->" << name << endl;
	cout << "Password -->" << password << endl;
}
