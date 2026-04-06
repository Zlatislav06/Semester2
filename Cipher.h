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
	Cipher operator+(const Cipher& c1);
	Cipher& operator+=(const Cipher& c1);
};