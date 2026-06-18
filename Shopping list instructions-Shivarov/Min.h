#pragma once
#include "ShoppingInstruction.h"
class Min :public ShoppingInstruction
{
private:
	Product product;
	unsigned int minAmounth;
public:
	Min(Product product, unsigned int minAmounth);
	void applayTo(Cart cart) override;
};

