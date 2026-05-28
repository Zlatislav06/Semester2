#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Exception:public std::exception
{
private:
	string msg;
public:
	Exception(string msg);
	Exception();
	static void Invalid_argument(Exception ex);
};

