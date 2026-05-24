#include "MyFile.h"
MyFile::MyFile(string data)
{
	this->data = data;
}
const string& MyFile::getData() const
{
	return data;
}
void MyFile::setData(string d)
{
	data = d;
}
