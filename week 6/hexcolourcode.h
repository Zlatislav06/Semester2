#pragma once
#include <iostream>
#include <functional>
#include <compare>
class HexColourCode
{
private:
	char* code=nullptr;
public:
	HexColourCode();
	HexColourCode(char* c);
	HexColourCode(const HexColourCode& H);
	HexColourCode operator=(const HexColourCode& H);
	void setCode(char* c);
	friend std::ostream& operator<<(std::ostream& out, const HexColourCode& H);
	auto operator<=>(const HexColourCode& H);
	HexColourCode operator+(const HexColourCode& H)=delete;
	HexColourCode operator-(const HexColourCode& H) = delete;
	HexColourCode operator*(const HexColourCode& H) = delete;
	HexColourCode operator/(const HexColourCode& H) = delete;
	HexColourCode operator%(const HexColourCode& H) = delete;
	~HexColourCode();
};
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