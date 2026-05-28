#include "CATFactory.h"
std::unique_ptr<Vehicle> CATFactory::createVehicle(const string& typeVehicle)
{
	string registrationNumber = "";
	cout << "Write registration number of vehicle:";
	cin >> registrationNumber;
	if (typeVehicle == "Motorcycle")
	{
		string name="";
		double maxSpeed = 0;
		cout << "Write name of owner:";
		cin >> name;
		cout << "Enter max speed:";
		cin >> maxSpeed;
		return std::make_unique<Motorcycle>(new Motorcycle(registrationNumber,name,maxSpeed));
	}
	if (typeVehicle == "Car")
	{

		string name = "";
		string mark = "";
		string model = "";
		int y = 0;
		cout << "Write name of owner:";
		cin >> name;
		cout << "Write the band of your car:";
		cin >> mark;
		cout << "Write the model of your car:";
		cin >> model;
		cout << "Enter the year it was manufactured:";
		cin >> y;
		return std::make_unique<Car>(new Car(registrationNumber, name, mark, model,y));

	}
	if (typeVehicle == "Train")
	{
		int m = 0;
		int v = 0; 
		int p = 0; 
		int sp = 0;
		cout << "Enter count of machinistes:";
		cin >> m;
		cout << "Enter count of vagons:";
		cin >> v;
		cout << "Enter count of plases:";
		cin >> p;
		cout << "Enter count of standing person:";
		cin >> sp;
		return std::make_unique<Train>(new Train(registrationNumber, m, v, p, sp));
	}

}