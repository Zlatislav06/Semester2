#pragma once
#include "Items.h"
class Shield :public Items
{
public:
	Shield();
	int UseItem(PlayerCharacter& P, string& str) override;

};

