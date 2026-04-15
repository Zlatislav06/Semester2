#pragma once
class Calculator
{
private:
	Calculator() {}

public:
	static Calculator& getInstance();
	double sum(double first, double second);
	double substeact(double first, double second);
	double multiply(double first, double second);
	double divide(double first, double second);
	Calculator(const Calculator&) = delete;
	Calculator& operator=(const Calculator&) = delete;
};
