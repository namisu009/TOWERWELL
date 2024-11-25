
#ifndef _PUZZLEMAP_H_
#define _PUZZLEMAP_H_

#include "Map.h"
#include "Character.h"
#include "PuzzleManager.h"
#include "RenderManager.h"
#include "Scene.h"
#include <string>

class PuzzleMap : public Map
{
    unordered_map <int, string> PuzzleMapping;// 색상과 퍼즐 ID 매핑
    int puzzleCount;
    int solvedPuzzleCount;

public:
    PuzzleMap() : Map() {
        setType(TYPE_PUZZLE);
        for (int i = PUZZLE_OBJ_01; i <= PUZZLE_OBJ_05; i++)
            PuzzleMapping[i] = "X";

        puzzleCount = 0;
        solvedPuzzleCount = 0;
        callDispatch(PUZZLE_SOLVED);
    }

    string getPuzzleId(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        int key = myScreen.ObjectInfo[y][x];
        if (key < PUZZLE_OBJ_01 || key > PUZZLE_OBJ_05) {
            return ""; // 퍼즐 없음
        }

        // PuzzleMapping에 key가 있는지 확인
        auto it = PuzzleMapping.find(key);
        if (it != PuzzleMapping.end()) {
            return it->second; // 퍼즐 ID 반환
        }
        else {
            return "";
        }
    }

    string getPuzzleId(int type) {
        // PuzzleMapping에 key가 있는지 확인
        auto it = PuzzleMapping.find(type);
        if (it != PuzzleMapping.end()) {
            return it->second; // 퍼즐 ID 반환
        }
        else {
            return "";
        }
    }

    void addRenderPuzzle() {
        RenderManager::puzzleClear();
        for (auto& i : PuzzleMapping)
        {
            if (i.second != "X")
                RenderManager::addPuzzle(PuzzleManager::getPuzzle(i.second));
        }
    }

    void setPuzzleId(PuzzleMapInfo colorId, string PuzzleId) { //색상과 퍼즐id 매핑
        PuzzleMapping[(int)colorId] = PuzzleId;
        puzzleCount++;

        RenderManager::addPuzzle(PuzzleManager::getPuzzle(PuzzleId));
    }

    void solvePuzzle() {
        solvedPuzzleCount++;
    }

    bool isAllPuzzlesSolved() {
        return puzzleCount == solvedPuzzleCount;
    }

    string getDoorId(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        if (!isDoor(x, y))
            return ""; // Map Z
        else
        {
            if (isExitDoor(x, y) && !isAllPuzzlesSolved())
            {
                Scene newScene;
                newScene.setDialog("PZ_NCL_DL");
                newScene.display();
                return "";
            }
            
            return getDoorMapping()[myScreen.MapInfo[y][x]]; //Map Id return
        }
    }

    /*
    void setPuzzleMapping() { //맵 위치와 퍼즐 ID 매핑, ScreenArray에 매핑
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

