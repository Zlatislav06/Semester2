#pragma once
#include <iostream> 
#include <vector>
#include "Contact.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Contacts
{
private:
	std::vector<Contact> v;
public:
	void addContact(Contact a);
	void findContact(string a);
	void printAll();
};

