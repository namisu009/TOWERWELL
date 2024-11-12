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
    int stageId; // �������� ID
    string currentMapId;
    unordered_map<string, Map*> maps;// �ش� ���������� ��
    unordered_map<string, Scene*> scenes;// �ش� ���������� ����
    bool isCleared; // �������� Ŭ���� ���� //������ �� Ǯ���� ��

    EventDispatcher* eventDispatcher; // �̺�Ʈ ����ó ����

public:
    Stage(){}
    Stage(EventDispatcher* _eventDispatcher) {
        currentMapId = "";
        isCleared = false;
        eventDispatcher = _eventDispatcher;
        eventDispatcher->subscribe(PUZZLE_SOLVED, [this]() { onPuzzleSolved(); });
    }

    /* ����� ��� */
    Map* getCurrentMap() {
        return maps[currentMapId];
    }

    void onMoveMap(int x, int y) { //���̵�
        string key = maps[currentMapId]->getDoorId(x, y);
        if (key != "")
            currentMapId = key;

        eventDispatcher->dispatch(MOVE_MAP);
    }
    /* �߰� ���*/

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