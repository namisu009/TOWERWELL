
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

    unordered_map <int, int> colorToPuzzleId;// ����� ���� ID ����
    int puzzleCount;

    //�ʱ� ���� ��ġ
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

    void initializeFromASCII(const char* filename)// �� �ʱ�ȭ // ���ϸ� ������ ArtLoadManager << �� RenderArray�� �ҷ��� �� �ʱ�ȭ
    {
        artLoadManager->RenderArrayLoad(&renderArray, filename);
    }

    void initializeFromScreen(const char* filename)// ��ũ�� �ʱ�ȭ (��ũ�� ���� ���� ����)
    {
        artLoadManager->ScreenArrayLoad(&screenArray, filename);
        width = screenArray.width;
        height = screenArray.height;
        init_x = screenArray.init_x;
        init_y = screenArray.init_y;
    }

    int getPuzzleId(int x, int y) {
        if (screenArray.MapInfo[y][x] < 101 || screenArray.MapInfo[y][x] > 105) 
            return -1; // ���� X
        else 
            screenArray.MapInfo[y][x]; //���� ID ����
    }

    void setPuzzleId(int colorId, int PuzzleId) { //����� ����id ����
        colorToPuzzleId[colorId] = PuzzleId;
        puzzleCount++;
    }

    void setPuzzleMapping() { //�� ��ġ�� ���� ID ����, ScreenArray�� ����
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
        if (screenArray.MapInfo[y + 1][x] == 4) return true; //������ �� ���� - 4
        return false;
    }

    bool isBackGround(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 3) return true; //����� �� 3
        return false;
    }

    bool isWall(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 2) return true; //���� �� 2 // ���� �ƴ� ��� ��ҵ��� ����ڰ� ��� ����
        return false;
    }

    bool isFloor(int x, int y) const {
        if (screenArray.MapInfo[y + 1][x] == 1) return true; //�ٴ��� �� 1
        return false;
    }

    int getInitX() { return init_x; }
    int getInitY() { return init_y; }

    int getWidth() { return width; }
    int getHeight() { return height; }

    void display() const;// �� ��� //Render << ����
};

#endif
