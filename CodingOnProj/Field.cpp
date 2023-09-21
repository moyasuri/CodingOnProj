#include "Field.h"
#include <stdlib.h>
#include "Monster.h"
#include "Player.h"
#include <Windows.h>

Field::Field() : _monster(nullptr) // 몬스터들이 등장 할 수 있는 배경
{

}

Field::~Field()
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster()
{
	int monsterSeed = 1 + rand() % 100;
	int randValue;
	if (monsterSeed <5)
	{
		randValue = MT_DRAGON;
	}
	else if (monsterSeed < 30)
	{
		randValue = MT_SKELETON;
	}
	else if (monsterSeed < 60)
	{
		randValue = MT_ORC;
	}
	else
	{
		randValue = MT_SLIME;
	}
	
	

	switch (randValue)
	{
	case MT_SLIME:
		_monster = new Slime();
		break;
	case MT_ORC:
		_monster = new Orc();
		break;
	case MT_SKELETON:
		_monster = new Skeleton();
		break;
	case MT_DRAGON:
		_monster = new Dragon();
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->CheckStatus();
		player->PrintInfo();
		_monster->PrintInfo();

		
		if (player->GetStunSW())
		{
			std::cout << "플레이어는 현재 스턴 상태입니다. 앞으로 " << player->GetStunDuration() << "턴 동안 아무행동도 취할 수 없습니다." << std::endl;
		}
		else
		{
			int cmd;
			bool _loop = true;
			while (_loop) {
				std::cout << "1 : 공격, 2 : 스킬 , 3 : 아이템" << std::endl;
				std::cin >> cmd;
				switch (cmd)
				{
				case 1:// 플레이어->몬스터 공격
					_monster->OnAttacked(player);
					_loop = false;
					break;
				case 2: //스킬사용 
					_monster->OnAttackedSkill(player);
					if (player->GetOnHit())
					{
						_loop = false;
					}
					break;
				case 3: // 아이템 
					if (!(player->NonItemCheck()))
					{
						player->UsingItem();
						_loop = false;
					}
					break;
				default:
					std::cout << "잘못된 입력입니다.";
				}
			}
		}
		if (_monster->IsDead())
		{
			std::cout << "몬스터가 죽었습니다." << std::endl;
			player->GetExp(_monster->GetMonsterType());
			player->DropItem();
			player->LevelUpChk();
			delete _monster;
			_monster = nullptr;
			break;
		}
		
		_monster->CheckStatus();
		
		
		Sleep(500); // 0.5초 대기 디버그용 

		if (_monster->GetStunSW())
		{
			std::cout << "몬스터 현재 스턴 상태입니다. 앞으로 " << _monster->GetStunDuration() << "턴 동안 아무행동도 취할 수 없습니다." << std::endl;
		}
		else
		{
			// 몬스터->플레이어 공격
			    
        
		
			double randomValue = (static_cast<double>(std::rand()) / RAND_MAX);
			if (randomValue < _monster->GetAttackProbability())
			{
				std::cout << "몬스터 기본공격 !!." << std::endl;
				player->OnAttacked(_monster); //
			}
			else
			{
				_monster->OnAttackedSkill(player);
			}
			
			


			if (player->IsDead())
			{
				std::cout << "플레이어가 죽었습니다." << std::endl;
				break;
			}
		}

	}
}