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

void ArtLoadManager::resetExpandThePuzzleInfo(Puzzle* p, ScreenArray* Array) {
    if (p == nullptr) return;

    int init_x = p->getX();
    int init_y = p->getY();
    int width = p->getObjectArray()->width / 2;
    int height = p->getObjectArray()->height;

    for (int y = init_y - height; y < init_y; y++) {
        for (int x = init_x - width; x < init_x + width; x++) {
            if (y < 0 || y > cmdHeight - 1 || x < 0 || x > cmdWidth - 1 || (y == init_y && x == init_x))
                continue;

            Array->ObjectInfo[y][x] = 0;
        }
    }
}

void ArtLoadManager::ExpandThePuzzleInfo(Puzzle* p, ScreenArray* Array){
    if (p == nullptr) return;

    int init_x = p->getX();
    int init_y = p->getY();
    int width = p->getObjectArray()->width / 2;
    int height = p->getObjectArray()->height;


    int ** dar = p->getObjectArray()->drawornotArr;
    for (int y = init_y - height; y < init_y; y++) {
        for (int x = init_x - width; x < init_x + width; x++) {
            if (y < 0 || y > cmdHeight - 1 || x < 0 || x > cmdWidth - 1)
                continue;

            int y1 = y - (init_y - height); // y가 dar의 0부터 시작하는 인덱스에 매핑
            int x1 = x - (init_x - width); // x가 dar의 0부터 시작하는 인덱스에 매핑

            if(dar[y1][x1] == 1)
                Array->ObjectInfo[y][x] = Array->ObjectInfo[init_y][init_x];
        }
    }
}

void ArtLoadManager::ExpandThePuzzleInfo(int _y, int _x, string name, IplImage* img, ScreenArray* Array) {
    CvScalar f1 = cvGet2D(img, _y, _x);
    CvScalar f2 = cvGet2D(img, _y, _x - 1);
    CvScalar f3 = cvGet2D(img, _y, _x + 1);
    CvScalar f4 = cvGet2D(img, _y - 1, _x);
    if (f1.val[0] == f2.val[0] && f1.val[1] == f2.val[1] && f1.val[2] == f2.val[2] ||
        f1.val[0] == f3.val[0] && f1.val[1] == f3.val[1] && f1.val[2] == f3.val[2] ||
        f1.val[0] == f4.val[0] && f1.val[1] == f4.val[1] && f1.val[2] == f4.val[2] ) //양옆에 하나라도 칠해져 있을 경우
        return;

    Puzzle* p = PuzzleManager::getPuzzle(name);

    if (p->getObjectArray() == nullptr) return;
    int width = p->getObjectArray()->width / 2;
    int height = p->getObjectArray()->height;

    p->SetStartPosition(_x, _y);

    int** dar = p->getObjectArray()->drawornotArr;
    for (int y = _y - height; y < _y; y++) {
        for (int x = _x - width; x < _x + width; x++) {
            if (y < 0 || y > cmdHeight - 1 || x < 0 || x > cmdWidth - 1)
                continue;

            int y1 = y - (_y - height); // y가 dar의 0부터 시작하는 인덱스에 매핑
            int x1 = x - (_x - width); // x가 dar의 0부터 시작하는 인덱스에 매핑

            if(dar[y1][x1] == 1)
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
        Array->ASCIIArtArr[y] = new char[width + 1];
        Array->drawornotArr[y] = new int[width];
        memset(Array->ASCIIArtArr[y], '\0', (width + 1) * sizeof(char));
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
                Array->MapInfo[y][x] = MAP_FIRST_OBJECT;
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
                else if (f1.val[2] == 100 && f1.val[1] == 0 && f1.val[0] == 100)
                    Array->MapInfo[y][x] = JUMP_WALL;
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
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 200){
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_04; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 5) {
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_05; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 10) {
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_06; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 15) {
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_07; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 20) {
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_08; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 25) {
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_09; flag = 1;
                }
                else if (f1.val[2] == 0 && f1.val[1] == 0 && f1.val[0] == 30) {
                    Array->ObjectInfo[y][x] = PUZZLE_OBJ_10; flag = 1;
                }

                if(flag){
                    string id = ((PuzzleMap*)map)->getPuzzleId(Array->ObjectInfo[y][x]);
                    ExpandThePuzzleInfo(y, x, id, img, Array);
                }
            }
        }
    }

}