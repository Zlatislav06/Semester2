#pragma once
#include "PlayerCharacter.h"
class Warrior:public PlayerCharacter
{
public:
	Warrior(string n, string un);
	Warrior(string n, string un, int h, int max, int d, int l);
	int Attack(PlayerCharacter& P) override;
	int Speshal(int a) override;
	void TakeDamage(PlayerCharacter& P, int attack) override;
};

