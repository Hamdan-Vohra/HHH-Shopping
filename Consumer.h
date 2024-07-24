#pragma once
class Consumer {
	string id;
	string password;
	string name;
	double current_balance;

public:
	Consumer();
	Consumer(string id, string name, string pass, double balance = 1000);
	bool operator==(const Consumer c1);
	void setname(string nam);
	float get_balance_amount();
	void set_balance_amount(float m);
	void update_balance_amount(float m);
	void setid(string ID);
	void setpassword(string nam);
	string getID();
	string getName();
	string getPass();
	void display();
};
