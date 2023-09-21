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

	//if (monsterSeed <5)
	if (1)
	{
		randValue = MT_DRAGON;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "짱쌘 투명드래곤이 등장합니다. " << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
	}
	else if (monsterSeed < 30)
	{
		randValue = MT_SKELETON;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "해골이 등장합니다. " << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
	}
	else if (monsterSeed < 60)
	{
		randValue = MT_ORC;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "오르크가 등장합니다. " << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
	}
	else
	{
		randValue = MT_SLIME;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "슬라임이 등장합니다. " << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
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
		// player->CheckStatus(); // 플레이어의 상태 체크 및 결과값 반영
		
		// 플레이어와 몬스터의 정보 출력
		player->PrintInfo(); 
		_monster->PrintInfo();

		
		
		if (player->andSkillType(ST_STUN)) // 플레이어가 스턴상태인가?
		{
			std::cout << "플레이어는 현재 스턴 상태입니다. 앞으로 " << player->GetStunDuration() << "턴 동안 아무행동도 취할 수 없습니다." << std::endl;
			player->SetStunDuration(player->GetStunDuration()-1);
		}
		else
		{
			int cmd;
			bool _loop = true;
			while (_loop) {
				std::cout << "(1) : 공격, (2) : 스킬, (3) : 아이템" << std::endl << std::endl;
				std::cin >> cmd;
				switch (cmd)
				{
				case 1:// 플레이어->몬스터 공격
					_monster->OnAttacked(player);
					_loop = false;
					break;
				case 2: // 스킬사용 
					if (player->andSkillType(ST_PORTIONSILENCE))
					{
						std::cout << "포션침묵에 걸려있습니다." << std::endl;
					}
					else
					{
						_monster->OnAttackedSkill(player);
						if (player->GetOnHit())
						{
							_loop = false;
						}
					}
					break;
				case 3: // 아이템 사용
					if (player->andSkillType(ST_PORTIONSILENCE)) 
					{
						std::cout << "포션침묵에 걸려있습니다." << std::endl;

					}
					else
					{
						if (!(player->NonItemCheck()))
						{
							player->UsingItem();
							_loop = false;
						}
					}
					break;
				default:
					std::cout << "잘못된 입력입니다.";
				}
			}
		}

		// 해치웠나?
		if (_monster->IsDead())
		{
			std::cout << "몬스터가 죽었습니다." << std::endl;
			player->GetExp(_monster->GetMonsterType()); // 몬스터타입에 따른 경험치 획득
			player->LevelUpChk(); // 레벨업 조건 확인
			player->DropItem();  // 아이템 드롭
			
			delete _monster; // 몬스터 필드에서 삭제
			_monster = nullptr; 

			// 디버프 초기화
			std::cout << "모든 상태이상이 해제되었습니다." << std::endl;
			player->SetandSkillType(0b00000000);
			break;
		}
		
		// 몬스터의 상태 체크 및 결과 값 반영
		_monster->CheckStatus(); 
		

		// 0.5초 대기
		Sleep(500); 

		if (_monster->andSkillType(ST_STUN)) // 몬스터가 스턴상태인가?
		{
			std::cout << "몬스터 현재 스턴 상태입니다. 앞으로 " << _monster->GetStunDuration() << "턴 동안 아무행동도 취할 수 없습니다." << std::endl;
		}
		else
		{
			// 몬스터->플레이어 공격

			double randomValue = (static_cast<double>(std::rand()) / RAND_MAX);

			// 몬스터가 일반공격을 할 확률 0.8로 설정함.
			if (randomValue < _monster->GetAttackProbability())
			{
				std::cout << "\n몬스터 기본공격 !!!!!" << std::endl;
				player->OnAttacked(_monster);
			}
			else
			{
				std::cout << "\n몬스터가 스킬을 시전합니다 !!!!!" << std::endl;
				player->OnAttackedSkill(_monster); // 몬스터가 스킬 공격을 할 확률 0.2;
			}


		}

		player->CheckStatus(); // 플레이어의 상태 체크 및 결과값 반영

		// 플레이어가 죽었는가?
		if (player->IsDead())
		{
			std::cout << "플레이어가 죽었습니다." << std::endl;
			delete _monster; // 싸우던 몬스터도 필드에서 삭제
			_monster = nullptr;
			break;
		}
	}
}