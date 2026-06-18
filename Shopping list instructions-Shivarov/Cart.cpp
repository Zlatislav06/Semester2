#include "Cart.h"
Cart::Cart():Inventory<Product>() { }
Cart::Cart(vector<Product> inventory, unsigned int size):Inventory<Product>(inventory,size) { }
double Cart::getTotalPrice()
{
	double sum = 0;
	for (Product x:inventory)
	{
		sum += x.getPrize();
	}
	return sum;
}
double Cart::getTotalPriceByCategory(ProductType category)
{
	double sum = 0;
	for (Product x : inventory)
	{
		if (x.getCategory() == category)
		{
			sum += x.getPrize();
		}
	}
	return sum;

}