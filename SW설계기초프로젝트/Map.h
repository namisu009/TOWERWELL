
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

    unordered_map <int, int> colorToPuzzleId;// 색상과 퍼즐 ID 매핑
    int puzzleCount;

    //초기 시작 위치
    int init_x;
    int init_y;

    ArtLoadManager* artLoadManager;
public:
    Map() {
        artLoadManager = artLoadManager->GetInstance();
        for (int i = 0; i < 5; i++)
            colorToPuzzleId[i] = 0;
        puzzleCount = 0;
    }

    RenderArray& getRenderArray() { return renderArray; }
    ScreenArray& getScreenArray() { return screenArray;  }

    void initializeFromASCII(const char* filename)// 맵 초기화 // 파일명 넣으면 ArtLoadManager << 의 RenderArray를 불러서 맵 초기화
    {
        artLoadManager->RenderArrayLoad(&renderArray, filename);
    }

    void initializeFromScreen(const char* filename)// 스크린 초기화 (스크린 파일 따로 존재)
    {
        artLoadManager->ScreenArrayLoad(&screenArray, filename);
        width = screenArray.width;
        height = screenArray.height;
        init_x = screenArray.init_x;
        init_y = screenArray.init_y;
    }

    int getPuzzleId(int x, int y) {
        if (screenArray.MapInfo[y][x] < 101 || screenArray.MapInfo[y][x] > 105) 
            return -1; // 퍼즐 X
        else 
            screenArray.MapInfo[y][x]; //퍼즐 ID 리턴
    }

    void setPuzzleId(int colorId, int PuzzleId) { //색상과 퍼즐id 매핑
        colorToPuzzleId[colorId] = PuzzleId;
        puzzleCount++;
    }

    void setPuzzleMapping() { //맵 위치와 퍼즐 ID 매핑, ScreenArray에 매핑
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int key = screenArray.MapInfo[y][x];
                if (colorToPuzzleId.find(key) != colorToPuzzleId.end()) {
                    screenArray.MapInfo[y][x] = colorToPuzzleId[key];
                }
            }
        }
    }

    bool isExitDoor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 4) return true; //나가는 문 정보 - 4
        return false;
    }

    bool isBackGround(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 3) return true; //배경일 땐 3
        return false;
    }

    bool isWall(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 2) return true; //벽일 땐 2 // 벽이 아닌 모든 요소들은 사용자가 통과 가능
        return false;
    }

    bool isFloor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 1) return true; //바닥일 때 1
        return false;
    }

    int getInitX() { return init_x; }
    int getInitY() { return init_y; }

    int getWidth() { return width; }
    int getHeight() { return height; }

    void display() const;// 맵 출력 //Render << 연동
};

#endif
