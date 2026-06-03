#include "User.h"

User::User(string n, string p, int xp,int maxxp, vector<PlayerCharacter*> c, vector<Items*> i, int b, int wb, int r)
{
	name = n;
	setPassword(p);
	characters = c;
	items = i;
	XP = xp;
	maxXP = maxxp;
	battles = b;
	winBattles = wb;
	rank = r;


}
User::User(string n, string p)
{
	std::vector<PlayerCharacter*> c;
	std::vector<Items*> i;
	name = n;
	setPassword(p);
	characters =c;
	characters = c; 
	items = i;
	rank = 1;
}
//Character's metods for function "Buy"
bool User::CheckCharacter(const HeroType n)
{
	bool check = true;
	for (PlayerCharacter* x : characters)
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
PlayerCharacter* User::WhoIsCharacter(string nameOfHero, const HeroType h)
{
	PlayerCharacter* p=nullptr;
	if (h == HeroType::Warrior)
	{
		Warrior wariior = { nameOfHero,name};
		p = &wariior;
	}
	if (h == HeroType::Archer)
	{
		Archer archer = { nameOfHero,name };
		p = &archer;
	}
	if (h == HeroType::Mage)
	{
		Mage mage = { nameOfHero,name };
		p= &mage;
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
		PlayerCharacter* p = WhoIsCharacter(nameOfHero, h);
		if (XP >= prize)
		{
			characters.push_back(p);
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
		cout << "Choose hero type, which you want to buy(cost 50XP):\n1) Warrior\n2) Archer\n3) Mage" << endl;
		int prizeInXpForHero = 50;
		string typeHero = "";
		cin >> typeHero;
		ConsoleClear();
		if (typeHero == "Warrior" || typeHero == "1" || typeHero == "1)")
		{
			HeroType h = HeroType::Warrior;
			AddCharacter(h, prizeInXpForHero);
		}
		else if (typeHero == "Archer" || typeHero == "2" || typeHero == "2)")
		{
			HeroType h = HeroType::Archer;
			AddCharacter(h, prizeInXpForHero);
		}
		else if (typeHero == "Mage" || typeHero == "3" || typeHero == "3)")
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
Items* User::WhoIsItem(const ItemsType itemtype)
{
	Items* items=nullptr;
	switch (itemtype)
	{
		case ItemsType::HealingPoltion:
			{
				HealingPoltion hp = {};
				items = &hp;
				break;
			}
		case ItemsType::Blade:
		{
			Blade blade = {};
			items = &blade;
			break;
		}
		case ItemsType::Mirror:
		{
			Mirror mirror = {};
			items = &mirror;
			break;
		}
		case ItemsType::Ray:
		{
			Ray ray = {};
			items = &ray;
			break;
		}
		case ItemsType::Shield:
		{
			Shield shield = {};
			items = &shield;
			break;
		}
		default:
		{
			setColor(Color::Red);
			cout << "Inavlid value!!!" << endl;
			setColor(Color::White);
			break;
		}
			
	}
	return items;
}
void User::AddItem(const ItemsType t)
{
	Items* it = WhoIsItem(t);
	int prizeInXpForHero = it->getPrize();
	if (XP >= prizeInXpForHero)
	{
		setColor(Color::Green);
		cout << "You buy the item!";
		setColor(Color::White);
		XP = XP - prizeInXpForHero;
		items.push_back(it);
	}
	else
	{
		setColor(Color::Red);
		cout << "You can't afford this item!" << endl;
		setColor(Color::White);
	}
}
void User::BuyItem()
{
	cout << "Choose item, which you want to buy:\n1) HealingPoltion\n2) Blade\n3) Mirror\n4) Ray\n5) Shield" << endl;
	string nameItem = "";
	cin >> nameItem;
	ConsoleClear();
	if (nameItem == "HealingPoltion" || nameItem == "1" || nameItem == "1)")
	{
		ItemsType t = ItemsType::HealingPoltion;
		AddItem(t);
	}
	else if (nameItem == "Blade" || nameItem == "2" || nameItem == "2)")
	{
		ItemsType t = ItemsType::Blade;
		AddItem(t);
	}
	else if (nameItem == "Mirror" || nameItem == "3" || nameItem == "3)")
	{
		ItemsType t = ItemsType::Mirror;
		AddItem(t);
	}
	else if (nameItem == "Ray" || nameItem == "4" || nameItem == "4)")
	{
		ItemsType t = ItemsType::Ray;
		AddItem(t);
	}
	else if (nameItem == "Shield" || nameItem == "5" || nameItem == "5)")
	{
		ItemsType t = ItemsType::Shield;
		AddItem(t);
	}
	else
	{
		setColor(Color::Red);
		cout << "Invalid value!!!" << endl;
		setColor(Color::White);
	}
}
//Leval's metods for function "Buy"
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
	else
	{
		setColor(Color::Red);
		cout << "Invalid value!!!" << endl;
		setColor(Color::White);
	}
	return h;
}
void User::SelectOptionAfterLevelUp(PlayerCharacter* it)
{
	string options = "";
	cout << "Now you can choose two options:\n1) Increase the character's maximum HP with 2\nIncrease the character's maximum damage with 1" << endl;
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
		setColor(Color::Red);
		cout << "Invalid value!!!" << endl;
		setColor(Color::White);
	}
}
void User::FindAndPrintForLevalUp(string select,int prize)
{
	auto it = std::find_if(characters.begin(), characters.end(),
		[&](PlayerCharacter* x)
		{
			return x->getHeroType() == ConvertStringToHeroType(select)
			|| x->getName() == select;
		});

	if (it != characters.end()) {
		SelectOptionAfterLevelUp(*it);
		XP = XP - prize;
		(*it)->setLeval((*it)->getLeval() + 1);
		
		setColor(Color::Green);
		cout << "You leval up the hero " << (*it)->getName() << ". Now he is leval" << (*it)->getLeval()<<endl<<endl;
		(*it)->Print();
		setColor(Color::White);
	}
	else
	{
		setColor(Color::Red);
		cout << name << "Don't have this type of hero or hero named so!" << endl;
		setColor(Color::White);
	}
}
void User::LevalUp()
{
	int prizeForLeval = 100;
	if (XP >= prizeForLeval)
	{
		string select = "";
		cout << "Select a character to level up (costs 100XP) by typing their name or type:" << endl;
		for (PlayerCharacter* x : characters)
		{
			x->Print();
			cout << endl << endl;
		}
		cin >> select;
		ConsoleClear();
		FindAndPrintForLevalUp(select, prizeForLeval);
	}
	else
	{
		setColor(Color::Red);
		cout << "You can't afford to leval up!" << endl;
		setColor(Color::White);
	}
}
//User's main metods
void User::Buy()
{
	string category = "";
	cout << "From what category, you want to buy:\n1) Characters\n2) Items\n3) Leval" << endl;
	cin >> category;
	if (category == "Characters" || category == "1" || category == "1)")
	{
		BuyCharacter();
	}
	else if (category == "Items" || category == "2" || category == "2)")
	{
		BuyItem();
	}
	else if (category == "Leval" || category == "3" || category == "3)")
	{
		LevalUp();
	}
	else
	{
		cout << "Invalid purchase!!!";
	}
}

void User::RankList()
{
	std::ifstream file("RankList.txt");
	string line;
	while (std::getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}


void User::Use(Items* item,PlayerCharacter& P)
{
	string inf = "";
	bool check = false;
	for (Items* x : items)
	{
		if (x->getType() == item->getType())
		{
			check = true;
			break;
		}
	}
	if (check)
	{
		std::erase_if(items, [&](Items* x) {return x->getType() == item->getType(); });
		setColor(Color::Green);
		cout << "You use this item!";
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
		
		throw Exeptions("You don't have this item");
		
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
const vector<PlayerCharacter*>&  User::getCharacters() const
{
	return characters;
}
const vector<Items*>& User::getItems() const
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
		throw Exeptions("Invalid password!!!");
	}
	
}
void User::setXP(int xp)
{
	XP = xp;
}
void User::setMaxXP(int xp)
{
	maxXP = xp;
}
void User::setBattles(int b)
{
	battles = b;
}
void User::setWinBattles(int wb)
{
	winBattles = wb;
}
void User::setRank(int r)
{
	rank = r;
}