#ifndef _SCREENINFO_H
#define _SCREENINFO_H

#include <windows.h>

const int cmdWidth = 480;
const int cmdHeight = 169;

const HANDLE hOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
const HWND hwnd = GetConsoleWindow();
const HDC hdc = GetDC(hwnd);

#endif
