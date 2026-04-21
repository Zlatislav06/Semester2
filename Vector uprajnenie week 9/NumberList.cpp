#include "NumberList.h"
void NumberList::addNum(int a)
{
	vector.push_back(a);
}
void NumberList::sortAsending()
{
	std::sort(vector.begin(), vector.end());
}
void NumberList::sortDesending()
{
	std::sort(vector.begin(), vector.end(),std::greater<int>());
}
void NumberList::printAll()
{
	for (int x : vector)
	{
		cout << x << " ";
	}
	cout << endl;
}