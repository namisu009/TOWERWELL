#ifndef _HANDLEMANAGER_H
#define _HANDLEMANAGER_H
#include <unordered_map>
#include <functional>
#include <string>

#include "Map.h"
#include "Scene.h"
#include "Command.h"
#include "PuzzleMap.h"
#include "Stage.h"
#include "JumpMap.h"
#include "EventDispatcher.h"
#include "GameObjectManager.h"
#include "PuzzleManager.h"
#include "RenderManager.h"

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

    static void getPuzzleMapHandle(Character* object, Stage* stage) {
     
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

        bindInput(0x46, [object, stage]() {
            PuzzleMap* map = ((PuzzleMap*)stage->getCurrentMap());

            Character* obj = object;
            Stage* stg = stage;

            int init_x = obj->getFootX();
            int init_y = obj->getFootY() - obj->getHeight() / 2;

            Puzzle* puzzle = PuzzleManager::getPuzzle(stg->getPuzzleId(init_x, init_y));
            if (puzzle) {
                if (puzzle->getDetailArray() != nullptr) {
                    puzzle->showPuzzleDetail();
                    getPuzzleDetailHandle(puzzle);
                }

                // 퍼즐 해결 조건 처리
                bool puzzleSolved = puzzle->isPuzzleSolved();
                if (puzzle->getType() == TYPE_ITEM_PUZZLE)
                    puzzleSolved = ((ItemPuzzle*)puzzle)->isSatisfyCondition(obj);
                else
                    puzzleSolved = puzzle->isIntermediateSolved();

                if (puzzleSolved) {
                    puzzle->progressPuzzle(); // 중간 해결 진행
                    obj->addInventory(puzzle->getPuzzleReward());
                }
            }

            if (stg->getDoorId(init_x, init_y) != "") {
                stg->onMoveMap(init_x, init_y);
            }
        });

        // 퍼즐 아이디 가져오기

    }

    static void getJumpMapHandle(Character* object, Stage* stage) {
        
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

        bindInput(0x46, [object, stage]() {

            int init_x = object->getFootX();
            int init_y = object->getFootY() - object->getHeight() / 2;

            if (stage->getDoorId(init_x, init_y) != "") {
                stage->onMoveMap(init_x, init_y);
            }
        });
    }

    static void getPuzzleDetailHandle(Puzzle* puzzle) {
        clearKeyMap();

        if (puzzle->getType() == TYPE_NUMBER_PUZZLE)
        {
            //또 다른 핸들로 넘어가기
            return;
        }

        int flag = 1;
        bindInput(VK_SPACE, []() {
            RenderManager::ClearRenderPuzzleDetail();
            eventDispatcher->dispatch(CHANGE_MAP_HANDLE);
        });

        while (flag) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                HandlerManager::processInput(VK_SPACE);
                flag = 0;
            }
        }

    }
};

#endif

