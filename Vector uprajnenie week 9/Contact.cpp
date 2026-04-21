#include "Contact.h"
#include <iostream> 
using std::string;
using std::cout;
using std::cin;
using std::endl;
bool CheckPhoneNumberWithSize10(string num)
{
	bool check = true;
	if (num[0] == '0')
	{
		for (int i = 1; i < num.size(); i++)
		{
			if (num[i] < '0' || num[i] > '9')
			{
				check = false;
				break;
			}
		}
	}
	else
	{
		check = false;
	}
	return check;
}
bool StringVsString(string str1,string str2)
{
	bool check = true;
	int size = 0;
	if (str1.size() >= str2.size())
	{
		size = str2.size();
	}
	else
	{
		size = str1.size();
	}
	for (int i = 0; i < size; i++)
	{
		if (str1[i] != str2[i])
		{
			check = false;
		}
	}
	return check;
}
bool CheckPhoneNumberWithBegin359(string num)
{
	bool check = true;
	string str = "+359";
	if (StringVsString(str,num))
	{
		for (int i = str.size()-1; i < num.size(); i++)
		{
			if (num[i] < '0' || num[i] > '9')
			{
				check = false;
				break;
			}
		}
	}
	else
	{
		check = false;
	}
	return check;
}
Contact::Contact()
{
	name = "";
	number = "088888888";
}
void Contact::setNumber(string num)
{
	int size = num.size();
	if (size == 10 && CheckPhoneNumberWithSize10(num))
	{
		number = num;
	}
	else if (size == 13 && CheckPhoneNumberWithBegin359(num))
	{
		number = num;
	}
	else
	{
		cout << "Invalid phonenumber. It will be 088888888"<<endl;
		number = "088888888";
	}

}
Contact::Contact(string n, string num)
{
	name = n;
	setNumber(num);
}
string Contact::getName()
{
	return name;
}
string Contact::getNumber()
{
	return number;
}