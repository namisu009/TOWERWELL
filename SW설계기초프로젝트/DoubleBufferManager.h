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

        DWORD bufferSize = csbi.dwSize.X * csbi.dwSize.Y; // ���� ũ�� ���
        COORD coord = { 0, 0 };
        DWORD dwWritten;

        // ���۸� ���� ���ڷ� ä���
        FillConsoleOutputCharacter(hBuffer, ' ', bufferSize, coord, &dwWritten);
        FillConsoleOutputAttribute(hBuffer, csbi.wAttributes, bufferSize, coord, &dwWritten);

        // Ŀ�� ��ġ �ʱ�ȭ
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

        //ȭ�� ���� 2���� �����.
        g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
            0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        for (int i = 0; i < 2; ++i) {
            DWORD dw;
            COORD coord = { 0, 0 };
            SetConsoleCursorInfo(g_hScreen[i], &cci);

            // ���� ũ�� ���� ��������
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(g_hScreen[i], &csbi);
            DWORD dwBufferSize = csbi.dwSize.X * csbi.dwSize.Y;

            // ���� ���ڷ� �ʱ�ȭ
            FillConsoleOutputCharacter(g_hScreen[i], ' ', dwBufferSize, coord, &dw);
            FillConsoleOutputAttribute(g_hScreen[i], csbi.wAttributes, dwBufferSize, coord, &dw);
            SetConsoleCursorPosition(g_hScreen[i], coord);
        }

        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(g_hScreen[0], &csbi);

        //Ŀ�� �����
        cci.dwSize = 1;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(g_hScreen[0], &cci);
        SetConsoleCursorInfo(g_hScreen[1], &cci);

    }

    //����ũ�� -> cmdWidth * 3;
    //����ũ�� -> cmdHeight * 5;
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
        if (length == 0 || length > cmdWidth) return; // ���� ũ�⸦ �ʰ��ϸ� ����

        SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string) , &dw, NULL);
    }

    static void ScreenprintAtPosition(int x, int y, const char* string) {
        DWORD dw;
        COORD CursorPosition = { x, y };
        //SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
        WriteConsoleOutputCharacterA(g_hScreen[g_nScreenIndex], string, strlen(string), CursorPosition, &dw); //<<�̳༮
    }

    static float GetDPIScalingFactor() {
        HWND hWnd = GetConsoleWindow();
        HDC hdc = GetDC(hWnd);

        // �⺻ DPI ���� 96 (100% ������)
        int dpi = GetDeviceCaps(hdc, LOGPIXELSX);

        ReleaseDC(hWnd, hdc);

        return dpi / 96.0f; // DPI �����ϸ� ���� ��ȯ
    }

    static RECT ConvertArrayToPixelRect(int arrayX, int arrayY, int arrayWidth, int arrayHeight) {
        RECT clientRect = GetConsoleClientRect();
        int clientWidth = clientRect.right - clientRect.left;
        int clientHeight = clientRect.bottom - clientRect.top;

        // �迭 �� �ȼ� ��ȯ ����
        float scaleX = clientWidth / 470.0f;
        float scaleY = clientHeight / 169.0f;

        // �ȼ� ��ǥ ���
        RECT rect;
        rect.left = arrayX * scaleX;
        rect.top = arrayY * scaleY;
        rect.right = rect.left + arrayWidth * scaleX;
        rect.bottom = rect.top + arrayHeight * scaleY;

        return rect;
    }

    static RECT adjustRectForVerticalCenter(RECT rect, int textHeight) {
        int rectHeight = rect.bottom - rect.top;
        int verticalOffset = (rectHeight - textHeight) / 2;

        // RECT�� �������� �̵�
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
        // �ؽ�Ʈ ���� ���
        DrawTextA(hdc, text.c_str(), -1, &tempRect, format | DT_CALCRECT);

        return tempRect.bottom - tempRect.top; // ���� �ؽ�Ʈ ���� ��ȯ
    }


    static RECT AdjustRect(const RECT& baseRect, float horizontalMarginRatio, float verticalMarginRatio) {
        RECT adjustedRect = baseRect;

        int horizontalMargin = (baseRect.right - baseRect.left) * horizontalMarginRatio;
        int verticalMargin = (baseRect.bottom - baseRect.top) * verticalMarginRatio;

        // RECT�� ���̴� �۾�
        adjustedRect.left += horizontalMargin;
        adjustedRect.right += horizontalMargin;
        adjustedRect.top += verticalMargin;
        adjustedRect.bottom -= verticalMargin;

        return adjustedRect;
    }

    static RECT GetConsoleClientRect() {
        HWND consoleWindow = GetConsoleWindow();
        RECT clientRect;

        // Ŭ���̾�Ʈ ���� ũ�� ��������
        GetClientRect(consoleWindow, &clientRect);

        return clientRect;
    }

    static void drawText(const char* text, int x, int y, int width = 0, int height = 0, int fontSize = 35) {
        // GDI ��Ʈ�� �ؽ�Ʈ ũ�� ����
        HWND consoleWindow = GetConsoleWindow();
        HDC hdc = GetDC(consoleWindow);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(g_hScreen[g_nScreenIndex], &csbi);

        int dpiScale = GetDPIScalingFactor();
        int adjustedFontSize = fontSize * dpiScale;

        RECT rect = ConvertArrayToPixelRect(x, y, width, height);

        int textHeight = calculateTextHeight(hdc, text, rect, DT_WORDBREAK | DT_CENTER, adjustedFontSize);

        RECT adjustedRect = adjustRectForVerticalCenter(rect, textHeight);
        adjustedRect = AdjustRect(adjustedRect, 0.05, 0);

        HFONT hFont = CreateFont(adjustedFontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "���� ���");

        HFONT oldFont = (HFONT)SelectObject(hdc, hFont);
        SetTextColor(hdc, RGB(150, 150, 150));
        SetBkMode(hdc, TRANSPARENT);
        //SetBkMode(hdc, OPAQUE);

        DrawText(hdc, text, -1, &adjustedRect, DT_LEFT | DT_WORDBREAK);

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);
        ReleaseDC(consoleWindow, hdc);
    }

    /*
    static void drawText(wstring text, int x, int y, int width = cmdWidth - 50, int height = 90, COLORREF color = RGB(150, 150, 150), int fontSize = 90, const std::wstring& fontName = L"���� ���") {
        //(type == 0 �� �� << ���� �Է�X)
        // Ȱ�� �ܼ� ������ �ڵ� ��������
        HANDLE activeBuffer = g_hScreen[g_nScreenIndex];
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(activeBuffer, &csbi);

        // Console Window �ڵ� ��������
        HWND consoleWindow = GetConsoleWindow();
        HDC hdc = GetDC(consoleWindow);

        RECT rcTextArea = { x, y, x + text.size() * fontSize, y + height};
        // �۾�ü �� ũ�� ����
        HFONT hFont = CreateFont(
            fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, fontName.c_str()
        );

        // ���� ��Ʈ ����
        HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

        SetTextColor(hdc, color);
        SetBkMode(hdc, TRANSPARENT);

        // �ؽ�Ʈ ���

        DrawText(hdc, text.c_str(), -1, &rcTextArea, DT_SINGLELINE | DT_VCENTER);

        //TextOut(hdc, x, y, text.c_str(), text.length());

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);
        ReleaseDC(consoleWindow, hdc);
    }
    */
};

#endif