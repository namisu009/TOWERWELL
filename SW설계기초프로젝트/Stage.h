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
    int stageId; // �������� ID
    string currentMapId;
    unordered_map<string, Map*> maps;// �ش� ���������� ��
    unordered_map<string, Scene*> scenes;// �ش� ���������� ����
    bool isCleared; // �������� Ŭ���� ���� //������ �� Ǯ���� ��
    EventDispatcher* eventDispatcher; // �̺�Ʈ ����ó ����
    EventDispatcher* StageEventDispatcher; // �̺�Ʈ ����ó ����

public:
    Stage(){}
    Stage(int id, EventDispatcher* _eventDispatcher) : Stage() {
        currentMapId = "";
        isCleared = false;
        stageId = id;
        eventDispatcher = _eventDispatcher;
        StageEventDispatcher = new EventDispatcher();
        StageEventDispatcher->subscribe(PUZZLE_SOLVED, [this]() { this->onPuzzleSolved(); });
    }

    /* ����� ��� */
    Map* getCurrentMap() {
        return maps[currentMapId];
    }

    Map* getMap(string id) {
        return maps[id];
    }

    EventDispatcher* getStageEventDispatcher() {
        return StageEventDispatcher;
    }

    void onMoveMap(int x, int y) { //���̵�
        string key = maps[currentMapId]->getDoorId(x, y);
        if (key != "")
            currentMapId = key;

        eventDispatcher->dispatch(MOVE_MAP);
    }
    /* �߰� ���*/

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
        string mapKey = "S" + to_string(stageId) + "_P_MAP_01";
        PuzzleMap* pz = MapManager::getPuzzleMap(mapKey);
        if (pz->isAllPuzzlesSolved())
        {
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
            return;  // ���� �ʿ� ����� ���� ������ ��� ��ȯ
        }

        Scene* scene = scenes[currentMapId];
        if (scene) {
            scene->display();

            RenderManager::setRenderMap(maps[currentMapId]);
        }
    
    }

    void onPuzzleSolved() {
        string mapKey = "S" + to_string(stageId + 1) + "_P_MAP_01";
        PuzzleMap* pz = (PuzzleMap*) maps[mapKey];
        pz->solvePuzzle();

        if (pz->isAllPuzzlesSolved())
        {
            isCleared = true;
        }
    }
};

#endif