#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

enum class ProductType
{
	Food, 
	Drink, 
	Household, 
	PersonalCare
};
class Product
{
private:
	string name;
	double prize=0;
	ProductType category;
public:
	Product(const string& name, double prize, ProductType category);
	bool operator ==(const Product& P);
	const string& getName() const;
	const double& getPrize() const;
	const ProductType& getCategory() const;
	void setName(string name);
	void setPrize(double prize);
	void setCategory(ProductType category);


};

