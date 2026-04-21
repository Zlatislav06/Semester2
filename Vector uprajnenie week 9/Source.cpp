#include <iostream> 
#include <memory>
#include "Contacts.h";
#include "NumberList.h"
#include "Box.h"
#include "Book.h"
int main()
{
	//zad 1
	Contact a("Ivan", "0891234566");
	Contact b("Zhari", "08912345");
	Contact c = {};
	Contacts z;
	z.addContact(a);
	z.addContact(b);
	z.addContact(c);
	z.findContact(a.getName());
	z.printAll();
	//zad 2
	NumberList n;
	n.addNum(1);
	n.addNum(3);
	n.addNum(3);
	n.addNum(7);
	n.addNum(5);
	n.addNum(8);
	n.addNum(11);
	n.addNum(0);
	n.sortAsending();
	n.printAll();
	n.sortDesending();
	n.printAll();
	//zad 3
	std::unique_ptr<Box> simpleBox = std::make_unique<Box>();
	Box* m = simpleBox.get();
	cout<<m->getWeight();
	// zad 4
	cout << endl<<endl;
	std::shared_ptr<Book> book1 = std::make_shared<Book>("Winnie-the-Pooh");
	std::shared_ptr<Book> book2 = book1;
	cout << book1.use_count();
	cout << endl;
	book2 = std::make_shared<Book>("Little Red Riding Hood");
	Book* g = book1.get();
	cout << g->getTitle();
	return 0;
}