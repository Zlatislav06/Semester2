#pragma once
#include "MyFile.h";
#include "Addble.h";
#include "Nullable.h";
class StandardFile :public MyFile, public Nullable, public Addble
{
public:
	StandardFile();
	void printDetails() const override;
	void null() override;
	void add(string toAdd) override;
};

