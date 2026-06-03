#include "Exeptions.h"
void setColor(Color color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)color);
}
Exeptions::Exeptions(const string& msg)
{
	message = msg;
}
void Exeptions::ShowError(const Exeptions& ex)
{
	setColor(Color::Red);
	cout << ex.what() << endl;
	setColor(Color::White);
}
const char* Exeptions::what() const noexcept
{
	return message.c_str();
}