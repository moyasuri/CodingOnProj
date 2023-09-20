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
		: _creatureType(creatureType), _hp(0), _mp(0), _attack(0), _defence(0), _stunDuration(0), _hellfireLimitDuration(0), _hellfireSW(false)
	{

	}
	virtual ~Creature()
	{

	}
	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	void OnAttackedSkill(Creature* attacker);
	bool IsDead() { return _hp <= 0; }
	
	
	
	// 스킬 구현
	virtual void Storm() {};
	virtual void Poison(int dotDamage, int duration) {};
	virtual void Stun() {};
	virtual void Immortal(int duration) {};
	virtual void Silence(int duration) {};
	virtual void PortionSilence(int duration) {};
	virtual void Hellfire() {};
	virtual void Undead(int duration) {};

	

protected:
	int _creatureType;
	int _hp;
	int _mp;
	int _attack;
	int _defence;


	int _stunDuration; // stun 시간
	int _hellfireLimitDuration; // hellFire 제한시간
	bool _hellfireDebuff;
	bool _hellfireSW;

	
};

