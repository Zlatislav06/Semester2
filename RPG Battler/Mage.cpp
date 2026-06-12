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
	setColor(Color::LightRed);
	cout << "The mage " << name << " struck " << P.getName() << " with " << attack << " damage" << endl;
	setColor(Color::White);

	string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	
	CastFromStringToVectorOrAttack(inf, usingItems);
	cout << "Do you want to use special move?(y/n)(Yes/No)" << endl;
	cin >> check;
	while (true)
	{
			if (check == "Yes" || check == "y" || check == "Y")
			{
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
				
				
				setColor(Color::LightPurple);
				cout << name << " will use special move and now, he will struck " << P.getName() << " with " << attack << " damage!" << endl;
				setColor(Color::White);
				break;
			}
			else if (check == "No" || check == "n" || check == "N")
			{
				setColor(Color::Red);
				cout << name << " don't want to use special move!!!" << endl;
				setColor(Color::White);
				break;
			}
			else
			{
				throw Exceptions("Invlaid command!!!");
			}

			
	}
	if (usingItems[(int)ItemsType::Blade] == true)
	{
				Blade blade = {};
				attack = blade.UseItem(P, inf);
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
		attack = shield.UseItem(*this, inf);
	}
	setHP(getHP() - attack);
}