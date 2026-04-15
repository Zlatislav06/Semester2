#include <iostream>
#include <functional>
#include <compare>
#include "hexcolourcode.h"
const int SIZE = 10;
using std::endl;
HexColourCode::HexColourCode()
{
	code = new char[SIZE];
}
HexColourCode::HexColourCode(char* c)
{
	code = c;
}
HexColourCode::HexColourCode(const HexColourCode& H)
{
	int size = 0;
	while (code[size] != '\0')
	{
		size++;
	}
	code = new char[size];
	for (int i = 0; i < size; i++)
	{
		code[i] = H.code[i];
	}
}
HexColourCode HexColourCode::operator=(const HexColourCode& H)
{
	if (this != &H)
	{
		delete[] code;
		int size = 0;
		while (code[size] != '\0')
		{
			size++;
		}
		code = new char[size];
		for (int i = 0; i < size; i++)
		{
			code[i] = H.code[i];
		}
	}
	return *this;
}
auto HexColourCode::operator<=>(const HexColourCode& H)
{
	int h1 = SixSystem(code);
	int h2 = SixSystem(H.code);
	return h1 <=> h2;
}
void HexColourCode::setCode(char* c)
{
	code = c;
}
std::ostream& operator<<(std::ostream& out, const HexColourCode& H)
{
	int index = 0;
	while (H.code[index] != '\0')
	{
		out << H.code[index];
		index++;

	}
	out << endl;
	return out;
}
HexColourCode::~HexColourCode()
{
	code = nullptr;
	delete[] code;
}