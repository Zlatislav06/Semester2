#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
class Person
{
private:
	string name;
	int age;
	string address;
public:
	Person(string n,int a,string add);
	const string& getName() const;
	const int& getAge() const;
	const string& getAddress() const;
	void setName(string n);
	void setAge(int a);
	void setAddress(string a);
	virtual void printInfo() const;

};

