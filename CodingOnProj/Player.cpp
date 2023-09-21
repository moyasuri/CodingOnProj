#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	string _name;
	switch (_playerType)
	{
	case PT_Knight:
		_name = "knight";
		break;

	case PT_Archer:
		_name = "archer";
		break;
	case PT_Mage:
		_name = "mage";
		break;

	}
	cout << "---------------------" << endl;
	cout << "[플레이어 정보] : [" <<_name << "] // HP: " << _hp << " MP: " << _mp <<  " ATT: " << _attack << " DEF: " << _defence << endl;
	cout << "---------------------" << endl;
}

void Player::PrintItemInfo()
{



	for (const auto& item : _item) {
		cout << "---------------------" << endl;
		cout << "[아이템 이름] " << item.first << " 남아있는 개수 " << item.second << endl;
		cout << "---------------------" << endl;
	}


	
}


bool Player::NonItemCheck()
{
	int Non_item = 0;

	for (const auto& item : _item) {

		Non_item |= item.second;
	}

	if (!Non_item) {
		cout << "현재 소지 아이템이 없습니다." << endl;
		return true;
	}

	return false;
}



void Player::UsingItem() // 아이템)
{

	PrintItemInfo();

	std::cout << "사용할 아이템을 선택해주세요 (1) : hp포션, (2) : mp 포션, (3) : 만병통치약 : ";
	int _cmd;
	cin >> _cmd;
	
	switch (_cmd)
	{
	case IT_HP:
		std::cout << "hp가 회복되었습니다." << std::endl;
		if (_cmd == 1)
		{
			--_item[0].second;
			_hp += 50; // hp 회복량
		}
		break;

	case IT_MP:

		std::cout << "mp가 회복되었습니다." << std::endl;
		if (_cmd == 2)
		{
			--_item[1].second;
			_mp += 30; // mp 회복량
			
		}
		break;

	case IT_ANTIDOTE:
		std::cout << "모든 상태이상이 풀렸습니다." << std::endl;
		if (_cmd == 3)
		{
			--_item[2].second;
			_skillType &= 0b00000000;
		}

		break;



	}
}