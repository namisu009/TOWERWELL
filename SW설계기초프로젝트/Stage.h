#ifndef _STAGE_H
#define _STAGE_H

#include <unordered_map>

#include "EventDispatcher.h"
#include "Puzzle.h"
#include "Map.h"
#include "PuzzleMap.h"
#include "MapManager.h"
#include "Scene.h"
#include "SceneMananger.h"

using namespace std;

class Stage {
private:
    int stageId; // 스테이지 ID
    string currentMapId;
    unordered_map<string, Map*> maps;// 해당 스테이지의 맵
    unordered_map<string, Scene*> scenes;// 해당 스테이지의 씬들
    bool isCleared; // 스테이지 클리어 여부 //퍼즐이 다 풀렸을 때
    EventDispatcher* eventDispatcher; // 이벤트 디스패처 참조
    EventDispatcher* StageEventDispatcher; // 이벤트 디스패처 참조

public:
    Stage() {}
    Stage(int id, EventDispatcher* _eventDispatcher) : Stage() {
        currentMapId = "";
        isCleared = false;
        stageId = id;
        eventDispatcher = _eventDispatcher;
        StageEventDispatcher = new EventDispatcher();
        StageEventDispatcher->subscribe(PUZZLE_SOLVED, [this]() { this->onPuzzleSolved(); });
    }

    /* 사용자 기능 */
    Map* getCurrentMap() {
        return maps[currentMapId];
    }

    Map* getMap(string id) {
        return maps[id];
    }

    EventDispatcher* getStageEventDispatcher() {
        return StageEventDispatcher;
    }

    void onMoveMap(int x, int y) { //맵이동
        string key = maps[currentMapId]->getDoorId(x, y);
        if (key != "")
            currentMapId = key;

        eventDispatcher->dispatch(MOVE_MAP);
    }
    /* 추가 기능*/

    string getDoorId(int x, int y) {
        Map* map = getCurrentMap();

        if (map->getType() == TYPE_PUZZLE) {
            return ((PuzzleMap*)map)->getDoorId(x, y);
        }

        return map->getDoorId(x, y);
    }

    string getPuzzleId(int x, int y) {
        Map* map = getCurrentMap();

        if (map->getType() == TYPE_PUZZLE) {
            return ((PuzzleMap*)map)->getPuzzleId(x, y);
        }

        return "";
    }

    void addMap(Map* map) {
        map->setEventDispatcher(StageEventDispatcher);
        maps[map->getMapId()] = map;

        if (currentMapId == "")
            currentMapId = map->getMapId();
    }

    void addPuzzle(string MapId, Puzzle* puzzle) {

    }

    bool getIsCleared() {
        PuzzleMap* pz = MapManager::getPuzzleMap(currentMapId);

        int cnt1 = 0, cnt2 = 0;
        for (auto& m : maps) {
            if (m.second->getType() == TYPE_PUZZLE) {
                cnt1++;
                if (((PuzzleMap*)m.second)->isAllPuzzlesSolved()) {
                    cnt2++;
                }
            }
        }

        if (cnt1 == cnt2) {
            isCleared = true;
        }

        return isCleared;
    }

    bool hasSceneForMap(const string& mapId) {
        return scenes.count(mapId) > 0 && scenes[mapId]->getCmdSize() > 0;
    }

    void setScene(string id, Scene* scene) {
        scenes[id] = scene;
    }

    void playScene() {
        if (!hasSceneForMap(currentMapId)) {
            return;  // 현재 맵에 연결된 씬이 없으면 즉시 반환
        }

        Scene* scene = scenes[currentMapId];
        if (scene) {
            scene->display();

            RenderManager::setRenderMap(maps[currentMapId]);
        }

    }

    void onPuzzleSolved() {
        if (maps[currentMapId]->getType() != TYPE_PUZZLE)
            return;

        PuzzleMap* pz = MapManager::getPuzzleMap(currentMapId);
        pz->solvePuzzle();

        int cnt1 = 0, cnt2 = 0;
        for (auto& m : maps) {
            if (m.second->getType() == TYPE_PUZZLE) {
                cnt1++;
                if (((PuzzleMap*)m.second)->isAllPuzzlesSolved()) {
                    cnt2++;
                }
            }
        }

        if (cnt1 == cnt2) {
            isCleared = true;
        }
    }
};

#endif