#pragma once
#include <iostream>
using std::string;
class Cipher
{
private:
	string text;
public:
	Cipher(string t);
	string encrypt();
	string operator[](int index);
	friend Cipher operator+(const Cipher& c1, const Cipher& c2);
	Cipher& operator+=(const Cipher& c1);
};
