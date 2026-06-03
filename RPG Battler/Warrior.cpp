#include "Warrior.h"
const int WHP=20;
const int WDAMAGE = 8;
const int PROTECTION = 4;
Warrior::Warrior(string n, string un):PlayerCharacter(n,un,HeroType::Warrior)
{
	HP = WHP;
	maxHP = WHP;
	damage = WDAMAGE;
	leval = 1;
}
Warrior::Warrior(string n, string un, int h, int max, int d, int l) :PlayerCharacter(n, un, h, max, d, l, HeroType::Warrior) { }

void Warrior::Attack(PlayerCharacter& P)
{
	string check = "";
	srand(time(nullptr));
	int attack = (rand() % damage) + 1;
	string inf = attack + "\n" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	if (usingItems[(int)ItemsType::Blade] == true)
	{
		Blade blade = {};
		attack = blade.UseItem(P, inf);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	cout << "The warrior " << name << " can slash " << P.getName() << "with " << attack << " damage" << endl;
	TakeDamage(P,attack);
}
int Warrior::Speshal(int a)
{
	int protection = (rand() % PROTECTION) + 1;
	if (a - protection <= 0)
	{
		a = 0;
	}
	else
	{
		a = a - protection;
	}
	cout << "The worrior defended himself with " << protection << " from the enemy's attack!" << endl;
	cout << "And now the attack is " << a << " damage" << endl;
	return a;
}
void Warrior::TakeDamage(PlayerCharacter& P, int attack)
{
	string inf = attack + "\n" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	int newAttack = attack;
	if (usingItems[(int)ItemsType::Ray] == true)
	{
		Ray ray = {};
		ray.UseItem(P,inf);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	if (usingItems[(int)ItemsType::Shield] == true)
	{
		Shield shield = {};
		newAttack = shield.UseItem(P, inf);
	}
	if (P.usingItems[(int)ItemsType::Mirror] != true)
	{
		newAttack = Speshal(attack);
	}
	else
	{
		Mirror mirror = {};
		mirror.UseItem(P,inf);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	P.setHP(P.getHP() - newAttack);
}