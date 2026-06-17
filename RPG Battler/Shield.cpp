#include "Shield.h"
#include "PlayerCharacter.h"
const int SPRIZE = 100;
Shield::Shield():Items(ItemsType::Shield, true, SPRIZE) { }

int Shield::UseItem(PlayerCharacter& P, string& str)
{
	int attack = 0;
	vector<bool> v = { false,false,false,false,false };
	attack = CastFromStringToVectorOrAttack(str, v);
	if (P.usingItems[(int)type] == true)
	{
		setColor(Color::Aqua);
		cout << "The player use a Shield and don't take damage!" << endl;
		setColor(Color::White);
		P.usingItems[(int)type] = false;
		v[(int)type] = false;
		string inf = std::to_string(attack) + ";" + ConvertVectorToString(v, COUNTOFITEMS);
		str = inf;
		return 0;
	}
	else
	{
		
		return attack;
	}

}