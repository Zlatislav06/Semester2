#pragma once
#include "PlayerCharacter.h"
class Mage:public PlayerCharacter
{
public:
	Mage(string n, string un);
	Mage(string n, string un, int h,int max, int d, int l);
	int Attack(PlayerCharacter& P) override;
	int Speshal(int a) override;
	void TakeDamage(PlayerCharacter& P, int attack) override;
};

