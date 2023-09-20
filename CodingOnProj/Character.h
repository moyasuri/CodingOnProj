#pragma once

#include <vector>
#include "Weapon.h"
class Weapon;

class Character
{

public:
	Character();
	virtual ~Character();
	void LootingWeapon(int _WeaponType);
	void AttackPlayer(Character& _cha_att, Character& _cha_def);
	void PrintWeaponStatus(const std::vector<Weapon*> _Weapon);
	void PrintPlayerStatus(const Character& _cha_att, const Character& _cha_def);

	// Getter and Setter for _hp
	int GetHP(const Character& cha) const;

	void SetHP(Character& cha,int hp);

	// Getter and Setter for _level
	int GetLevel(const Character& cha) const;

	void SetLevel(Character& cha,int level);


private:
	int _hp = 0;
	int _level =1;
	std::vector<Weapon*> _Weapon;


};

