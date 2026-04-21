#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::endl;
using std::cout;
using std::cin;
class NumberList
{
private:
	std::vector<int> vector;
public:
	void addNum(int a);
	void sortAsending();
	void sortDesending();
	void printAll();
};

