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
		: _creatureType(creatureType), _playerType(0),_hp(0), _mp(0)
	{
		_maxhp = 0;
		_maxmp = 0;
		_attack = 0;
		_defence = 0;
		_level = 1;
		_exp = 0;
		_neededExp = 100;
		_onHit = true;
		
		_hellfireAttackWeight = 2;
		_hellfireHpDown = 20;

		_skillType = 0;
		_hellfireLimitDuration = 0;
		_stunDuration = 0;
		_immortalDuration = 0;
		_poisonDuration = 0;
		_silenceDuration = 0;
		_portionsilenceDuration = 0;
		_undeadDuration = 0;
	}
	virtual ~Creature()
	{

	}
	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	void OnAttackedSkill(Creature* attacker);
	bool IsDead() { return _hp <= 0; }
	void CheckStatus();
	virtual int GetMonsterType()
	{
		return 0;
	}
	
	




	int GetStunDuration() const {
		return _stunDuration;
	}

	void SetStunDuration(int value) {
		_stunDuration = value;
	}
	// Getter for _onHit
	bool GetOnHit() const {
		return _onHit;
	}

	// Setter for _onHit
	void SetOnHit(bool value) {
		_onHit = value;
	}

	
	// bitmask
	bool andSkillType(uint8_t bitmask) {

		return _skillType & bitmask;
	}
	void SetandSkillType(uint8_t bitmask) {

		_skillType &= bitmask;
	}

	void SetorSkillType(uint8_t bitmask) {
		_skillType |= bitmask;
	}

	

protected:
	int _creatureType; // 몬스터, 플레이어
	int _hp;
	int _maxhp;
	int _mp;
	int _maxmp;
	int _attack;
	int _defence;
	int _playerType; // 직업
	int _level;
	int _exp;
	int _neededExp;
	bool _onHit;

	
	uint8_t _skillType;
	
	// 업화 가중치
	int _hellfireAttackWeight; // 공격 가중치
	int _hellfireHpDown; // 업화 체력 소모량

	// 디버프 지속시간
	int _hellfireLimitDuration; 
	int _stunDuration; 
	int _immortalDuration;
	int _poisonDuration;
	int _silenceDuration;
	int _portionsilenceDuration;
	int _undeadDuration;


	
};

