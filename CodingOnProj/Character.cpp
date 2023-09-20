#include "Character.h"
#include "Gun.h"
#include "Sword.h"


Character::Character(std::string str)
{
	_name = str;
	_hp = 50;
}
Character::~Character()
{

}




void Character::LootingWeapon(int _WeaponType)
{
	Weapon* newWeapon = nullptr;
	if (_WeaponType == WeaponType::GUN)
	{
		newWeapon = new Gun();
	}
	else if (_WeaponType == WeaponType::SWORD)
	{
		newWeapon = new Sword();
	}

	if (newWeapon != nullptr)
	{
		_Weapon.push_back(newWeapon);
	}

	SetNumWeapons(GetNumWeapons() + 1);
	
}

void Character::AttackPlayer(Character& _cha_def)
{
	// if(Cha)
	
	int temp_cmd = 0;
	int temp_cmd2 = 0;

	std::cout << "무기를 루팅해주세요, 0 : GUN, 1 : SWORD " << std::endl;
	std::cin >> temp_cmd2;
	LootingWeapon(temp_cmd2);
	PrintWeaponStatus(_Weapon);

	std::cout << "어떤 무기로 공격하시겠습니까?" << std::endl;
	std::cin >> temp_cmd;
	
	_cha_def._hp = _cha_def._hp - _Weapon[temp_cmd]->GetDamage();
	_Weapon[temp_cmd]->Attack();

	PrintPlayerStatus(_cha_def);


}

void Character::PrintWeaponStatus(const std::vector<Weapon*> _Weapon)
{
	int i = 0;
	std::string s_tmp = "";


	for (Weapon* weapon : _Weapon)
	{
		if (weapon->GetWeaponType() == 0)
		{
			s_tmp = "GUN";
		}
		else if (weapon->GetWeaponType() == 1)
		{
			s_tmp = "SWORD";
		}
		std::cout << "[" << i<< "] 번째 무기 타입은 " << s_tmp << " 남은 공격횟수는 " << weapon->GetAttacksLeft() << "입니다." <<  std::endl;
		++i;
	}
}

void Character::PrintPlayerStatus(const Character& _cha_def)
{
	std::cout << "공격자" << GetName() << "의 hp : " << GetHP() << std::endl;
	std::cout << "방어자" << _cha_def.GetName() << "의 hp : " << _cha_def.GetHP() << std::endl;
	
}

// Getter and Setter for _hp
int Character::GetHP() const{
	return _hp;
}

void Character::SetHP(int hp){
	_hp = hp;
}

// Getter and Setter for _level
int Character::GetLevel(const Character& cha) const {
	return _level;
}

void Character::SetLevel(Character& cha, int level) {
	_level = level;
}

