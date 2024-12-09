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
            object->jump(true);
            });

        // 대시
        bindInput(VK_SPACE, [object]() {
            object->dash();
            });

        bindInput(0x46, [object, stage]() {

            int init_x = object->getFootX();
            int init_y = object->getFootY() - object->getHeight() / 2;

            if (stage->getDoorId(init_x, init_y) == "EXIT") {
                if (stage->getIsCleared()) {
                    eventDispatcher->dispatch(STAGE_COMPLETED);
                }
                //stage->onMoveMap(init_x, init_y);
            }
            });

        bindInput(0x43, [object, stage]() {
            //eventDispatcher->dispatch(MOVE_MAP);
        });
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

                if ((GetAsyncKeyState(VK_ESCAPE) & 0x0001))
                    return;

                // 퍼즐 해결 조건 처리
                bool puzzleSolved = puzzle->isPuzzleSolved();

                if (puzzle->getType() == TYPE_ITEM_PUZZLE)
                    puzzleSolved = ((ItemPuzzle*)puzzle)->isSatisfyCondition(obj);
                else
                    puzzleSolved = puzzle->isSatisfyCondition();

                if (puzzleSolved) {
                    puzzle->progressPuzzle(); // 중간 해결 진행
                    obj->addInventory(puzzle->getPuzzleReward());
                }
                else {
                    puzzle->PuzzleNCLSceneDisplay();
                }

                return;
            }

            if (stg->getDoorId(init_x, init_y) != "EXIT" && stg->getDoorId(init_x, init_y) != "") {
                if (!stg->getCurrentMap()->isExitDoor(init_x, init_y)) {
                    stg->getCurrentMap()->setInitPosition(init_x, obj->getFootY());
                }
                stg->onMoveMap(init_x, init_y);
                return;
            }

            if (stage->getDoorId(init_x, init_y) == "EXIT") {
                if (stage->getIsCleared()) {
                    stage->onMoveMap(init_x, init_y);
                    //eventDispatcher->dispatch(STAGE_COMPLETED);
                }
            }
        });

        // 퍼즐 아이디 가져오기

    }

    static void getPuzzleDetailHandle(Puzzle* puzzle) {
        clearKeyMap();

        if (puzzle->getType() == TYPE_NUMBER_PUZZLE && !puzzle->isPuzzleSolved()) {
            getNumberPuzzleHandle(puzzle);
            return;
        }

        int flag = 1;
        bindInput(VK_SPACE, []() {
            RenderManager::ClearRenderDetail();
            eventDispatcher->dispatch(CHANGE_MAP_HANDLE);
        });

        while (flag) {
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                HandlerManager::processInput(VK_SPACE);
                flag = 0;
            }
        }

    }

    static void getNumberPuzzleHandle(Puzzle* puzzle) {
        NumberPuzzle* numberPuzzle = (NumberPuzzle*) puzzle;
        if (!numberPuzzle) {
            return;
        }

        int flag = 1;
        string userInput;

        RenderManager::setRenderDialog(GameObjectManager::getDialog("NUMBER_WINDOW"));
        RenderManager::renderInputText(userInput, cmdWidth + GameObjectManager::getDialog("NUMBER_WINDOW")->getX(), 1085);
        /*
        const auto& art = GameObjectManager::getDialog("NUMBER_WINDOW")->getRenderArray(); // ASCII 아트 가져오기
        DoubleBufferManager::ScreenFlipping();

        COORD pos = { 0, 0 };
        pos.X = GameObjectManager::getDialog("NUMBER_WINDOW")->getX();
        pos.Y = GameObjectManager::getDialog("NUMBER_WINDOW")->getY();
        */
        // 숫자 키 입력 핸들링
        bindInput(VK_RETURN, [&]() {
            if (!userInput.empty()) {
                vector<int> answer;

                // 입력 문자열을 숫자로 변환
                for (char c : userInput) {
                    if (isdigit(c)) {
                        answer.push_back(c - '0');
                    }
                }

                // 퍼즐에 입력값 전달
                if (numberPuzzle->setAnswer(answer)) {
                    RenderManager::setRenderDialog(nullptr);
                    RenderManager::ClearRenderDetail();
                    flag = 0; // 핸들링 종료
                }

                userInput.clear(); // 입력 초기화
            }
            });

        bindInput(VK_ESCAPE, [&]() {
            RenderManager::setRenderDialog(nullptr);
            RenderManager::ClearRenderDetail();
            flag = 0; // 핸들링 종료
        });

        bindInput(VK_BACK, [&]() {
            if (!userInput.empty()) {
                userInput.pop_back(); // 마지막 문자 삭제
                RenderManager::renderInputText(userInput, cmdWidth + GameObjectManager::getDialog("NUMBER_WINDOW")->getX(), 1085);    // 화면 갱신
            }
        });

        // 숫자 키 입력 바인딩
        for (int key = '0'; key <= '9'; ++key) {
            bindInput(key, [&, key]() {
                //if (userInput.size() > 4)
                //    return;

                userInput += static_cast<char>(key);
                RenderManager::renderInputText(userInput, cmdWidth + GameObjectManager::getDialog("NUMBER_WINDOW")->getX(), 1085);    // 화면 갱신
            });
        }
        /*
        int x = GameObjectManager::getDialog("NUMBER_WINDOW")->getX();
        // 객체의 ASCII 아트를 특정 위치에 렌더링
        for (int y = 0; y < art->height; y++)
        {
            DoubleBufferManager::ScreenPrint(x, pos.Y, art->ASCIIArtArr[y]);
        }

        pos.Y = GameObjectManager::getDialog("NUMBER_WINDOW")->getY();
        DoubleBufferManager::ScreenFlipping();
        Sleep(10);
        */


        while (flag) {
            if (_kbhit()) { // 키 입력 확인
                int key = _getch(); // 키 입력 읽기      
                switch (key) {
                case VK_BACK:
                    processInput(VK_BACK); break;
                case VK_RETURN:
                    processInput(VK_RETURN); break;
                case VK_ESCAPE:
                    processInput(VK_ESCAPE); break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    processInput(key);
                    break;
                }
            }
            this_thread::sleep_for(chrono::milliseconds(10));
        }

        eventDispatcher->dispatch(CHANGE_MAP_HANDLE);
        return;
    }
};

#endif

