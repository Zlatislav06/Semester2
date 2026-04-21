#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Box
{
private:
	double weight;
public:
	Box(double w = 0);
	double getWeight();
};

