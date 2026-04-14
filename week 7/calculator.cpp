#include <iostream>
using std::cout;
#include "calculator.h"
#define erorr_msg cout<<"Divided by zero is imposible!";
double Calculator::sum(double first, double second)
{
	return first + second;
}
double Calculator::substeact(double first, double second)
{
	return first - second;
}
double Calculator::multiply(double first, double second)
{
	return first * second;
}
double Calculator::divide(double first, double second)
{
	double divide = 0;
	if (second != 0)
	{
		divide = first / second;
	}
	else
	{
		erorr_msg;
	}
	return divide;
}
