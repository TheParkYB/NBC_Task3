#include "Item.h"

Item::Item(string name, int price)
{
	this->name = name;
	this->price = price;
	itemType = ItemType::None;
}

string Item::GetName() const
{
	return name;
}

int Item::GetPrice() const
{
	return price;
}

ItemType Item::GetItemType() const
{
	return itemType;
}
