#include <iostream>
#include "Character.h"
#include <Windows.h>
using namespace std;


void printName(std::vector<Character*> _myVec);
void removePlayer(std::vector<Character*>& _myVec);
int main()
{
	std::vector<Character*> myVec;
	bool cha_create = true;
	string _name = "";

	// 캐릭터 생성부
	while (cha_create)
	{
		int i = 0;
		cout << "character 이름을 입력해주세요 :" << endl;
		cin >> _name;
		myVec.push_back(new Character(_name));
		cout << "character 생성을 더하시겠습니까? 0 : No, 1: Yes " << endl;
		cin >> i;
		if (!i)
		{
			cha_create = false;
		}
	}

	// 게임 시작부

	int att, def;
	while (1)
	{
		printName(myVec);
		Sleep(1000);

		cout << "공격자, 방어자를 순서대로 입력해주세요 ex) 3 4  : " << endl;
		cin >> att >> def;

		myVec[att]->AttackPlayer(*myVec[def]);
		removePlayer(myVec);

	}


	
	

}

void printName(std::vector<Character*> _myVec)
{
	int cnt = 0;
	for (Character* _cha : _myVec)
	{

		cout << "캐릭터 이름 /// " << _cha->GetName() << "플레이어 번호 = " << cnt++ << endl;

	}
}

void removePlayer(std::vector<Character*>& _myVec)
{
	for (int i = 0; i < _myVec.size(); /* no increment here */) {
		if (_myVec[i]->GetHP() < 0)
		{
			cout << _myVec[i]->GetName() << "은 죽었습니다." << endl;
			_myVec.erase(_myVec.begin() + i);
		}
		else {
			++i;
		}
	}

}
