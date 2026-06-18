#pragma once
#include "Cart.h"
Product createProduct();
Cart createCart();
ProductType ConvertStringToProductType(string str);
class ShoppingInstruction
{
private:
	
public:

	virtual void applayTo(Cart cart)=0;
	static std::unique_ptr<ShoppingInstruction> create(const string& str);
	virtual ~ShoppingInstruction() = default;
};

