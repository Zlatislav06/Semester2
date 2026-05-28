#include "Train.h"
Train::Train(string regNumber, int m, int v, int p, int sp):Vehicle(regNumber)
{
	setCountOfMachinistes(m);
	setCountOfPlases(p);
	setCountOfStendingPersons(sp);
	setCountOfVagons(v);
}
const int& Train::getCountOfMachinistes() const
{
	return countOfMachinistes;
}
const int& Train::getCountOfVagons() const
{
	return countOfVagons;
}
const int& Train::getCountOfPlases() const
{
	return countOfPlases;
}
const int& Train::getCountOfStendingPersons() const
{
	return countOfStendingPersons;
}
void Train::setCountOfMachinistes(const int& m)
{
	if (m >= 0)
	{
		countOfMachinistes = m;
	}
	else
	{
		throw std::invalid_argument("Machinists can't be less then zero!!!");
	}
}
void Train::setCountOfVagons(const int& v)
{
	if (v >= 0)
	{
		countOfVagons = v;
	}
	else
	{
		throw std::invalid_argument("Vagons can't be less then zero!!!");
	}
}
void Train::setCountOfPlases(const int& p)
{
	if (p >= 0)
	{
		countOfPlases = p;
	}
	else
	{
		throw std::invalid_argument("Plases can't be less then zero!!!");
	}
}
void Train::setCountOfStendingPersons(const int& sp)
{
	if (sp >= 0)
	{
		countOfStendingPersons = sp;
	}
	else
	{
		throw std::invalid_argument("Stending persons can't be less then zero!!!");
	}
}
std::unique_ptr<Vehicle> Train::clone()
{
	return std::make_unique<Train>(*this);
}