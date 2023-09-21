#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::PrintInfo()
{
	string _name;
	switch (_monsterType)
	{
	case MT_SLIME:
		_name = "slime";
		break;
	case MT_ORC:
		_name = "orc";
		break;
	case MT_SKELETON:
		_name = "skeleton";
		break;
	case MT_DRAGON:
		_name = "dragon";
		break;
	}
	std::cout << "------------------------------------------------" << std::endl;
	cout << "[몬스터 정보] : ["<< _name << "] // HP: " << _hp << " ATT: " << _attack << " DEF: " << _defence << endl;
	std::cout << "------------------------------------------------" << std::endl;
}