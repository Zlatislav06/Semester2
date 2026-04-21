#pragma once
#include <iostream>
using std::string;
class Contact
{
private:
	string name;
	string number;
public:
	Contact();
	Contact(string n, string num);
	string getName();
	string getNumber();
	void setNumber(string num);
};

