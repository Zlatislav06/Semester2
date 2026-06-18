#include "ChangeProduct.h"
ChangeProduct::ChangeProduct(Product p1, Product p2):product1(p1),product2(p2) { }
void ChangeProduct::applayTo(Cart cart)
{
	int countOfProduct = cart[product1];
	cart.remove(product1,countOfProduct);
	cart.add(product2, countOfProduct);
}