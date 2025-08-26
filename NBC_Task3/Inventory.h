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
		pItems_ = new T[capacity];
		capacity_ = capacity;
		size_ = 0;
	}

	Inventory(const Inventory<T>& other)
	{
		Assign(other);
	}

	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

private:
	bool compareItemsByPrice(const T& a, const T& b)
	{
		return a.GetPrice() < b.GetPrice();
	}

public:
	void Assign(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;

		pItems_ = new T[capacity_];
		for (int iNum = 0; iNum < size_; iNum++)
			pItems_[iNum] = other.pItems_[iNum];
	}

	void AddItem(const T& item)
	{
		if (size_ == capacity_)
			Resize(capacity_ * 2);

		pItems_[size_++] = item;
	}

	void RemoveLastItem()
	{
		if (size_ <= 0)
			cout << "인벤토리가 비어있습니다" << endl;
		else
			size_--;
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
			cout << "[이름 : " << (&pItems_[iNum])->GetName() << ", 가격 : " << (&pItems_[iNum])->GetPrice() << "G]" << endl;
		}
	}

	void Resize(int newCapacity)
	{
		T* newItemArr = new T[newCapacity];

		for (int iNum = 0; iNum < size_; iNum++)
			newItemArr[iNum] = pItems_[iNum];

		delete[] pItems_;
		pItems_ = newItemArr;
	}

	void SortItems()
	{
		sort(&pItems_[0], &pItems_[size_ - 1], compareItemsByPrice);
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};
