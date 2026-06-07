#include "Archer.h"
const int ARHP = 15;
const int ARDAMAGE = 8;
Archer::Archer(string n, string un) :PlayerCharacter(n, un, HeroType::Archer)
{
	HP = ARHP;
	maxHP = ARHP;
	damage = ARDAMAGE;
	level = 1;
}
Archer::Archer(string n, string un, int h, int max, int d, int l) :PlayerCharacter(n, un, h,max, d, l, HeroType::Archer) { }

void Archer::Attack(PlayerCharacter& P)
{
	string check = "";
	srand(time(nullptr));
	int attack = (rand() % damage) + 1;
	cout << "The archer " << name << " can shoot at " << P.getName() << "with " << attack << " damage" << endl;

	if (attack <= 4)
	{
		cout << "Do you want to use special move?(y/n)(Yes/No)" << endl;
		cin >> check;
		while (true)
		{
			if (check == "Yes" || check == "y" || check == "Y")
			{
				string inf = attack + "\n" + ConvertVectorToString(usingItems, COUNTOFITEMS);
				if (usingItems[(int)ItemsType::Ray] == true)
				{
					Ray ray = {};
					ray.UseItem(P,inf);
				}
				CastFromStringToVectorOrAttack(inf, usingItems);
				if (P.usingItems[(int)ItemsType::Mirror] != true)
				{
					attack = Speshal(attack);
				}
				else
				{
					Mirror mirror = {};
					mirror.UseItem(P,inf);
				}
				if (usingItems[(int)ItemsType::Blade] == true)
				{
					Blade blade = {};
					attack = blade.UseItem(P,inf);
				}
				CastFromStringToVectorOrAttack(inf, usingItems);
				cout << name << "will use speshal move and now, he will shoot at " << P.getName() << "with " << attack << " damage" << endl;;
				break;
			}
			else if (check == "No" || check == "n" || check == "N")
			{
				cout << name << "don't want to use speshal move!!!" << endl;
				break;
			}
			else
			{
				cout << "Invalid command!!!" << endl;
			}
		}
	}
	else
	{
		cout << "Archer can't use his speshal move!!!";
	}
	TakeDamage(P, attack);

}
int Archer::Speshal(int a)
{
	return a * 2;
}
void Archer::TakeDamage(PlayerCharacter& P, int attack)
{
	string inf = attack + "\n" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	if (usingItems[(int)ItemsType::Shield] == true)
	{
		Shield shield = {};
		attack=shield.UseItem(P,inf);

	}
	P.setHP(P.getHP() - attack);
}