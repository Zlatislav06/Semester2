#include "Merger.h"
Merger::Merger(Cart cart):cart1(cart) { }
void Merger::applayTo(Cart cart)
{
	for (Product x : cart1.getInvantory())
	{
		cart.add(x, 1);
	}
}