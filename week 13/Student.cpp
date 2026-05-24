#include "Student.h"
Student::Student(string n, int a, string add,int s) : Person(n,a,add)
{
	semester = s;
}
const int& Student::getSemester() const
{
	return semester;
}
void Student::setSemester(int s)
{
	semester = s;
}
void Student::printInfo() const
{
	double curse = semester / 2;
	if (semester % 2 != 0)
	{
		curse= (semester-1) / 2;
	}
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Curse: " << curse << endl << endl;
	cout << "Semester: " << semester << endl << endl;

}