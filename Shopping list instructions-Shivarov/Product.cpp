#include "Product.h"
Product::Product(const string& name, double prize, ProductType category)
{
	this->name = name;
	setPrize(prize);
	this->category = category;
}
bool Product::operator ==(const Product& P)
{
	bool check = false;
	if (name == P.name)
	{
		if (prize == P.prize)
		{
			if (category == P.category)
			{
				check = true;
			}
		}
	}
	return check;
}
const string& Product::getName() const
{
	return name;
}
const double& Product::getPrize() const
{
	return prize;
}
const ProductType& Product::getCategory() const
{
	return category;
}
void Product::setName(string name)
{
	this->name = name;
}
void Product::setPrize(double prize)
{
	if (prize >= 0)
	{
		this->prize = prize;
	}
	else
	{
		throw std::invalid_argument("Prize can't be less then zero");
	}
}
void Product::setCategory(ProductType category)
{
	this->category = category;
}