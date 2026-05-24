#include "FileSystem.h"
void FileSystem::printAllDetails()
{
	for (std::unique_ptr<MyFile>& file : fileSystem)
	{
		file->printDetails();
	}
}
void FileSystem::addFile(std::unique_ptr<MyFile> file)
{
	fileSystem.push_back(move(file));
}
void FileSystem::removeFile(int index)
{
	fileSystem.erase(fileSystem.begin() + index);
}