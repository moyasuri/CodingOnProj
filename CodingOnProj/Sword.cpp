#include "Sword.h"

Sword::Sword()
{
	SetDamage(5);
	SetDamage(3);
	SetWeaponType(WeaponType::Sword);
}

void Sword::Attack()
{
	SetAttacksLeft(GetAttacksLeft() - 1);
	std::cout << "찌르기" << std::endl;
}