#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int k;
	bool isOdd = true;
	cout << "홀수를 입력해주세요 : ";
	
	while (isOdd)
	{
		cin >> k;
		if (k % 2 == 1)
		{
			isOdd = false;
		}
		else
		{
			cout << "홀수가 아닙니다. 다시입력해주세요 : ";
		}
	}
	
	
	
	int** arr = new int*[k];

	for (int i = 0; i < k;i++)
	{
		arr[i] = new int[k];
	}

	for (int i = 0;i < k;i++)
	{
		for (int j = 0; j < k;j++)
		{
			arr[i][j] = 0;
		}

	}
	




	int Row = 0;
	int Col = (k - 1) / 2;; //초기
	int num = 1;
	arr[Row][Col] = num;
	




	for (int i = 0;i < k*k-1;i++)
	{

		// 첫번째 행의 마지막 열에서는 우상단으로 이동하는 것이 아니라 바로 아래칸으로 이동
		if ( Row == 0 && Col == k - 1)
		{
			Row = 1;
			arr[Row][Col] = ++num;
		}
		else if (Row == 0)// 첫번째 행에서 우상단으로 이동할 때는 마지막 행의 다음 열로 이동한다
		{
			Row = k-1;
			Col = Col + 1;
			arr[Row][Col] = ++num;
		}
		else if (Col == k - 1)// 마지막 열에서 우상단으로 이동할 때는 첫번째 열의 이전 행으로 이동한다
		{
			Col = 0;
			Row = Row - 1;
			arr[Row][Col] = ++num;
		}
		else if ((arr[Row - 1][Col + 1] != 0))
		{
			// Col = Col;
			Row = Row + 1;
			arr[Row][Col] = ++num;
		}
		else
		{
			Row = Row - 1;
			Col = Col + 1;
			arr[Row][Col] = ++num;
		}

		//for (int i = 0; i < k;i++)
		//{
		//	for (int j = 0; j < k;j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}


		//cout << endl;


	}

	for (int i = 0; i < k;i++)
	{
		for (int j = 0; j < k;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	
	for (int i = 0; i < k;i++)
	{
		delete[] arr[i];
	}
	delete arr;
	

	

}