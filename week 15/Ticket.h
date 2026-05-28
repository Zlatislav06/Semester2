#pragma once
#include <iostream>
#include <memory>
using std::cin;
using std::cout;
using std::string;
using std::endl;
class Ticket
{
private:
	string registrationNumber;
	double money;
	string data;
	string payment;
	bool isPaid;
public:
	Ticket(string regNumber, double m, string d, bool i);
	const string& getRegistrtionNumber() const;
	const double& getMoney() const;
	const string& getData() const;
	const string& getPayment() const;
	const bool& getIsPaid() const;
	void setRegistrtionNumber(const string& regNumber);
	void setMoney(const double& m);
	void setData(const string& d);
	void setPayment(const string& p);
	void setIsPaid(const bool& ispaid);

};

