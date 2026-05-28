#pragma once
#include "Ticket.h"
#include "Vehicle.h"
#include <vector>
#include <algorithm>
#include <functional>
using std::vector;
class CAT
{
private:
	vector<std::unique_ptr<Vehicle>> vehicles;
	vector<Ticket> tickets;
public:
	void add(const Vehicle& vehicle);
	void add(const Ticket& ticket);
	void removeVehicle(int index);
	void removTicket(int index);
	std::unique_ptr<Vehicle>& find(string regNumber);
	vector<Ticket> findAllTickets(const Vehicle& vehicle);
	vector<Ticket> findAllTicketsWithCondition(std::function<bool(const Ticket& ticket,int maxOrMin)> z);
	vector<std::unique_ptr<Vehicle>> findAllVehiclesWithCondition(std::function<bool(const Vehicle& vehicle,int maxOrMin)> z);

};

