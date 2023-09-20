#pragma once
#include "Creature.h"
#include <vector>
#include <iostream>

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum PortionType
{
	PT_Hp = 1,
	PT_Mp = 2,
	PT_Antidote = 3
};

class Player : public Creature
{
public:
	Player(int playerType) : Creature(CT_PLAYER), _playerType(playerType)
	{
		_item.push_back(std::make_pair("hp", 0));
		_item.push_back(std::make_pair("mp", 0));
		_item.push_back(std::make_pair("Antidote", 0));

		/*    for (const auto& item : data) {
        std::cout << "String: " << item.first << ", Int: " << item.second << std::endl;*/
    
	}

	virtual ~Player() 
	{

	}

	virtual void PrintInfo();

	void Stun() override
	{

	}
	void Storm() override
	{

	}

	// Immortal 함수를 오버라이드
	void Immortal(int duration) override {
		// Knight 클래스에서 Immortal 함수의 동작 재정의
		std::cout << "Knight의 Immortal이 " << duration << " 턴 동안 활성화됩니다." << std::endl;
		// 여기서 Immortal의 추가 동작을 구현할 수 있습니다.
	}

protected:
	int _playerType;
	std::vector<std::pair<std::string, int>> _item; // 아이템
	
};

class Knight : public Player
{
public:
	Knight() : Player(PT_Knight)
	{
		_hp = 150;
		_mp = 30;
		_attack = 10;
		_defence = 5;

	}



};

class Archer : public Player
{
public:
	Archer() : Player(PT_Archer)
	{
		_hp = 80;
		_mp = 50;
		_attack = 15;
		_defence = 3;
	}
	virtual void Poison() {};

};

class Mage : public Player
{
public:
	Mage() : Player(PT_Mage)
	{
		_hp = 50;
		_mp = 100;
		_attack = 25;
		_defence = 0;

	}
};