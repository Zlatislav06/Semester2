#pragma once
#include "Items.h"

class HealingPoltion :public Items
{
public:
	HealingPoltion();
	int UseItem(PlayerCharacter& P,string& str) override;
};

