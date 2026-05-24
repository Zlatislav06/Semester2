#pragma once
#include<vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include "MyFile.h";
#include "Addble.h";
#include "Nullable.h";
using std::cout;
using std::cin;
using std::string;
using std::endl;
class FileSystem
{
private:
	std::vector<std::unique_ptr<MyFile>> fileSystem;
public:
	void printAllDetails();
	void addFile(std::unique_ptr<MyFile> file);
	void removeFile(int index);
};

