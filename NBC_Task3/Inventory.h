#pragma once
#include <iostream>
#include <algorithm>
#include "ItemEx.h"
using namespace std;

template <typename T>
class Inventory
{
public:
	Inventory(int capacity = 10)
	{
		pItems_ = new T * [capacity] {nullptr, };
		capacity_ = capacity;
		size_ = 0;
	}

	Inventory(const Inventory<T>& other)
	{
		Assign(other);
	}

	~Inventory()
	{
		DeleteItemAddress();
	}

private:
	//가격으로 아이템 비교하기
	bool compareItemsByPrice(const T& a, const T& b)
	{
		return a.GetPrice() < b.GetPrice();
	}

	void DeleteItemAddress()
	{
		if (pItems_ == nullptr)
			return;

		//배열의 각 요소별로 제거하고 최종적으로 배열 자체를 제거
		for (int iNum = 0; iNum < capacity_; iNum++)
		{
			if (pItems_[iNum] != nullptr)
				delete pItems_[iNum];
		}

		delete[] pItems_;
	}

public:
	void Assign(const Inventory<T>& other)
	{
		DeleteItemAddress();//기존에 보유한 아이템 제거

		//주어진 값을 복사하여 할당
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T*[capacity_];
		for (int iNum = 0; iNum < size_; iNum++)
		{
			switch ((*&other.pItems_[iNum])->GetItemType())
			{
			case ItemType::Weapon:
				pItems_[iNum] = new WeaponItem(static_cast<WeaponItem*>(other.pItems_[iNum]));
				break;

			case ItemType::Consume:
				pItems_[iNum] = new ConsumeItem(static_cast<ConsumeItem*>(other.pItems_[iNum]));
				break;
			}
		}
	}

	void AddItem(const T* item)
	{
		if (size_ == capacity_)
			Resize(capacity_ * 2);

		pItems_[size_++] = const_cast<T*>(item);
	}

	void RemoveLastItem()
	{
		if (size_ <= 0)
		{
			cout << "인벤토리가 비어있습니다" << endl;
			return;
		}
		
		delete pItems_[size_];
		pItems_[size_--] = nullptr;
	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}

	void PrintAllItems() const
	{
		if (size_ <= 0)
		{
			cout << "인벤토리가 비어있습니다" << endl;
			return;
		}
		
		for (int iNum = 0; iNum < size_; iNum++)
		{
			//기본 내용
			cout << "[이름 : " << (*&pItems_[iNum])->GetName() << ", 가격 : " << (*&pItems_[iNum])->GetPrice() << "G, ";

			//아이템 종류에 따라 적절한 클래스로 캐스팅하여 내용 출력
			switch ((*&pItems_[iNum])->GetItemType())
			{
			case ItemType::Weapon:
			{
				WeaponItem* weapon = static_cast<WeaponItem*>(pItems_[iNum]);
				cout << "내구도 : " << weapon->GetDurability() << "]" << endl;
			}
				break;

			case ItemType::Consume:
			{
				ConsumeItem* consume = static_cast<ConsumeItem*>(pItems_[iNum]);
				cout << "개수 : " << consume->GetCount() << "]" << endl;
			}
				break;

			default:
				break;
			}
		}
	}

	void Resize(int newCapacity)
	{
		//새 배열 생성
		T** newItemArr = new T*[newCapacity] {nullptr, };

		//주소 옮기기
		for (int iNum = 0; iNum < size_; iNum++)
			newItemArr[iNum] = pItems_[iNum];

		//기존보다 크기가 작아질때 접근이 불가능한 아이템이 생기면 삭제한다.
		if (size_ > capacity_)
		{
			for (int iNum = size_; iNum < capacity_; iNum++)
				delete pItems_[iNum];

			size_ = capacity_;
		}

		//새 배열을 사용
		delete[] pItems_;
		pItems_ = newItemArr;
		capacity_ = newCapacity;
	}

	void SortItems()
	{
		//가격 기준 정렬
		sort(&pItems_[0], &pItems_[size_ - 1], compareItemsByPrice);
	}

private:
	T** pItems_;//아이템 목록
	int capacity_;//최대 사용 가능한 공간
	int size_;//현재 아이템 개수
};
