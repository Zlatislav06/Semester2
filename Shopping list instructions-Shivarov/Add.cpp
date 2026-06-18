#include "Add.h"
Add::Add(Product product, unsigned int amount) :product(product), amount(amount) { }
void Add::applayTo(Cart cart)
{
	cart.add(product, amount);
}