#include "Ticket.h"
Ticket::Ticket(string regNumber, double m, string d, bool i)
{
	setRegistrtionNumber(regNumber);
	setMoney(m);
	data = d;
	isPaid = i;
}
const string& Ticket::getRegistrtionNumber() const
{
	return registrationNumber;
}
const double& Ticket::getMoney() const
{
	return money;
}
const string& Ticket::getData() const
{
	return data;
}
const string& Ticket::getPayment() const
{
	return payment;
}
const bool& Ticket::getIsPaid() const
{
	return isPaid;
}
void Ticket::setRegistrtionNumber(const string& regNumber)
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
void Ticket::setMoney(const double& m)
{
	if (m >= 0)
	{
		money = m;
	}
	else
	{
		throw std::invalid_argument("Money for ticket can't be less then zero!!!");
	}
}
void Ticket::setData(const string& d)
{
	data = d;
}
void Ticket::setPayment(const string& p)
{
	payment = p;
}
void Ticket::setIsPaid(const bool& ispaid)
{
	isPaid = ispaid;
}