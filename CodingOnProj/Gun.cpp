
#include "Gun.h"


Gun::Gun()
{
	SetDamage(10);
	SetAttacksLeft(1);
	SetWeaponType(GUN);
}

void Gun::Attack()
{
	
	SetAttacksLeft(GetAttacksLeft() - 1);
	std::cout << "총쏘기" << std::endl;
}