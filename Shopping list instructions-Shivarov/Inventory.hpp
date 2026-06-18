#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <typename T>
class Inventory
{
protected:
	vector<T> inventory;
	unsigned int size = 0;
	vector<T> SerchUniqueElements();
public:
	Inventory();
	Inventory(vector<T> inventory, unsigned int size);
	void add(const T& item, unsigned int size);
	void remove(const T& item, unsigned int size);
	bool isThisItemPresentInInventory(const T& item);
	unsigned int countOfUniqueItems();
	unsigned int count();
	bool isEmty();
	const unsigned int& getSize() const;
	void setSize(const unsigned int& size);
	const vector<T>& getInvantory() const;
	int operator [](const T& item);
	Inventory<T>& operator+=(const T& item);
	Inventory<T>& operator-=(const T& item);
	Inventory<T> operator ++(int index);
	Inventory<T>& operator ++();
	Inventory<T> operator --(int index);
	Inventory<T>& operator --();
};
template <typename T>
Inventory<T> operator+(const Inventory<T>& item1, const Inventory<T>& item2);
template <typename T>
vector<T> Inventory<T>::SerchUniqueElements()
{
	vector<T> v;
	for (T z:inventory)
	{
		auto it = std::find_if(v.begin(), v.end(), [&](const T& x)
			{
				return x == z;
			});
		if (it == v.end())
		{
			v.push_back(z);
		}
	}
	return v;
}
template <typename T>
Inventory<T>::Inventory()
{
	vector<T> v;
	inventory = v;
	size = 0;
}
template <typename T>
Inventory<T>::Inventory(vector<T> inventory, unsigned int size)
{
	this->inventory = inventory;
	this->size = size;
}
template <typename T>
void Inventory<T>::add(const T& item, unsigned int size)
{
	if (size <= 0)
	{
		throw std::invalid_argument("Count of items who you want to add in inventory can't be zero or less!!!");
	}
	for (int i = 0; i < size; i++)
	{
		inventory.push_back(item);
	}
	this->size += size;
}
template <typename T>
void Inventory<T>::remove(const T& item, unsigned int size)
{
	if (size <= 0)
	{
		throw std::invalid_argument("Count of items who you want to reomve from inventory can't be zero or less!!!");
	}
	int removedItems = std::erase_if(inventory, [&](const T& x)
		{
			return item == x;
		});
	this->size -= removedItems;
	if (removedItems > size)
	{
		inventory.add(item,removedItems-size);
		
	}
	if (removedItems < size)
	{
		throw std::invalid_argument("Don't have so match items!!!");
		
	}
	
}
template <typename T>
bool Inventory<T>::isThisItemPresentInInventory(const T& item)
{
	auto it = std::find_if(inventory.begin(), inventory.end(), [&](const T& x)
		{
			return x == item;
		});
	if (it == inventory.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
template <typename T>
unsigned int Inventory<T>::countOfUniqueItems()
{
	
	
	return SerchUniqueElements().size();
}
template <typename T>
unsigned int Inventory<T>::count()
{
	return inventory.size();
}
template <typename T>
bool Inventory<T>::isEmty()
{
	bool check = false;
	if (inventory.size() == 0)
	{
		check = true;
	}
	return check;
}
template <typename T>
const unsigned int& Inventory<T>::getSize() const
{
	return size;
}
template <typename T>
void Inventory<T>::setSize(const unsigned int& size)
{
	this->size = size;
}
template <typename T>
const vector<T>& Inventory<T>::getInvantory() const
{
	return inventory;
}
template <typename T>
int Inventory<T>::operator [](const T& item)
{
	int br = 0;
	for (T x:inventory)
	{
		if (item == x)
		{
			br++;
		}
	}
	return br;
}
template <typename T>
Inventory<T>& Inventory<T>::operator+=(const T& item)
{
	inventory.push_back(item);
	this->size++;
	return *this;
}
template <typename T>
Inventory<T>& Inventory<T>::operator-=(const T& item)
{
	remove(item, 1);
	return *this;
}
template <typename T>
Inventory<T> Inventory<T>::operator ++(int index)
{
	Inventory<T> I(*this);
	++(*this);
	return I;
}
template <typename T>
Inventory<T>& Inventory<T>::operator ++()
{
	vector<T> v = SerchUniqueElements();
	for (T x:v)
	{
		inventory.push_back(x);
		this->size++;

	}
	return *this;
}
template <typename T>
Inventory<T> Inventory<T>::operator --(int index)
{
	Inventory<T> I(*this);
	--(*this);
	return I;
}
template <typename T>
Inventory<T>& Inventory<T>::operator --()
{
	vector<T> v = SerchUniqueElements();
	for (T x:v)
	{
		remove(x,1);
	}
	return *this;
}
template <typename T>
Inventory<T> operator+(const Inventory<T>& item1, const Inventory<T>& item2)
{
	Inventory<T> I;
	for (T x:item1)
	{
		I.add(x, 1);
	}
	for (T x:item2)
	{
		I.add(x, 1);
	}
	return I;
}