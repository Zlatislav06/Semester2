#include "Person.h"
Person::Person(string n, int a, string add)
{
	name = n;
	age = a;
	address = add;	
}
const string& Person::getName() const
{
	return name;
}
const int& Person::getAge() const
{
	return age;
}
const string& Person::getAddress() const
{
	return address;
}
void Person::setName(string n)
{
	name = n;
}
void Person::setAge(int a)
{
	age = a;
}
void Person::setAddress(string a)
{
	address = a;
}
void Person::printInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Address: " << address << endl<<endl;
}