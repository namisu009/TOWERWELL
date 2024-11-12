#ifndef _HANDLEMANAGER_H
#define _HANDLEMANAGER_H
#include <unordered_map>
#include <functional>

#include "Map.h"
#include "Scene.h"
#include "Command.h"
#include "PuzzleMap.h"
#include "Stage.h"
#include "JumpMap.h"
#include "EventDispatcher.h"
#include "GameObjectManager.h"

using namespace std;

class HandlerManager {
private:
    static unordered_map<int, function<void()>> keyMap;// �Է� Ű - �Լ� ����
    static EventDispatcher* eventDispatcher;

public:
    // EventDispatcher ����
    static void setEventDispatcher(EventDispatcher* dispatcher) {
        eventDispatcher = dispatcher;
    }
    static void bindInput(int key, const function<void()>& action) {
        keyMap[key] = action;
    }
    static void clearKeyMap() {
        keyMap.clear();
    }
    static void processInput(int key) {
        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key](); // �ش� Ű�� ���ε� �Լ� ����
        }
    }

    static void getPuzzleMapHandle(Character* object, Stage* stage, Map* map) {
     
        clearKeyMap();

        bindInput(VK_RIGHT, [object]() {
            object->setDx(4);
            });

        // ���� �̵�
        bindInput(VK_LEFT, [object]() {
            object->setDx(-4);
            });

        // ����
        bindInput(VK_UP, [object]() {
            object->jump();
        });

        bindInput(0x46, [object, stage, map]() {
            ScreenArray myScreen = map->getScreenArray();

            int init_x = object->getFootX();
            int init_y = object->getFootY() - object->getHeight() / 2;
            
            int in = myScreen.MapInfo[init_y][init_x];
            if (in == PUZZLE_OBJ_01 || in == PUZZLE_OBJ_02)
            {
                Scene newScene;
                Command newCmd;

                GameObjectManager::createObejct("Dialog", "SC3_PZ_01", "src\\SC3_PZ_01.png");

                newCmd.addObject(GameObjectManager::getCharacter("SC3_PZ_01"));
                newScene.addCommand(newCmd);

                newScene.display();
            }
            
            if (map->getDoorId(init_x, init_y) != "") {
                stage->onMoveMap(init_x, init_y);
            }
        });

        // ���� ���̵� ��������

    }

    static void getJumpMapHandle(Character* object, JumpMap* map) {
        
        clearKeyMap();

        bindInput(VK_RIGHT, [object]() {
            object->setDx(4);
        });

        // ���� �̵�
        bindInput(VK_LEFT, [object]() {
            object->setDx(-4);
        });

        // ����
        bindInput(VK_UP, [object]() {
            object->jump();
        });

        // ���
        bindInput(VK_SPACE, [object]() {
            object->dash();
        });
    }
};

#endif

