
#ifndef _PUZZLEMAP_H_
#define _PUZZLEMAP_H_

#include "Map.h"
#include "Character.h"
#include <string>

class PuzzleMap : public Map
{
    unordered_map <int, string> PuzzleMapping;// ����� ���� ID ����
    int puzzleCount;
    int clearPuzzleCount;

public:
    PuzzleMap() {
        setType(TYPE_PUZZLE);
        for (int i = PUZZLE_OBJ_01; i <= PUZZLE_OBJ_05; i++)
            PuzzleMapping[i] = "X";
        puzzleCount = 0;
        clearPuzzleCount = 0;

    }

    string getPuzzleId(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        if (myScreen.MapInfo[y][x] < PUZZLE_OBJ_01 || myScreen.MapInfo[y][x] > PUZZLE_OBJ_05)
            return ""; // ���� X
        else
            return PuzzleMapping[myScreen.MapInfo[y][x]]; //���� ID ����
    }

    void setPuzzleId(int colorId, string PuzzleId) { //����� ����id ����
        PuzzleMapping[colorId] = PuzzleId;
        puzzleCount++;
    }

    void clearPuzzle() {
        clearPuzzleCount++;
    }

    string getDoorId(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        if (!isDoor(x, y))
            return ""; // Map Z
        else
        {
            if (isExitDoor(x, y) && clearPuzzleCount != puzzleCount)
                return "";
                
            
            return getDoorMapping()[myScreen.MapInfo[y][x]]; //Map Id return
        }
    }

    /*
    void setPuzzleMapping() { //�� ��ġ�� ���� ID ����, ScreenArray�� ����
        ScreenArray& myScreen = getScreenArray();
        for (int y = 0; y < getHeight(); y++) {
            for (int x = 0; x < getWidth(); x++) {
                int key = myScreen.MapInfo[y][x]; //101
                if (PuzzleMapping.find(key) != PuzzleMapping.end()) {
                    myScreen.MapInfo[y][x] = PuzzleMapping[key];
                }
            }
        }
    }
    */
};

#endif

