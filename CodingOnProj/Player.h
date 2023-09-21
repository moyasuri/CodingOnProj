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
	Player(int playerType) : Creature(CT_PLAYER)
	{
		_playerType = playerType;
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
	virtual bool NonItemCheck();
	virtual void UsingItem();
	virtual void PrintItemInfo();
	virtual void DropItem();
	virtual void GetExp(int monsterType);
	virtual void LevelUpChk();
	



protected:
	std::vector<std::pair<std::string, int>> _item; // 아이템
	
	
};

class Knight : public Player
{
public:
	Knight() : Player(PT_Knight)
	{
		std::cout << "기사가 생성되었습니다." << std::endl;
		_hp = 150;
		_maxhp = 150;
		_mp = 50;
		_maxmp = 50;
		_attack = 10;
		_defence = 5;

	}



};

class Archer : public Player
{
public:
	Archer() : Player(PT_Archer)
	{
		std::cout << "궁수가 생성되었습니다." << std::endl;
		_hp = 80;
		_maxhp = 80;
		_mp = 50;
		_maxmp = 50;
		_attack = 15;
		_defence = 3;
	}
	

};

class Mage : public Player
{
public:
	Mage() : Player(PT_Mage)
	{
		std::cout << "마법사가 생성되었습니다." << std::endl;
		_hp = 50;
		_maxhp = 50;
		_mp = 200;
		_maxmp = 100;
		_attack = 25;
		_defence = 0;

	}
};