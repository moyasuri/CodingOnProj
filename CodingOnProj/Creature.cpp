#include "Creature.h"
#include "Player.h"


void Creature::OnAttacked(Creature* attacker)
{
	int damage = attacker->_attack - _defence;
	if (damage < 0)
		damage = 1;

	_hp -= damage;
	if (_hp < 0)
		_hp = 0;
}

void Creature::CheckStatus(){
	bool isDebuff = 0b11111111 & _skillType;
	if (isDebuff)
	{
		if (_skillType & ST_STUN)
		{
			_stunSW = true;
			if (_stunDuration == 0)
			{
				_skillType &= (~ST_STUN);
				_stunSW = false;
			}
			--_stunDuration;
		}

		if (_skillType & ST_POISON)
		{
			_hp -= 20;
			if (_poisonDuration == 0)
			{
				_skillType &= (~ST_POISON);
			}
			--_poisonDuration;
		}

		if (_skillType & ST_IMMORTAL) // 
		{
			
			if (_immortalDuration == 0)
			{
				_skillType &= (~ST_IMMORTAL);
			}
			--_immortalDuration;

		}
		if (_skillType & ST_SILENCE)
		{
			if(_silenceDuration==0)
			{
				_skillType &= (~ST_SILENCE);
			}
			--_silenceDuration;
		}
		if (_skillType & ST_PORTIONSILENCE)
		{
			if (!_silenceportionDuration)
			{
				_skillType &= (~ST_PORTIONSILENCE);
			}
			--_silenceportionDuration;
		}


		if (_skillType & ST_HELLFIRE) // 요주의 인물
		{

		}

		if (_skillType & ST_UNDEAD)
		{
			if (!_undeadDuration)
			{
				_skillType &= (~ST_UNDEAD);
			}
			--_undeadDuration;
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
			std::cout << "(1) 최후의 의지 : 3턴동안 피가 1 밑으로 내려가지 않습니다." << std::endl;
			std::cin >> _cmd;
			if (_cmd == 1)
			{
				if (attacker->_mp  > 30)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 30; // 최의 mp
					attacker->_skillType = attacker->_skillType | ST_IMMORTAL;
					_immortalDuration = 3;
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}
				
			}

			break;
		case PT_Archer:
			std::cout << "(1) 맹독 : 5턴동안 지속적인 독 데미지를 부여합니다. " << std::endl;
			std::cin >> _cmd;
			if (_cmd == 1)
			{
				if (attacker->_mp > 30)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 30; // 맹독 mp
					_skillType = _skillType | ST_POISON;
					_poisonDuration = 3;
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}

			}

			break;
		case PT_Mage:
			std::cout << "(1) 스턴 : 적이 3턴동안 아무행동도 할 수 없습니다." << std::endl;
			std::cout << "(2) 스톰 : 폭풍을 소환하여 큰 데미지를 부여합니다" << std::endl;
			std::cin >> _cmd;
			if (_cmd == 1)
			{
				if (attacker->_mp > 50)
				{
					attacker->SetOnHit(true);
					attacker->_mp -= 50; // 스턴 mp
					_skillType = _skillType | ST_STUN;
					_stunDuration = 3;
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
					attacker->_mp -= 50; // 폭풍 소환 mp
					_hp -= 100;
				}
				else
				{
					std::cout << "마나가 부족합니다" << std::endl;
					attacker->SetOnHit(false);
				}

			}
			break;
		}


	}
	else
	{


	}
}


	




