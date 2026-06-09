#include "User.h"
#include <thread>
#include <chrono>
const int STEPEN = 10;
const int P1 = 1;
const int P2 = 2;
const int MINHEROES = 1;
const int MAXHEROES = 3;
const int WINXP = 10;
const int LOOSEXP = 5;
double Percentage(const User& a)
{
	return ((double)a.getWinBattles() /
		(double)a.getBattles()) * 100;
}
void LogOut(User* player1, User* player2)
{
	player1 = nullptr;
	player2 = nullptr;
	setColor(Color::Red);
	cout << "Players loged out!"<<endl;
	setColor(Color::White);
}
void Sort(vector<std::unique_ptr<User>>& users)
{
	std::sort(users.begin(), users.end(),
		[](const std::unique_ptr<User>& a,const std::unique_ptr<User>& b)
		{
			if (a->getWinBattles() == b->getWinBattles())
			{
				if (a->getMaxXP() == b->getMaxXP())
				{
					return Percentage(*a) > Percentage(*b);
				}
				return a->getMaxXP() > b->getMaxXP();
			}
			return a->getWinBattles() > b->getWinBattles();
		});
}
HeroType ConvertFromStringToHeroType(string str)
{
	HeroType e = HeroType::Warrior;
	if (str == "Warrior")
	{
		e = HeroType::Warrior;
	}
	else if (str == "Mage")
	{
		e = HeroType::Mage;
	}
	else if (str == "Archer")
	{
		e = HeroType::Archer;
	}
	else
	{
		throw Exceptions("Invalid Value!!!");
	}
	return e;
}
string ConvertFromHeroTypeToString(HeroType e)
{
	string str = "";
	if (e ==HeroType::Warrior)
	{
		str = "Warrior";
	}
	else if (e == HeroType::Mage)
	{
		str = "Mage";
	}
	else if (e == HeroType::Archer)
	{
		str = "Archer";
	}
	else
	{
		throw Exceptions("Invalid Value!!!");
	}
	return str;
}
void SaveInformation(const User& user)
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
	for (const std::unique_ptr<PlayerCharacter>& p : user.getCharacters())
	{
		file << p->getName() << ";" << p->ConvertHeroTypeToString() << ";" << p->getHP() << ";" << p->getMaxHP() << ";" << p->getDamage() << ";" << p->getLevel() << ";";
	}
	file<<endl << user.getItems().size() << endl;
	for (const std::unique_ptr<Items>& p : user.getItems())
	{
		file << p->ConvertItemTypeToString() << ";";
	}
	if (user.getItems().size() != 0)
	{
		file << endl;
	}
	file.close();
}
void SaveAllInformation(vector<std::unique_ptr<User>>& users)
{
	string nameFile = "Users.txt";
	std::ofstream file1(nameFile);
	file1.close();
	Sort(users);
	std::ofstream file("RankList.txt");
	for (int i = 0; i < users.size(); i++)
	{
		file << i + 1 << ") " << users[i]->getName() << endl;
		users[i]->setRank(i + 1);
	}
	file.close();
	for (std::unique_ptr<User>& x : users)
	{
		SaveInformation(*x);
	}
}
void AddStarterCharacterInUser(User& user)
{
	while (true)
	{
		string newHero = "";
		string nameHero = "";
		cout << "Choose your first character:" << endl;
		setColor(Color::Purple);
		cout << "1) Mage" << endl;
		setColor(Color::Green);
		cout << "2) Archer" << endl;
		setColor(Color::LightRed);
		cout << "3) Warrior" << endl;
		setColor(Color::White);
		cout << "Your choice is ";
		cin >> newHero;
		cout << "Name of hero:";
		cin >> nameHero;
		try
		{
			if (newHero == "1" || newHero == "1)" || ToLower(newHero) == "mage")
			{
				user.AddStarterCharacter(std::make_unique<Mage>(nameHero, user.getName()));
				break;
			}
			else if (newHero == "2" || newHero == "2)" || ToLower(newHero) == "archer")
			{
				user.AddStarterCharacter(std::make_unique<Archer>(nameHero, user.getName()));
				break;
			}
			else if (newHero == "3" || newHero == "3)" || ToLower(newHero) == "warrior")
			{
				user.AddStarterCharacter(std::make_unique<Warrior>(nameHero, user.getName()));
				break;
			}
			else
			{
				throw Exceptions("Invalid character type!!!");
			}
		}
		catch (Exceptions ex)
		{
			ConsoleClear();
			Exceptions::ShowError(ex);

		}
	}
}
void AddStarterItemInUser(User& user)
{
	while (true)
	{
		string nameItem = "";
		cout << "Choose your first item:" << endl;
		setColor(Color::Green);
		cout << "1) HealingPotion" << endl;
		setColor(Color::LightRed);
		cout << "2) Blade" << endl;
		setColor(Color::Purple);
		cout << "3) Mirror" << endl;
		setColor(Color::Yellow);
		cout << "4) Ray" << endl;
		setColor(Color::Blue);
		cout << "5) Shield" << endl;
		setColor(Color::White);
		cout << "Your choice is ";
		cin >> nameItem;
		try
		{
			ConsoleClear();
			if (ToLower(nameItem) == "healingpotion" || nameItem == "1" || nameItem == "1)")
			{
				user.AddStarterItem(std::make_unique<HealingPoltion>());
				break;
			}
			else if (ToLower(nameItem) == "blade" || nameItem == "2" || nameItem == "2)")
			{
				user.AddStarterItem(std::make_unique<Blade>());
				break;
			}
			else if (ToLower(nameItem) == "mirror" || nameItem == "3" || nameItem == "3)")
			{
				user.AddStarterItem(std::make_unique<Mirror>());
				break;
			}
			else if (ToLower(nameItem) == "ray" || nameItem == "4" || nameItem == "4)")
			{
				user.AddStarterItem(std::make_unique<Ray>());
				break;
			}
			else if (ToLower(nameItem) == "shield" || nameItem == "5" || nameItem == "5)")
			{
				user.AddStarterItem(std::make_unique<Shield>());
				break;
			}
			else
			{
				throw Exceptions("Invalid value!!!");
			}
		}
		catch (Exceptions ex)
		{
			ConsoleClear();
			Exceptions::ShowError(ex);

		}
	}
}
User* CreateNewUser(string n, string p, vector<std::unique_ptr<User>>& users)
{
	auto user = std::make_unique<User>(n, p);
	AddStarterCharacterInUser(*user);
	AddStarterItemInUser(*user);
	users.push_back(std::move(user));
	Sort(users);
	std::ofstream file("RankList.txt");
	for (int i = 0; i < users.size(); i++)
	{
		file << i + 1 << ") " << users[i]->getName()<<endl;
		users[i]->setRank(i+1);
	}
	SaveInformation(*users.back());
	file.close();
	return users.back().get();
}
int CountOfUsers()
{
	int br = 0;
	std::ifstream file("RankList.txt");
	string line;
	while (std::getline(file, line)) 
	{
		br++;
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

std::unique_ptr<Items> ConvertFromStringToItem(string str)
{
	std::unique_ptr<Items> item=nullptr;
	if (str == "HealingPoltion")
	{
		item = std::make_unique<HealingPoltion>();
	}
	else if (str == "Blade")
	{
		item = std::make_unique<Blade>();
	}
	else if (str == "Mirror")
	{
		item = std::make_unique<Mirror>();
	}
	else if (str == "Ray")
	{
		item = std::make_unique<Ray>();
	}
	else if (str == "Shield")
	{
		item = std::make_unique<Shield>();
	}
	else
	{
		throw Exceptions("Invalid Value!!!");
	}
	return item;
}
std::unique_ptr<PlayerCharacter> CreateHero(string n, string un, int h,int max, int d, int l,HeroType heroType)
{
	std::unique_ptr<PlayerCharacter> hero = nullptr;
	switch (heroType)
	{
		case HeroType::Warrior:
		{
		
			hero = std::make_unique<Warrior>(n, un, h, max, d, l);
			break;
		}
		case HeroType::Mage:
		{
			
			hero = std::make_unique<Mage>(n, un, h, max, d, l);
			break;
		}
		case HeroType::Archer:
		{
			
			hero = std::make_unique<Archer>(n, un, h, max, d, l);
			break;
		}
		default:
		{
			throw Exceptions("Invalid value!!!");
			break;
		}
	}
	return hero;
}
vector<std::unique_ptr<PlayerCharacter>> TakeHeroesFromString(string line,int size,int index,string name)
{
	vector<std::unique_ptr<PlayerCharacter>> ch;
	for (int i = 0; i < size; i++)
	{
		std::unique_ptr<PlayerCharacter> charater = nullptr;
		string heroName = TakeStringFromOtherStirng(line, index, ';');
		HeroType heroType = ConvertFromStringToHeroType(TakeStringFromOtherStirng(line, index, ';'));
		int HP = TakeIntFromStirng(line, index, ';');
		int MaxHP = TakeIntFromStirng(line, index, ';');
		int Damage = TakeIntFromStirng(line, index, ';');
		int Leval = TakeIntFromStirng(line, index, ';');
		charater = CreateHero(heroName, name, HP, MaxHP, Damage, Leval, heroType);
		ch.push_back(std::move(charater));
	}
	return ch;
}
vector<std::unique_ptr<Items>> TakeItemsFromString(string line, int size, int index)
{
	vector<std::unique_ptr<Items>> items;
	for (int i = 0; i < size; i++)
	{
		std::unique_ptr<Items> item = ConvertFromStringToItem(TakeStringFromOtherStirng(line, index, ';'));
		items.push_back(std::move(item));
	}
	return items;
}
vector<std::unique_ptr<User>> GiveInformationToProgram()
{
	vector<std::unique_ptr<User>> users;
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
		int sizeCharacters = stoi(line);
		index = 0;
		vector<std::unique_ptr<PlayerCharacter>> ch;
		if (sizeCharacters != 0)
		{
			std::getline(file, line);
			ch = TakeHeroesFromString(line, sizeCharacters, index, name);
			index = 0;
		}
		std::getline(file, line);
		int sizeItems = stoi(line);
		vector<std::unique_ptr<Items>> items;
		if (sizeItems != 0)
		{
			index = 0;
			std::getline(file, line);
			items = TakeItemsFromString(line, sizeItems, index);
		}
		users.push_back(std::make_unique<User>(name, password, XP, maxXP, std::move(ch), std::move(items), battles, winBattles, rank));
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
User* FindUser(string& name, string& password, vector<std::unique_ptr<User>>& users)
{
	while (true)
	{
		
			cout << "Enter your username:";
			cin >> name;
			cout << "Enter valid password:";
			cin >> password;
			auto it = std::find_if(users.begin(), users.end(), [&](const std::unique_ptr<User>& x)
				{
					return x->getName() == name && x->getPassword()==password; 
				});
			if (it == users.end())
			{
				try
				{
					throw Exceptions("Don't have user with that name or password!!!");
				}
				catch (Exceptions ex)
				{

					Exceptions::ShowError(ex);
					setColor(Color::Red);
					cout << "Try again!!!" << endl;
					setColor(Color::White);
				}
			}
			else
			{
				return it->get();
				
			}
	}
}
bool IsThereAProblemWithTheFile(vector<std::unique_ptr<User>>& users)
{
	bool check = true;
	if (FileExist("Users.txt"))
	{
		try
		{
			users = GiveInformationToProgram();
		}
		catch (...)
		{
			Exceptions::ShowError(Exceptions("Have a problem with the list from users!!!"));
		}
	}
	else
	{
		check = false;
	}
	return check;
}
User* LogInOrCreateInGame(User* player,int indexOfPlayer, vector<std::unique_ptr<User>>& users,bool check)
{
	
	string command = "";
	cout << "Hello player "<<indexOfPlayer<<", to play this game you need to log in your account, and if you don't have one you can create one." << endl;
	cout << "Now you can choose one of those two options:" << endl;
	cout << "1) Create" << endl;
	
	if (check)
	{
		cout << "2) LogIn" << endl;
	}
	cout << "Write the command here:";
	cin >> command;
	if (command == "1" || command == "1)" || ToLower(command) == "create")
	{
		string name = "";
		string password = "";
		cout << "Enter how you want to call you in the game:";
		cin >> name;
		while (true)
		{

			try
			{
				cout << "Enter valid password:";
				cin >> password;
				player = CreateNewUser(name, password, users);
				break;
			}
			catch (Exceptions ex)
			{
				Exceptions::ShowError(ex);
			}
			setColor(Color::Red);
			cout << "Try again!!!"<<endl;
			setColor(Color::White);
		}


	}
	else if (command == "2" || command == "2)" || ToLower(command) == "login")
	{
		string name = "";
		string password = "";
		player =FindUser(name, password, users);
	}
	else
	{
		throw Exceptions("Invalid command!!!");
	}
	ConsoleClear();
	setColor(Color::LightGreen);
	cout << "Player " << indexOfPlayer << " is now loged in!!!" << endl;
	setColor(Color::White);
	return player;
}
PlayerCharacter* ChooseHeroOneFromMoreThenOne(PlayerCharacter* playerHero,User* player,auto& playerCharacters,int size)
{
	string choice = "";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << playerCharacters[i]->getName() << "(" << ConvertFromHeroTypeToString(playerCharacters[i]->getHeroType()) << ")" << endl;
	}
	cin >> choice;
	auto it = std::find_if(playerCharacters.begin(), playerCharacters.end(), [&](const std::unique_ptr<PlayerCharacter>& x)
		{
			return x->getName() == choice;
		});
	if (it == playerCharacters.end())
	{
		throw Exceptions(player->getName() + " don't have this choice!");
	}
	playerHero = it->get();
	return playerHero;
}
PlayerCharacter* ChooseHeroOneFromOne(PlayerCharacter* playerHero,User* player, auto& playerCharacters)
{
	playerHero = playerCharacters[0].get();
	cout << "You have only one hero." << endl;
	cout << "Therefore " << player->getName() << " will play with " << playerHero->getName() << "." << endl;
	return playerHero;
}
PlayerCharacter* ChooseHero(User* player,int index)
{
	cout << "Player "<<index<<"(" << player->getName() << ") can choose one of his characters(only by name):" << endl;
	int size = player->getCharacters().size();
	auto& playerCharacters = player->getCharacters();
	PlayerCharacter* playerHero = nullptr;
	if (size > MINHEROES && size <= MAXHEROES)
	{
		playerHero = ChooseHeroOneFromMoreThenOne(playerHero, player, playerCharacters,size);

	}
	else if (size == MINHEROES)
	{

		playerHero= ChooseHeroOneFromOne(playerHero, player,playerCharacters);

	}
	else
	{
		throw Exceptions("Invlid count of heroes!!!");
	}
	cout << endl;
	playerHero->Print();
	return playerHero;
}
void UseSpecialItemRay(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero,int index)
{
	string command = "";
	bool check = false;
	
	std::unique_ptr<Items> item = std::make_unique<Ray>();
	if (index == P1)
	{
		check = DoYouHaveThisItem(player1->getItems(), item);
	}
	else if(index==P2)
	{
		check = DoYouHaveThisItem(player2->getItems(), item);
	}
	else
	{
		throw Exceptions("Wrong index!!!");
	}

	if (check)
	{
		setColor(Color::LightBlue);
		cout << "Ray is special item and can be used now!" << endl;
		setColor(Color::White);
		cout << "If you want write it, if you don't want it write \"No\" or any other word." << endl;
		cin >> command;
		try
		{

			if (index == P1)
			{
				if (ToLower(command) == "ray")
				{
					player1->Use(std::make_unique<Ray>(), *player1Hero);
					cout << "Player "<<index<<" (" << player1->getName() << ") use ray!" << endl;
				}
			}
			else if(index==P2)
			{
				if (ToLower(command) == "ray")
				{
					player2->Use(std::make_unique<Ray>(), *player2Hero);
					cout << "Player " << index << " (" << player2->getName() << ") use ray!" << endl;
				}

			}
			
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}
	}
}
void UseSpecialItemShield(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero, int index)
{
	string command = "";
	bool check = false;

	std::unique_ptr<Items> item = std::make_unique<Shield>();
	if (index == P1)
	{
		check = DoYouHaveThisItem(player1->getItems(), item);
	}
	else if (index == P2)
	{
		check = DoYouHaveThisItem(player2->getItems(), item);
	}
	else
	{
		throw Exceptions("Wrong index!!!");
	}
	if (check)
	{
		setColor(Color::LightBlue);
		cout << "Shield is special item and can be used now!" << endl;
		setColor(Color::White);
		cout << "If you want write it, if you don't want it write \"No\" or any other word." << endl;
		cin >> command;
		try
		{

			if (index == P1)
			{
				if (ToLower(command) == "shield")
				{
					player1->Use(std::make_unique<Shield>(), *player1Hero);
					cout << "Player " << index << " (" << player1->getName() << ") use shield!" << endl;
				}
			}
			else if (index == P2)
			{
				if (ToLower(command) == "shield")
				{
					player2->Use(std::make_unique<Shield>(), *player2Hero);
					cout << "Player " << index << " (" << player2->getName() << ") use shield!" << endl;
				}

			}

		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}
	}
}
void MoveAttackP1VsP2(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	try
	{
		UseSpecialItemRay(player1, player2, player1Hero, player2Hero, P1);
		setColor(Color::White);
		int attack=player1Hero->Attack(*player2Hero);
		setColor(Color::LightBlue);
		UseSpecialItemShield(player1, player2, player1Hero, player2Hero, P2);
		setColor(Color::White);
		player2Hero->TakeDamage(*player1Hero,attack);
	}
	catch(Exceptions ex)
	{
		Exceptions::ShowError(ex);
	}
	
}
void MoveUseItemsP1VsP2(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	string command = "";
	cout << "Player 1(" << player1->getName() << ") can use one from every type of items, if you have this item(use index or short name):" << endl;
	cout << "1) Healing Potion (potion)"<<endl;
	cout << "2) Blade (blade)" << endl;
	cout << "3) Mirror (mirror)" << endl;
	cin >> command;
	try
	{
		if (command == "1" || command == "1)" || ToLower(command) == "potion")
		{
			player1->Use(std::make_unique<HealingPoltion>(), *player1Hero);
			cout << "Player 1(" << player1->getName() << ") use healing potion!" << endl;
		}
		else if (command == "2" || command == "2)" || ToLower(command) == "blade")
		{
			player1->Use(std::make_unique<Blade>(), *player1Hero);
			cout << "Player 1(" << player1->getName() << ") use blade!" << endl;
		}
		else if (command == "3" || command == "3)" || ToLower(command) == "mirror")
		{
			player1->Use(std::make_unique<Mirror>(), *player1Hero);
			cout << "Player 1(" << player1->getName() << ") use mirror!" << endl;
		}
		else
		{
			throw Exceptions("Invalid choice for item!!!");
		}
	}
	catch (Exceptions ex)
	{
		Exceptions::ShowError(ex);
	}
}
void MoveP1VsP2(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	string command = "";
	cout << "Player 1(" << player1->getName() << ") can make one from these moves:" << endl;
	cout << "1) Attack" << endl;
	cout << "2) Use items" << endl;
	cout << "Write one move(for move \"Use items\" please use index or the word \"use\"):";
	cin >> command;
	if (command == "1" || command == "1)" || ToLower(command) == "attack")
	{
		MoveAttackP1VsP2(player1, player2, player1Hero, player2Hero);
	}
	else if (command[0] == 'U')
	{
		cout << "Didn\'t I ask for something?";
		setColor(Color::Red);
		cout << ">:(" << endl;
		setColor(Color::White);
	}
	else if (command == "2" || command == "2)" || ToLower(command) == "use")
	{
		MoveUseItemsP1VsP2(player1, player2, player1Hero, player2Hero);
	}
	else
	{
		throw Exceptions("Invalid command!!!");
	}

}
void MoveAttackP2VsP1(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	try
	{
		UseSpecialItemRay(player1, player2, player1Hero, player2Hero, P2);
		setColor(Color::White);
		int attack = player2Hero->Attack(*player1Hero);
		UseSpecialItemShield(player1, player2, player1Hero, player2Hero, P1);
		setColor(Color::White);
		player1Hero->TakeDamage(*player2Hero, attack);
	}
	catch (Exceptions ex)
	{
			Exceptions::ShowError(ex);
	}

}
void MoveUseItemsP2VsP1(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	string command = "";
	cout << "Player 2(" << player2->getName() << ") can use one from every type of items(use index or short name):" << endl;
	cout << "1) Healing Potion (potion)" << endl;
	cout << "2) Blade (blade)" << endl;
	cout << "3) Mirror (mirror)" <<endl ;
	cout << "Write type of item who you want to use:";
	cin >> command;
	try
	{
		if (command == "1" || command == "1)" || command == "potion")
		{
			player1->Use(std::make_unique<HealingPoltion>(), *player1Hero);
			cout << "Player 2(" << player2->getName() << ") use healing potion!" << endl;
		}
		else if (command == "2" || command == "2)" || command == "blade")
		{
			player1->Use(std::make_unique<Blade>(), *player1Hero);
			cout << "Player 2(" << player2->getName() << ") use blade!" << endl;
		}
		else if (command == "3" || command == "3)" || command == "mirror")
		{
			player1->Use(std::make_unique<Mirror>(), *player1Hero);
			cout << "Player 2(" << player2->getName() << ") use mirror!" << endl;
		}
		else
		{
			throw Exceptions("Invalid choice for item!!!");
		}
	}
	catch (Exceptions ex)
	{
		Exceptions::ShowError(ex);
	}
}
void MoveP2VsP1(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	string command = "";
	cout << "Player 2(" << player2->getName() << ") can make one from these moves:" << endl;
	cout << "1) Attack" << endl;
	cout << "2) Use items" << endl;
	cout << "Write one move(for move \"Use items\" please use index or the word \"use\"):";
	cin >> command;
	if (command == "1" || command == "1)" || command == "Attack")
	{
		MoveAttackP2VsP1(player1, player2, player1Hero, player2Hero);
	}
	else if (command[0] == 'U')
	{
		cout << "Didn\'t I ask for something?";
		setColor(Color::Red);
		cout << ">:(" << endl;
		setColor(Color::White);
	}
	else if (command == "2" || command == "2)" || ToLower(command) == "use")
	{
		MoveUseItemsP2VsP1(player1, player2, player1Hero, player2Hero);
	}
	
	else
	{
		throw Exceptions("Invalid command!!!");
	}

}
void Points(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero,int index)
{
	if (index == P1)
	{
		setColor(Color::LightGreen);
		cout << player2Hero->getName() << " win and " << player2->getName() << " receive 10XP!" << endl << endl;
		player2->setMaxXP(player2->getMaxXP() + WINXP);
		player2->setXP(player2->getXP() + WINXP);
		setColor(Color::Red);
		cout << player1Hero->getName() << " lost and " << player1->getName() << " receive 5XP!" << endl << endl;
		setColor(Color::White);
		player1->setMaxXP(player1->getMaxXP() + LOOSEXP);
		player1->setXP(player1->getXP() + LOOSEXP);
		player1->setBattles(player1->getBattles() + 1);
		player2->setBattles(player2->getBattles() + 1);
		player2->setWinBattles(player2->getWinBattles() + 1);
	}
	else if(index==P2)
	{
		setColor(Color::LightGreen);
		cout << player1Hero->getName() << " win and " << player1->getName() << " receive 10XP!" << endl << endl;
		player1->setMaxXP(player1->getMaxXP() + WINXP);
		player1->setXP(player1->getXP() + WINXP);
		setColor(Color::Red);
		cout << player2Hero->getName() << " lost and " << player2->getName() << " receive 5XP!" << endl << endl;
		setColor(Color::White);
		player2->setMaxXP(player2->getMaxXP() + LOOSEXP);
		player2->setXP(player2->getXP() + LOOSEXP);
		player1->setBattles(player1->getBattles() + 1);
		player2->setBattles(player2->getBattles() + 1);
		player1->setWinBattles(player1->getWinBattles() + 1);
	}
}
void NormalBattle(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero, int& moves)
{
	while (true)
	{
		try
		{
			moves++;
			setColor(Color::LightAqua);
			cout << "Move " << moves << endl << endl;
			setColor(Color::White);
			MoveP1VsP2(player1, player2, player1Hero, player2Hero);
			cout << endl;
			player2Hero->Print();
			cout << endl << endl;
			if (player1Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P1);
				break;
			}
			if (player2Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P2);
				break;
			}
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}
		try
		{
			moves++;
			setColor(Color::LightAqua);
			cout << "Move " << moves << endl << endl;
			setColor(Color::White);
			MoveP2VsP1(player1, player2, player1Hero, player2Hero);
			cout << endl;
			player1Hero->Print();
			cout << endl << endl;
			if (player1Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P1);
				break;
			}
			if (player2Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P2);
				break;
			}
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}

	}
}
void ReverseBattle(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero,int& moves)
{
	while (true)
	{
		try
		{
			moves++;
			setColor(Color::LightAqua);
			cout << "Move " << moves << endl << endl;
			setColor(Color::White);
			MoveP2VsP1(player1, player2, player1Hero, player2Hero);
			cout << endl;
			player1Hero->Print();
			cout << endl << endl;
			if (player1Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P1);
				break;
			}
			if (player2Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P2);
				break;
			}
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}
		try
		{
			moves++;
			setColor(Color::LightAqua);
			cout << "Move " << moves << endl << endl;
			setColor(Color::White);
			MoveP1VsP2(player1, player2, player1Hero, player2Hero);
			cout << endl;
			player2Hero->Print();
			cout << endl << endl;
			if (player1Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P1);
				break;
			}
			if (player2Hero->getHP() == 0)
			{
				Points(player1, player2, player1Hero, player2Hero, P2);
				break;
			}
			
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}

	}
}
void Battle(User* player1, User* player2, PlayerCharacter* player1Hero, PlayerCharacter* player2Hero)
{
	int moves = 0;
	srand(time(nullptr));
	int random = (rand() % P2) + 1;
	setColor(Color::Purple);
	cout << "Fate chose player "<<random << endl<<endl;
	setColor(Color::White);
	if (random == P1)
	{
		NormalBattle(player1,player2, player1Hero,player2Hero,moves);
	}
	else if (random == P2)
	{
		ReverseBattle(player1, player2, player1Hero, player2Hero, moves);
	}

}
void Ready(User* player1, User* player2, vector<std::unique_ptr<User>>& users)
{
	string command = "";
	string ready = "";
	PlayerCharacter* player1Hero = ChooseHero(player1, P1);
	setColor(Color::Green);
	cout << player1->getName() << " chose his hero!" << endl;
	setColor(Color::White);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	ConsoleClear();
	PlayerCharacter* player2Hero = ChooseHero(player2, P2);
	while (true)
	{
		try
		{
			cout << "Are you ready for battle?(Yes/No)(y/n)" << endl;
			cout << "The answer:";
			cin >> ready;
			if (ready == "Yes" || ready == "yes" || ready == "y")
			{
				while (true)
				{

					ConsoleClear();
					Battle(player1, player2, player1Hero, player2Hero);
					player1Hero->setHP(player1Hero->getMaxHP());
					player2Hero->setHP(player2Hero->getMaxHP());
					SaveAllInformation(users);
					cout << "Do you want to exit or try again?" << endl;
					cout << "Write \"exit\" or \"try\":";
					cin >> command;

					if (command == "exit")
					{
						
						break;
					}
					else if (command == "try")
					{
						cout << "Get start!" << endl;
					}
					else
					{
						throw Exceptions("Invalid command!!!");
					}
				}

				break;
			}
			else if (ready == "No" || ready == "no" || ready == "n")
			{
				ConsoleClear();
				setColor(Color::Yellow);
				cout << "Good!\nI will wait 5 seconds and ask again" << endl;
				setColor(Color::White);
				std::this_thread::sleep_for(std::chrono::seconds(5));
			}
			else
			{
				ConsoleClear();
				throw Exceptions("Invalid command!!!");
			}
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}


	}
}
void ChooseOneOfMainOptions(User* player1, User* player2, vector<std::unique_ptr<User>>& users,bool check)
{
	while (true)
	{
		try
		{
			string command = "";
			cout << "Player 1(" << player1->getName() << ") with "<<player1->getXP()<<"XP can choose one of theese six options(only by index or short name):" << endl;
			cout << "1) Player vs Player(PvP)" << endl;
			cout << "2) Player vs Computer(PvC)" << endl;
			cout << "3) Shop" << endl;
			cout << "4) Log Out (Logout)"<<endl;
			cout << "5) Exit"<<endl;
			cout << "6) RankList" << endl;
			cout << "Write the command here:";
			cin >> command;
			if (command == "1" || command == "1)" || ToLower(command) == "pvp")
			{
				try
				{
					player2=LogInOrCreateInGame(player2, P2, users,check);
					
				}
				catch (Exceptions ex)
				{
					Exceptions::ShowError(ex);
				}
				while (true)
				{
					try
					{
						Ready(player1,player2,users);

						break;
					}
					catch (Exceptions ex)
					{
						Exceptions::ShowError(ex);
					}
				}
				
				

			}
			else if (command == "2" || command == "2)" || ToLower(command) == "pvc")
			{
				throw Exceptions("This option is under development!!!");
			}
			else if (command == "3" || command == "3)" || ToLower(command) == "shop")
			{
				player1->Buy();
				SaveAllInformation(users);
			}
			else if (command == "4" || command == "4)" || ToLower(command) == "logout")
			{
				LogOut(player1,player2);
				break;
			}
			else if (command == "5" || command == "5)" || ToLower(command) == "exit")
			{
				setColor(Color::Yellow);
				cout << "End of the game!\nI hope you liked it!";
				setColor(Color::White);
				break;
			}
			else if (command == "6" || command == "6)" || ToLower(command) == "ranklist")
			{
				player1->RankList();
			}
			else
			{
				throw Exceptions("Inavlid option!!!");
			}
		}
		catch (Exceptions ex)
		{
			Exceptions::ShowError(ex);
		}
	}
}

void Inforation()
{
	string command = "";
	cout << "The main functionality of the game is the battle between two players.Each player must be registered with their own user profile.Each user can maintain more than one character in their user profile." << endl;
	cout << "The player who starts first is randomly selected.The battle is played in turns.During their turn, a player can:" << endl;
	setColor(Color::Red);
	cout << "- Attack:" << endl;
	setColor(Color::White);
	cout << "The attack deals a certain amount of damage to the opposing character." << endl;
	cout << "The amount of damage is randomly determined in an interval determined by the character type(see below)." << endl;
	cout << "The amount of damage is applied to the opposing character's HP." << endl;
	cout << "For example : a player deals 3 damage to an opponent with a current HP of 14. The opposing character's current HP is now 14 - 3 = 11." << endl;
	setColor(Color::Blue);
	cout << "- Uses a magic item." << endl;
	setColor(Color::White);
	cout << "See below for descriptions of magic items." << endl;
	cout << "A player can only use one of two actions during their turn.After performing this action, it is the next player's turn." << endl;
	cout << "The battle ends when a character\'s current HP reaches 0. Then the rewards (in XP, see below) are determined as follows:" << endl;
	cout << "- 10 XP for the winner." << endl;
	cout << "- 5 XP for the loser." << endl << endl;

	cout << "The hero type determines the hero\'s maximum HP, the range of damage he deals to the enemy, and the hero\'s special ability.The hero types are :" << endl;
	cout << "Warrior: HP 20, damage 1 - 8" << endl;
	cout << "Special ability - Block : " << endl;
	cout << "The warrior can block the attacks of the other hero.Every time the enemy attacks a warrior, the warrior randomly draws a number between 1 and 4." << endl;
	cout << "This number is subtracted from the Damage the enemy deals.This happens automatically before the warrior takes the damage.For example : the enemy deals 6 Damage to a warrior." << endl;
	cout << "The warrior randomly draws a number between 1 and 4 - he takes 3. He blocks 3 Damage and the Damage actually dealt to him is 6 - 3 = 3" << endl;
	cout << "Mage : HP 12, damage 1 - 12" << endl;
	cout << "Special ability - Damage reversal : " << endl;
	cout << "The mage can turn low damage into high damage.Whenever the wizard deals damage to his opponent, the wizard\'s player may decide to transform the damage according to the formula (newDamage = 12 - oldDamage)." << endl;
	cout << "For example: the wizard draws 1 Damage. His player activates his special ability and the damage becomes 12 - 1 = 11. " << endl;
	cout << "This ability is triggered at the player\'s discretion, after the initial damage has been determined, but before it is dealt to the opponent." << endl;
	cout << "Archer : HP 15, damage 1 - 8" << endl;
	cout << "Special ability - damage doubling : " << endl;
	cout << "If the archer deals damage that is between 1 and 4 inclusive, the archer may decide to double it." << endl;
	cout << "So Damage 1 becomes 2, 2 becomes 4, 3 becomes 6, and 4 becomes 8. This ability is triggered at the player\'s discretion, after the initial damage has been determined, but before it is dealt to the opponent." << endl;
	cout << "Special abilities count as part of a player\'s turn, but can be activated after a player has chosen to attack." << endl;
	cout << "Note that a player activates the wizard and archer special abilities, but the war special ability occurs automatically after each opponent's turn, and after activating it, the war player can make the usual choice between the actions of their turn - attack and use a magic item." << endl << endl;
	cout << "Click any button for return to main menu:";
	cin >> command;
}
void StartGame()
{
	vector<std::unique_ptr<User>> users;
	bool check = IsThereAProblemWithTheFile(users);
	User* player1 = nullptr;
	User* player2 = nullptr;
	try
	{
		player1 = LogInOrCreateInGame(player1, P1, users, check);
		ChooseOneOfMainOptions(player1, player2, users, check);
	}
	catch (Exceptions ex)
	{
		Exceptions::ShowError(ex);
	}
}
void Game()
{
	while(true)
	{
		string command = "";
		setColor(Color::Aqua);
		cout << "Get started RPG Battler!!!"<<endl<<endl;
		setColor(Color::White);
		cout << "The player can choose one of those options(start the game, give information for the game and exit from the game):"<<endl;
		setColor(Color::Green);
		cout << "1) Start"<<endl;
		setColor(Color::LightYellow);
		cout << "2) Information"<<endl;
		setColor(Color::Red);
		cout << "3) Exit (any button also can be used)" << endl;
		setColor(Color::White);
		cout << "Write one of the options:";
		cin >> command;
		ConsoleClear();
		if(command=="1" || command=="1)" || ToLower(command) =="start")
		{
			StartGame();
		}
		else if (command == "2" || command == "2)" || ToLower(command) == "information")
		{
			Inforation();
		}
		else
		{
			break;
		}
		ConsoleClear();
	}
	

}
int main()
{
	Game();
	return 0;
}