#include "ShoppingPlan.h"
ShoppingPlan::ShoppingPlan() { }
ShoppingPlan::ShoppingPlan(Cart cart):cart(cart) { }
void ShoppingPlan::addInstruction(std::unique_ptr <ShoppingInstruction>& instruction)
{
	instructions.push_back(instruction);
}
void ShoppingPlan::removeInstruction(int index)
{
	instructions.erase(instructions.begin()+index);
}
void ShoppingPlan::excecute()
{
	for (std::unique_ptr<ShoppingInstruction>& x : instructions)
	{
		x->applayTo(cart);
	}
}
unsigned int ShoppingPlan::count()
{
	return instructions.size();
}
const Cart& ShoppingPlan::getCart() const
{
	return cart;
}