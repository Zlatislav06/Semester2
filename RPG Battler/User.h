#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "PlayerCharacter.h"
#include "Items.h"
#include "Mage.h"
#include "Archer.h"
#include "Warrior.h"
#include "HealingPoltion.h"
#include "Blade.h"
#include "Mirror.h"
#include "Ray.h"
#include "Shield.h"
#include "Exeptions.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
class User
{
private:
	string name;
	string password;
	int XP=0;
	int maxXP = 0;
	vector<PlayerCharacter*> characters;
	vector<Items*> items;
	int battles=0;
	int winBattles=0;
	int rank;
	bool isValidPassword(const string& password);
	bool CheckCharacter(const HeroType n);
	void AddCharacter(const HeroType h,int prize);
	PlayerCharacter* WhoIsCharacter(string nameOfHero, const HeroType h);
	Items* WhoIsItem(const ItemsType itemtype);
	void AddItem(const ItemsType t);
	void BuyCharacter();
	void BuyItem();
	HeroType ConvertStringToHeroType(string str);
	void FindAndPrintForLevalUp(string select,int prize);
	void SelectOptionAfterLevelUp(PlayerCharacter* it);
	void LevalUp();
	
public:
	User(string n, string p, int xp,int maxxp,vector<PlayerCharacter*> c, vector<Items*> i, int b, int wb, int r);
	User(string n, string p);
	void RankList();
	void AddStarterCharacter(PlayerCharacter* P);
	void Buy();
	void Use(Items* item,PlayerCharacter& P);
	const string& getName() const;
	const vector<PlayerCharacter*>& getCharacters() const;
	const vector<Items*>& getItems() const;
	const string& getPassword() const;
	const int& getXP() const;
	const int& getMaxXP() const;
	const int& getBattles() const;
	const int& getWinBattles() const;
	const int& getRank() const;
	void setName(string n);
	void setPassword(string p);
	void setXP(int xp);
	void setMaxXP(int xp);
	void setBattles(int b);
	void setWinBattles(int wb);
	void setRank(int r);
};

