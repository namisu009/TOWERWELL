#ifndef _DOUBLEBUFFERMANAGER_H
#define _DOUBLEBUFFERMANAGER_H

#include <stdio.h>
#include<Windows.h>
#include<time.h>
#include <conio.h>
#include <string>

#include "ScreenInfo.h"



using namespace std;

class DoubleBufferManager
{
private:
    static int g_nScreenIndex;
    static HANDLE g_hScreen[2];

public:
    static HANDLE* getHandle() {
        return &g_hScreen[g_nScreenIndex];
    }

    static void ClearConsoleBuffer(HANDLE hBuffer) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hBuffer, &csbi);

        DWORD bufferSize = csbi.dwSize.X * csbi.dwSize.Y; // 버퍼 크기 계산
        COORD coord = { 0, 0 };
        DWORD dwWritten;

        // 버퍼를 공백 문자로 채우기
        FillConsoleOutputCharacter(hBuffer, ' ', bufferSize, coord, &dwWritten);
        FillConsoleOutputAttribute(hBuffer, csbi.wAttributes, bufferSize, coord, &dwWritten);

        // 커서 위치 초기화
        SetConsoleCursorPosition(hBuffer, coord);
    }

    static void ScreenInit()
    {
        COORD bufferSize = { (SHORT)cmdWidth, (SHORT)cmdHeight };
        SMALL_RECT windowSize = { 0, 0, (SHORT)(cmdWidth - 1), (SHORT)(cmdHeight - 1) };

        SetConsoleScreenBufferSize(hOutHandle, bufferSize);
        SetConsoleWindowInfo(hOutHandle, TRUE, &windowSize);
        system("mode con: cols=480 lines=169");

        CONSOLE_CURSOR_INFO cci;

        COORD pos = { 0, 0 };
        DWORD dw;
        FillConsoleOutputCharacter(hOutHandle, ' ', cmdWidth * cmdHeight, pos, &dw);

        //화면 버퍼 2개를 만든다.
        g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        for (int i = 0; i < 2; ++i) {
            DWORD dw;
            COORD coord = { 0, 0 };
            SetConsoleCursorInfo(g_hScreen[i], &cci);

            // 버퍼 크기 정보 가져오기
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(g_hScreen[i], &csbi);
            DWORD dwBufferSize = csbi.dwSize.X * csbi.dwSize.Y;

            // 공백 문자로 초기화
            FillConsoleOutputCharacter(g_hScreen[i], ' ', dwBufferSize, coord, &dw);
            FillConsoleOutputAttribute(g_hScreen[i], csbi.wAttributes, dwBufferSize, coord, &dw);
            SetConsoleCursorPosition(g_hScreen[i], coord);
        }

        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(g_hScreen[0], &csbi);

        //커서 숨기기
        cci.dwSize = 1;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(g_hScreen[0], &cci);
        SetConsoleCursorInfo(g_hScreen[1], &cci);

    }

    //가로크기 -> cmdWidth * 3;
    //세로크기 -> cmdHeight * 5;
    static void ScreenFlipping()
    {
        SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
        g_nScreenIndex = 1 - g_nScreenIndex;
    }

    static void ScreenClear()
    {
        ClearConsoleBuffer(g_hScreen[g_nScreenIndex]);
    }

    static void ScreenRelease()
    {
        CloseHandle(g_hScreen[0]);
        CloseHandle(g_hScreen[1]);
    }

    static void ScreenPrint(int x, int y, const char* string)
    {
        DWORD dw;
        COORD CursorPosition = { x, y };

        size_t length = strlen(string);
        if (length == 0 || length > cmdWidth) return; // 가로 크기를 초과하면 무시

        SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string) , &dw, NULL);
    }

    static void ScreenprintAtPosition(int x, int y, const char* string) {
        DWORD dw;
        COORD CursorPosition = { x, y };
        //SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteConsoleOutputCharacterA(g_hScreen[g_nScreenIndex], string, strlen(string), CursorPosition, &dw); //<<이녀석
    }

    static void drawText(const char* text, int x, int y, int fontSize = 40, const char* fontName = "Consolas") {
        // GDI 폰트와 텍스트 크기 설정
        HWND consoleWindow = GetConsoleWindow();
        HDC hdc = GetDC(consoleWindow);

        HANDLE activeBuffer = g_hScreen[g_nScreenIndex];
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(activeBuffer, &csbi);

        int consoleWidth = 0;
        int consoleHeight = 0;

        if (GetConsoleScreenBufferInfo(activeBuffer, &csbi)) {
            consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        }


        int dialogPosX = x;
        int dialogPosY = y;


        RECT rcTextArea = { dialogPosX, dialogPosY, dialogPosX * 10, dialogPosY * 3 }; // 텍스트가 출력될 영역
        HFONT hFont = CreateFont(fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "Consolas");

        HFONT oldFont = (HFONT)SelectObject(hdc, hFont);
        SetTextColor(hdc, RGB(150, 150, 150));
        SetBkMode(hdc, TRANSPARENT);

        DrawText(hdc, text, -1, &rcTextArea, DT_SINGLELINE | DT_TOP | DT_LEFT);

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);
        ReleaseDC(consoleWindow, hdc);
    }

    /*
    static void drawText(wstring text, int x, int y, int width = cmdWidth - 50, int height = 90, COLORREF color = RGB(150, 150, 150), int fontSize = 90, const std::wstring& fontName = L"맑은 고딕") {
        //(type == 0 일 떄 << 숫자 입력X)
        // 활성 콘솔 버퍼의 핸들 가져오기
        HANDLE activeBuffer = g_hScreen[g_nScreenIndex];
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(activeBuffer, &csbi);

        // Console Window 핸들 가져오기
        HWND consoleWindow = GetConsoleWindow();
        HDC hdc = GetDC(consoleWindow);

        RECT rcTextArea = { x, y, x + text.size() * fontSize, y + height};
        // 글씨체 및 크기 설정
        HFONT hFont = CreateFont(
            fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, fontName.c_str()
        );

        // 이전 폰트 저장
        HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

        SetTextColor(hdc, color);
        SetBkMode(hdc, TRANSPARENT);

        // 텍스트 출력

        DrawText(hdc, text.c_str(), -1, &rcTextArea, DT_SINGLELINE | DT_VCENTER);

        //TextOut(hdc, x, y, text.c_str(), text.length());

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);
        ReleaseDC(consoleWindow, hdc);
    }
    */
};

#endif