#pragma once
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Train.h"
#include "Car.h"
class CATFactory
{
public:
	static std::unique_ptr<Vehicle> createVehicle(const string& typeVehicle);
};

