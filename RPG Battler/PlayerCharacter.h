#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
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
const int WHP = 20;
const int WDAMAGE = 8;
const int PROTECTION = 4;
const int MHP = 12;
const int MDAMAGE = 12;
const int ARHP = 15;
const int ARDAMAGE = 8;
string ConvertVectorToString(vector<bool> v, int size);
int FromCharToNumber(char a);
int Power(int number, int power);
vector<bool> CastFromStringToVector(string str, int attackSize);
int CastFromStringToAttack(string str, int& attackSize);
int CastFromStringToVectorOrAttack(string str, vector<bool>& boolVector);
string ToLower(string str);
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
	int level;
	HeroType heroType;
	
	
	
	//void UseItemWihtoutSpeshalEffect(vector<bool>& use);
	//void UseItemWihtoutSpeshalEffect(vector<bool>& use);
	//void UseItemWihtoutSpeshalEffect(vector<bool>& use);
	
public:
	string ConvertHeroTypeToString();
	vector<bool> usingItems = { false,false,false,false,false };
	PlayerCharacter(string n,string un, HeroType ht);
	PlayerCharacter(string n, string un, int h,int max, int d, int l , HeroType ht);
	const string& getName() const;
	const string& getUserName() const;
	const HeroType& getHeroType() const;
	const int& getHP() const;
	const int& getMaxHP() const;
	const int& getDamage() const;
	const int& getLevel() const;
	void setHeroType(HeroType ht);
	void setHP(int hp);
	void setMaxHP(int maxHp);
	void setDamage(int d);
	void setLevel(int l);
	virtual int Attack(PlayerCharacter& P);
	virtual void TakeDamage(PlayerCharacter& P,int attack);
	void Print();
	virtual int Speshal(int a)=0;
	virtual ~PlayerCharacter() = default;
};

