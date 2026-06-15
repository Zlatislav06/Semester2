#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

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
bool DoYouHaveThisItem(const vector<std::unique_ptr<Items>>& items, std::unique_ptr<Items>& item);
class User
{
private:
	string name;
	string password;
	int XP=0;
	int maxXP = 0;
	vector<std::unique_ptr<PlayerCharacter>> characters;
	vector<std::unique_ptr<Items>> items;
	int battles=0;
	int winBattles=0;
	int rank;
	bool isValidPassword(const string& password);
	bool CheckCharacter(const HeroType n);
	void AddCharacter(const HeroType h,int prize);
	std::unique_ptr<PlayerCharacter> WhoIsCharacter(string nameOfHero, const HeroType h);
	std::unique_ptr<Items> WhoIsItem(const ItemsType itemtype);
	void AddItem(const ItemsType t);
	void BuyCharacter();
	void BuyItem();
	HeroType ConvertStringToHeroType(string str);
	void FindAndPrintForLevelUp(string select,int prize);
	void SelectOptionAfterLevelUp(std::unique_ptr<PlayerCharacter>& it);
	void LevelUp();
	string ConvertItemTypeToString(ItemsType e);
	
	
public:
	User(string n, string p, int xp,int maxxp, vector<std::unique_ptr<PlayerCharacter>> c, vector<std::unique_ptr<Items>> i, int b, int wb, int r);
	User(string n, string p);
	void RankList();
	void AddStarterCharacter(std::unique_ptr<PlayerCharacter> P);
	void AddStarterItem(std::unique_ptr<Items> item);
	void Buy();
	void Use(std::unique_ptr<Items> item,PlayerCharacter& P);
	void PrintItems();
	const string& getName() const;
	const vector<std::unique_ptr<PlayerCharacter>>& getCharacters() const;
	const vector<std::unique_ptr<Items>>& getItems() const;
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

