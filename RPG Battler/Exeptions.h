#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
enum class Color
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Aqua = 3,
	Red = 4,
	Purple = 5,
	Yellow = 6,
	White = 7,
	Gray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightAqua = 11,
	LightRed = 12,
	LightPurple = 13,
	LightYellow = 14,
	BrightWhite = 15
};
void setColor(Color color);

class Exeptions:public std::exception
{
private:
	string message;
public:
	Exeptions(const string& msg);
	static void ShowError(const Exeptions& ex);
	const char* what() const noexcept override;
};

