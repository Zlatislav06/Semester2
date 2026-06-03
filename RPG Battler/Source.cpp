#include "User.h"
const int STEPEN = 10;
double Percentage(User* a)
{
	return ((double)a->getWinBattles() / (double)a->getBattles()) * 100;
}
void Sort(vector<User*>& users)
{
	std::sort(users.begin(), users.end(),
		[](User* a, User* b)
		{
			if (a->getWinBattles() == b->getWinBattles())
			{
				if (a->getMaxXP() == b->getMaxXP())
				{
					return Percentage(a) > Percentage(b);
				}
				return a->getMaxXP() > b->getMaxXP();
			}
			return a->getWinBattles() > b->getWinBattles();
		});
}
void SaveInformation(User user)
{
	string nameFile = "Users.txt";
	std::ofstream file(nameFile, std::ios::app);
	file << user.getName()<<";";
	file << user.getPassword() << ";";
	file << user.getXP() << ";";
	file << user.getMaxXP() << ";";
	file << user.getBattles() << ";";
	file << user.getWinBattles() << ";";
	file << user.getRank() << ";" << endl;
	file << user.getCharacters().size() << endl;
	for (PlayerCharacter* p : user.getCharacters())
	{
		file << p->getName() << ";" << p->ConvertHeroTypeToString() << ";" << p->getHP() << ";" << p->getMaxHP() << ";" << p->getDamage() << ";" << p->getLeval() << ";";
	}
	file << user.getItems().size() << endl;
	for (Items* p : user.getItems())
	{
		file << p->ConvertItemTypeToString() << ";";
	}
	file.close();
}
User CreateNewUser(string n, string p, vector<User*>& users)
{
	User user = { n,p};
	users.push_back(&user);
	Sort(users);
	std::ofstream file("RankList.txt");
	for (int i = 0; i < users.size(); i++)
	{
		file << i + 1 << ") " << users[i]->getName();
		users[i]->setRank(i+1);
	}
	SaveInformation(user);
	file.close();

	return user;
}
int CountOfUsers()
{
	int br = 0;
	std::ifstream file("RankList.txt");
	string line;
	while (std::getline(file, line)) 
	{
		br = FromCharToNumber(line[0]);
	}
	file.close();
	return br;
}
string TakeStringFromOtherStirng(string str,int& index,char a)
{
	string smallString = "";
	while (str[index] != a)
	{
		smallString += str[index];
		index++;
	}
	index++;
	return smallString;
}
int TakeIntFromStirng(string str, int& index,char a)
{
	string smallString = TakeStringFromOtherStirng(str,index,a);
	int number = 0;
	for (int i = 0; i < smallString.size(); i++)
	{
		number+= FromCharToNumber(smallString[i]) * Power(STEPEN, smallString.size() - i - 1);
	}
	return number;
}
HeroType ConvertFromStringToHeroType(string str)
{
	HeroType e=HeroType::Warrior;
	if (str == "Warrior")
	{
		HeroType e = HeroType::Warrior;
	}
	else if (str == "Mage")
	{
		HeroType e = HeroType::Mage;
	}
	else if (str == "Archer")
	{
		HeroType e = HeroType::Archer;
	}
	else
	{
		throw Exeptions("Invalid Value!!!");
	}
	return e;
}
Items* ConvertFromStringToItem(string str)
{
	Items* item=nullptr;
	if (str == "HealingPoltion")
	{
		HealingPoltion hp = {};
		item = &hp;
	}
	else if (str == "Blade")
	{
		Blade blade = {};
		item = &blade;
	}
	else if (str == "Mirror")
	{
		Mirror mirror = {};
		item = &mirror;
	}
	else if (str == "Ray")
	{
		Ray ray = {};
		item = &ray;
	}
	else if (str == "Shield")
	{
		Shield shield = {};
		item = &shield;
	}
	else
	{
		throw Exeptions("Invalid Value!!!");
	}
	return item;
}
PlayerCharacter* CreateHero(string n, string un, int h,int max, int d, int l,HeroType heroType)
{
	PlayerCharacter* hero = nullptr;
	switch (heroType)
	{
		case HeroType::Warrior:
		{
			Warrior warrior = {n,un, h,max, d, l };
			hero = &warrior;
			break;
		}
		case HeroType::Mage:
		{
			Mage mage = { n,un, h,max, d, l };
			hero = &mage;
			break;
		}
		case HeroType::Archer:
		{
			Archer archer = { n,un, h,max, d, l };
			hero = &archer;
			break;
		}
		default:
		{
			throw Exeptions("Invalid value!!!");
			break;
		}
	}
	return hero;
}
vector<PlayerCharacter*> TakeHeroesFromString(string line,int size,int index,string name)
{
	vector<PlayerCharacter*> ch;
	for (int i = 0; i < size; i++)
	{
		PlayerCharacter* charater = nullptr;
		string heroName = TakeStringFromOtherStirng(line, index, ';');
		HeroType heroType = ConvertFromStringToHeroType(TakeStringFromOtherStirng(line, index, ';'));
		int HP = TakeIntFromStirng(line, index, ';');
		int MaxHP = TakeIntFromStirng(line, index, ';');
		int Damage = TakeIntFromStirng(line, index, ';');
		int Leval = TakeIntFromStirng(line, index, ';');
		charater = CreateHero(heroName, name, HP, MaxHP, Damage, Leval, heroType);
		ch.push_back(charater);
	}
	return ch;
}
vector<Items*> TakeItemsFromString(string line, int size, int index)
{
	vector<Items*> items;
	for (int i = 0; i < size; i++)
	{
		Items* item = ConvertFromStringToItem(TakeStringFromOtherStirng(line, index, ';'));
		items.push_back(item);
	}
	return items;
}
vector<User*> GiveInformationToProgram()
{
	vector<User*> users;
	string nameFile = "Users.txt";
	std::ifstream file(nameFile);
	int  size= CountOfUsers();
	for (int i = 0; i < size; i++)
	{	
		string line;
		std::getline(file, line);
		int index = 0;
		string name = TakeStringFromOtherStirng(line,index,';');
		string password = TakeStringFromOtherStirng(line, index, ';');
		int XP =TakeIntFromStirng(line, index, ';');
		int maxXP = TakeIntFromStirng(line, index, ';');
		int battles = TakeIntFromStirng(line, index, ';');
		int winBattles = TakeIntFromStirng(line, index, ';');
		int rank = TakeIntFromStirng(line, index, ';');
		index = 0;
		std::getline(file, line);
		int sizeCharacters= TakeIntFromStirng(line, index, '\n');
		index = 0;
		std::getline(file, line);
		vector<PlayerCharacter*> ch=TakeHeroesFromString(line, sizeCharacters,index,name);
		index = 0;
		std::getline(file, line);
		int sizeItems = TakeIntFromStirng(line, index, '\n');
		index = 0;
		std::getline(file, line);
		vector<Items*> items= TakeItemsFromString(line, sizeItems,index);
		User user = { name,password,XP,maxXP,ch ,items,battles,winBattles,rank };
		users.push_back(&user);
	}
	file.close();
	return users;
}
bool FileExist(string nameFile)
{
	std::ifstream file(nameFile);
	if (!file.is_open()) {
		return false;
	}

	
	if (file.peek() == EOF) {
		return false;
	}
	else {
		return true;
	}

	file.close();
}
int main()
{
	bool check = true;
	if (FileExist("Users.txt"))
	{
		try
		{
			vector<User*> users = GiveInformationToProgram();
		}
		catch(...)
		{
			Exeptions::ShowError(Exeptions("Have a problem with the list from users!!!"));
		}
	}
	else
	{
		check = false;
	}
	
	string command = "";
	
	cout << "Hello player 1, to play this game you need to log in, and if you don't have one you can create one."<<endl;
	cout << "Now you can choose one of those two options:" << endl;
	cout << "1) Create" << endl;
	if (check)
	{
		cout << "2) Log in" << endl;
	}
	
	if (command == "1" || command == "1)" || command == "Create")
	{
		string name = "";
		string password = "";
		cout << "Enter how you want to call you in the game:";
		cin >> name;
		while (true)
		{
			string password = "";
			try
			{
				cout << "Enter valid password:";
				cin >> password;
				break;
			}
			catch (Exeptions ex)
			{
				Exeptions::ShowError(ex);
			}
			cout << "Try again!!!";
		
		}


	}
	if (command == "2" || command == "2)" || command == "Log in")
	{
		string name = "";
		string password = "";
		cout << "Enter your username:";
		cin >> name;

		while (true)
		{
			string password = "";
			try
			{
				cout << "Enter valid password:";
				cin >> password;
				break;
			}
			catch (Exeptions ex)
			{
				Exeptions::ShowError(ex);
			}
			cout << "Try again!!!"<<endl;

		}

	}
	cout << "Player 1:" << endl;
	return 0;
}