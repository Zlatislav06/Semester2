#pragma once
#include <iostream>
using std::string;
class Users
{
public:
	int id;
	string username;
	string password;
	Calculator* calc=nullptr;

	Users(string u,string p,Calculator* c);
	string getUsername();
	void setUsername(string username);
	string getPassword();
	void setPassword(string password);
};