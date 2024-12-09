
#ifndef _MAP_H_
#define _MAP_H_

#include<vector>
#include<unordered_map>
#include<string>

#include "RenderStruct.h"
#include "EventDispatcher.h"
#include "ArtLoadManager.h"

using namespace std;

#pragma once
class Map
{
private:
    const char* renderFile;
    const char* screenFile;

    RenderArray renderArray;
    ScreenArray screenArray;

    string mapId;

    int width;// 맵 너비
    int height;// 맵 높이

    //사용자 초기 시작 위치
    int init_x;
    int init_y;

    int type;

    unordered_map<int, string> DoorMapping;

    ArtLoadManager* artLoadManager;
    EventDispatcher* eventDispatcher;
public:
    Map() {
        artLoadManager = artLoadManager->GetInstance();
    }

    RenderArray& getRenderArray() { return renderArray; }
    ScreenArray& getScreenArray() { return screenArray; }

    EventDispatcher* getEventDispathcer() { return eventDispatcher; }

    void initializeFromASCII()// 맵 초기화 // 파일명 넣으면 ArtLoadManager << 의 RenderArray를 불러서 맵 초기화
    {
        artLoadManager->RenderArrayLoad(&renderArray, renderFile);
    }

    void initializeFromScreen()// 스크린 초기화 (스크린 파일 따로 존재)
    {
        artLoadManager->ScreenArrayLoad(type, this, screenFile);
        width = screenArray.width;
        height = screenArray.height;
        init_x = screenArray.init_x;
        init_y = screenArray.init_y;
    }

    void initializeFromASCII(const char* filename)// 맵 초기화 // 파일명 넣으면 ArtLoadManager << 의 RenderArray를 불러서 맵 초기화
    {
        artLoadManager->RenderArrayLoad(&renderArray, filename);
    }

    void initializeFromScreen(const char* filename)// 스크린 초기화 (스크린 파일 따로 존재)
    {
        artLoadManager->ScreenArrayLoad(type, this, filename);
        width = screenArray.width;
        height = screenArray.height;
        init_x = screenArray.init_x;
        init_y = screenArray.init_y;
    }

    void setEventDispatcher(EventDispatcher* dispatcher) {
        eventDispatcher = dispatcher;
    }

    void setMapId(string id) {
        mapId = id;
    }

    bool isExitDoor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_EXIT) return true;
        return false;
    }

    bool isDoor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_DOOR_01 || screenArray.MapInfo[y + 1][x] == MAP_DOOR_02 || screenArray.MapInfo[y + 1][x] == MAP_EXIT) return true;
        return false;
    }

    bool isBackGround(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_BACKGROUND) return true;
        return false;
    }

    bool isWall(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_WALL) return true;
        return false;
    }

    bool isClimbWall(int x, int y) {
        if (screenArray.MapInfo[y + 1][x] == JUMP_WALL) return true;
        return false;
    }

    bool isFloor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_FLOOR) return true;
        return false;
    }

    void setDoorId(int colorId, string doorId) {
        DoorMapping[colorId] = doorId;
    }

    virtual string getDoorId(int x, int y) {
        if (!isDoor(x, y) && !isExitDoor(x, y))
            return ""; // Map Z
        else
            return DoorMapping[screenArray.MapInfo[y][x]]; //Map Id return
    }

    void setInitPosition(int x, int y) { init_x = x; init_y = y; }

    int getInitX() { return init_x; }
    int getInitY() { return init_y; }

    int getWidth() { return width; }
    int getHeight() { return height; }

    int getType() {
        return type;
    }

    unordered_map <int, string> getDoorMapping() {
        return DoorMapping;
    }

    string getMapId() {
        return mapId;
    }

    void setType(int _type) {
        type = _type;
    }

    void callDispatch(EventType type) {

    }

    void setFile(const char* filename1, const char* filename2) {
        renderFile = filename1;
        screenFile = filename2;
    }
};

#endif
