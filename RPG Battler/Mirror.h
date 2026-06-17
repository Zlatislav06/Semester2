#pragma once
#include "Items.h"
class Mirror :public Items
{
public:
	Mirror();
	int UseItem(PlayerCharacter& P, string& str) override;
};

