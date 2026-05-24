#include "Teacher.h"
Teacher::Teacher(string n, int a, string add, int y, double s) :Person(n, a, add)
{
	yearsOfTeaching = y;
	sallary = s;
}
const int& Teacher::getYearsOfTeaching() const
{
	return yearsOfTeaching;
}
const double& Teacher::getSallary() const
{
	return sallary;
}
void Teacher::setYearsOfTeaching(int y)
{
	yearsOfTeaching = y;
}
void Teacher::setSallary(double s)
{
	sallary = s;
}
void Teacher::printInfo() const
{
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Years of Teaching: " << yearsOfTeaching << endl;
	cout << "Sallary: " << sallary << endl<<endl;
}