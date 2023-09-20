#pragma once

enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1
};

class Creature
{
public:
	Creature(int creatureType)
		: _creatureType(creatureType), _hp(0), _mp(0), _attack(0), _defence(0), _limitTurn(0), _hellfireLimitTurn(0)
	{

	}
	virtual ~Creature()
	{

	}
	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }
	
	
	
	// 스킬 구현
	virtual void Storm() {};
	virtual void Poison() {};
	virtual void Stun() {};
	virtual void Immortal(int) {};
	virtual void Silence() {};
	virtual void PortionSilence() {};
	virtual void Hellfire() {};
	virtual void Undead() {};

	

protected:
	int _creatureType;
	int _hp;
	int _mp;
	int _attack;
	int _defence;


	int _limitTurn; // stun 시간
	int _hellfireLimitTurn; // hellFire 시간

	
};

