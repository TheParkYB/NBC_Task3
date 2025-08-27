#include "ItemEx.h"

#pragma region WeaponItem

WeaponItem::WeaponItem(string name, int price, int durability) : Item(name, price)
{
	this->durability = durability;
	itemType = ItemType::Weapon;
}

WeaponItem::WeaponItem(WeaponItem* original) : Item(original)
{
	durability = original->durability;
	itemType = ItemType::Weapon;
}

int WeaponItem::GetDurability()
{
	return durability;
}

void WeaponItem::SetDurability(int value)
{
	durability = value;
}

void WeaponItem::AddDurability(int value)
{
	durability += value;
}

#pragma endregion

#pragma region ConsumeItem

ConsumeItem::ConsumeItem(string name, int price, int count) : Item(name, price)
{
	this->count = count;
	itemType = ItemType::Consume;
}

ConsumeItem::ConsumeItem(ConsumeItem* original) : Item(original)
{
	count = original->count;
	itemType = ItemType::Consume;
}

int ConsumeItem::GetCount()
{
	return count;
}

void ConsumeItem::SetCount(int value)
{
	count = value;
}

void ConsumeItem::AddCount(int value)
{
	count += value;
}

#pragma endregion
