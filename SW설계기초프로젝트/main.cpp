#include "GameManager.h"
#include <io.h>
#include <fcntl.h>

#include <windows.h>
#include <iostream>


void EnableDPIAwareness() {
    SetProcessDPIAware();
}

// 창 크기와 위치를 설정하는 함수
void SetConsoleWindowPosition(int cmdWidth, int cmdHeight) {
    HWND consoleWindow = GetConsoleWindow();

    // 창 크기 계산 (픽셀 단위)
    int windowWidth = cmdWidth * CELL_WIDTH;
    int windowHeight = cmdHeight * CELL_HEIGHT;

    // 화면 해상도 가져오기
    HMONITOR hMonitor = MonitorFromWindow(consoleWindow, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO monitorInfo = { sizeof(MONITORINFO) };
    GetMonitorInfo(hMonitor, &monitorInfo);

    int screenWidth = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
    int screenHeight = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;

    // 창 위치 계산 (화면 중앙에 배치)
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;

    // 창 크기와 위치 설정
    MoveWindow(consoleWindow, posX, posY, windowWidth, windowHeight, TRUE);
}

void AdjustConsole(int cmdWidth, int cmdHeight) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 버퍼 크기와 창 크기 설정
    COORD bufferSize = { (SHORT)cmdWidth, (SHORT)cmdHeight };
    SMALL_RECT windowSize = { 0, 0, (SHORT)(cmdWidth - 1), (SHORT)(cmdHeight - 1) };

    SetConsoleScreenBufferSize(hConsole, bufferSize);
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // 창 크기와 위치 설정
    SetConsoleWindowPosition(cmdWidth, cmdHeight);
}


void fullscreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void setConsoleEncoding() {
    // 표준 출력과 입력을 UTF-8로 설정
    _setmode(_fileno(stdout), _O_U8TEXT); // 유니코드 출력
    _setmode(_fileno(stdin), _O_U8TEXT); // 유니코드 입력
}

int main() {
    //fullscreen();
    EnableDPIAwareness();
    AdjustConsole(cmdWidth, cmdHeight);

    setConsoleEncoding();
    GameManager gameManager;
    gameManager.start();
    return 0;
}