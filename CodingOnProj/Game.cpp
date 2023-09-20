#include <iostream>
#include "Game.h"

using namespace std;


#include "Player.h"
#include "Field.h"

Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game()
{
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;
}

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();

	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;

		/*Double Deletion 방지 : 이미 삭제된 메모리를 다시 삭제하려고 시도하면 프로그램이 비정상적으로 종료될 수 있습니다.이를 방지하기 위해 포인터를 nullptr로 설정하면 해당 포인터가 이미 삭제된 메모리를 가리키고 있음을 나타내므로 두 번 이상 삭제를 시도하지 않습니다.

			안전한 접근 방지 : 삭제된 메모리에 접근하려고 시도하면 예상하지 못한 동작 또는 오류를 발생시킬 수 있습니다.포인터를 nullptr로 설정하면 해당 메모리에 더 이상 접근할 수 없게 되므로 프로그램의 안전성이 향상됩니다.

			디버깅 용이성 : 포인터를 nullptr로 설정하면 해당 포인터를 사용할 때 런타임 에러를 방지하고 디버깅을 용이하게 합니다. nullptr 포인터를 감지하고 해당 위치에서 문제를 파악하기 쉽기 때문입니다.*/

		CreatePlayer();
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "------------------" << endl;
		cout << "캐릭터를 생성하세요!" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "------------------" << endl;

		cout << "> ";

		int input = 0;
		cin >> input;

		if (input == PT_Knight)
		{
			_player = new Knight();
		}
		else if (input == PT_Archer)
		{
			_player = new Archer();
		}
		else if (input == PT_Mage)
		{
			_player = new Mage();
		}
	}
}