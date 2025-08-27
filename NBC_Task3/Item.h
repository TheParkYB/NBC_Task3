#pragma once
#include <string>
using namespace std;

//아이템 종류
enum class ItemType
{
	None,
	Weapon,
	Consume
};

class Item
{
public:
	//기본적으로 사용할 생성자
	Item(string name = "", int price = 0);

	//지정한 아이템을 복사하여 생성
	Item(Item* original);

	string GetName() const;
	int GetPrice() const;
	ItemType GetItemType() const;

protected:
	string name;//이름
	int price;//가격
	ItemType itemType;//아이템 종류
};