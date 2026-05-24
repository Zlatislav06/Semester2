#include "ConstantFile.h"
ConstantFile::ConstantFile():MyFile(data)
{
	
}
void ConstantFile::printDetails() const
{
	cout << "Constant file - cannot be changed";
}
ConstantFile& ConstantFile::getInstance()
{
	static ConstantFile instance;
	return instance;

}
