#include <iostream>
#include "numbericalVector.h"
const int SIZE = 10;
using std::cout;
using std::endl;
#define msg cout<<"It's imposible to return index bigger then the size!!!"<<endl;

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int* ReSize(int* a, int size, int new_size)
{
	int* arr = new int[new_size] {0};
	for (int i = 0; i < size; i++)
	{
		arr[i] = a[i];
	}
	return arr;
}
NumbericalVector::NumbericalVector()
{
	size = 3;
	cordinates = new int[size] {0};
}
NumbericalVector::NumbericalVector(int s)
{
	size = s;
	cordinates = new int[size] {0};
}
NumbericalVector::NumbericalVector(const NumbericalVector& other)
{

	size = other.size;
	cordinates = new int[size];
	for (int i = 0; i < other.size; i++)
	{
		cordinates[i] = other.cordinates[i];
	}

}
void NumbericalVector::setValue(int index, int val)
{

	cordinates[index] = val;

}
int NumbericalVector::operator[](const int index)
{
	if (size < index)
	{
		msg;
	}
	return cordinates[index];
}
NumbericalVector& NumbericalVector::operator=(const NumbericalVector& V)
{
	if (this != &V)
	{
		delete[] cordinates;
		size = V.size;
		cordinates = new int[size];
		for (int i = 0; i < V.size; i++)
		{
			cordinates[i] = V.cordinates[i];
		}
	}
	return *this;
}
NumbericalVector NumbericalVector::operator+(const NumbericalVector& V)
{
	int maxSize = max(size, V.size);
	NumbericalVector v1 = { maxSize };
	v1.cordinates = ReSize(cordinates, size, maxSize);
	int minSize = min(size, V.size);
	for (int i = 0; i < minSize; i++)
	{
		v1.cordinates[i] = cordinates[i] + V.cordinates[i];
	}
	return v1;


}
NumbericalVector& NumbericalVector::operator+=(const NumbericalVector& V)
{
	int maxSize = max(size, V.size);

	cordinates = ReSize(cordinates, size, maxSize);
	size = maxSize;
	for (int i = 0; i < maxSize; i++)
	{
		cordinates[i] += V.cordinates[i];
	}
	return *this;
}
int NumbericalVector::operator*(const NumbericalVector& V)
{
	int sum = 0;
	int minSize = min(size, V.size);
	for (int i = 0; i < minSize; i++)
	{
		sum += cordinates[i] * V.cordinates[i];
	}
	return sum;
}
std::ostream& operator<<(std::ostream& out, const NumbericalVector& V)
{
	out << "[" << V.cordinates[0];
	for (int i = 1; i < V.size; i++)
	{
		out << "," << V.cordinates[i];
	}
	out << "]" << endl;
	return out;
}
auto NumbericalVector::operator<=>(const NumbericalVector& V) const
{
	if (size != V.size)
	{
		return size <=> V.size;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (cordinates[i] != V.cordinates[i])
			{
				return cordinates[i] <=> V.cordinates[i];
			}
		}

	}
	return size <=> V.size;
}

NumbericalVector::~NumbericalVector()
{
	cordinates = nullptr;
	delete[] cordinates;
}