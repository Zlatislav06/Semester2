#include "Motorcycle.h"
Motorcycle::Motorcycle(string regNumber, string n, double m):Vehicle(regNumber)
{
	setName(n);
	setMaxSpeed(m);
}
const string& Motorcycle::getName() const
{
	return name;
}
const double& Motorcycle::getMaxSpeed() const
{
	return maxSpeed;
}
void Motorcycle::setName(const string& n)
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
void Motorcycle::setMaxSpeed(const double& m)
{
	if (m >= 0)
	{
		maxSpeed = m;
	}
	else
	{
		throw std::invalid_argument("Max speed can't be less then zero!!!");
	}
}
std::unique_ptr<Vehicle> Motorcycle::clone()
{
	return std::make_unique<Motorcycle>(*this);
}