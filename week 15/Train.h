#pragma once
#include "Vehicle.h"
class Train:public Vehicle 
{
protected:
	int countOfMachinistes=0;
	int countOfVagons = 0;
	int countOfPlases=0;
	int countOfStendingPersons=0;
public:
	Train(string regNumber, int m, int v, int p, int sp);
	const int& getCountOfMachinistes() const;
	const int& getCountOfVagons() const;
	const int& getCountOfPlases() const;
	const int& getCountOfStendingPersons() const;
	void setCountOfMachinistes(const int& m);
	void setCountOfVagons(const int& v);
	void setCountOfPlases(const int& p);
	void setCountOfStendingPersons(const int& sp);
	std::unique_ptr<Vehicle> clone() override;

};

