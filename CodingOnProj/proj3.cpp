#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

#include <vector>


bool isDuplicate(int n, vector<int> myVec)
{
	for (int i = 0; i < n ;i++)
	{
		if (myVec[i] == myVec[n])
		{
			return true;
		}
	}

	return false;
};

int main()
{
	srand((unsigned int)time(nullptr));

	vector<int> myVector;
	vector<int> comVector;

	


	

	comVector.assign(6,0);
	myVector.assign(6, 0);
	
	for (int i = 0; i < 6;i++)
	{
		bool isDuplicated_Re = true;
		while (isDuplicated_Re)
		{

			comVector[i] = rand() % 25 + 1;
			if (isDuplicate(i, comVector))
			{

				continue;
			}
			else
			{

				isDuplicated_Re = false;
			}
		}
	}



	// 중복검사 함수
	

	int Input;
	
	cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl;
	for (int i = 0; i < 6;i++)
	{
		bool isDuplicated_Re = true;
		while (isDuplicated_Re)
		{
			cout << i + 1 << "번째 번호를 입력하세요: ";
			cin >> Input;
			myVector[i] = Input;
			if (Input < 1 || Input >25)
			{
				cout << "잘못된 숫자입니다. 다시 입력해주세요" << endl;
				continue;
			}
			if (isDuplicate(i, myVector))
			{
				cout << "이미 입력된 숫자입니다." << endl;
				continue;
			}
			else
			{
				
				isDuplicated_Re = false;
			}
		}
	}

	cout << "------------------" << endl;
	cout << "당첨번호 공개!" << endl;
	
	int wins = 7;
	for (const int& num : comVector)
	{
		cout << num << " ";
		for (const int& num2 : myVector)
		{
			if (num == num2)
			{
				wins--;
			}
		}
	}

	
	cout << endl;
	cout << "1~7등가지의 결과가 나올 수 있습니다." << endl;
	cout << "결과 : " << wins << "등입니다!";



}