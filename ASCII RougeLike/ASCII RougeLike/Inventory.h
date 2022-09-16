#pragma once
#include <string>
#include <list>
#include "Item.h"

class Inventory
{
public:
	//Constructor
	Inventory();
	Inventory(std::string name, int money);
	void INIT(std::string name, int money);
	//Functions of inventory
	bool Buy(Inventory& otherInv, Item& itemToBuy, int& money);
	bool AddItem(Item& newItem);
	bool RemoveItem(Item& newItem);

	Item ItemAtIndex(int index);

	void PrintInventory();

	//Getters
	int Money();
	int NumItems() { return items.size(); }
	const std::string Name() { return _name; }
	//Setters
	void Money(int money);

private:
	std::string _name;
	int _money;
	std::list<Item> items;
};

