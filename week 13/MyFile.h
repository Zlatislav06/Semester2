#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
class MyFile
{
protected:
	string data;
public:
	MyFile(string data);
	const string& getData() const;
	void setData(string d);
	virtual void printDetails() const=0;
	virtual ~MyFile()=default;

};

