#include <iostream>
#include "calculator.h"
#include "users.h"
#include "Cipher.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;
void Print(string z)
{
	for (int i = 0; i < z.size(); i++)
	{
		cout << z[i];
	}
	cout << endl;

}

int main()
{
	int a = 3;
	Users u1 = {"fwkofwj","w0f0w0wkf"};
	Calculator* calc = u1.getCalculator();
	
	
	Cipher c1 = { "fjwo hfo osb fe dxx    llb" };
	Cipher c2 = { " ejddse gsng;nz;dne ean ensglsgn z nqw;" };
	Cipher c3 = c1 + c2;
	Print(c3.encrypt());
	return 0;
}