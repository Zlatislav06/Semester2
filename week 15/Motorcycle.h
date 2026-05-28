#pragma once
#include "Vehicle.h"
class Motorcycle:public Vehicle
{
protected:
	string name;
	double maxSpeed;
public:
	Motorcycle(string regNumber, string n, double m);
	const string& getName() const;
	const double& getMaxSpeed() const;
	void setName(const string& n);
	void setMaxSpeed(const double& m);
	std::unique_ptr<Vehicle> clone() override;
};

