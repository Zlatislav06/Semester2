#pragma once
#include "Person.h"
class Student:public Person
{
private:
	int semester;
public:
	Student(string n,int a,string add,int s);
	const int& getSemester() const;
	void setSemester(int s);
	void printInfo() const override;
};

