#include <iostream>
#include <vector>
using namespace std;
#include<stdio.h>
#include<stdlib.h>    // srand, rand
#include<time.h>    // time_t, clock, difftime
#include<conio.h>
#include <algorithm>
#include <set>

//1)
//제한 시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
//2)
//제한 시간이 종료되면 게임을 종료 시키고 입력한 단어의 개수를 출력
//3)
//단, 한번 입력된 단어는 입력하지 못하게 하기




int main()
{
    //int keyin;
    //time_t new_time, old_time;
    //old_time = clock();        // 시작 시간 
    //keyin = 1;                // 키입력 초기값 
    //int DELAY = 30000;

    //int x, y, answer, sum;


    //while (1) {
    //    do {
    //        new_time = clock();    // 현재 시간 
    //        if (difftime(new_time, old_time) > DELAY) {    // 시간 초과 검사 
    //            answer = 0;        // 답이 없음 
    //            keyin = 0;        // 키입력이 없음 
    //            break;
    //        }
    //    } while (!kbhit());        // 키가 안 눌린 동안 

    //    if (keyin == 1) {
    //        cout<<        // 답을 받음 

    //        /* enter키를 치는 시점에 시간 계산을 위해 추가할 내용 */
    //        new_time = clock();    // 현재 시간 
    //        if (difftime(new_time, old_time) > DELAY)    answer = 0;

    //    }
    //}




    set<string> con_String;

    // set 집합에서 같은걸 쳤는지 확인하는 방법

    // 출력하는 방법
    string input;
    int ex_size;
    bool overlap =true;


    // set<string>::iterator it = con_String.begin();

    while (1)
    {
        
        do {
            ex_size = con_String.size();
            cout << "다음 단어를 입력하세요 : ";
            cin >> input;
            con_String.insert(input);
            if (con_String.size() == ex_size) // 중복된 단어
            {
                
                overlap = true;
            }
            else {
                overlap = false;
            }
            
            if (overlap)
            {
                cout << "중복된 단어 입니다" << endl << endl;
            }

                

        } while (overlap);
        
        

        for (set<string>::iterator it = con_String.begin() ; it != con_String.end();it++)
        {
            cout << *it << " >> ";
            
        }
        cout << endl;
    }






}


