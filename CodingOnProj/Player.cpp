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
	cout << "[플레이어 정보] : [" << _name << "] // HP: " << _hp << " MP: " << _mp << " ATT: " << _attack << " DEF: " << _defence << " exp: " << _exp << " 필요경험치: " << _neededExp << endl;
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
	int item_exist = 0;

	for (const auto& item : _item) {

		item_exist |= item.second;
	}

	if (!item_exist) {
		cout << "현재 소지 아이템이 없습니다." << endl;
		return true;
	}
	return false;
}



void Player::UsingItem() // 아이템)
{

	PrintItemInfo();

	std::cout << "사용할 아이템을 선택해주세요 (1) : hp포션, (2) : mp 포션, (3) : 만병통치약 : ";

	
	bool _loop = true;
	int _cmd;
	while (_loop) {
		cin >> _cmd;
		switch (_cmd)
		{
			case IT_HP:
				if (_item[0].second > 0) 
				{
					std::cout << "hp가 회복되었습니다." << std::endl;
					--_item[0].second;
					_hp += 100; // hp 회복량
					if (_hp > _maxhp)
						_hp = _maxhp;
					_loop = false;
				}
				else
				{
					std::cout << "hp포션이 없습니다." << std::endl;
					std::cout << "다시 입력해주세요." << std::endl;

				}
			break;
			case IT_MP:
				if (_item[1].second > 0)
				{
					std::cout << "mp가 회복되었습니다." << std::endl;
					--_item[1].second;
					_mp += 100; // mp 회복량
					if (_mp > _maxmp)
						_mp = _maxmp;
					_loop = false;
				}
				else
				{
					std::cout << "mp포션이 없습니다." << std::endl;
					std::cout << "다시 입력해주세요." << std::endl;

				}

			break;
			case IT_ANTIDOTE:
				if (_item[2].second > 0)
				{
					std::cout << "모든 상태이상이 풀렸습니다." << std::endl;
					--_item[2].second;
					_skillType &= 0b00000000;
					_loop = false;
				}
				else
				{
					std::cout << "상태이상 포션이 없습니다." << std::endl;
					std::cout << "다시 입력해주세요." << std::endl;
				}
			break;
		}
	}
}

void Player::DropItem() {

	// 요주의 인물
	int dropChance = rand() % 10 + 1;
	if (dropChance > 2)
	{


		int ItemNum_Rand = rand() % 3 + 1;
		vector<int>ItemsDrop;
		for (int i = 0; i < ItemNum_Rand;i++)
		{
			ItemsDrop.push_back(rand() % 3 + 1);
		}

		for (int itemType : ItemsDrop)
		{
			switch (itemType)
			{
			case IT_HP:
				std::cout << "hp포션을 얻었습니다" << std::endl;
				++_item[0].second;
				break;

			case IT_MP:
				std::cout << "mp포션을 얻었습니다." << std::endl;
				++_item[1].second;
				break;

			case IT_ANTIDOTE:
				std::cout << "만병통치약을 얻었습니다." << std::endl;
				++_item[2].second;
				break;
			}
		}
	}


}

void Player::GetExp(int monsterType)
{
	switch (monsterType)
	{
		case 1:
			_exp += 30;
			break;
		case 2:
			_exp += 50;
			break;
		case 3:
			_exp += 100;
			break;
		case 4:
			_exp += 500;
			break;
	}

}
void Player::LevelUpChk()
{
	while (_exp >= _neededExp)
	{
			++_level;
			_exp -=_neededExp;
			_neededExp += 50;
			_attack += 2;
			_maxhp += 5;
			_maxmp += 3;
			_hp = _maxhp;
			_mp = _maxmp;
			std::cout << "레벨업 !! 현재 레벨 " << _level << "입니다." << std::endl;
	}
}


