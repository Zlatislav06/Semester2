#include "Vehicle.h"
Vehicle::Vehicle(string r)
{
	setRegistrtionNumber(r);
}
const string& Vehicle::getRegistrtionNumber() const
{
	return registrationNumber;
}
void Vehicle::setRegistrtionNumber(const string& regNumber)
{
	if (regNumber[0] >= 'A' && regNumber[0] <= 'Z')
	{
		if (regNumber[1] >= 'A' && regNumber[1] <= 'Z')
		{
			int index = 2;
			for (int i = index; i < regNumber.size() - 2; i++)
			{
				index++;
				if (regNumber[i] < '0' && regNumber[i] > '9')
				{
					
					throw std::invalid_argument("Invalid registration number!!!");
				}
			}
			index++;
			if (regNumber[index] >= 'A' && regNumber[index] <= 'Z')
			{
				index++;
				if (regNumber[index] >= 'A' && regNumber[index] <= 'Z')
				{
					registrationNumber = regNumber;
				}
				else
				{
					throw std::invalid_argument("Invalid registration number!!!");
				}
				
			}
			else
			{
				throw std::invalid_argument("Invalid registration number!!!");
			}
		}
		else
		{
			throw std::invalid_argument("Invalid registration number!!!");
		}
	}
	else
	{
		throw std::invalid_argument("Invalid registration number!!!");
	}
}