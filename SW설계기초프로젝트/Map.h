
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

    int width;// �� �ʺ�
    int height;// �� ����

    //����� �ʱ� ���� ��ġ
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

    void initializeFromASCII(const char* filename)// �� �ʱ�ȭ // ���ϸ� ������ ArtLoadManager << �� RenderArray�� �ҷ��� �� �ʱ�ȭ
    {
        artLoadManager->RenderArrayLoad(&renderArray, filename);
    }

    void initializeFromScreen(const char* filename)// ��ũ�� �ʱ�ȭ (��ũ�� ���� ���� ����)
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
        if (screenArray.MapInfo[y + 1][x] == MAP_BACKGROUND) return true; //����� �� 3
        return false;
    }

    bool isWall(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_WALL) return true; //���� �� 2 // ���� �ƴ� ��� ��ҵ��� ����ڰ� ��� ����
        return false;
    }

    bool isFloor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == MAP_FLOOR) return true; //�ٴ��� �� 1
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
