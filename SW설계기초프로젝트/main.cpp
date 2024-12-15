#include "GameManager.h"
#include <io.h>
#include <fcntl.h>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <filesystem> 

enum PageState {
    MAIN_PAGE_01,
    MAIN_PAGE_02
};

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
void LoadAndDisplayAsciiArt(const char* filePath) {
    ArtLoadManager* artManager = ArtLoadManager::GetInstance();
    RenderArray asciiArt = { 0 };

    artManager->RenderArrayLoad(&asciiArt, filePath);


    DoubleBufferManager::ScreenClear();

    for (int y = 0; y < asciiArt.height; y++) {
        if (asciiArt.ASCIIArtArr[y] != nullptr) {
            DoubleBufferManager::ScreenPrint(0, y, asciiArt.ASCIIArtArr[y]);
        }
    }

    DoubleBufferManager::ScreenFlipping();

    /*  if (asciiArt.ASCIIArtArr) {
          for (int y = 0; y < asciiArt.height; y++) {
              delete[] asciiArt.ASCIIArtArr[y];
          }
          delete[] asciiArt.ASCIIArtArr;
      }
      if (asciiArt.drawornotArr) {
          for (int y = 0; y < asciiArt.height; y++) {
              delete[] asciiArt.drawornotArr[y];
          }
          delete[] asciiArt.drawornotArr;
      }*/

}


void InitializeDoubleBufferOnce() {
    static bool isInitialized = false;
    if (!isInitialized) {
        DoubleBufferManager::ScreenInit();
        isInitialized = true;
    }
}

int main() {
    EnableDPIAwareness();
    AdjustConsole(cmdWidth, cmdHeight);
    InitializeDoubleBufferOnce();
    setConsoleEncoding();
    PageState currentState = MAIN_PAGE_01;

    LoadAndDisplayAsciiArt("src\\main_page_01.png");


    while (true) {
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (currentState != MAIN_PAGE_02) {
                currentState = MAIN_PAGE_02;
                LoadAndDisplayAsciiArt("src\\main_page_02.png");

            }
            Sleep(200);
        }
        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (currentState != MAIN_PAGE_01) {
                currentState = MAIN_PAGE_01;
                LoadAndDisplayAsciiArt("src\\main_page_01.png");
            }
            Sleep(200);
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            if (currentState == MAIN_PAGE_01) {
                break;
            }
            else if (currentState == MAIN_PAGE_02) {
                return 0;
            }
        }
        Sleep(100);
    }
    DoubleBufferManager::ScreenRelease();


    GameManager gameManager;
    //gameManager.initialize();
    gameManager.start();
    return 0;
}

