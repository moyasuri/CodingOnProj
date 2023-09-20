#include "Character.h"

#include "Gun.h"
#include "Sword.h"


Character::Character()
{
	_hp = 50;
}
Character::~Character()
{

}

void Character::LootingWeapon(int _WeaponType)
{
	if (_WeaponType == Gun)
	{
		_Weapon.push_back(new Gun());
	}
	if (_WeaponType == Sword)
	{
		_Weapon.push_back(new Sword);
	}
	
}

void Character::AttackPlayer(Character& _cha_att, Character& _cha_def)
{
	int temp_cmd = 0;
	std::cout << "어떤 무기로 공격하시겠습니까?" << std::endl;
	std::cin >> temp_cmd;
	_cha_def._hp - _cha_att._Weapon[temp_cmd]->GetDamage();
	_cha_att._Weapon[temp_cmd]->Attack();
}

void Character::PrintWeaponStatus(const std::vector<Weapon*> _Weapon)
{
	
	for (Weapon* weapon : _Weapon)
	{
		std::cout << "무기 타입은 : " <<  weapon->GetWeaponType() << std::endl;
		std::cout << "남은 공격횟수는 " << weapon->GetAttacksLeft() << std::endl;
	}
	

}

void Character::PrintPlayerStatus(const Character& _cha_att, const Character& _cha_def)
{
	std::cout << "공격자의 hp : " << _cha_att.GetHP(_cha_att) << std::endl;
	std::cout << "방어자의 hp : " << _cha_def.GetHP(_cha_def) << std::endl;
	
}

// Getter and Setter for _hp
int Character::GetHP(const Character& cha) const{
	return cha._hp;
}

void Character::SetHP(Character& cha, int hp){
	_hp = hp;
}

// Getter and Setter for _level
int Character::GetLevel(const Character& cha) const {
	return _level;
}

void Character::SetLevel(Character& cha, int level) {
	_level = level;
}
