#include "Min.h"
Min::Min(Product product, unsigned int minAmounth) :product(product), minAmounth(minAmounth) { }
void Min::applayTo(Cart cart)
{
	int countOfProduct=cart[product];
	if (countOfProduct < minAmounth)
	{
		cart.add(product, minAmounth- countOfProduct);
	}
}