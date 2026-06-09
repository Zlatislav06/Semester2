#include "Mage.h"

Mage::Mage(string n, string un):PlayerCharacter(n,un,HeroType::Mage)
{
	HP = MHP;
	maxHP = MHP;
	damage = MDAMAGE;
	level = 1;
}
Mage::Mage(string n, string un, int h, int max, int d, int l) :PlayerCharacter(n, un, h, max, d, l, HeroType::Mage) { }

int Mage::Attack(PlayerCharacter& P)
{
	string check = "";
	srand(time(nullptr));
	int attack = (rand() % damage) + 1;
	cout << "The mage " << name << " struck " << P.getName() << " with " << attack << " damage" << endl;
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
				}
				else
				{
					Mirror mirror = {};
					mirror.UseItem(P,inf);
				}
				if (usingItems[(int)ItemsType::Blade] == true)
				{
					Blade blade = {};
					attack = blade.UseItem(P, inf);
				}
				CastFromStringToVectorOrAttack(inf, usingItems);
				cout << name << " will use special move and now, he will struck " << P.getName() << " with " << attack << " damage!" << endl;
				break;
			}
			else if (check == "No" || check == "n" || check == "N")
			{
				cout << name << " don't want to use special move!!!" << endl;
				break;
			}
			else
			{
				setColor(Color::Red);
				cout << "Invalid command!!!" << endl;
				setColor(Color::White);
			}
	}
	return attack;
	
}
int Mage::Speshal(int a)
{
	return damage - a;
}
void Mage::TakeDamage(PlayerCharacter& P, int attack)
{
	string useShield = "";
	string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	if (usingItems[(int)ItemsType::Shield] == true)
	{
		Shield shield = {};
		attack = shield.UseItem(P, inf);
	}
	setHP(getHP() - attack);
}