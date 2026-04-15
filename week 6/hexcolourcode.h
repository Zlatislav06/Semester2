#pragma once
#include <iostream>
#include <functional>
#include <compare>
int SixSystem(char* c);
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
	std::strong_ordering operator<=>(const HexColourCode& H);
	HexColourCode operator+(const HexColourCode& H)=delete;
	HexColourCode operator-(const HexColourCode& H) = delete;
	HexColourCode operator*(const HexColourCode& H) = delete;
	HexColourCode operator/(const HexColourCode& H) = delete;
	HexColourCode operator%(const HexColourCode& H) = delete;
	~HexColourCode();
};

