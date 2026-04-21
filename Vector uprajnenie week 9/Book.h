#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
class Book
{
private:
	string title;
public:
	Book(string t="");
	string getTitle();
};

