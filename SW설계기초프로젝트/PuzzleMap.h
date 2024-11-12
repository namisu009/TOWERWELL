
#ifndef _PUZZLEMAP_H_
#define _PUZZLEMAP_H_

#include "Map.h"
#include "Character.h"
#include <string>

class PuzzleMap : public Map
{
    unordered_map <int, string> colorToPuzzleId;// 색상과 퍼즐 ID 매핑
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
            return ""; // 퍼즐 X
        else
            return colorToPuzzleId[myScreen.MapInfo[y][x]]; //퍼즐 ID 리턴
    }

    void setPuzzleId(int colorId, string PuzzleId) { //색상과 퍼즐id 매핑
        colorToPuzzleId[colorId] = PuzzleId;
        puzzleCount++;
    }

    /*
    void setPuzzleMapping() { //맵 위치와 퍼즐 ID 매핑, ScreenArray에 매핑
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

