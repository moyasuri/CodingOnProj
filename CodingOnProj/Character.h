#pragma once

#include <vector>
#include "Weapon.h"
class Weapon;

class Character
{

public:
	Character(std::string str);
	virtual ~Character();
	void LootingWeapon(int _WeaponType);
	void AttackPlayer(Character& _cha_def);
	void PrintWeaponStatus(const std::vector<Weapon*> _Weapon);
	void PrintPlayerStatus( const Character& _cha_def);

	// Getter and Setter for _hp
	int GetHP() const;

	void SetHP(int hp);

	// Getter and Setter for _level
	int GetLevel(const Character& cha) const;

	void SetLevel(Character& cha,int level);

	// Getter for numWeapons
	int GetNumWeapons() const {
		return _numWeapons;
	}

	// Setter for numWeapons
	void SetNumWeapons(int count) {
		_numWeapons = count;
	}

	// Getter for _name
	std::string GetName() const {
		return _name;
	}

	// Setter for _name
	void SetName(const std::string& name) {
		_name = name;
	}


private:
	int _hp = 0;
	int _level =1;
	std::vector<Weapon*> _Weapon;
	int _numWeapons = 0;

	std::string _name;

};

