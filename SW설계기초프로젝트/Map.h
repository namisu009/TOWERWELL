
#ifndef _MAP_H_
#define _MAP_H_

#include<vector>
#include<unordered_map>

#include "RenderStruct.h"
#include "ArtLoadManager.h"

using namespace std;

#pragma once
class Map
{
private:
    RenderArray renderArray;
    ScreenArray screenArray;

    int width;// 맵 너비
    int height;// 맵 높이

    //사용자 초기 시작 위치
    int init_x;
    int init_y;

    int type;

    ArtLoadManager* artLoadManager;
public:
    Map() {
        artLoadManager = artLoadManager->GetInstance();
    }

    RenderArray& getRenderArray() { return renderArray; }
    ScreenArray& getScreenArray() { return screenArray;  }

    void initializeFromASCII(const char* filename)// 맵 초기화 // 파일명 넣으면 ArtLoadManager << 의 RenderArray를 불러서 맵 초기화
    {
        artLoadManager->RenderArrayLoad(&renderArray, filename);
    }

    void initializeFromScreen(const char* filename)// 스크린 초기화 (스크린 파일 따로 존재)
    {
        artLoadManager->ScreenArrayLoad(type, &screenArray, filename);
        width = screenArray.width;
        height = screenArray.height;
        init_x = screenArray.init_x;
        init_y = screenArray.init_y;
    }

    bool isExitDoor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_EXIT) return true;
        return false;
    }

    bool isBackGround(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_BACKGROUND) return true; //배경일 땐 3
        return false;
    }

    bool isWall(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_WALL) return true; //벽일 땐 2 // 벽이 아닌 모든 요소들은 사용자가 통과 가능
        return false;
    }

    bool isFloor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_FLOOR) return true; //바닥일 때 1
        return false;
    }

    int getInitX() { return init_x; }
    int getInitY() { return init_y; }

    int getWidth() { return width; }
    int getHeight() { return height; }

    int getType() {
        return type;
    }

    void setType(int _type) {
        type = _type;
    }
};

#endif
