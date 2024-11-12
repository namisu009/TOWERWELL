#ifndef _HANDLEMANAGER_H
#define _HANDLEMANAGER_H
#include <unordered_map>
#include <functional>

#include "Map.h"
#include "PuzzleMap.h"
#include "JumpMap.h"
#include "EventDispatcher.h"

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

    static void getPuzzleMapHandle(Character* object, PuzzleMap* map) {
     
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

