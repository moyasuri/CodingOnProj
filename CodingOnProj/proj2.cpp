#include <iostream>
#include <Windows.h>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
    const int timeLimitInSeconds = 30; // 시간 제한(초)


    DWORD bytesRead;
    string userInput;
    bool overlap;
    int ex_size;

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD ir[128];

    vector<string> myVector ;
    int v_size;
    string lastElement;

    
    // 시작 시간을 기록합니다.
    DWORD startTime;
    bool chk = true;
    bool chk_2 = true;
    string ex_element;

    cout << "끝말잇기 시작 : 단어를 입력해주세요" << endl;
    cin >> userInput;
    myVector.push_back(userInput);

    while (chk) {

        cout << "다음 단어를 입력하세요 : ";
        startTime = GetTickCount64();
        chk_2 = true;
        while (chk_2) {



            // 현재 시간을 가져옵니다.
            DWORD currentTime = GetTickCount64();

            // 경과 시간을 계산합니다.
            DWORD elapsedTime = currentTime - startTime;

            // 시간 제한을 초과하면 종료합니다.
            if (elapsedTime >= timeLimitInSeconds * 1000) {
                cout << "시간 제한 초과! 프로그램 종료합니다." << endl;
                chk = false;
                break;
            }

            // 입력 이벤트를 비동기적으로 확인합니다.
            if (PeekConsoleInput(hStdin, ir, 128, &bytesRead)) {
                for (DWORD i = 0; i < bytesRead; i++) {
                    if (ir[i].EventType == KEY_EVENT && ir[i].Event.KeyEvent.bKeyDown) {
                        // userInput = ir[i].Event.KeyEvent.uChar.AsciiChar;

                        // 스펠체크
                        cin >> userInput;
                        myVector.push_back(userInput);
                        v_size = myVector.size();
                        ex_element = myVector[v_size- 2]; // 이전 원소
                        
                        
                        if (ex_element[ex_element.size()-1] != userInput[0])
                        {
                            myVector.pop_back();
                            cout << "잘못된 단어입니다." << endl;
                            cout << "다음 단어를 입력하세요 : ";
                            break;
                        }

                        // 중복 확인
                        
                        bool isDuplicate = false;
                        lastElement = myVector.back(); // 마지막으로 추가 된 원소

                        for (int i = 0; i < myVector.size() - 1; ++i) {
                            if (myVector[i] == lastElement) {
                                cout << "중복된 단어입니다" << endl;;
                                isDuplicate = true;
                                break;
                            }
                        }

                        // 중복이 있다면 마지막 원소 제거
                        if (isDuplicate) {
                            myVector.pop_back();
                        }
                        
                        for (const string& str : myVector)
                        {
                            if (str == myVector[0])
                            {
                                cout << str;
                            }
                            else
                            {
                                cout << "->" << str;
                            }
                        }
                        cout << endl;
                        // startTime = GetTickCount64();
                        chk_2 = false;
                        break;
                    }
                }
            }

            // 입력 이벤트가 없으면 잠시 대기합니다.
            Sleep(10);
        }

    }
    return 0;
}