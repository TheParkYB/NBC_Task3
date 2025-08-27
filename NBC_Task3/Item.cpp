#include "Item.h"

Item::Item(string name, int price)
{
	this->name = name;
	this->price = price;
	itemType = ItemType::None;
}

Item::Item(Item* original)
{
	name = original->name;
	price = original->price;
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
