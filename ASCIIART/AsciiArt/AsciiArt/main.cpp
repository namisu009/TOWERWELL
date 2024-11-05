#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<String.h>

int cmdWidth = 480;
int cmdHeight = 169;

int width;
int height;

int init_x;
int init_y;

int cnt = 0;

char** arr;

bool flag = true;

HANDLE hOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
    COORD size = { 200, 200 };
    SetConsoleScreenBufferSize(hOutHandle, size);

    CONSOLE_CURSOR_INFO curCursorInfo;
    GetConsoleCursorInfo(hOutHandle, &curCursorInfo);
    curCursorInfo.bVisible = 0;
    SetConsoleCursorInfo(hOutHandle, &curCursorInfo);

    SetConsoleDisplayMode(hOutHandle, CONSOLE_WINDOWED_MODE, 0);

    system("mode con: cols=480 lines=169");

    IplImage* img;

    char str[100];
    while (1) {

        printf("이미지 경로 입력: ");
        scanf("%s", &str);
        img = cvLoadImage((const char*)str);
        if (img != NULL)
            break;

    }

    cvShowImage("img", img);
    cvWaitKey();

    CvSize imgSize = cvGetSize(img);
    width = imgSize.width;
    height = imgSize.height;

    COORD pos = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(hOutHandle, ' ', cmdWidth * cmdHeight, pos, &dw);
    arr = (char**)malloc(sizeof(char*) * height);
    for (int y = 0; y < height; y++) {
        arr[y] = (char*)malloc(sizeof(char) * width);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            CvScalar f = cvGet2D(img, y, x);
            if (f.val[0] == 0)        arr[y][x] = '@';
            else if (f.val[0] == 50)  arr[y][x] = 'w';
            else if (f.val[0] == 100) arr[y][x] = '=';
            else if (f.val[0] == 111) arr[y][x] = '|';
            else if (f.val[0] == 150) arr[y][x] = '-';
            else if (f.val[0] == 200) arr[y][x] = '~';
            else if (f.val[0] == 250) arr[y][x] = '.';
            else arr[y][x] = ' ';
        }
    }


    init_x = cmdWidth / 2 - width / 2;
    init_y = cmdHeight - height;

    pos.X = init_x;
    pos.Y = init_y;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pos.X++;
            SetConsoleCursorPosition(hOutHandle, pos);
            printf("%c", arr[y][x]);
        }
        pos.X = init_x;
        pos.Y++;
    }

    while (1) {
        if (_kbhit()) {        //키보드 입력 확인 (true / false)
            Sleep(10);
            char c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
            if (c == 'q'){
                exit(1);
            }
        }
    }
}
