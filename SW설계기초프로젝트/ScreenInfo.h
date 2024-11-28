#ifndef _SCREENINFO_H
#define _SCREENINFO_H

#include <windows.h>

const int cmdWidth = 480;
const int cmdHeight = 169;

const HANDLE hOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
const HWND hwnd = GetConsoleWindow();
const HDC hdc = GetDC(hwnd);

const int CELL_WIDTH = 3;   // 문자 셀의 가로 크기
const int CELL_HEIGHT = 5;  // 문자 셀의 세로 크기


#endif
