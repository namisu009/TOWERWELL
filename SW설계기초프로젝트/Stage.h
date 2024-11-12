#ifndef _STAGE_H
#define _STAGE_H

#include <unordered_map>

#include "EventDispatcher.h"
#include "Puzzle.h"
#include "Map.h"
#include "Scene.h"

using namespace std;

class Stage {
private:
    int stageId; // 스테이지 ID
    string currentMapId;
    unordered_map<string, Map*> maps;// 해당 스테이지의 맵
    unordered_map<string, Scene*> scenes;// 해당 스테이지의 씬들
    bool isCleared; // 스테이지 클리어 여부 //퍼즐이 다 풀렸을 때

    EventDispatcher* eventDispatcher; // 이벤트 디스패처 참조

public:
    Stage(){}
    Stage(EventDispatcher* _eventDispatcher) {
        currentMapId = "";
        isCleared = false;
        eventDispatcher = _eventDispatcher;
        eventDispatcher->subscribe(PUZZLE_SOLVED, [this]() { onPuzzleSolved(); });
    }

    /* 사용자 기능 */
    Map* getCurrentMap() {
        return maps[currentMapId];
    }

    void onMoveMap(int x, int y) { //맵이동
        string key = maps[currentMapId]->getDoorId(x, y);
        if (key != "")
            currentMapId = key;

        eventDispatcher->dispatch(MOVE_MAP);
    }
    /* 추가 기능*/

    void addMap(Map* map) {
        map->setEventDispatcher(eventDispatcher);
        maps[map->getMapId()] = map;

        if (currentMapId == "")
            currentMapId = map->getMapId();
    }

    void addPuzzle(string MapId, Puzzle* puzzle) {

    }

    bool getIsCleared() {
        return isCleared;
    }

    void playScene() {
        
    }

    void onPuzzleSolved() {

    }
};

#endif