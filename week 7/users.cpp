#include <iostream>
using std::cout;
#include "calculator.h"
#include "users.h"
static int br = 0;


Users::Users(string u, string p, Calculator* c)
{
	br++;
	id = br;
	username = u;
	password = p;
	calc = c;
}
string Users::getUsername()
{
	return username;
}
void Users::setUsername(string u)
{
	username = u;
}
string Users::getPassword()
{
	return password;
}
void Users::setPassword(string p)
{
	password = p;
}