#pragma once
#include "Item.h"

class WeaponItem : public Item
{
public:
	//기본적으로 사용할 생성자
	WeaponItem(string name, int price, int durability = 1);
	//지정한 아이템을 복사하여 생성
	WeaponItem(WeaponItem* original);

	int GetDurability();
	void SetDurability(int value);

	void AddDurability(int value);

private:
	int durability;//내구도
};

class ConsumeItem : public Item
{
public:
	//기본적으로 사용할 생성자
	ConsumeItem(string name, int price, int count = 1);
	//지정한 아이템을 복사하여 생성
	ConsumeItem(ConsumeItem* original);

	int GetCount();
	void SetCount(int value);

	void AddCount(int value);

private:
	int count;//개수
};