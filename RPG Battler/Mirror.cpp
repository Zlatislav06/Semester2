#include "Mirror.h"
#include "PlayerCharacter.h"
const int MPRIZE = 80;
Mirror::Mirror():Items(ItemsType::Mirror, false, MPRIZE) { }

int Mirror::UseItem(PlayerCharacter& P, string& str)
{
	int attack = 0;
	vector<bool> v = { false,false,false,false,false };
	attack = CastFromStringToVectorOrAttack(str, v);
	if (P.usingItems[(int)type] == true)
	{
		setColor(Color::Aqua);
		cout << "The opponent use a Mirror!" << endl;
		setColor(Color::White);
		P.usingItems[(int)type] = false;
		v[(int)type] = false;
		return 0;
	}
	else
	{
		return 1;
	}
}