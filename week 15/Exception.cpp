#include "Exception.h"
Exception::Exception(string msg)
{
	this->msg = msg;
}
Exception::Exception() { }

void Exception::Invalid_argument(Exception ex)
{
	cout<<msg<<endl;
}