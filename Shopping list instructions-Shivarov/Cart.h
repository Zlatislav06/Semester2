#pragma once
#include "Inventory.hpp";
#include "Product.h";
class Cart:public Inventory<Product>
{
public:
	Cart();
	Cart(vector<Product> inventory, unsigned int size);
	double getTotalPrice();
	double getTotalPriceByCategory(ProductType category);
};

