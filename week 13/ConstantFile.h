#pragma once
#include "MyFile.h";
class ConstantFile:public MyFile
{
private:
	ConstantFile();
	ConstantFile(const ConstantFile&) = delete;
	ConstantFile& operator=(const ConstantFile&) = delete;
public:
	
	static ConstantFile& getInstance();
	void printDetails() const override;
};

