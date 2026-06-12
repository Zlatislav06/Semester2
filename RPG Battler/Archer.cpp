#include "Archer.h"
Archer::Archer(string n, string un) :PlayerCharacter(n, un, HeroType::Archer)
{
	HP = ARHP;
	maxHP = ARHP;
	damage = ARDAMAGE;
	level = 1;
}
Archer::Archer(string n, string un, int h, int max, int d, int l) :PlayerCharacter(n, un, h,max, d, l, HeroType::Archer) { }

int Archer::Attack(PlayerCharacter& P)
{
	string check = "";
	srand(time(nullptr));
	int attack = (rand() % damage) + 1;
	setColor(Color::LightRed);
	cout << "The archer " << name << " shoot at " << P.getName() << " with " << attack << " damage" << endl;
	setColor(Color::White);
	string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	if (usingItems[(int)ItemsType::Blade] == true)
	{
		Blade blade = {};
		attack = blade.UseItem(P, inf);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	if (attack <= 4)
	{
		cout << "Do you want to use special move?(y/n)(Yes/No)" << endl;
		cin >> check;
		while (true)
		{
			if (check == "Yes" || check == "y" || check == "Y")
			{
				string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
				if (usingItems[(int)ItemsType::Ray] == true)
				{
					Ray ray = {};
					ray.UseItem(P,inf);
				}
				CastFromStringToVectorOrAttack(inf, usingItems);
				if (P.usingItems[(int)ItemsType::Mirror] != true)
				{
					attack = Speshal(attack);
					inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
				}
				else
				{
					Mirror mirror = {};
					mirror.UseItem(P,inf);
				}
				CastFromStringToVectorOrAttack(inf, usingItems);
				if (usingItems[(int)ItemsType::Blade] == true)
				{
					Blade blade = {};
					attack = blade.UseItem(P,inf);
				}
				CastFromStringToVectorOrAttack(inf, usingItems);
				setColor(Color::LightPurple);
				cout << name << " will use special move and now, he will shoot at " << P.getName() << " with " << attack << " damage!" << endl;
				setColor(Color::White);
				break;
			}
			else if (check == "No" || check == "n" || check == "N")
			{
				cout << name << " don't want to use special move!!!" << endl;
				break;
			}
			else
			{
				throw Exceptions("Invlaid command!!!");
			}
		}
	}
	else
	{
		setColor(Color::Red);
		cout << "Archer can't use his special move!!!"<<endl;
		setColor(Color::White);
	}
	return attack;
	

}
int Archer::Speshal(int a)
{
	return a * 2;
}
void Archer::TakeDamage(PlayerCharacter& P, int attack)
{
	string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	if (usingItems[(int)ItemsType::Shield] == true)
	{
		Shield shield = {};
		attack=shield.UseItem(*this,inf);

	}
	setHP(getHP() - attack);
}