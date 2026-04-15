#pragma once
#include <iostream>
#include <functional>
#include <compare>
class NumbericalVector
{
private:
	
	int* cordinates = nullptr;
public:
	int size;
	NumbericalVector();
	NumbericalVector(int s);
	NumbericalVector& operator=(const NumbericalVector& V);
	int operator[](const int index);
	NumbericalVector operator+(const NumbericalVector& V);
	NumbericalVector& operator+=(const NumbericalVector& V);
	int operator*(const NumbericalVector& V);
	friend std::ostream& operator<<(std::ostream& out, const NumbericalVector& V);
	std::strong_ordering operator<=>(const NumbericalVector& V) const;
	NumbericalVector(const NumbericalVector& other);
	void setValue(int index, int val);
	~NumbericalVector();

};