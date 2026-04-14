#include <iostream>
#include "Cipher.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;
#define erorr_msg cout<<"Divided by zero is imposible!";
#define erorr_null cout<<"This text is empty!";
void InOneStringToAnother(string& new_text, string old_text, int size)
{
	for (int i = 0; i < size + 1; i++)
	{
		new_text += old_text[i];

	}
}
Cipher::Cipher(string t)
{
	text = t;
}
string Cipher::encrypt()
{
	if (text.size() == 0)
	{
		erorr_null;
	}
	int index = 0;
	string t1 = "";
	string reverse = "";
	for (int i = 0; i < text.size() + 1; i++)
	{
		if (text[i] == ' ' || text.size() == i)
		{
			int size = index - 1;
			string t2 = "";
			for (int j = 0; j < index; j++)
			{

				t2 += t1[size - j];

			}
			t2 += " ";
			InOneStringToAnother(reverse, t2, index);
			index = 0;
			t1 = "";

		}
		else
		{
			t1 += text[i];
			index++;
		}

	}
	return reverse;
}
string Cipher::operator[](int index)
{
	int br = 0;
	string result = "";
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == ' ')
		{

			if (br == index)
			{
				break;
			}
			else
			{
				result = "";
			}
			br++;
		}
		else
		{
			result += text[i];
		}
	}
	return result;
}
Cipher Cipher::operator+(const Cipher& c1)
{
	string new_text = "";
	for (int i = 0; i < text.size(); i++)
	{
		new_text += text[i];
	}
	for (int i = 0; i < c1.text.size(); i++)
	{
		new_text += c1.text[i];
	}
	Cipher c2 = { new_text };
	return c2;
}
Cipher& Cipher::operator+=(const Cipher& c1)
{
	string new_text = "";
	for (int i = 0; i < text.size(); i++)
	{
		new_text += text[i];
	}
	for (int i = 0; i < c1.text.size(); i++)
	{
		new_text += c1.text[i];
	}
	Cipher c2 = { new_text };
	return c2;
}