#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#include "calculator.h"
#include "users.h"
#define error_username cout<<"Username can't be empty! Try again!"<<endl;
#define error_password cout<<"Password can't be empty! Try again!"<<endl;

int Users::br = 0;

Users::Users(string u,string p) {
    setUsername(u);
    setPassword(p);
    id = ++br;
    calc = &Calculator::getInstance();
}
string Users::getUsername()
{
	return username;
}
void Users::setUsername(string u)
{
    while(u.empty())
    {
        error_username;
        cin >> u;
    }
	username = u;
}
string Users::getPassword()
{
	return password;
}
void Users::setPassword(string p)
{
    while (p.empty())
    {
        error_password;
        cin >> p;
    }
	password = p;
}
Calculator* Users::getCalculator() {
    return calc;
}