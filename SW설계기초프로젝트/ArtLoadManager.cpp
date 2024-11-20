#include "ArtLoadManager.h"
#include "Puzzle.h"
#include "PuzzleMap.h"
#include "Map.h"

using namespace std;

ArtLoadManager* ArtLoadManager::instance;

// static 함수로 선언
ArtLoadManager* ArtLoadManager::GetInstance() {
    // staitc 변수로 선언함으로서, instance ㅂㄴ수는 한번만 초기화되고, 프로그램 수명 내내 지속됨.
    // 특히 C++11부터 thread-safe 변수 초기화가 보장됨.
    if (instance == NULL)
        instance = new ArtLoadManager();

    return instance;
}
/*
void ExpandThePuzzleInfo(int _y, int _x, string name, ScreenArray* Array) {
    if (Array->ObjectInfo[_y][_x + 1] != 0 || Array->ObjectInfo[_y][_x - 1] != 0 || Array->ObjectInfo[_y - 1][_x] != 0) //양옆에 하나라도 칠해져 있을 경우
        return;

    Puzzle* p = PuzzleManager::getPuzzle(name);
    int width = p->getWidth() / 2;
    int height = p->getHeight() / 2;

    for (int y = _y - height; y < _y + height; y++) {
        for (int x = _x - width; x < _x + width; x++) {
            if (y < 0 || y > cmdHeight - 1 || x < 0 || x > cmdWidth - 1)
                continue;
            Array->ObjectInfo[y][x] = Array->ObjectInfo[_y][_x];
        }
    }
}
*/

void ExpandThePuzzleInfo(int _y, int _x, string name, IplImage* img, ScreenArray* Array) {
    CvScalar f1 = cvGet2D(img, _y, _x);
    CvScalar f2 = cvGet2D(img, _y, _x - 1);
    CvScalar f3 = cvGet2D(img, _y, _x + 1);
    CvScalar f4 = cvGet2D(img, _y - 1, _x);
    if (f1.val[0] == f2.val[0] && f1.val[1] == f2.val[1] && f1.val[2] == f2.val[2] ||
        f1.val[0] == f3.val[0] && f1.val[1] == f3.val[1] && f1.val[2] == f3.val[2] ||
        f1.val[0] == f4.val[0] && f1.val[1] == f4.val[1] && f1.val[2] == f4.val[2] ) //양옆에 하나라도 칠해져 있을 경우
        return;

    Puzzle* p = PuzzleManager::getPuzzle(name);

    if (p == nullptr) return;
    int width = p->getWidth() / 2;
    int height = p->getHeight();

    p->SetStartPosition(_x, _y);

    for (int y = _y - height; y < _y; y++) {
        for (int x = _x - width; x < _x + width; x++) {
            if (y < 0 || y > cmdHeight - 1 || x < 0 || x > cmdWidth - 1)
                continue;

            Array->ObjectInfo[y][x] = Array->ObjectInfo[_y][_x];
        }
    }

}

void ArtLoadManager::RenderArrayLoad(RenderArray* Array, const char* fileName) {
    IplImage* img = cvLoadImage(fileName);
    CvSize imgSize = cvGetSize(img);

    int width = imgSize.width;
    int height = imgSize.height;

    Array->width = width;
    Array->height = height;

    Array->ASCIIArtArr = new char* [height];
    Array->drawornotArr = new int* [height];
    for (int y = 0; y < height; y++) {
        Array->ASCIIArtArr[y] = new char[width];
        Array->drawornotArr[y] = new int[width];
        memset(Array->ASCIIArtArr[y], '\0', width * sizeof(char));
        memset(Array->drawornotArr[y], 0, width * sizeof(int));
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            CvScalar f1 = cvGet2D(img, y, x);
            Array->ASCIIArtArr[y][x] = ' ';

            if (f1.val[0] == 0) Array->ASCIIArtArr[y][x] = '@';
            else if (f1.val[0] == 50)  Array->ASCIIArtArr[y][x] = '#';//w
            else if (f1.val[0] == 100) Array->ASCIIArtArr[y][x] = '=';
            else if (f1.val[0] == 111) Array->ASCIIArtArr[y][x] = '|';
            else if (f1.val[0] == 150) Array->ASCIIArtArr[y][x] = '-';
            else if (f1.val[0] == 200) Array->ASCIIArtArr[y][x] = '~';
            else if (f1.val[0] == 250) Array->ASCIIArtArr[y][x] = '.';


            if (f1.val[0] == 0 && f1.val[1] >= 250 && f1.val[2] == 0) Array->drawornotArr[y][x] = 0;
            else Array->drawornotArr[y][x] = 1;
        }
    }
}

void ArtLoadManager::ScreenArrayLoad(int type, Map* map, const char* fileName) {
    ScreenArray* Array = &(map->getScreenArray());
    IplImage* img = cvLoadImage(fileName);
    CvSize imgSize = cvGetSize(img);

    int width = imgSize.width;
    int height = imgSize.height;

    Array->width = width;
    Array->height = height;

    Array->MapInfo = new int* [height];
    Array->ObjectInfo = new int* [height];
    for (int y = 0; y < height; y++) {
        Array->MapInfo[y] = new int[width];
        Array->ObjectInfo[y] = new int[width];
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            CvScalar f1 = cvGet2D(img, y, x);

            Array->MapInfo[y][x] = 0;
            Array->ObjectInfo[y][x] = 0;

            if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 0)
                Array->MapInfo[y][x] = MAP_FLOOR;
            else if (f1.val[2] >= 250 && f1.val[1] == 0 && f1.val[0] >= 250)
                Array->MapInfo[y][x] = MAP_WALL;
            else if (f1.val[2] == 0 && f1.val[1] == 255 && f1.val[0] == 0)
                Array->MapInfo[y][x] = MAP_BACKGROUND;
            else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 255) {
                Array->MapInfo[y][x] = MAP_START;
                Array->init_x = x;
                Array->init_y = y;
            }
            else if (f1.val[2] == 0 && f1.val[1] == 255 && f1.val[0] == 255)
                Array->MapInfo[y][x] = MAP_EXIT;
            if (type == TYPE_JUMP)
            {
                if (f1.val[2] == 255 && f1.val[1] == 0 && f1.val[0] == 0)
                    Array->MapInfo[y][x] = JUMP_TRAP;
            }

            if (type == TYPE_PUZZLE) {
                int flag = 0;
                if (f1.val[2] == 0 && f1.val[1] == 100 && f1.val[0] == 100)
                    Array->MapInfo[y][x] = MAP_DOOR_01;
                else if (f1.val[2] == 0 && f1.val[1] == 200 && f1.val[0] == 200)
                    Array->MapInfo[y][x] = MAP_DOOR_02;

                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 50){
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_01; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 100){
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_02; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 150){
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_03; flag = 1;
                }
                else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[0] == 200){
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_04; flag = 1;
                }

                if(flag){
                    string id = ((PuzzleMap*)map)->getPuzzleId(Array->ObjectInfo[y][x]);
                    ExpandThePuzzleInfo(y, x, id, img, Array);
                }
            }
        }
    }

}