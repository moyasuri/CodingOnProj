#pragma once
#include <iostream>

enum SkillType
{
	ST_STUN = 0b00000001,
	ST_POISON = 0b00000010,
	ST_IMMORTAL = 0b00000100,
	ST_SILENCE = 0b00001000,
	ST_PORTIONSILENCE = 0b0010000,
	ST_HELLFIRE = 0b00100000,
	ST_UNDEAD = 0b01000000,

};

enum ItemType {
	IT_HP = 1,
	IT_MP = 2,
	IT_ANTIDOTE = 3,

};

enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1
};

class Creature
{
public:
	Creature(int creatureType)
		: _creatureType(creatureType), _playerType(0),_hp(0), _mp(0), _attack(0), _defence(0), _stunDuration(0), _hellfireLimitDuration(0), _hellfireSW(false)
	{
		_level = 1;
		_exp = 0;
		_neededExp = 100;
	}
	virtual ~Creature()
	{

	}
	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	void OnAttackedSkill(Creature* attacker);
	bool IsDead() { return _hp <= 0; }
	void CheckStatus();
	
	
	// 스킬 구현
	//virtual void Storm() {};
	//virtual void Poison(int dotDamage, int duration) {};
	//virtual void Stun() {};
	//virtual void Immortal(int duration) {};
	//virtual void Silence(int duration) {};
	//virtual void PortionSilence(int duration) {};
	//virtual void Hellfire() {};
	//virtual void Undead(int duration) {}; //필요가없다

	
	
	bool GetStunSW() const {
		return _stunSW;
	}

	// Setter for _stunSW
	void SetStunSW(bool value) {
		_stunSW = value;
	}

	int GetStunDuration() const {
		return _stunDuration;
	}
	
	// Getter for _onHit
	bool GetOnHit() const {
		return _onHit;
	}

	// Setter for _onHit
	void SetOnHit(bool value) {
		_onHit = value;
	}

protected:
	int _creatureType;
	int _hp;
	int _maxhp;
	
	int _mp;
	int _maxmp;
	int _attack;
	int _defence;
	int _playerType;
	int _level;
	int _exp;
	int _neededExp;
	int _monsterType;

	int _stunDuration; // stun 시간
	int _stunDuration_z;
	bool _stunSW=false;
	
	int _hellfireLimitDuration; // hellFire 제한시간
	int _hellfireLimitDuration_z;


	bool _hellfireDebuff;
	bool _hellfireSW;
	int _hellfireAttackWeight;
	int _hellfireHpWeight;

	bool _immortalSW;
	int _immortalDuration;
	int _immortalDuration_z;
	uint8_t _skillType = 0; // 0으로 초기화 이거 소개하자

	bool _poisonSW;
	int _poisonDuration;

	int _silenceDuration;
	
	int _silenceportionDuration;

	int _undeadDuration;

	bool _onHit;

	
};

