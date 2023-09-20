#include "Creature.h"
#include "Player.h"


void Creature::OnAttacked(Creature* attacker)
{
	int damage = attacker->_attack - _defence;
	if (damage < 0)
		damage = 1;

	_hp -= damage;
	if (_hp < 0)
		_hp = 0;
}

void Creature::OnAttackedSkill(Creature* attacker)
{

	if (attacker->_creatureType == CT_PLAYER)
	{
		(Player)attacker->_playerType;
		

	}
	else(
	{

	}


	if(attacker->_creatureType)
	int damage = attacker->_attack - _defence;
	if (damage < 0)
		damage = 1;

	_hp -= damage;
	if (_hp < 0)
		_hp = 0;
}