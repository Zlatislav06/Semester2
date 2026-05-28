#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;
#include "Vehicle.h"

int main()
{
	try
	{

	}
	catch (std::invalid_argument ex)
	{
		cout << ex.what();
	}
	return 0;
}