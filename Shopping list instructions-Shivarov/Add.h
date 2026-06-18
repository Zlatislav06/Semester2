#pragma once
#include "ShoppingInstruction.h"
class Add:public ShoppingInstruction
{
private:
	Product product;
	unsigned int amount;
public:
	Add(Product product, unsigned int amount);
	void applayTo(Cart cart) override;
};

