#include "Items.h"
#include "PlayerCharacter.h"
Items::Items(ItemsType t, bool se, int p)
{
	type = t;
	speshalEffecct = se;
	prize = p;
}
const ItemsType& Items::getType() const
{
	return type;
}
const bool& Items::getSpeshalEffecct() const
{
	return speshalEffecct;
}
const int& Items::getPrize() const
{
	return prize;
}
void Items::setType(ItemsType t)
{
	switch (t)
	{
		case ItemsType::HealingPoltion: 
		{
		}
		case ItemsType::Blade:
		{
		}
		case ItemsType::Mirror:
		{
		}
		case ItemsType::Ray:
		{
		}
		case ItemsType::Shield:
		{
			type = t;
			break;
		}
		default:
		{
			throw Exceptions("Invalid value!!!");
			break;
		}
			
	}
}
void Items::setSpeshalEffecct(bool spe)
{
	speshalEffecct=spe;
}
void Items::setPrize(int p)
{
	prize = p;
}
string Items::ConvertItemTypeToString()
{
	string iType = "";
	switch (type)
	{
	case ItemsType::HealingPoltion:
	{
		iType = "HealingPoltion";
		break;
	}
	case  ItemsType::Blade:
	{
		iType = "Blade";
		break;
	}
	case  ItemsType::Mirror:
	{
		iType = "Mirror";
		break;
	}
	case  ItemsType::Ray:
	{
		iType = "Ray";
		break;
	}
	case  ItemsType::Shield:
	{
		iType = "Shield";
		break;
	}
	default:
	{
		throw Exceptions("Invalid value!!!");
		break;
	}
	}
	return iType;
}



int Items::UseItem(PlayerCharacter& P, string& str)
{
	return 1;
}
