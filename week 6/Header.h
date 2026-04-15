#pragma once
class Temperature
{
private:
	int temperature;
	char system;

public:
	Temperature(double t,char s);
	double getTemperature();
	void setTemperature(double t);
	char getSystem();
	void setSystem(char s);
	bool operator==(const Temperature& T1);
	bool operator<(const Temperature& T1);
	bool operator>(const Temperature& T1);
	bool operator!=(const Temperature& T1);
	Temperature operator+(const Temperature& T1);
	Temperature operator-(const Temperature& T1);
	Temperature& operator+=(const Temperature& T1);
	Temperature& operator-=(const Temperature& T1);
};