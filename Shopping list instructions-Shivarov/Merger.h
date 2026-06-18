#pragma once
#include "ShoppingInstruction.h"
class Merger :public ShoppingInstruction
{
private:
	Cart cart1;
public:
	Merger(Cart cart);
	void applayTo(Cart cart) override;
};