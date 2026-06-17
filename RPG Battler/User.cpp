#include "User.h"
bool DoYouHaveThisItem(const vector<std::unique_ptr<Items>>& items, std::unique_ptr<Items>& item)
{
	
	bool check = false;
	for (const std::unique_ptr<Items>& x : items)
	{
		if (x->getType() == item->getType())
		{
			check = true;
			break;
		}
	}
	return check;
}
User::User(string n, string p, int xp, int maxxp, vector<std::unique_ptr<PlayerCharacter>> c, vector<std::unique_ptr<Items>> i, int b, int wb, int r)
{
	name = n;
	setPassword(p);
	characters = std::move(c);
	items = std::move(i);
	XP = xp;
	maxXP = maxxp;
	battles = b;
	winBattles = wb;
	rank = r;


}
User::User(string n, string p)
	: name(n), rank(1)
{
	setPassword(p);
}
string User::ConvertItemTypeToString(ItemsType e)
{
	string itemType = "";
	switch (e)
	{
		case ItemsType::HealingPoltion: 
		{
			itemType = "HealingPotion";
			break;
		}
		case ItemsType::Blade:
		{
			itemType = "Blade";
			break;
		}
		case ItemsType::Mirror:
		{
			itemType = "Mirror";
			break;
		}
		case ItemsType::Ray:
		{
			itemType = "Ray";
			break;
		}
		case ItemsType::Shield:
		{
			itemType = "Shield";
			break;
		}
	}
	return itemType;
}
//Character's metods for function "Buy"
bool User::CheckCharacter(const HeroType n)
{
	bool check = true;
	for (std::unique_ptr<PlayerCharacter>& x : characters)
	{
		if (x->getHeroType() == n)
		{
			setColor(Color::Red);
			cout <<"You have this type of character and you can't buy another one!"<<endl;
			setColor(Color::White);
			check = false;
			break;
		}
	}
	return check;
}
std::unique_ptr<PlayerCharacter> User::WhoIsCharacter(string nameOfHero, const HeroType h)
{
	std::unique_ptr<PlayerCharacter> p=nullptr;
	if (h == HeroType::Warrior)
	{
		p = std::make_unique<Warrior>(nameOfHero, name);
	}
	if (h == HeroType::Archer)
	{
		p = std::make_unique<Archer>(nameOfHero, name);
	}
	if (h == HeroType::Mage)
	{
		p = std::make_unique<Mage>(nameOfHero, name);
	}
	return p;
}
void User::AddCharacter(const HeroType h,int prize)
{
	if (CheckCharacter(h))
	{
		cout << "Choose name of your new character:" << endl;
		string nameOfHero = "";
		cin >> nameOfHero;
		std::unique_ptr<PlayerCharacter> p = WhoIsCharacter(nameOfHero, h);
		if (XP >= prize)
		{
			characters.push_back(std::move(p));
			XP = XP - prize;
		}
		else
		{
			setColor(Color::Red);
			cout << "You can't afford this character!" << endl;
			setColor(Color::White);
		}
		
	}
}
void  User::BuyCharacter()
{
	if (characters.size() < 3)
	{
		cout << "Choose hero type, which you want to buy(cost 50XP):\n1) Warrior\n2) Archer\n3) Mage\n4) Exit" << endl;
		int prizeInXpForHero = 50;
		string typeHero = "";
		cin >> typeHero;
		ConsoleClear();
		if (ToLower(typeHero) == "warrior" || typeHero == "1" || typeHero == "1)")
		{
			HeroType h = HeroType::Warrior;
			AddCharacter(h, prizeInXpForHero);
		}
		else if (ToLower(typeHero) == "archer" || typeHero == "2" || typeHero == "2)")
		{
			HeroType h = HeroType::Archer;
			AddCharacter(h, prizeInXpForHero);
		}
		else if (ToLower(typeHero) == "mage" || typeHero == "3" || typeHero == "3)")
		{
			HeroType h = HeroType::Mage;
			AddCharacter(h, prizeInXpForHero);
		}
		else if (ToLower(typeHero) == "exit" || typeHero == "3" || typeHero == "3)")
		{
			HeroType h = HeroType::Mage;
			AddCharacter(h, prizeInXpForHero);
		}

	}
	else if (characters.size() == 3)
	{
		setColor(Color::Yellow);
		cout << "You have from all types of characters! You don't need another one!";
		setColor(Color::White);
	}
	else
	{
		setColor(Color::Red);
		cout << "Invalid value!!!";
		setColor(Color::White);
	}
}
//Item's metods for function "Buy"
std::unique_ptr<Items> User::WhoIsItem(const ItemsType itemtype)
{
	std::unique_ptr<Items> items=nullptr;
	switch (itemtype)
	{
		case ItemsType::HealingPoltion:
			{
				
				items = std::make_unique<HealingPoltion>();
				break;
			}
		case ItemsType::Blade:
		{
			items = std::make_unique<Blade>();
			break;
		}
		case ItemsType::Mirror:
		{
			items = std::make_unique<Mirror>();
			break;
		}
		case ItemsType::Ray:
		{
			items = std::make_unique<Ray>();
			break;
		}
		case ItemsType::Shield:
		{
			items = std::make_unique<Shield>();
			break;
		}
		default:
		{
			throw Exceptions("Inalid value!!!");
			break;
		}
			
	}
	return items;
}
void User::AddItem(const ItemsType t)
{
	std::unique_ptr<Items> it = WhoIsItem(t);
	int prizeInXpForHero = it->getPrize();
	if (XP >= prizeInXpForHero)
	{
		setColor(Color::Green);
		cout << "You buy the item!"<<endl;
		setColor(Color::White);
		XP = XP - prizeInXpForHero;
		items.push_back(std::move(it));
	}
	else
	{
		throw Exceptions("You can't afford this item!");
	}
}
void User::BuyItem()
{
	cout << "Choose item, which you want to buy:\n1) HealingPotion (30XP)\n2) Blade (50XP)\n3) Mirror (80XP)\n4) Ray (90XP)\n5) Shield (100XP) \n6) Exit" << endl;
	string nameItem = "";
	cout << "Write name or index of your item:";
	cin >> nameItem;
	ConsoleClear();
	if (ToLower(nameItem) == "healingpotion" || nameItem == "1" || nameItem == "1)")
	{
		ItemsType t = ItemsType::HealingPoltion;
		AddItem(t);
	}
	else if (ToLower(nameItem) == "blade" || nameItem == "2" || nameItem == "2)")
	{
		ItemsType t = ItemsType::Blade;
		AddItem(t);
	}
	else if (ToLower(nameItem) == "mirror" || nameItem == "3" || nameItem == "3)")
	{
		ItemsType t = ItemsType::Mirror;
		AddItem(t);
	}
	else if (ToLower(nameItem) == "ray" || nameItem == "4" || nameItem == "4)")
	{
		ItemsType t = ItemsType::Ray;
		AddItem(t);
	}
	else if (ToLower(nameItem) == "shield" || nameItem == "5" || nameItem == "5)")
	{
		ItemsType t = ItemsType::Shield;
		AddItem(t);
	}
	else if (ToLower(nameItem) == "exit" || nameItem == "6" || nameItem == "6)")
	{
		return;
	}
	else
	{
		throw Exceptions("Inalid value!!!");
	}
}
//Level's metods for function "Buy"
HeroType User::ConvertStringToHeroType(string str)
{
	HeroType h=HeroType::Warrior;;
	if (str == "Warrior")
	{
		h = HeroType::Warrior;
	}
	else if (str == "Archer")
	{
		h = HeroType::Archer;
	}
	else if (str == "Mage")
	{
		h = HeroType::Mage;
	}
	return h;
}
void User::SelectOptionAfterLevelUp(std::unique_ptr<PlayerCharacter>& it)
{
	string options = "";
	cout << "Now you can choose two options:\n1) Increase the character's maximum HP with 2\n2) Increase the character's maximum damage with 1" << endl;
	cin >> options;
	if (options == "1" || options == "1)")
	{
		(it)->setMaxHP((it)->getMaxHP() + 2);
	}
	else if (options == "2" || options == "2)")
	{
		(it)->setDamage((it)->getDamage() + 1);
	}
	else
	{
		throw Exceptions("Inalid value!!!");
	}
}
void User::FindAndPrintForLevelUp(string select,int prize)
{

	auto it = std::find_if(characters.begin(), characters.end(),
		[&](std::unique_ptr<PlayerCharacter>& x)
		{
			return x->getHeroType() == ConvertStringToHeroType(select)
			|| x->getName() == select;
		});

	if (it == characters.end()) 
	{
		throw Exceptions(name + "don't have this type of hero or hero named so!");
	}
	else
	{
		
		SelectOptionAfterLevelUp(*it);
		XP = XP - prize;
		(*it)->setLevel((*it)->getLevel() + 1);
		(*it)->setHP((*it)->getMaxHP());
		setColor(Color::Green);
		cout << "You level up the hero " << (*it)->getName() << ". Now he is level" << (*it)->getLevel()<<endl<<endl;
		(*it)->Print();
		setColor(Color::White);
		
		
	}
}
void User::LevelUp()
{
	int prizeForLevel = 100;
	if (XP >= prizeForLevel)
	{
		string select = "";
		cout << "Select a character to level up (costs 100XP) by typing their name or type:" << endl;
		for (std::unique_ptr<PlayerCharacter>& x : characters)
		{
			x->Print();
			cout << endl << endl;
		}
		cout << "Write who character you will level up:";
		cin >> select;
		ConsoleClear();
		FindAndPrintForLevelUp(select, prizeForLevel);

	}
	else
	{
		throw Exceptions("You can't afford to level up!");
	}
}
//User's main metods
void User::Buy()
{
	string category = "";
	cout << "From what category, you want to buy:\n1) Characters\n2) Items\n3) Level (Level up one of your characters(cost 100XP))\n4) Exit" << endl;
	cin >> category;
	if (ToLower(category) == "characters" || category == "1" || category == "1)")
	{
		BuyCharacter();
	}
	else if (ToLower(category) == "items" || category == "2" || category == "2)")
	{
		BuyItem();
	}
	else if (ToLower(category) == "level" || category == "3" || category == "3)")
	{
		LevelUp();
	}
	else if (ToLower(category) == "exit" || category == "4" || category == "4)")
	{
		setColor(Color::Red);
		cout << "You exit from shop!"<<endl;
		setColor(Color::White);
	}
	else
	{
		throw Exceptions("Invalid purchase!!!");
	}
}

void User::RankList()
{

	cout << "This is list of players( arranged by wins, XP ever received and percentage of wins in relation to total battles played):" << endl;
	std::ifstream file("RankList.txt");
	string line;
	while (std::getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}
void User::AddStarterCharacter(std::unique_ptr<PlayerCharacter> P)
{
	auto it =std::find_if(characters.begin(), characters.end(), [&](std::unique_ptr<PlayerCharacter>& x)
		{
			return x->getHeroType() == P->getHeroType(); 
		});
	if (it == characters.end())
	{
		characters.push_back(std::move(P));
	}
	else
	{
		throw Exceptions("There cannot be two of the same character types for one user!!!\nTry Again!!!");
	}
	
}
void User::AddStarterItem(std::unique_ptr<Items> item)
{
	items.push_back(std::move(item));
}
void User::Use(std::unique_ptr<Items> item, PlayerCharacter& P)
{
	string inf = "";
	if (DoYouHaveThisItem(items,item))
	{
		int removed= std::erase_if(items, [&](const std::unique_ptr<Items>& x) {return x->getType() == item->getType(); });
		if (removed > 1)
		{
			for (int i = 0; i < (removed - 1); i++)
			{
				items.push_back(WhoIsItem(item->getType()));
			}
		}
		setColor(Color::Green);
		cout << "You use this item!"<<endl;
		setColor(Color::White);
		int indexOfItem = (int)item->getType();
		P.usingItems[indexOfItem] = true;
		if (indexOfItem == (int)ItemsType::HealingPoltion)
		{
			HealingPoltion healingPoltion = {};
			
			healingPoltion.UseItem(P,inf);
		}
	}
	else
	{
		
		throw Exceptions("You don't have this item");
		
	}
	

}

void User::PrintItems()
{
	if (items.size() == 0)
	{
		setColor(Color::Red);
		cout << "You don't have items!"<<endl;
		setColor(Color::White);
	}
	else
	{
		cout << "Theese are your items:" << endl;
		for (std::unique_ptr<Items>& x : items)
		{
			cout << ConvertItemTypeToString(x->getType()) << endl;
		}
	}
	
}
bool User::isValidPassword(const string& password)
{
	if (password.length() < 8)
	{
		return false;
	}

	bool hasUpper = false;
	bool hasLower = false;
	bool hasDigit = false;
	bool hasSpecial = false;

	for (char ch : password)
	{
		if (std::isupper(ch))
		{
			hasUpper = true;
		}
		else if (std::islower(ch))
		{
			hasLower = true;
		}
		else if (std::isdigit(ch))
		{
			hasDigit = true;
		}
		else
		{
			hasSpecial = true;
		}
	}

	return hasUpper && hasLower
		&& hasDigit && hasSpecial;
}

const string& User::getName() const
{
	return name;
}
const string& User::getPassword() const
{
	return password;
}
const int& User::getXP() const
{
	return XP;
}
const int& User::getMaxXP() const
{
	return maxXP;
}
const int& User::getBattles() const
{
	return battles;
}
const int& User::getWinBattles() const
{
	return winBattles;
}
const int& User::getRank() const
{
	return rank;
}
const vector<std::unique_ptr<PlayerCharacter>>&  User::getCharacters() const
{
	return characters;
}
const vector<std::unique_ptr<Items>>& User::getItems() const
{
	return items;
}
void User::setName(string n)
{
	name = n;
}
void User::setPassword(string p)
{
	if (isValidPassword(p))
	{
		password = p;
	}
	else
	{
		throw Exceptions("Invalid password!!!");
	}
	
}
void User::setXP(int xp)
{
	if (xp >= 0)
	{
		XP = xp;
	}
	else
	{
		throw Exceptions("Experience points can't be less then zero!!!");
	}
	
}
void User::setMaxXP(int xp)
{
	if (xp >= 0)
	{
		maxXP = xp;
	}
	else
	{
		throw Exceptions("Max experience points can't be less then zero!!!");
	}
}
void User::setBattles(int b)
{
	if (battles >= 0)
	{
		battles = b;
	}
	else
	{
		throw Exceptions("Battles can't be less then zero!!!");
	}
	
}
void User::setWinBattles(int wb)
{
	if (winBattles >= 0)
	{
		winBattles = wb;
	}
	else
	{
		throw Exceptions("Wins can't be less then zero!!!");
	}
	
}
void User::setRank(int r)
{
	if (rank >= r)
	{
		rank = r;
	}
	else
	{
		throw Exceptions("Rank can't be less then zero!!!");
	}
	
}