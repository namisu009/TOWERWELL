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
    static void ScreenInit()
    {
        COORD size = { cmdWidth + 10, cmdHeight + 10 };
        SetConsoleScreenBufferSize(hOutHandle, size);

        system("mode con: cols=480 lines=170");

        CONSOLE_CURSOR_INFO cci;

        COORD pos = { 0, 0 };
        DWORD dw;
        FillConsoleOutputCharacter(hOutHandle, ' ', cmdWidth * cmdHeight * cmdWidth, pos, &dw);

        //화면 버퍼 2개를 만든다.
        g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        //커서 숨기기
        cci.dwSize = 1;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(g_hScreen[0], &cci);
        SetConsoleCursorInfo(g_hScreen[1], &cci);

    }

    static void ScreenFlipping()
    {
        SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
        g_nScreenIndex = !g_nScreenIndex;
    }

    static void ScreenClear()
    {
        COORD CursorPosition = { 0,0 };
        DWORD dw;
        char string[cmdWidth] = { ' ' };

        for (int y = 0; y < cmdHeight; y++) {
            CursorPosition.Y = y;
            SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
            WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
        }
    }

    static void ScreenRelease()
    {
        CloseHandle(g_hScreen[0]);
        CloseHandle(g_hScreen[1]);
    }

    static void ScreenPrint(int x, int y, char* string)
    {
        DWORD dw;
        COORD CursorPosition = { x, y };
        SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
    }

    static void ScreenprintAtPosition(int x, int y, const char* string) {
        DWORD dw;
        COORD CursorPosition = { x, y };
        //SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteConsoleOutputCharacterA(g_hScreen[g_nScreenIndex], string, strlen(string), CursorPosition, &dw); //<<이녀석
    }

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
};

#endif