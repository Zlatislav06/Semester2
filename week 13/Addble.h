#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
class Addble
{
public:
	virtual void add(string toAdd)=0;
	virtual ~Addble() = default;
};

