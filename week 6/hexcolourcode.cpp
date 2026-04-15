#include <iostream>
#include <functional>
#include <compare>
#include "hexcolourcode.h"
const int SIZE = 10;
using std::endl;
int SixSystem(char* c)
{
	int sum = 0;
	int size = 0;
	char b;
	while (c[size] != 0)
	{
		size++;
	}

	for (int i = 0; i < size; i++)
	{
		if (c[i] >= 'a' && c[i] <= 'z')
		{
			b = c[i] - ('a' - 'A');
		}
		else
		{
			b = c[i];
		}
		switch (b)
		{
		case '1':
		{
			sum++;
			break;
		}
		case '2':
		{
			sum += 2;
			break;
		}
		case '3':
		{
			sum += 3;
			break;
		}
		case '4':
		{
			sum += 4;
			break;
		}
		case '5':
		{
			sum += 5;
			break;
		}
		case '6':
		{
			sum += 6;
			break;
		}
		case '7':
		{
			sum += 7;
			break;
		}
		case '8':
		{
			sum += 8;
			break;
		}
		case '9':
		{
			sum += 9;
			break;
		}
		case 'A':
		{
			sum += 10;
			break;
		}
		case 'B':
		{
			sum += 11;
			break;
		}
		case 'C':
		{
			sum += 12;
			break;
		}
		case 'D':
		{
			sum += 13;
			break;
		}
		case 'E':
		{
			sum += 14;
			break;
		}
		case 'F':
		{
			sum += 15;
			break;
		}


		}

	}
	return sum;
}
HexColourCode::HexColourCode()
{
	code = new char[SIZE];
}
HexColourCode::HexColourCode(char* c)
{
	int size = strlen(c) + 1;
	code = new char[size];
	for (int i = 0; i < size; i++)
	{
		code[i] = c[i];
	}
}
HexColourCode::HexColourCode(const HexColourCode& H)
{
	int size = 0;
	while (H.code[size] != '\0')
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
		while (H.code[size] != '\0')
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

void HexColourCode::setCode(char* c)
{
	delete[] code;
	int size = strlen(c) + 1;
	code = new char[size];
	for (int i = 0; i < size; i++)
	{
		code[i] = c[i];
	}
}
std::strong_ordering HexColourCode::operator<=>(const HexColourCode& H)
{
	int h1 = SixSystem(code);
	int h2 = SixSystem(H.code);
	return h1 <=> h2;
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
	
	delete[] code;
}