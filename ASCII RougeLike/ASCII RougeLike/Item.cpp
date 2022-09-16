#include "Item.h"

Item::Item(std::string name, int cost, int effectValue)
{
	_name = name;
	_cost = cost;
	_effectValue = effectValue;

}

//bool Item::Equals(Item&  item)
//{
//	return (_cost == item.Cost())
//		 && (_name == item.Name())
//		 && (_effectValue == item.effectValue());
//}

const std::string Item::Name() const
{
	return _name;
}

const int Item::Cost() const
{
	return _cost;
}

const int Item::effectValue() const
{
	return _effectValue;
}

const int Item::Count() const
{
	return count;
}

