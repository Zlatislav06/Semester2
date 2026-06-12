#pragma once
#include "Items.h"
class Blade:public Items
{
public:
	Blade();
	int UseItem(PlayerCharacter& P, string& str) override;
	
};

