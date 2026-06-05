#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "Items.h"
#include "Exeptions.h"

#include "Ray.h"
#include "Blade.h"
#include "HealingPoltion.h"
#include "Shield.h"
#include "Mirror.h"


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
const int COUNTOFITEMS = 5;
string ConvertVectorToString(vector<bool> v, int size);
int FromCharToNumber(char a);
int Power(int number, int power);
vector<bool> CastFromStringToVector(string str, int attackSize);
int CastFromStringToAttack(string str, int& attackSize);
int CastFromStringToVectorOrAttack(string str, vector<bool>& boolVector);

void ConsoleClear();
enum class HeroType
{
	Warrior,
	Mage,
	Archer
};
class PlayerCharacter
{
protected:
	string name;
	string userName;
	int HP;
	int maxHP;
	int damage;
	int leval;
	HeroType heroType;
	
	
	
	//void UseItemWihtoutSpeshalEffect(vector<bool>& use);
	//void UseItemWihtoutSpeshalEffect(vector<bool>& use);
	//void UseItemWihtoutSpeshalEffect(vector<bool>& use);
	
public:
	string ConvertHeroTypeToString();
	vector<bool> usingItems = { false };
	PlayerCharacter(string n,string un, HeroType ht);
	PlayerCharacter(string n, string un, int h,int max, int d, int l , HeroType ht);
	const string& getName() const;
	const string& getUserName() const;
	const HeroType& getHeroType() const;
	const int& getHP() const;
	const int& getMaxHP() const;
	const int& getDamage() const;
	const int& getLeval() const;
	void setHeroType(HeroType ht);
	void setHP(int hp);
	void setMaxHP(int maxHp);
	void setDamage(int d);
	void setLeval(int l);
	virtual void Attack(PlayerCharacter& P);
	virtual void TakeDamage(PlayerCharacter& P,int attack);
	void Print();
	virtual int Speshal(int a)=0;
	virtual ~PlayerCharacter() = default;
};

