#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void isDuplicate(vector<int>& _myVec,const int& player, int& terminate)
{
	while (true)
	{
		
			
		if (player == 0)
		{
			cout << "1 ~ 9 사이의 숫자 3개를 입력하세요 (이외의 숫자 : 종료)" << endl;
			for (int& num : _myVec)
			{
				bool chk_num = true;
				while (chk_num)
				{
					cin >> num;

					if (num <1 || num>9)
					{
						terminate = 1;
						return;
					}
					else
					{
						chk_num = false;
					}

				}
			}
		}
		else
		{
			for (int& num : _myVec)
			{
				num = rand() % 9 + 1;;
			}
		}
			
		sort(_myVec.begin(), _myVec.end());

		// 중복 제거
		_myVec.erase(unique(_myVec.begin(), _myVec.end()), _myVec.end());

		if (_myVec.size() != 3)
		{
			_myVec.assign(3, 0);
			if (player == 0)
			{
				cout << "중복입니다." << endl;
			}
		}
		else
		{
			return;
		}

	}
}

int main()
{
	srand((unsigned int)time(nullptr));
	vector<int> myVec(3);
	vector<int> ComVec(3);



	int stkCnt=0, ballCnt=0;
	int end = 0;
	
	while (stkCnt != 3)
	{
		stkCnt= 0 , ballCnt=0;
		isDuplicate(myVec, 0, end);
		if (end == 1)
		{
			cout << "게임을 종료하였습니다.";
			break;
		}
		isDuplicate(ComVec, 1, end);
		
		for (int i=0; i<3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (myVec[i] == ComVec[j])
				{
					if(i == j)
						stkCnt++;
					else
					{
						ballCnt++;
					}
				}
			}
		}
		cout << "Strke : " << stkCnt << "           " << "Ball : " << ballCnt << endl;
	}

}