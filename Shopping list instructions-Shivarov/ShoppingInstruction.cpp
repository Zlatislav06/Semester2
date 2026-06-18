#include "ShoppingInstruction.h"
#include "Merger.h"
#include "Min.h"
#include "Remove.h"
#include "Add.h"
#include "ChangeProduct.h"
ProductType ConvertStringToProductType(string str)
{
	ProductType productType = ProductType::Food;
	if (str == "Food")
	{
		productType= ProductType::Food;
	}
	if (str == "Drink")
	{
		productType = ProductType::Drink;
	}
	if (str == "Household")
	{
		productType = ProductType::Household;
	}
	if (str == "PersonalCare")
	{
		productType = ProductType::PersonalCare;
	}
	return productType;
}
Product createProduct()
{
	string name = "";
	double prize = 0;
	string productType = "";
	cout << "Enter name of product:";
	cin >> name;
	cout << "Enter prize of product:";
	cin >> prize;
	cout << "Enter product type of product:";
	cin >> productType;
	return Product(name,prize,ConvertStringToProductType(productType));
}
Cart createCart()
{
	Cart cart = {};
	while(true)
	{
		string ready = "";
		Product product = createProduct();
		cart.add(product,1);
		cout << "Do you want to add another product?"<<endl;
		cin >> ready;
		if (ready == "yes" || ready == "y" || ready == "Yes")
		{
			break;
		}
		cout << endl;
	}
	return cart;

}
std::unique_ptr<ShoppingInstruction> ShoppingInstruction::create(const string& str)
{
	if (str == "merger")
	{
		Cart cart = createCart();
		return std::make_unique<Merger>(cart);
	}
	else
	{
		Product product1 = createProduct();
		if (str == "change_product")
		{
			Product product2 = createProduct();
			return std::make_unique<ChangeProduct>(product1,product2);
		}
		else
		{
			if (str == "min")
			{
				unsigned int min = 0;
				cout << "Minimum:";
				cin >> min;
				return std::make_unique<ChangeProduct>(product1, min);
			}
			else if (str == "add")
			{
				unsigned int amouth = 0;
				cout << "Amouth of items:";
				cin >> amouth;
				return std::make_unique<ChangeProduct>(product1, amouth);
			}
			else if (str == "remove")
			{
				unsigned int amouth = 0;
				cout << "Amouth of items:";
				cin >> amouth;
				return std::make_unique<ChangeProduct>(product1, amouth);
			}
			else
			{
				throw std::invalid_argument("Invalid instruction!!!");
			}
		}
		
		
	}

}