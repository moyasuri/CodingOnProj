#include <iostream>
#include <Windows.h>
#include <vector>
#include<set>
using namespace std;

int main() {
    const int timeLimitInSeconds = 5; // 시간 제한(초)

    
    DWORD bytesRead;
    string userInput;
    bool overlap;
    int ex_size;

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD ir[128];
    set<string> _str;
    // 시작 시간을 기록합니다.
    DWORD startTime; 
    bool chk = true;
    bool chk_2 = true;
    string letter_chk;

    cout << "끝말잇기 시작 : 단어를 입력해주세요" <<endl;
    cin >> userInput;
    _str.insert(userInput);


    letter_chk = *(--_str.end());

    if (letter_chk[letter_chk.size()] == *userInput.begin())
    return 0;
}