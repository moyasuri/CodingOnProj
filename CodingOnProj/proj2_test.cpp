#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    const int timeLimitInSeconds = 5; // 시간 제한(초)

    cout << "숫자를 입력하세요: ";

    DWORD bytesRead;
    char userInput;

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD ir[128];

    // 시작 시간을 기록합니다.
    DWORD startTime = GetTickCount64();
    while (true) {
        while (true) {
            // 현재 시간을 가져옵니다.
            DWORD currentTime = GetTickCount64();

            // 경과 시간을 계산합니다.
            DWORD elapsedTime = currentTime - startTime;

            // 시간 제한을 초과하면 종료합니다.
            if (elapsedTime >= timeLimitInSeconds * 1000) {
                cout << "시간 제한 초과! 프로그램 종료합니다." << endl;
                return 1;
            }

            // 입력 이벤트를 비동기적으로 확인합니다.
            if (PeekConsoleInput(hStdin, ir, 128, &bytesRead)) {
                for (DWORD i = 0; i < bytesRead; i++) {
                    if (ir[i].EventType == KEY_EVENT && ir[i].Event.KeyEvent.bKeyDown) {
                        userInput = ir[i].Event.KeyEvent.uChar.AsciiChar;
                        cout << "입력한 문자: " << userInput << endl;
                        return 0;
                    }
                }
            }

            // 입력 이벤트가 없으면 잠시 대기합니다.
            Sleep(100);
        }

    }
    return 0;
}