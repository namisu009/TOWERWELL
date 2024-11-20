#ifndef _DIALOGMANAGER_H
#define _DIALOGMANAGER_H

#include <Windows.h>
#include <string>
#include "ScreenInfo.h" // cmdWidth, cmdHeight ���Ե� ���

using namespace std;

class DialogManager
{
public:
    static void DrawWithDoubleBuffer() {
        // ���� ���۸��� ���� �޸� DC ����
        COORD bufferSize = bufferSize = { cmdWidth, cmdHeight };
        SMALL_RECT windowSize = { 0, 0, cmdWidth - 1, cmdHeight - 1 };
        int fontSize = 50;
        wstring fontName = L"Consolas";
        
        HDC memDC = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, bufferSize.X, bufferSize.Y);
        SelectObject(memDC, hBitmap);

        // ��� ���� ó��
        SetBkMode(memDC, TRANSPARENT);

        // ���⿡ ���� �׸��� �۾� ����
        TextOut(memDC, 50, 50, L"Hello, World!", 13);

        // ȭ�鿡 �׸���
        BitBlt(hdc, 0, 0, bufferSize.X, bufferSize.Y, memDC, 0, 0, SRCCOPY);

        // �ڿ� ����
        DeleteObject(hBitmap);
        DeleteDC(memDC);
    }

    /*
    static void drawText(const std::wstring& text, int x, int y, COLORREF color) {

        HFONT hFont;
        HFONT oldFont;


        hFont = CreateFont(
            fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
            DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, fontName.c_str()
        );

        oldFont = (HFONT)SelectObject(hdc, hFont);

        // �۾� ���� ����
        SetTextColor(hdc, color);

        // ��� ���� ó��
        SetBkMode(hdc, TRANSPARENT);

        // �ؽ�Ʈ ���
        TextOut(hdc, x, y, text.c_str(), text.length());

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);

    }
    */
};

#endif
