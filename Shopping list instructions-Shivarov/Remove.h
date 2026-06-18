#pragma once
#include "ShoppingInstruction.h"
class Remove :public ShoppingInstruction
{
private:
	Product product;
	unsigned int amount;
public:
	Remove(Product product, unsigned int amount);
	void applayTo(Cart cart) override;
};


