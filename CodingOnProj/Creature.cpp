#include "Creature.h"
#include "Player.h"
#include "Monster.h"


void Creature::OnAttacked(Creature* attacker)
{
	int damage;

	if (attacker->andSkillType(ST_HELLFIRE))
	{
		damage= attacker->_attack* attacker->_hellfireAttackWeight - _defence;
	}
	else
	{
		damage = attacker->_attack - _defence;
	}

	if (damage <= 0)
		damage = 1;

	_hp -= damage;
	if (_hp < 0)
		_hp = 0;
}

void Creature::CheckStatus(){


	bool isDebuff = 0b11111111 & _skillType; // 상태이상이 걸려있는가?
	if (isDebuff)
	{
		if (_creatureType == CT_PLAYER)
		{
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "플레이어의 상태이상" << std::endl;
		}
		else
		{
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "몬스터의 상태이상" << std::endl;
		}
		// 스턴 확인, 남은횟수 차감은 플레이어의 턴 뒤에
		if (_skillType & ST_STUN)
		{			
			if (!_stunDuration)
			{
				std::cout << "스턴이 해제되었습니다." << std::endl;
				SetandSkillType(~ST_STUN);
			}
		}
		
		// 독 확인, 데미지
		if (_skillType & ST_POISON)
		{
			--_poisonDuration;
			if (!_poisonDuration)
			{
				std::cout << "맹독이 해독되었습니다." << std::endl;
				SetandSkillType(~ST_POISON);
			}
			else
			{
				_hp -= 20;
				std::cout << "앞으로 남은 맹독 턴수는 " << _poisonDuration << " 입니다." << std::endl;
			}
		}

		// 침묵 확인
		if (_skillType & ST_SILENCE)
		{
			--_silenceDuration;

			if(!_silenceDuration)
			{
				std::cout << "침묵이 풀렸습니다." << std::endl;
				SetandSkillType(~ST_SILENCE);
			}
			else
			{
				std::cout << "앞으로 남은 침묵 턴수는 " << _silenceDuration << " 입니다." << std::endl;
				
			}
		}
		// 포션침묵 확인
		if (_skillType & ST_PORTIONSILENCE)
		{
			--_portionsilenceDuration;
			if (!_portionsilenceDuration)
			{
				std::cout << "포션침묵이 풀렸습니다." << std::endl;
				SetandSkillType(~ST_PORTIONSILENCE);
			}
			else
			{
				std::cout << "앞으로 남은 포션침묵 턴수는 " << _portionsilenceDuration << " 입니다." << std::endl;
				
			}
		}
		// 언데드 확인
		if (_skillType & ST_UNDEAD)
		{
			--_undeadDuration;
			if (!_undeadDuration)
			{
				std::cout << "언데드 스킬이 풀렸습니다." << std::endl;
				SetandSkillType(~ST_UNDEAD);
			}
			else
			{
				std::cout << "앞으로 남은 언데드 스킬 턴수는 " << _undeadDuration << " 입니다." << std::endl;
				
			}
		}
		// 불굴의 의지 확인
		if (_skillType & ST_IMMORTAL)
		{
			--_immortalDuration;
			if (_hp <= 0)
			{
				_hp = 1;
			}
			
			if (!_immortalDuration)
			{
				std::cout << "불굴의 의지 지속시간이 끝났습니다." << std::endl;
				SetandSkillType(~ST_IMMORTAL);
			}
			else
			{
				std::cout << "앞으로 남은 불굴의 의지 턴수는 " << _immortalDuration << " 입니다." << std::endl;
			}
		}
		
		// 업화 확인
		if (_skillType & ST_HELLFIRE) 
		{
			--_hellfireLimitDuration;
			if (!_hellfireLimitDuration)
			{
				std::cout << "숨이 끊어졌습니다." << std::endl;
				_hp = 0;
			}
			else
			{
				_hp -= _hellfireHpDown;
				_hellfireAttackWeight *= 2;
				_hellfireHpDown += 20;
				std::cout << "지옥의 업화 남은 턴수는 " << _hellfireLimitDuration << " 입니다." << std::endl;
			}
		}
	}
}


void Creature::OnAttackedSkill(Creature* attacker)
{

	if (attacker->_creatureType == CT_PLAYER)
	{
		int _cmd;
		std::cout << "스킬을 선택해주세요. " << std::endl;
		switch (attacker->_playerType)
		{
		case PT_Knight:
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "(1) 최후의 의지 : 3턴동안 피가 1 밑으로 내려가지 않습니다." << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
			std::cin >> _cmd;
			if (_cmd == 1)
			{
				if (attacker->_mp  > 30)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 30;
					attacker->SetorSkillType(ST_IMMORTAL);

					// 업화 상태 보너스
					if (attacker->andSkillType(ST_HELLFIRE))
					{
						attacker->_immortalDuration = 6;
					}
					else
					{
						attacker->_immortalDuration = 3;
					}
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}
			}
			else {
				std::cout << "잘못된 입력입니다." << std::endl;
				attacker->SetOnHit(false);
			}
			break;
		case PT_Archer:
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "(1) 맹독 : 5턴동안 지속적인 독 데미지를 부여합니다. " << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
			std::cin >> _cmd;
			if (_cmd == 1)
			{
				if (attacker->_mp > 30)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 30; // 맹독 mp
					SetorSkillType(ST_POISON);
					// 업화상태 보너스
					if (attacker->andSkillType(ST_HELLFIRE))
					{
						_poisonDuration = 10;
					}
					else
					{
						_poisonDuration = 5;
					}
					
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}

			}
			else {
				std::cout << "잘못된 입력입니다." << std::endl;
				attacker->SetOnHit(false);
			}
			break;
		case PT_Mage:
			std::cout << "------------------------------------------------" << std::endl;
			std::cout << "(1) 스턴 : 적이 3턴동안 아무행동도 할 수 없습니다." << std::endl;
			std::cout << "(2) 스톰 : 폭풍을 소환하여 큰 데미지를 부여합니다" << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
			std::cin >> _cmd;
			if (_cmd == 1)
			{
				if (attacker->_mp > 50)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 50; // 스턴 mp
					SetorSkillType(ST_STUN);
					// 업화상태 보너스
					if (attacker->andSkillType(ST_HELLFIRE))
					{
						_stunDuration = 5;
					}
					else
					{
						_stunDuration = 3;
					}
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}
			}
			else if (_cmd == 2)
			{
				if (attacker->_mp > 50)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 50; 
					// 업화 상태 보너스
					if (attacker->andSkillType(ST_HELLFIRE))
					{
						_hp -= 100*attacker->_hellfireAttackWeight;
					}
					else
					{
						_hp -= 100;
					}
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}
			}
			else 
			{
				std::cout << "잘못된 입력입니다." << std::endl;
				attacker->SetOnHit(false);
			}
			break;
		}
	}
	else // 몬스터 타입의 스킬
	{
		// 어떤 스킬을 사용할지에 대한 시드 설정
		double randomValue = (static_cast<double>(std::rand()) / RAND_MAX);
		switch (attacker->GetMonsterType())
		{
		case MT_SLIME:
			std::cout << "맹독 : 몬스터가 5턴동안 지속적인 독 데미지를 부여합니다. " << std::endl;
				SetorSkillType(ST_POISON);
				_poisonDuration = 5;
			break;
		case MT_ORC:
			if (randomValue < 0.8) 
			{
				std::cout << "맹독 : 몬스터가 5턴동안 지속적인 독 데미지를 부여합니다. " << std::endl;
				SetorSkillType(ST_POISON);
				_poisonDuration = 5;
			}
			else 
			{
				std::cout << "침묵 : 플레이어가 2턴동안 마법을 쓸 수 없습니다. " << std::endl;
				SetorSkillType(ST_SILENCE);
				_silenceDuration = 2;
			}
			break;
		case MT_SKELETON:
			if (randomValue < 0.5)
			{
				std::cout << "맹독 : 몬스터가 5턴동안 지속적인 독 데미지를 부여합니다. " << std::endl;
				SetorSkillType(ST_POISON);
				_poisonDuration = 5;
			}
			else if (randomValue < 0.8)
			{
				std::cout << "침묵 : 플레이어가 2턴동안 마법을 쓸 수 없습니다. " << std::endl;
				SetorSkillType(ST_SILENCE);
				_silenceDuration = 2;
			}
			else
			{
				std::cout << "언데드 : 플레이어가 2턴안에 포션을 먹을시 회복량의 반만큼 체력이 깎입니다. " << std::endl;
				SetorSkillType(ST_UNDEAD);
				_undeadDuration = 2;
			}
			break;
		case MT_DRAGON:
			if (randomValue < 0.2)
			{
				std::cout << "맹독 : 몬스터가 5턴동안 지속적인 독 데미지를 부여합니다. " << std::endl;
				SetorSkillType(ST_POISON);
				_poisonDuration = 5;
			}
			else if (randomValue < 0.4)
			{
				std::cout << "침묵 : 플레이어가 2턴동안 마법을 쓸 수 없습니다. " << std::endl;
				SetorSkillType(ST_SILENCE);
				_silenceDuration = 3;
			}
			else if (randomValue < 0.6)
			{
				std::cout << "포션침묵 : 플레이어가 2턴동안 포션을 사용 할 수 없습니다." << std::endl;
				SetorSkillType(ST_PORTIONSILENCE);
				_portionsilenceDuration = 3;
			}
			else if (randomValue < 0.8)
			{
				std::cout << "언데드 : 플레이어가 2턴안에 포션을 먹을시 회복량의 반만큼 깎입니다. " << std::endl;
				SetorSkillType(ST_UNDEAD);
				_undeadDuration = 3;
			}
			else
			{
				std::cout << "스턴 : 플레이어가 2턴동안 아무런 행동도 할 수 없습니다. " << std::endl;
				SetorSkillType(ST_STUN); 
				_stunDuration = 2;
			}

			// 업화시전
			if (!andSkillType(ST_HELLFIRE))
			{
				SetorSkillType(ST_HELLFIRE);
				std::cout << "지옥의 업화 디버프가 발생합니다!!!!!!!! " << std::endl;
				_hellfireLimitDuration = 15;
			}

			break;
		}
	}
}
