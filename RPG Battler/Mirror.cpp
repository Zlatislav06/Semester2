#include "Mirror.h"
#include "PlayerCharacter.h"
const int MPRIZE = 80;
Mirror::Mirror():Items(ItemsType::Mirror, false, MPRIZE) { }

int Mirror::UseItem(PlayerCharacter& P, string& str)
{
	
	if (P.usingItems[(int)type] == true)
	{
		setColor(Color::Aqua);
		cout << "The opponent use a Mirror!" << endl;
		setColor(Color::White);
		P.usingItems[(int)type] = false;
		return 0;
	}
	else
	{
		return 1;
	}
}