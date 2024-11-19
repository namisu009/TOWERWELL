#ifndef _ARTLOADMANAGER_H_
#define _ARTLOADMANAGER_H_

#include<opencv2/opencv.hpp>
#include<string>
#include "RenderStruct.h"

class Map;

using namespace std;

class ArtLoadManager
{
private:
    static ArtLoadManager* instance;
    ArtLoadManager() {}
    ArtLoadManager(const ArtLoadManager& ref) {}
    ArtLoadManager& operator=(const ArtLoadManager& ref) {}
    ~ArtLoadManager() {}
public:
    ArtLoadManager* GetInstance();
    void RenderArrayLoad(RenderArray* Array, const char* fileName);
    void ScreenArrayLoad(int type, Map* map, const char* fileName);
};

#endif
