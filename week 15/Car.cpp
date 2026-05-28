#include "Car.h"
Car::Car(string regNumber, string n, string mark, string model, int y) :Vehicle(regNumber)
{
	setName(n);
	this->mark = mark;
	this->model = model;
	year = y;
}
const string& Car::getName() const
{
	return name;
}
const string& Car::getMark() const
{
	return mark;
}
const string& Car::getModel() const
{
	return model;
}
const int& Car::getYear() const
{
	return year;
}
void Car::setName(const string& n)
{
	if (n[0] >= 'A' && n[0] <= 'Z')
	{
		name = n;
	}
	else
	{
		throw std::invalid_argument("The name cannot be lowercase!!!");
	}
	
}
void Car::setMark(const string& m)
{
	mark = m;
}
void Car::setModel(const string& m)
{
	model = m;
}
void Car::setYear(const int& y)
{
	year = y;
}
std::unique_ptr<Vehicle> Car::clone()
{
	return std::make_unique<Car>(*this);
}