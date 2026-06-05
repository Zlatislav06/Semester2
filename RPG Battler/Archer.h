#pragma once
#include "PlayerCharacter.h"
class Archer :public PlayerCharacter
{
public:
	Archer(string n, string un);
	Archer(string n, string un, int h, int max, int d, int l);
	void Attack(PlayerCharacter& P) override;
	int Speshal(int a) override;
	void TakeDamage(PlayerCharacter& P, int attack) override;
};

