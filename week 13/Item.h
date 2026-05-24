#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
class Item
{
private:
	string name;
public:
	Item(string n);
	const string& getName() const;
	void setName(string n);
};

