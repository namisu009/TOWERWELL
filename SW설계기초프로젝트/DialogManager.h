#ifndef _DIALOGMANAGER_H
#define _DIALOGMANAGER_H

#include <Windows.h>
#include <string>
#include "ScreenInfo.h" // cmdWidth, cmdHeight 포함된 헤더

using namespace std;

class DialogManager
{
public:
    static void DrawWithDoubleBuffer() {
        // 더블 버퍼링을 위한 메모리 DC 생성
        COORD bufferSize = bufferSize = { cmdWidth, cmdHeight };
        SMALL_RECT windowSize = { 0, 0, cmdWidth - 1, cmdHeight - 1 };
        int fontSize = 50;
        wstring fontName = L"Consolas";
        
        HDC memDC = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, bufferSize.X, bufferSize.Y);
        SelectObject(memDC, hBitmap);

        // 배경 투명 처리
        SetBkMode(memDC, TRANSPARENT);

        // 여기에 실제 그리기 작업 수행
        TextOut(memDC, 50, 50, L"Hello, World!", 13);

        // 화면에 그리기
        BitBlt(hdc, 0, 0, bufferSize.X, bufferSize.Y, memDC, 0, 0, SRCCOPY);

        // 자원 해제
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

        // 글씨 색상 설정
        SetTextColor(hdc, color);

        // 배경 투명 처리
        SetBkMode(hdc, TRANSPARENT);

        // 텍스트 출력
        TextOut(hdc, x, y, text.c_str(), text.length());

        SelectObject(hdc, oldFont);
        DeleteObject(hFont);

    }
    */
};

#endif
