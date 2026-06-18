#include "Remove.h"
Remove::Remove(Product product, unsigned int amount) :product(product), amount(amount) { }
void Remove::applayTo(Cart cart)
{
	cart.remove(product, amount);
}