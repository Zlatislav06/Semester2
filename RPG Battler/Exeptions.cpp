#include "Exeptions.h"
void setColor(Color color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)color);
}
Exceptions::Exceptions(const string& msg)
{
	message = msg;
}
void Exceptions::ShowError(const Exceptions& ex)
{
	setColor(Color::Red);
	cout << ex.what() << endl;
	setColor(Color::White);
}
const char* Exceptions::what() const noexcept
{
	return message.c_str();
}