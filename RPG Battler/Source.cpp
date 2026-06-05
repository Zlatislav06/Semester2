#include "User.h"
const int STEPEN = 10;
const int P1 = 1;
const int P2 = 2;
double Percentage(std::unique_ptr<User> a)
{
	return ((double)a->getWinBattles() / (double)a->getBattles()) * 100;
}
void Sort(vector<std::unique_ptr<User>>& users)
{
	std::sort(users.begin(), users.end(),
		[](std::unique_ptr<User> a, std::unique_ptr<User> b)
		{
			if (a->getWinBattles() == b->getWinBattles())
			{
				if (a->getMaxXP() == b->getMaxXP())
				{
					return Percentage(std::make_unique<User>(a)) > Percentage(std::make_unique<User>(b));
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
		throw Exceptions("Invalid Value!!!");
	}
	return e;
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
void AddStarterCharacterInUser(User user)
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
			if (newHero == "1" && newHero == "1)" && newHero == "Mage")
			{
				user.AddStarterCharacter(new Mage(nameHero, user.getName()));
				break;
			}
			else if (newHero == "2" && newHero == "2)" && newHero == "Archer")
			{
				user.AddStarterCharacter(new Archer(nameHero, user.getName()));
				break;
			}
			else if (newHero == "3" && newHero == "3)" && newHero == "Warrior")
			{
				user.AddStarterCharacter(new Warrior(nameHero, user.getName()));
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
std::unique_ptr<User> CreateNewUser(string n, string p, vector<std::unique_ptr<User>>& users)
{
	User user = { n,p};
	AddStarterCharacterInUser(user);
	users.push_back(std::make_unique<User>(user));
	Sort(users);
	std::ofstream file("RankList.txt");
	for (int i = 0; i < users.size(); i++)
	{
		file << i + 1 << ") " << users[i]->getName();
		users[i]->setRank(i+1);
	}
	SaveInformation(user);
	file.close();

	return std::make_unique<User>(user);
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

Items* ConvertFromStringToItem(string str)
{
	Items* item=nullptr;
	if (str == "HealingPoltion")
	{
		item = new HealingPoltion();
	}
	else if (str == "Blade")
	{
		item = new Blade();
	}
	else if (str == "Mirror")
	{
		item =new Mirror();
	}
	else if (str == "Ray")
	{
		item = new Ray();
	}
	else if (str == "Shield")
	{
		item = new Shield();
	}
	else
	{
		throw Exceptions("Invalid Value!!!");
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
		
			hero = new Warrior(n, un, h, max, d, l);
			break;
		}
		case HeroType::Mage:
		{
			
			hero = new Mage{ n,un, h,max, d, l };
			break;
		}
		case HeroType::Archer:
		{
			
			hero = new Archer{ n,un, h,max, d, l };
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
		vector<PlayerCharacter*> ch;
		if (sizeCharacters != 0)
		{
			std::getline(file, line);
			ch = TakeHeroesFromString(line, sizeCharacters, index, name);
			index = 0;
		}
		std::getline(file, line);
		int sizeItems = stoi(line);
		vector<Items*> items;
		if (sizeItems != 0)
		{
			index = 0;
			std::getline(file, line);
			items = TakeItemsFromString(line, sizeItems, index);
		}
		users.push_back(std::make_unique<User>(new User(name, password, XP, maxXP, ch, items, battles, winBattles, rank)));
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
std::unique_ptr<User> FindUser(string& name, string& password, vector<std::unique_ptr<User>>& users)
{
	while (true)
	{
		
			cout << "Enter your username:";
			cin >> name;
			cout << "Enter valid password:";
			cin >> password;
			auto it = std::find_if(users.begin(), users.end(), [&](const std::unique_ptr<User> x)
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
				return (std::make_unique<User>(it));
				
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
void LogInOrCreateGame(std::unique_ptr<User> player,int indexOfPlayer, vector<std::unique_ptr<User>>& users)
{
	bool check = IsThereAProblemWithTheFile(users);
	string command = "";
	cout << "Hello player "<<indexOfPlayer<<", to play this game you need to log in, and if you don't have one you can create one." << endl;
	cout << "Now you can choose one of those two options:" << endl;
	cout << "1) Create" << endl;
	
	if (check)
	{
		cout << "2) Log in" << endl;
	}
	cin >> command;
	if (command == "1" || command == "1)" || command == "Create")
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
	else if (command == "2" || command == "2)" || command == "Log in")
	{
		string name = "";
		string password = "";
		player = FindUser(name, password, users);
	}
	else
	{
		throw Exceptions("Invalid command!!!");
	}
	ConsoleClear();
	setColor(Color::LightGreen);
	cout << "Player " << indexOfPlayer << " is now log in!!!" << endl;
	setColor(Color::White);
}
int main()
{
	vector<std::unique_ptr<User>> users;
	std::unique_ptr<User> player1 = nullptr;
	std::unique_ptr<User> player2 = nullptr;
	try
	{
		LogInOrCreateGame(std::make_unique<User>(player1), P1, users);
	}
	catch (Exceptions ex)
	{
		Exceptions::ShowError(ex);
	}
	
	while (true)
	{
		try
		{
			string command = "";
			cout << "Player 1(" << player1->getName() << ") can choose one of this three options:" << endl;
			cout << "1) Player vs Player" << endl;
			cout << "2) Player vs Computer" << endl;
			cout << "3) shop" << endl;
			cin >> command;
			if (command == "1" && command == "1)" && command == "Player vs Player")
			{
				try
				{
					LogInOrCreateGame(std::make_unique<User>(player2), P2, users);
				}
				catch (Exceptions ex)
				{
					Exceptions::ShowError(ex);
				}
				cout << "Player 1(" << player1->getName() << ") can choose one of his characters:" << endl;
				int size = player1->getCharacters().size();
				vector<PlayerCharacter*> player1Characters = player1->getCharacters();
				PlayerCharacter* player1Hero = nullptr;
				if (size> 1)
				{
					for (int i = 0; i < size; i++)
					{
						cout << i + 1 << ") " << player1Characters[i]->getName()<<endl;
					}
				}
				else if(size==1)
				{

					player1Hero = player1Characters[0];
					cout << "You have only one hero. Therefore " << player1->getName() << " will play with "<<player1Hero->getName()<<".";
					
				}
				else
				{
					throw Exceptions("Invlid count of heroes!!!");
				}
				break;
			}
			else if (command == "2" && command == "2)" && command == "Player vs Computer")
			{
				throw Exceptions("This option is under development!!!");
			}
			else if (command == "3" && command == "3)" && command == "shop")
			{
				player1->Buy();
				
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
	
	

	

	

	return 0;
}