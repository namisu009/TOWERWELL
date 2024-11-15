#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include <unordered_map>
#include "Stage.h"
#include "Map.h"

using namespace std;

class StageManager {
private:
    static int currentStageId;// 현재 스테이지 ID
    static unordered_map<int, Stage*> stages;

public:
    static void setCurrentStage(int id) {
        currentStageId = id;
    }
    static void addStage(int id, EventDispatcher* eventDispatcher) {
        stages[id] = new Stage(eventDispatcher); // Stage 객체를 동적으로 생성
    }

    static void addMap(int id, Map* map) {
        stages[id]->addMap(map);
    }


    static void setPuzzleId(int id, string key, PuzzleMapInfo colorId, string puzzleId) {
        Map* map = stages[id]->getMap(key);
        if (map->getType() == TYPE_PUZZLE) {
            ((PuzzleMap*)map)->setPuzzleId(colorId, puzzleId);
        }

        PuzzleManager::setEventDispatcher(puzzleId, stages[id]->getStageEventDispatcher());
    }

    static void setDoorID(int id, string key, int colorId, string doorId) {
        stages[id]->getMap(key)->setDoorId(colorId, doorId);
    }

    static Stage* getCurrentStage() {
        return stages[currentStageId];
    }
    static Stage* getStage(int stageId) {
        return stages[stageId];
    }
};

#endif