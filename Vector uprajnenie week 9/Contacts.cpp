#include "Contacts.h"
void Contacts::addContact(Contact a)
{
	v.push_back(a);
}
void printContact(Contact a)
{
	cout << "Name:" << a.getName() << endl;
	cout << "Phonenumber:" << a.getNumber() << endl;
}
void Contacts::findContact(string a)
{
	int check = false;
	int index = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].getName() == a)
		{
			check = true;
			index = i;
			break;
		}
	}
	if (check)
	{
		printContact(v[index]);
	}
	else
	{
		cout << "Don't have contact with this name"<<a<<endl;
	}
}
void Contacts::printAll()
{
	for (Contact x : v)
	{
		printContact(x);
		cout << endl;
	}
}