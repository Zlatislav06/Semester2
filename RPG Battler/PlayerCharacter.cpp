#include "PlayerCharacter.h"
const int STEPEN = 10;
string ConvertVectorToString(vector<bool> v, int size)
{
	string inf = "";
	for (int i = 0; i < size; i++)
	{
		if (v[i] = true)
		{
			inf += "1";
		}
		else
		{
			inf += "0";
		}
	}
	return inf;
}
int FromCharToNumber(char a)
{
	switch (a)
	{
	case '1':
	{
		return 1;
		break;
	}
	case '2':
	{
		return 2;
		break;
	}
	case '3':
	{
		return 3;
		break;
	}
	case '4':
	{
		return 4;
		break;
	}
	case '5':
	{
		return 5;
		break;
	}
	case '6':
	{
		return 6;
		break;
	}
	case '7':
	{
		return 7;
		break;
	}
	case '8':
	{
		return 8;
		break;
	}
	case '9':
	{
		return 9;
		break;
	}
	case '0':
	{
		return 0;
		break;
	}
	default:
	{
		throw Exceptions("Invalid value!!!");
	}
	}
}
int Power(int number, int power)
{
	int sum = 1;
	for (int i = 0; i < power; i++)
	{
		sum *= number;
	}
	return sum;
}
vector<bool> CastFromStringToVector(string str, int attackSize)
{
	int index = 0;
	vector<bool> v = { false };
	for (int i = attackSize + 1; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			v[index] = true;
		}
		else if (str[i] == '0')
		{
			v[index] = false;
		}
		else
		{
			break;
		}
		index++;
	}
	return v;
}
int CastFromStringToAttack(string str, int& attackSize)
{
	int attack = 0;
	int index = 0;
	while (str[index] != '\n')
	{
		index++;
	}
	attackSize = index;

	for (int i = 0; i < attackSize; i++)
	{
		attack = FromCharToNumber(str[i]) * Power(STEPEN, attackSize - i-1);
	}
	return attack;
}
int CastFromStringToVectorOrAttack(string str, vector<bool>& boolVector)
{
	int attackSize = 0;
	int attack = CastFromStringToAttack(str, attackSize);
	boolVector = CastFromStringToVector(str, attackSize);
	return attack;

}

void ConsoleClear()
{
	system("cls");
}
PlayerCharacter::PlayerCharacter(string n, string un, HeroType ht)
{
	name = n;
	userName = un;
	setHeroType(ht);
}
PlayerCharacter::PlayerCharacter(string n, string un, int h, int max, int d, int l, HeroType ht)
{
	name = n;
	userName = un;
	setMaxHP(max);
	setHeroType(ht);
	setHP(h);
	setLevel(l);
	setDamage(d);
}
const string& PlayerCharacter::getName() const
{
	return name;
}
const string& PlayerCharacter::getUserName() const
{
	return userName;
}
const HeroType& PlayerCharacter::getHeroType() const
{
	return heroType;
}
const int& PlayerCharacter::getHP() const
{
	return HP;
}
const int& PlayerCharacter::getDamage() const
{
	return damage;
}
const int& PlayerCharacter::getMaxHP() const
{
	return maxHP;
}
const int& PlayerCharacter::getLevel() const
{
	return level;
}
void PlayerCharacter::setHeroType(HeroType ht)
{
	switch (ht)
	{
		case HeroType::Warrior:
		{
			heroType = ht;
			break;
		}
		case HeroType::Mage:
		{
			heroType = ht;
			break;
		}
		case HeroType::Archer:
		{
			heroType = ht;
			break;
		}
		default:
		{
			throw Exceptions("Invalid hero type!");
			break;
		}
			
	}
}
void PlayerCharacter::setHP(int hp)
{
	if (hp>0)
	{
		HP = hp;
	}
	else
	{
		throw Exceptions("The max HP of cheracter can't be a less then zero or zero!");
	}
}
void PlayerCharacter::setMaxHP(int maxHp)
{
	if (maxHp > 0)
	{
		maxHP = maxHp;
	}
	else
	{
		throw Exceptions("The max HP of cheracter can't be a less then zero or zero!");
	}
}
void PlayerCharacter::setDamage(int d)
{
	if (d > 0)
	{
		damage = d;
	}
	else
	{
		throw Exceptions("the max damage of cheracter can't be a less then zero or zero!");
	}
}
void PlayerCharacter::setLevel(int l)
{
	if (l > 0)
	{
		level = l;
	}
	else
	{
		throw Exceptions("the level of cheracter can't be a less then zero or zero!");
	}
}
string PlayerCharacter::ConvertHeroTypeToString()
{
	string hType = "";
	switch (heroType)
	{
		case HeroType::Warrior:
		{
			hType = "Warrior";
			break;
		}
		case HeroType::Mage:
		{
			hType = "Mage";
			break;
		}
		case HeroType::Archer:
		{
			hType = "Archer";
			break;
		}
		default:
		{
			throw Exceptions("Invalid value!!!");
			break;
		}
	}
	return hType;
}

void PlayerCharacter::Print()
{
	string hType = ConvertHeroTypeToString();
	cout << "The hero also called " << name << " have this status:" << endl;
	cout << "Class:" << hType << endl;
	cout << "HP:" << HP << endl;
	cout << "Damage: 1-" << damage << endl;
	cout << "Level: " << level << endl;
}
void PlayerCharacter::Attack(PlayerCharacter& P) { }
void PlayerCharacter::TakeDamage(PlayerCharacter& P, int attack){ }
