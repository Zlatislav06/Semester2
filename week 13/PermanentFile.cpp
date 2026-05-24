#include "PermanentFile.h"
PermanentFile::PermanentFile():MyFile(data)
{
	if (data != "")
	{
		this->data = data;
	}
}
void PermanentFile::printDetails() const
{
	cout << "Permanent file - data cannot be deleted"<<endl;
}
void PermanentFile::add(string toAdd)
{
	data += toAdd;
}