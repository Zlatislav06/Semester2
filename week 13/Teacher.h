#pragma once
#include "Person.h"
class Teacher :public Person
{
private:
	int yearsOfTeaching;
	double sallary;
public:
	Teacher(string n, int a, string add, int y, double s);
	const int& getYearsOfTeaching() const;
	const double& getSallary() const;
	void setYearsOfTeaching(int y);
	void setSallary(double s);
	void printInfo() const override;
};

