#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "MyFile.h"
#include "FileSystem.h"
#include "PermanentFile.h"
#include "StandardFile.h"
int main()
{
	Person* p = new Teacher("Traikov", 35, "Strawberry 12", 12, 3000.25);
	p->printInfo();
	return 0;
}