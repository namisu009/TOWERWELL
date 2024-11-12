#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include <unordered_map>
#include "Stage.h"
#include "Map.h"

using namespace std;

class StageManager {
private:
    static int currentStageId;// ���� �������� ID
    static unordered_map<int, Stage> stages;// �������� ����

public:
    static void setCurrentStage(int id) {
        currentStageId = id;
    }
    static void addStage(int id, EventDispatcher* eventDispatcher) {
        Stage stage(eventDispatcher);
        stages[id] = stage;
    }

    static void addMap(int id, Map* map) {
        stages[id].addMap(map);
    }

    static Stage* getCurrentStage() {
        return &stages[currentStageId];
    }
    static Stage* getStage(int stageId) {
        return &stages[stageId];
    }
};

#endif