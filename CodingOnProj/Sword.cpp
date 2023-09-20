#include "Sword.h"

Sword::Sword()
{
	SetDamage(5);
	SetAttacksLeft(3);
	SetWeaponType(SWORD);
}

void Sword::Attack()
{
	SetAttacksLeft(GetAttacksLeft() - 1);
	std::cout << "찌르기" << std::endl;
}