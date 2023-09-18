#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <conio.h>

std::atomic<bool> isRunning(true); // 스레드 종료 조건
// thread , mainthread 공유하기 위해서 atomic


// 스레드 함수: 사용자 입력 받기
void userInputThread() {
    std::string input;
    char ch = ' ';

    while (isRunning) {
        input = "";
        std::cout << "사용자 입력: ";
        while (true) {
            ch = _getch(); // cin << 블록함수 
            // _getch << 하나씩

            input += ch;
            //std::cout << " ch " << ch << std::endl;;
            std::cout << ch;
            if (!isRunning)
            {
                break;
            }
            if (ch == 13) {
                std::cout << "break" << std::endl;
                break; // Enter 키를 누르면 종료
            }
        }
        std::cout << "입력값: " << input << std::endl;
    }
}

int main() {
    std::thread inputThread(userInputThread);
    int seconds = 0;

    // 메인 스레드에서 초를 세기
    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds++;
        std::cout << "경과 시간 (초): " << seconds << std::endl;

        // 10초가 되면 스레드 종료
        if (seconds >= 10) {
            isRunning = false;
            inputThread.join(); // 스레드 종료 대기
            break;
        }
    }

    std::cout << "메인 스레드 종료" << std::endl;

    return 0;
}