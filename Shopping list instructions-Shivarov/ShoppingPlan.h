#pragma once
#include "Cart.h"
#include "ShoppingInstruction.h"
class ShoppingPlan
{
private:
	Cart cart;
	vector<std::unique_ptr<ShoppingInstruction>> instructions;
public:
	ShoppingPlan();
	ShoppingPlan(Cart cart);
	void addInstruction(std::unique_ptr <ShoppingInstruction>& instruction);
	void removeInstruction(int index);
	void excecute();
	unsigned int count();
	const Cart& getCart() const;

};

