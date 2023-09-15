#include <iostream>
#include <vector>
using namespace std;
#include <random>


bool game(int input, int& cnt_g) {

    bool chk = true;

    for (int i = 0; i < input;i++)
    {
        cout << ++cnt_g << endl;
        if (cnt_g == 31)
        {
            chk = false;
            break;
          
            // 동작 그만
        }
    }


    return chk;
}

int main()
{


    int num = 0;
    int cnt=0;
    int input = 0;

    bool chk = true;
    bool n_chk = true;
    mt19937_64 rng1(std::time(nullptr));
    uniform_int_distribution<__int32> dist_com(1, 3);

    
    // 컴퓨터 , 나를 구분 지어야한다.
    while (chk)
    {
        while (n_chk)
        {
            
            cout << "개수를 입력하세요: ";
            cin >> input;
            if (input < 0 || input>4)
            {
                cout << "1~3 사이의 수를 입력하세요." << endl;
            }
            else
            {
                n_chk = false;
            }

        }
        n_chk = true;
        cout << "사용자가 부른 숫자!" << endl;
        chk = game(input, cnt);
        if (!chk)
        {
            cout << "게임 종료 컴퓨터의 승리입니다" << endl;
        }
        cout << "컴퓨터가 부른 숫자!" << endl;

        chk = game(dist_com(rng1),cnt);
        if (!chk)
        {
            cout << "게임 종료 사용자의 승리입니다" << endl;
        }
    
    }

    
    
    
}


