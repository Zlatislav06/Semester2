#pragma once
#include "ShoppingInstruction.h"
class ChangeProduct :public ShoppingInstruction
{
private:
	Product product1;
	Product product2;
public:
	ChangeProduct(Product p1,Product p2);
	void applayTo(Cart cart) override;
};
