#pragma once
#include "MyFile.h"
#include "Addble.h"
class PermanentFile:public Addble,public MyFile
{
public:
	PermanentFile();
	void printDetails() const override;
	void add(string toAdd) override;
};

