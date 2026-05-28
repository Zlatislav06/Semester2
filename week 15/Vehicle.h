#pragma once
#include <iostream>
#include <memory>
using std::cin;
using std::cout;
using std::string;
using std::endl;
class Vehicle
{
protected:
	string registrationNumber;
public:
	Vehicle(string r);
	const string& getRegistrtionNumber() const;
	void setRegistrtionNumber(const string& regNumber);
	virtual std::unique_ptr<Vehicle> clone()=0;
};

