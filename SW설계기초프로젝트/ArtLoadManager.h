#ifndef _ARTLOADMANAGER_H_
#define _ARTLOADMANAGER_H_

#include<opencv2/opencv.hpp>
#include "RenderStruct.h"

class ArtLoadManager
{
private:
    static ArtLoadManager* instance;
    ArtLoadManager() {}
    ArtLoadManager(const ArtLoadManager& ref) {}
    ArtLoadManager& operator=(const ArtLoadManager& ref) {}
    ~ArtLoadManager() {}
public:
	// static �Լ��� ����
	ArtLoadManager* GetInstance() {
		// staitc ������ ���������μ�, instance �������� �ѹ��� �ʱ�ȭ�ǰ�, ���α׷� ���� ���� ���ӵ�.
		// Ư�� C++11���� thread-safe ���� �ʱ�ȭ�� �����.
        if (instance == NULL)
            instance = new ArtLoadManager();

		return instance;
	}

	void RenderArrayLoad(RenderArray* Array, const char * fileName) {
		IplImage* img = cvLoadImage(fileName);
        CvSize imgSize = cvGetSize(img);

        int width = imgSize.width;
        int height = imgSize.height;

        Array->width = width;
        Array->height = height;

        Array->ASCIIArtArr =  new char*[height];
        Array->drawornotArr =  new int* [height];
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

                if (f1.val[0] == 0 && f1.val[1] == 0) Array->ASCIIArtArr[y][x] = '*';
                else if (f1.val[0] == 50)  Array->ASCIIArtArr[y][x] = 'w';
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


    void ScreenArrayLoad(int type, ScreenArray* Array, const char* fileName) {
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
                /*
                if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 0)
                    Array->MapInfo[y][x] = MAP_FLOOR;
                else if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_WALL;
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 0)
                    Array->MapInfo[y][x] = MAP_BACKGROUND;
                else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 255) {
                    Array->MapInfo[y][x] = MAP_START;
                    Array->init_x = x;
                    Array->init_y = y;
                }
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_EXIT;
                if (type == TYPE_JUMP)
                {
                    if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 0)
                        Array->MapInfo[y][x] = JUMP_TRAP;
                }
                
                if (type == TYPE_PUZZLE) {

                    if (f1.val[0] == 0 && f1.val[1] == 100 && f1.val[2] == 100)
                        Array->MapInfo[y][x] = MAP_DOOR_01;
                    else if (f1.val[0] == 0 && f1.val[1] == 200 && f1.val[2] == 200)
                        Array->MapInfo[y][x] = MAP_DOOR_02;

                    else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 50)
                        Array->MapInfo[y][x] = PUZZLE_OBJ_01;
                    else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 100)
                        Array->MapInfo[y][x] = PUZZLE_OBJ_02;
                    else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 150)
                        Array->MapInfo[y][x] = PUZZLE_OBJ_03;
                    else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 200)
                        Array->MapInfo[y][x] = PUZZLE_OBJ_04;

                }
                */
                //Array->ObjectInfo[y][x] = 0;

                
                if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 0) 
                    Array->MapInfo[y][x] = MAP_FLOOR; 
                else if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_WALL;
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 0) 
                    Array->MapInfo[y][x] = MAP_BACKGROUND;
                else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 255) {
                    Array->MapInfo[y][x] = MAP_START;
                    Array->init_x = x;
                    Array->init_y = y;
                }else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_EXIT;
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_DOOR_01;
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_DOOR_02;
                else 
                    Array->MapInfo[y][x] = 0;
                
                if (type == TYPE_JUMP)
                {
                    if (f1.val[0] == 255 && f1.val[1] == 255 && f1.val[2] == 0) {
                        Array->MapInfo[y][x] = JUMP_DOUBLEJUMP;
                    }
                    else if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 0)
                        Array->MapInfo[y][x] = JUMP_TRAP;
                }
                else if (type == TYPE_PUZZLE) {
                    if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 0)
                        Array->MapInfo[y][x] = PUZZLE_OBJ_01;
                    else if (f1.val[0] == 255 && f1.val[1] == 255 && f1.val[2] == 0)
                        Array->MapInfo[y][x] = PUZZLE_OBJ_02;
                }
                
            }
        }
    }

};

#endif
