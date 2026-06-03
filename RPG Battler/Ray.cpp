#include "Ray.h"
#include "PlayerCharacter.h"
const int RPRIZE = 90;
Ray::Ray():Items(ItemsType::Ray, true, RPRIZE) { }

int Ray::UseItem(PlayerCharacter& Opponent, string& str)
{
	vector<bool> v = { false };
	int attack=CastFromStringToVectorOrAttack(str, v);
	if (v[(int)type] == true)
	{
		setColor(Color::Aqua);
		cout << "You use Ray to break a opponent's mirror!" << endl;
		setColor(Color::White);
		Opponent.usingItems[(int)ItemsType::Mirror] = false;
		v[(int)type] = false;
		string inf = attack + "\n" + ConvertVectorToString(v, COUNTOFITEMS);
		str = inf;
	}

	return 0;
}