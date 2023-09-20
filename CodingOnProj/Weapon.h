#pragma once
#include <iostream>

enum WeaponType
{
	GUN,
	SWORD,

};

class Weapon
{

public:
	// Constructor
	Weapon();
	~Weapon()
	{

	}

	virtual void Attack()
	{

	}
	

	// Getter for _damage
	int GetDamage() const {
		return _damage;
	}

	// Setter for _damage
	void SetDamage(int damage) {
		_damage = damage;
	}

	// Getter for _attacksLeft
	int GetAttacksLeft() const {
		return _attacksLeft;
	}

	// Setter for _attacksLeft
	void SetAttacksLeft(int attacksLeft) {
		_attacksLeft = attacksLeft;
	}

	// Getter for _WeaponType
	int GetWeaponType() const {
		return _WeaponType;
	}

	// Setter for _WeaponType
	void SetWeaponType(int WeaponType) {
		_WeaponType = WeaponType;
	}


private:
	int _damage;
	int _attacksLeft;
	int _WeaponType;
	

};

