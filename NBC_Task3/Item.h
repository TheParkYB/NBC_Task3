#pragma once
#include <string>
using namespace std;

enum class ItemType
{
	None,
	Weapon,
	Consume
};

class Item
{
public:
	Item(string name = "", int price = 0);

	string GetName() const;
	int GetPrice() const;
	ItemType GetItemType() const;

protected:
	string name;
	int price;
	ItemType itemType;
};