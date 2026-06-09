#include "HealingPoltion.h"
#include "PlayerCharacter.h"
const int HPPRIZE = 30;
const int MAXHEAL = 10;
const int MINHEAL = 5;
HealingPoltion::HealingPoltion() :Items(ItemsType::HealingPoltion, false, HPPRIZE) { }



int HealingPoltion::UseItem(PlayerCharacter& P,string& str)
{
	if (P.usingItems[(int)type] == true)
	{
		srand(time(nullptr));
		int heal = (rand() % MINHEAL + 1);
		heal += MAXHEAL - MINHEAL;
		if (P.getHP() + heal >= P.getMaxHP())
		{
			P.setHP(P.getMaxHP());
		}
		else
		{
			P.setHP(P.getHP() + heal);
		}
		P.usingItems[(int)type] = false;
		return 1;
	}
	else
	{
		return 0;
	}
	
}