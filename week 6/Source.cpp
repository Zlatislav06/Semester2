#include <iostream>
#include "Header.h"
#include "hexcolourcode.h"
#include "numbericalVector.h"
const int SIZE = 10;
using std::cout;
using std::string;
using std::cin;
using std::endl;
#define erorr_msg cout<<"This symbol is invalid! He will be \'c\'"<<endl;
#define msg cout<<"It's imposible to return index bigger then the size!!!"<<endl;

//zad1
void Print(Temperature t)
{

	if (t.getSystem() == 'c')
	{
		cout << "Temperature in Celsius is ";
	}
	cout << t.getTemperature();

}
	//zad2
	void PrintVector(NumbericalVector V)
	{
		cout<<V;
	}
	//zad3

	
int main()
{
	NumbericalVector v1 = { 3 };
	NumbericalVector v2 = { 4 };
	v1.setValue(0, 1);
	v1.setValue(1, 2);
	v1.setValue(2, 3);
	v2.setValue(0, -1);
	v2.setValue(1, 0);
	v2.setValue(2, 8);
	v2.setValue(3, 8);
	NumbericalVector v3=v1+ v2;
	v1 = v2;
	PrintVector(v1);
	PrintVector(v2);
	cout << v1[2];
	PrintVector(v1);
	char a[] = "fa54643546";
	HexColourCode h1 = {a};
	cout << SixSystem(a)<<endl;
	HexColourCode h2 = { a };
	cout << ((h1<=>h2)>0);

	return 0;
}