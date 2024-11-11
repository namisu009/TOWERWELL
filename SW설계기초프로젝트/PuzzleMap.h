
#ifndef _PUZZLEMAP_H_
#define _PUZZLEMAP_H_
#include "Map.h"

class PuzzleMap : public Map
{
    unordered_map <int, int> colorToPuzzleId;// ����� ���� ID ����
    int puzzleCount;

public:
    PuzzleMap() {
        for (int i = PUZZLE_OBJ_01; i <= PUZZLE_OBJ_05; i++)
            colorToPuzzleId[i] = 0;
        puzzleCount = 0;
    }

    int getPuzzleId(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        if (myScreen.MapInfo[y][x] < PUZZLE_OBJ_01 || myScreen.MapInfo[y][x] > PUZZLE_OBJ_05)
            return -1; // ���� X
        else
            myScreen.MapInfo[y][x]; //���� ID ����
    }

    void setPuzzleId(int colorId, int PuzzleId) { //����� ����id ����
        colorToPuzzleId[colorId] = PuzzleId;
        puzzleCount++;
    }

    void setPuzzleMapping() { //�� ��ġ�� ���� ID ����, ScreenArray�� ����
        ScreenArray myScreen = getScreenArray();
        for (int y = 0; y < getHeight(); y++) {
            for (int x = 0; x < getWidth(); x++) {
                int key = myScreen.MapInfo[y][x];
                if (colorToPuzzleId.find(key) != colorToPuzzleId.end()) {
                    myScreen.MapInfo[y][x] = colorToPuzzleId[key];
                }
            }
        }
    }

};

#endif

