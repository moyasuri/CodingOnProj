#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELETON = 3,
	MT_DRAGON = 4
};

class Monster : public Creature
{
public:
	Monster(int monsterType) 
		: Creature(CT_MONSTER), _monsterType(monsterType)
	{

	}

	virtual void PrintInfo();
	
	int GetMonsterType() const {
		return _monsterType;
	}

	double GetAttackProbability() const {
		return _attackProbability;
	}



protected:
	int _monsterType;
	double _attackProbability = 0.8;
};

class Slime : public Monster
{
public:
	Slime() : Monster(MT_SLIME)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}

};

class Orc : public Monster
{
public:
	Orc() : Monster(MT_ORC)
	{
		_hp = 80;
		_attack = 8;
		_defence = 3;
	}

};

class Skeleton : public Monster
{
public:
	Skeleton() : Monster(MT_SKELETON)
	{
		_hp = 100;
		_attack = 15;
		_defence = 4;
	}

};

class Dragon : public Monster
{
public:
	Dragon() : Monster(MT_DRAGON)
	{
		_hp = 1000;
		_attack = 30;
		_defence = 10;
			
	}


};