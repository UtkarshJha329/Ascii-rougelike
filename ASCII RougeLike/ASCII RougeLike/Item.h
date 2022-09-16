#pragma once
#include <string>

class Item
{
public:
	Item(std::string name, int cost, int effectValue);
	bool operator== (const Item& item) {
		return (_name.compare(item.Name()) == 0) && (_cost == item.Cost()) && (_effectValue == item.effectValue());
	}

	/*bool Equals(Item& item);*/

	//Gettters
	const std::string Name() const;
	const int Cost() const;
	const int effectValue() const;
	const int Count() const;

public:
	int count = 1;

private:
	std::string _name;
	int _cost;
	int _effectValue;
};

