#include "Blade.h"
#include "PlayerCharacter.h"
const int BPRIZE = 50;
Blade::Blade():Items(ItemsType::Blade,false, BPRIZE) { }
int Blade::UseItem(PlayerCharacter& P, string& str)
{
	int attack = 0;
	vector<bool> v = { false,false,false,false,false };
	attack = CastFromStringToVectorOrAttack(str, v);
	setColor(Color::Green);
	cout << "Blade will make hero's attack from "<<attack<< " damage to "<<attack*2<<" damage!" << endl;
	setColor(Color::White);
	if (v[(int)type] == true)
	{
		v[(int)type] = false;
		string inf = std::to_string(attack) + ";" + ConvertVectorToString(v, COUNTOFITEMS);
		str = inf;
		return attack*2;
	}
	else
	{

		return attack;
	}
	
}

