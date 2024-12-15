#ifndef _ARTLOADMANAGER_H_
#define _ARTLOADMANAGER_H_

#include<opencv2/opencv.hpp>
#include<string>
#include "RenderStruct.h"

class Map;

using namespace std;

class Puzzle;

class ArtLoadManager
{
private:
    static ArtLoadManager* instance;
    ArtLoadManager() {}
    ArtLoadManager(const ArtLoadManager& ref) {}
    ArtLoadManager& operator=(const ArtLoadManager& ref) {}
    ~ArtLoadManager() {}
public:
    static ArtLoadManager* GetInstance();
    void RenderArrayLoad(RenderArray* Array, const char* fileName);
    void ScreenArrayLoad(int type, Map* map, const char* fileName);
    void resetExpandThePuzzleInfo(Puzzle* p, ScreenArray* Array);
    void ExpandThePuzzleInfo(Puzzle* p, ScreenArray* Array);
    void ExpandThePuzzleInfo(int _y, int _x, string name, IplImage* img, ScreenArray* Array);
};

#endif
