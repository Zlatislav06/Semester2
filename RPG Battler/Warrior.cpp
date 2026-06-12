#include "Warrior.h"

Warrior::Warrior(string n, string un):PlayerCharacter(n,un,HeroType::Warrior)
{
	HP = WHP;
	maxHP = WHP;
	damage = WDAMAGE;
	level = 1;
}
Warrior::Warrior(string n, string un, int h, int max, int d, int l) :PlayerCharacter(n, un, h, max, d, l, HeroType::Warrior) { }

int Warrior::Attack(PlayerCharacter& P)
{
	string check = "";
	srand(time(nullptr));
	int attack = (rand() % damage) + 1;
	string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	if (usingItems[(int)ItemsType::Blade] == true)
	{
		Blade blade = {};
		attack = blade.UseItem(P, inf);
		string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	setColor(Color::LightRed);
	cout << "The warrior " << name << " slash " << P.getName() << " with " << attack << " damage" << endl;
	setColor(Color::White);
	return attack;
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
	setColor(Color::Aqua);
	cout << "The warrior defended himself with " << protection << " from the enemy's attack!" << endl;
	setColor(Color::LightRed);
	cout << "And now the attack is " << a << " damage" << endl;
	setColor(Color::White);
	return a;
}
void Warrior::TakeDamage(PlayerCharacter& P, int attack)
{
	string inf = std::to_string(attack) + ";" + ConvertVectorToString(usingItems, COUNTOFITEMS);
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
		newAttack = shield.UseItem(*this, inf);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	if (P.usingItems[(int)ItemsType::Mirror] != true)
	{
		newAttack = Speshal(newAttack);
	}
	else
	{
		Mirror mirror = {};
		mirror.UseItem(P,inf);
	}
	CastFromStringToVectorOrAttack(inf, usingItems);
	setHP(getHP() - newAttack);
}