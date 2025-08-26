#pragma once
#include "Item.h"

class WeaponItem : public Item
{
public:
	WeaponItem(string name, int price, int durability = 1);

	int GetDurability();
	void SetDurability(int value);

	void AddDurability(int value);

private:
	int durability;
};

class ConsumeItem : public Item
{
public:
	ConsumeItem(string name, int price, int count = 1);

	int GetCount();
	void SetCount(int value);

	void AddCount(int value);

private:
	int count;
};