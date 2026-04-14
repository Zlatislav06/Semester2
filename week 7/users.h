#pragma once
#include <iostream>
using std::string;
class Users
{
private:
	static int br;
	int id;
	string username;
	string password;
	Calculator* calc = nullptr;
public:
	
	string getUsername();
	void setUsername(string u);
	string getPassword();
	void setPassword(string p);
	Users(string u, string p);
	
	Calculator* getCalculator();
};