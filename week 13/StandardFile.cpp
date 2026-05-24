#include "StandardFile.h"
StandardFile::StandardFile():MyFile(data)
{

}
void StandardFile::printDetails() const
{
	cout << "Standard file - data can be added and deleted";
}
void StandardFile::null()
{
	data = "";
}
void StandardFile::add(string toAdd)
{
	data += toAdd;
}