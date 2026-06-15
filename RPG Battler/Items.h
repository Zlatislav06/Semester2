#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
class PlayerCharacter;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
enum class ItemsType
{
	HealingPoltion=0,
	Blade,
	Mirror,
	Ray,
	Shield
};
class Items
{
protected:
	ItemsType type;
	bool speshalEffecct = false;
	int prize;
	
public:
	Items(ItemsType t, bool se, int p);
	const ItemsType& getType() const;
	const bool& getSpeshalEffecct() const;
	const int& getPrize() const;
	void setType(ItemsType t);
	void setSpeshalEffecct(bool spe);
	void setPrize(int p);
	virtual int UseItem(PlayerCharacter& P,string& str);
	string ConvertItemTypeToString();
	//virtual int UseAttackOrDefenseItem(vector<bool>& use,int attack)=0;
	virtual ~Items() = default;
};

