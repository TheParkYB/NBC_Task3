#include <iostream>
#include <stack>
#include "Inventory.h"
#include "item.h"
#include "ItemEx.h"
using namespace std;

int main()
{
	Inventory<Item>* myInven = new Inventory<Item>();

	cout << "시작 장비를 선택해주세요." << endl;
	cout << "1. 대검" << endl;
	cout << "2. 한손검 (방패 지급)" << endl;
	cout << "3. 쌍검" << endl;
	cout << "4. 해머" << endl;
	cout << "5. 활 (화살 지급)";

	while (true)
	{
		cout << "\n번호 입력 : ";
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			myInven->AddItem(new WeaponItem("나무 대검", 1000, 80));
			break;
		case 2:
			myInven->AddItem(new WeaponItem("장식용 한손검", 1000, 120));
			myInven->AddItem(new WeaponItem("냄비 뚜껑", 500, 200));
			break;
		case 3:
			myInven->AddItem(new WeaponItem("연습용 쌍검", 1000, 100));
			break;
		case 4:
			myInven->AddItem(new WeaponItem("합판 해머", 1000, 70));
			break;
		case 5:
			myInven->AddItem(new WeaponItem("훈련용 활", 1000, 50));
			myInven->AddItem(new ConsumeItem("둥근 촉 화살", 1, 100));
			break;
		default:
			cout << "\n잘못 입력했습니다. 다시 해주세요.";
			break;
		}

		if (myInven->GetSize() > 0)
			break;
	}
	
	cout << "\n시작 지원 아이템을 받으시겠습니까?" << endl;
	cout << "1. 풍족하게 받는다." << endl;
	cout << "2. 적당히 받는다." << endl;
	cout << "3. 최소한만 받는다." << endl;
	cout << "4. 필요없다.";

	while (true)
	{
		cout << "\n번호 입력 : ";
		int select;
		cin >> select;
		if (select >= 1 && select <= 4)
		{
			stack<Item*> supportItems;
			switch (select)
			{
			case 1:
				supportItems.push(new ConsumeItem("투척용 쿠나이", 100, 5));
				supportItems.push(new ConsumeItem("나무통 폭탄", 2000, 2));
				supportItems.push(new ConsumeItem("귀인의 가루", 500, 2));
				supportItems.push(new ConsumeItem("경화의 가루", 500, 2));
				supportItems.push(new ConsumeItem("마비덫", 1000, 1));
			case 2:
				supportItems.push(new ConsumeItem("휴대식량", 500, 3));
				supportItems.push(new ConsumeItem("모닥불용 장작", 400, 10));
				supportItems.push(new WeaponItem("채집용 칼", 500, 20));
			case 3:
				supportItems.push(new ConsumeItem("HP 포션(소)", 100, 10));
				supportItems.push(new ConsumeItem("MP 포션(소)", 100, 10));
			default:
				break;
			}

			while (!supportItems.empty())
			{
				myInven->AddItem(supportItems.top());
				supportItems.pop();
			}

			break;
		}

		cout << "\n잘못 입력했습니다. 다시 해주세요.";
	}

	cout << endl;
	myInven->PrintAllItems();

	delete myInven;
	return 0;
}