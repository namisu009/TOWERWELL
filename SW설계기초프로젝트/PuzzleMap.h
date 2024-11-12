
#ifndef _PUZZLEMAP_H_
#define _PUZZLEMAP_H_

#include "Map.h"
#include "Character.h"
#include <string>

class PuzzleMap : public Map
{
    unordered_map <int, string> colorToPuzzleId;// ����� ���� ID ����
    int puzzleCount;

public:
    PuzzleMap() {
        setType(TYPE_PUZZLE);
        for (int i = PUZZLE_OBJ_01; i <= PUZZLE_OBJ_05; i++)
            colorToPuzzleId[i] = "X";
        puzzleCount = 0;
    }

    string getPuzzleId(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        if (myScreen.MapInfo[y][x] < PUZZLE_OBJ_01 || myScreen.MapInfo[y][x] > PUZZLE_OBJ_05)
            return ""; // ���� X
        else
            return colorToPuzzleId[myScreen.MapInfo[y][x]]; //���� ID ����
    }

    void setPuzzleId(int colorId, string PuzzleId) { //����� ����id ����
        colorToPuzzleId[colorId] = PuzzleId;
        puzzleCount++;
    }

    /*
    void setPuzzleMapping() { //�� ��ġ�� ���� ID ����, ScreenArray�� ����
        ScreenArray& myScreen = getScreenArray();
        for (int y = 0; y < getHeight(); y++) {
            for (int x = 0; x < getWidth(); x++) {
                int key = myScreen.MapInfo[y][x]; //101
                if (colorToPuzzleId.find(key) != colorToPuzzleId.end()) {
                    myScreen.MapInfo[y][x] = colorToPuzzleId[key];
                }
            }
        }
    }
    */
};

#endif

