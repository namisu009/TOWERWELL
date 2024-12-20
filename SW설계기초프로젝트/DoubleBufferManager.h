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
        WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
    }

    static void ScreenprintAtPosition(int x, int y, const char* string) {
        DWORD dw;
        COORD CursorPosition = { x, y };
        //SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteConsoleOutputCharacterA(g_hScreen[g_nScreenIndex], string, strlen(string), CursorPosition, &dw); //<<이녀석
    }

    static float GetDPIScalingFactor() {
        HWND hWnd = GetConsoleWindow();
        HDC hdc = GetDC(hWnd);

        // 기본 DPI 값은 96 (100% 스케일)
        int dpi = GetDeviceCaps(hdc, LOGPIXELSX);

        ReleaseDC(hWnd, hdc);

        return dpi / 96.0f; // DPI 스케일링 비율 반환
    }

    static RECT ConvertArrayToPixelRect(int arrayX, int arrayY, int arrayWidth, int arrayHeight) {
        RECT clientRect = GetConsoleClientRect();
        int clientWidth = clientRect.right - clientRect.left;
        int clientHeight = clientRect.bottom - clientRect.top;

        // 배열 → 픽셀 변환 비율
        float scaleX = static_cast<float>(clientWidth) / 470.0f;
        float scaleY = static_cast<float>(clientHeight) / 169.0f;

        // 픽셀 좌표 계산
        RECT rect;
        rect.left = static_cast<int>(arrayX * scaleX);
        rect.top = static_cast<int>(arrayY * scaleY);
        rect.right = static_cast<int>(rect.left + arrayWidth * scaleX);
        rect.bottom = static_cast<int>(rect.top + arrayHeight * scaleY);

        return rect;
    }

    static RECT adjustRectForVerticalCenter(RECT rect, int textHeight) {
        int rectHeight = rect.bottom - rect.top;
        int verticalOffset = (rectHeight - textHeight) / 2;

        // RECT를 수직으로 이동
        rect.top += verticalOffset;
        rect.bottom = rect.top + textHeight;

        return rect;
    }

    static int calculateTextHeight(HDC hdc, const std::string& text, RECT rect, int format, int fontSize) {

        HFONT hFont = CreateFont(fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "Consolas");

        HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

        RECT tempRect = rect;
        // 텍스트 높이 계산
        DrawTextA(hdc, text.c_str(), -1, &tempRect, format | DT_CALCRECT);

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);

        return tempRect.bottom - tempRect.top; // 계산된 텍스트 높이 반환
    }


    static RECT AdjustRect(const RECT& baseRect, float horizontalMarginRatio, float verticalMarginRatio) {
        RECT adjustedRect = baseRect;

        int horizontalMargin = static_cast<int>((baseRect.right - baseRect.left) * horizontalMarginRatio);
        int verticalMargin = static_cast<int>((baseRect.bottom - baseRect.top) * verticalMarginRatio);

        // RECT를 줄이는 작업
        adjustedRect.left += horizontalMargin;
        adjustedRect.right -= horizontalMargin;
        adjustedRect.top += verticalMargin;
        adjustedRect.bottom -= verticalMargin;

        return adjustedRect;
    }

    static RECT GetConsoleClientRect() {
        HWND consoleWindow = GetConsoleWindow();
        RECT clientRect;

        // 클라이언트 영역 크기 가져오기
        GetClientRect(consoleWindow, &clientRect);

        return clientRect;
    }
    static void drawText(const char* text, int x, int y, int width = 0, int height = 0, int fontSize = 35) {
        // Get the console window and device context
        HWND consoleWindow = GetConsoleWindow();
        HDC hdc = GetDC(consoleWindow);

        // Get DPI scaling factor for dynamic adjustments
        float dpiScale = GetDPIScalingFactor();
        int adjustedFontSize = static_cast<int>(fontSize * dpiScale);

        // Convert logical array coordinates to pixel-based rectangle
        RECT rect = ConvertArrayToPixelRect(x, y, width, height);

        // Calculate the text height dynamically based on the DPI-scaled font size
        int textHeight = calculateTextHeight(hdc, text, rect, DT_WORDBREAK | DT_CENTER, adjustedFontSize);

        // Adjust the rectangle for vertical centering
        RECT adjustedRect = adjustRectForVerticalCenter(rect, textHeight);

        // Further adjust the rectangle by reducing margins for better positioning
        adjustedRect = AdjustRect(adjustedRect, 0.05f, 0.05f);

        // Create a font with dynamic size based on DPI scaling
        HFONT hFont = CreateFont(
            adjustedFontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "맑은 고딕");

        // Save the old font and set the new font
        HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

        // Set text color and background mode
        SetTextColor(hdc, RGB(150, 150, 150));
        SetBkMode(hdc, TRANSPARENT);

        // Draw the text
        DrawText(hdc, text, -1, &adjustedRect, DT_LEFT | DT_WORDBREAK);

        // Restore the old font and release resources
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
