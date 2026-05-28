#pragma once
#include "Vehicle.h"
class Car:public Vehicle
{
protected:
	string name;
	string mark;
	string model;
	int year;
public:
	Car(string regNumber, string n, string mark, string model, int y);
	const string& getName() const;
	const string& getMark() const;
	const string& getModel() const;
	const int& getYear() const;
	void setName(const string& n);
	void setMark(const string& m);
	void setModel(const string& m);
	void setYear(const int& y);
	std::unique_ptr<Vehicle> clone() override;
};

