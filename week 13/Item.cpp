#include "Item.h"
Item::Item(string n) 
{
	name = n;
}
const string& Item::getName() const
{
	return name;
}
void Item::setName(string n)
{
	name = n;
}