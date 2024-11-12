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
    static unordered_map<int, function<void()>> keyMap;// 입력 키 - 함수 매핑
    static EventDispatcher* eventDispatcher;

public:
    // EventDispatcher 설정
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
            keyMap[key](); // 해당 키에 매핑된 함수 실행
        }
    }

    static void getPuzzleMapHandle(Character* object, PuzzleMap* map) {
     
        clearKeyMap();

        bindInput(VK_RIGHT, [object]() {
            object->setDx(4);
            });

        // 왼쪽 이동
        bindInput(VK_LEFT, [object]() {
            object->setDx(-4);
            });

        // 점프
        bindInput(VK_UP, [object]() {
            object->jump();
        });

        // 퍼즐 아이디 가져오기

    }

    static void getJumpMapHandle(Character* object, JumpMap* map) {
        
        clearKeyMap();

        bindInput(VK_RIGHT, [object]() {
            object->setDx(4);
        });

        // 왼쪽 이동
        bindInput(VK_LEFT, [object]() {
            object->setDx(-4);
        });

        // 점프
        bindInput(VK_UP, [object]() {
            object->jump();
        });

        // 대시
        bindInput(VK_SPACE, [object]() {
            object->dash();
        });
    }
};

#endif

