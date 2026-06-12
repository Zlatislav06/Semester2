#pragma once
#include "Items.h"
class Ray :public Items
{
public:
	Ray();
	int UseItem(PlayerCharacter& P, string& str) override;

};

