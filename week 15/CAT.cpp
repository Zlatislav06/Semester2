#include "CAT.h"


void CAT::add(const Vehicle& vehicle)
{

	vehicles.push_back(std::make_unique<Vehicle>(vehicle));
}
void CAT::add(const Ticket& ticket)
{
	tickets.push_back(ticket);
}
void CAT::removeVehicle(int index)
{
	vehicles.erase(vehicles.begin()+index);
}
void CAT::removTicket(int index)
{
	tickets.erase(tickets.begin() + index);
}
std::unique_ptr<Vehicle>& CAT::find(string regNumber)
{
	auto it =std::find_if(vehicles.begin(), vehicles.end(), [&](const std::unique_ptr<Vehicle>&x)
		{
			return x->getRegistrtionNumber() == regNumber;
		});

	if (it != vehicles.end())
	{
		return *it;
	}
	else
	{
		throw std::logic_error("This vehicle don't exist!!!");
	}
}
vector<Ticket> CAT::findAllTickets(const Vehicle& vehicle)
{
	vector<Ticket> v;
	for (Ticket t : tickets)
	{
		if (t.getRegistrtionNumber() == vehicle.getRegistrtionNumber())
		{
			v.push_back(t);
		}
	}
	if (v.size() == 0)
	{
		throw std::logic_error("Registration number don't exist!!!");
	}
	return v;
}
vector<Ticket> CAT::findAllTicketsWithCondition(std::function<bool(const Ticket& ticket, int maxOrMin)> z)
{
	vector<Ticket> v;
	for (Ticket t : tickets)
	{
		if (z)
		{
			v.push_back(t);
		}
	}
	if (v.size() == 0)
	{
		throw std::logic_error("No tickets compleate this condition!!!");
	}
	return v;
}
vector<std::unique_ptr<Vehicle>> CAT::findAllVehiclesWithCondition(std::function<bool(const Vehicle& vehicle, int maxOrMin)> z)
{
	vector<std::unique_ptr<Vehicle>> v;
	for (std::unique_ptr<Vehicle>& vehicle:vehicles)
	{
		if (z)
		{
			v.push_back(vehicle);
		}
	}
	if (v.size() == 0)
	{
		throw std::logic_error("No tickets compleate this condition!!!");
	}
	return v;
}