#include <iostream>
#include "Header.h"
const int SIZE = 10;
using std::cout;
using std::endl;
#define erorr_msg cout<<"This symbol is invalid! He will be \'c\'"<<endl;

double ConvertToCelsius(double t, char s)
{
	double converted_temperature = 0;
	if (s == 'c')
	{
		converted_temperature = t;
	}
	else if (s == 'f')
	{
		converted_temperature = (t - 32) / 1.8;
	}
	else
	{
		erorr_msg;
		s = 'c';
		converted_temperature = t;
	}
	return converted_temperature;

}

Temperature::Temperature(double t, char s)
{
	temperature = t;
	system = s;
}
double Temperature::getTemperature()
{
	return temperature;
}
void Temperature::setTemperature(double t)
{
	temperature = t;
}
char Temperature::getSystem()
{

	return system;

}
void Temperature::setSystem(char s)
{
	if (s == 'c' || s == 'f')
	{
		system = s;
	}
	else
	{
		erorr_msg;
		system = 'c';
	}
}
bool Temperature::operator==(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	return t1 == t2;
}
bool Temperature::operator<(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	return t1 < t2;
}
bool Temperature::operator>(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	return t1 > t2;
}
bool Temperature::operator!=(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	return t1 != t2;
}
Temperature  Temperature::operator+(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	Temperature T2 = { t1 + t2,'c' };
	return T2;
}
Temperature  Temperature::operator-(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	Temperature T2 = { t1 - t2,'c' };
	return T2;
}
Temperature& Temperature::operator+=(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	temperature = t1 + t2;
	system = 'c';
	return *this;
}
Temperature& Temperature::operator-=(const Temperature& T1)
{
	double t1 = ConvertToCelsius(temperature, system);
	double t2 = ConvertToCelsius(T1.temperature, T1.system);
	temperature = t1 - t2;
	system = 'c';
	return *this;
}
