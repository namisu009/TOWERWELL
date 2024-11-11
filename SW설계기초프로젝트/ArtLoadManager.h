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
	// static 함수로 선언
	ArtLoadManager* GetInstance() {
		// staitc 변수로 선언함으로서, instance ㅂㄴ수는 한번만 초기화되고, 프로그램 수명 내내 지속됨.
		// 특히 C++11부터 thread-safe 변수 초기화가 보장됨.
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

        Array->ASCIIArtArr = (char**)malloc(sizeof(char*) * height);
        Array->drawornotArr = (int**)malloc(sizeof(int*) * height);
        for (int y = 0; y < height; y++) {
            Array->ASCIIArtArr[y] = (char*)malloc(sizeof(char) * width);
            Array->drawornotArr[y] = (int*)malloc(sizeof(int) * width);
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
                

                if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 0) Array->drawornotArr[y][x] = 0;
                else Array->drawornotArr[y][x] = 1;
            }
        }
	}

    void DialogRenderArrayLoad(RenderArray* Array, const char* fileName) {
        IplImage* img = cvLoadImage(fileName);
        CvSize imgSize = cvGetSize(img);

        int width = imgSize.width;
        int height = imgSize.height;

        Array->width = width;
        Array->height = height;

        Array->ASCIIArtArr = (char**)malloc(sizeof(char*) * height);
        Array->drawornotArr = (int**)malloc(sizeof(int*) * height);
        for (int y = 0; y < height; y++) {
            Array->ASCIIArtArr[y] = (char*)malloc(sizeof(char) * width);
            Array->drawornotArr[y] = (int*)malloc(sizeof(int) * width);
        }

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                CvScalar f1 = cvGet2D(img, y, x);
                Array->ASCIIArtArr[y][x] = ' ';
                if (f1.val[0] <= 128 && f1.val[1] <= 128  && f1.val[2] <= 128) Array->ASCIIArtArr[y][x] = '*';
            }
        }
    }

    void ScreenArrayLoad(ScreenArray* Array, const char* fileName) {
        IplImage* img = cvLoadImage(fileName);
        CvSize imgSize = cvGetSize(img);

        int width = imgSize.width;
        int height = imgSize.height;

        Array->width = width;
        Array->height = height;

        Array->MapInfo = (int**)malloc(sizeof(int*) * height);
        for (int y = 0; y < height; y++) {
            Array->MapInfo[y] = (int*)malloc(sizeof(int) * width);
        }

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                CvScalar f1 = cvGet2D(img, y, x);

                if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 0) 
                    Array->MapInfo[y][x] = MAP_FLOOR; 
                else if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_WALL;
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 0) 
                    Array->MapInfo[y][x] = MAP_BACKGROUND;
                else if (f1.val[0] == 255 && f1.val[1] == 0 && f1.val[2] == 0) 
                    Array->MapInfo[y][x] = JUMP_TRAP;
                else if (f1.val[0] == 0 && f1.val[1] == 0 && f1.val[2] == 255) {
                    Array->MapInfo[y][x] = MAP_START;
                    Array->init_x = x;
                    Array->init_y = y;
                }
                else if (f1.val[0] == 255 && f1.val[1] == 255 && f1.val[2] == 0)
                    Array->MapInfo[y][x] = JUMP_DOUBLEJUMP;
                else if (f1.val[0] == 0 && f1.val[1] == 255 && f1.val[2] == 255)
                    Array->MapInfo[y][x] = MAP_DOOR;
                else 
                    Array->MapInfo[y][x] = 0;
                
            }
        }
    }

};

#endif
