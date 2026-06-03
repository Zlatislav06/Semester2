#include "Blade.h"
#include "PlayerCharacter.h"
const int BPRIZE = 50;
Blade::Blade():Items(ItemsType::Blade,false, BPRIZE) { }
int Blade::UseItem(PlayerCharacter& P, string& str)
{
	int attack = 0;
	vector<bool> v = { false };
	attack = CastFromStringToVectorOrAttack(str, v);
	if (v[(int)type] == true)
	{
		v[(int)type] = false;
		string inf = attack + "\n" + ConvertVectorToString(v, COUNTOFITEMS);
		str = inf;
		return attack*2;
	}
	else
	{

		return attack;
	}
	
}

