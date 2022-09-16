#include <iostream>
#include <list>
#include <string>
#include "Inventory.h"


Inventory::Inventory()
{
}

Inventory::Inventory(std::string name, int money)
{
	_name = name;
	_money = money;
}

void Inventory::INIT(std::string name, int money)
{
	_name = name;
	_money = money;
}

bool Inventory::Buy(Inventory & otherInv, Item& itemToBuy, int& money)
{
	if (itemToBuy.Cost() <= _money) {
		if (otherInv.RemoveItem(itemToBuy)) {
			if (this->AddItem(itemToBuy)) {
				_money -= itemToBuy.Cost();
				money -= itemToBuy.Cost();
				otherInv.Money(otherInv.Money() + itemToBuy.Cost());
				return true;
			}
		}
	}

	return false;
}

bool Inventory::AddItem(Item & newItem)
{
	std::list<Item>::iterator itemIt;
	for (itemIt = items.begin(); itemIt != items.end(); itemIt++) {
		if ((*itemIt) == newItem) {
			(*itemIt).count++;
			return true;
		}
	}

	items.push_back(newItem);
	items.back().count = 1;
	return true;

}

bool Inventory::RemoveItem(Item& item)
{
	std::list<Item>::iterator itemIt;
	for (itemIt = items.begin(); itemIt != items.end(); itemIt++) {
		//std::cout << (*itemIt).Name() << std::endl;
		if (*itemIt == item) {
			(*itemIt).count--;
			if ((*itemIt).count <= 0) {
				items.erase(itemIt);
			}
			return true;
		}
	}
	return false;
}

Item Inventory::ItemAtIndex(int index)
{
	int i = 0;
	std::list<Item>::iterator itemIt;
	for (itemIt = items.begin(); itemIt != items.end(); itemIt++) {
		if (i == index) {
			return *itemIt;
		}
		i++;
	}
}

void Inventory::PrintInventory()
{
	std::cout << "Money: " << _money << std::endl;
	int i = 0;
	std::list<Item>::iterator itemIt;
	for (itemIt = items.begin(); itemIt != items.end(); itemIt++) {

		std::cout << "\t" << i << ") " << (*itemIt).Name() << "   X" << (*itemIt).count << "    Cost: " << (*itemIt).Cost() << std::endl;
		i++;
	}
}

int Inventory::Money()
{
	return _money;
}

void Inventory::Money(int money)
{
	_money = money;
}

