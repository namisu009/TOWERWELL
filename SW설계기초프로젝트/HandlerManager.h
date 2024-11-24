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

    static void getJumpMapHandle(Character* object, Stage* stage) {

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

        bindInput(0x46, [object, stage]() {

            int init_x = object->getFootX();
            int init_y = object->getFootY() - object->getHeight() / 2;

            if (stage->getDoorId(init_x, init_y) != "") {
                stage->onMoveMap(init_x, init_y);
            }
            });
    }

    static void getPuzzleMapHandle(Character* object, Stage* stage) {
     
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

                // ���� �ذ� ���� ó��
                bool puzzleSolved = puzzle->isPuzzleSolved();
                if (puzzle->getType() == TYPE_ITEM_PUZZLE)
                    puzzleSolved = ((ItemPuzzle*)puzzle)->isSatisfyCondition(obj);
                else
                    puzzleSolved = puzzle->isIntermediateSolved();

                if (puzzleSolved) {
                    puzzle->progressPuzzle(); // �߰� �ذ� ����
                    obj->addInventory(puzzle->getPuzzleReward());
                }
                else {
                    puzzle->PuzzleNCLSceneDisplay();
                }
            }

            if (stg->getDoorId(init_x, init_y) != "") {
                stg->onMoveMap(init_x, init_y);
            }
        });

        // ���� ���̵� ��������

    }

    static void getPuzzleDetailHandle(Puzzle* puzzle) {
        clearKeyMap();

        if (puzzle->getType() == TYPE_NUMBER_PUZZLE) {
            getNumberPuzzleHandle(puzzle);
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

    static void getNumberPuzzleHandle(Puzzle* puzzle) {
        NumberPuzzle* numberPuzzle = (NumberPuzzle*) puzzle;
        if (!numberPuzzle) {
            return;
        }

        int flag = 1;
        string userInput;

        // ���� Ű �Է� �ڵ鸵
        bindInput(VK_RETURN, [&]() {
            if (!userInput.empty()) {
                vector<int> answer;

                // �Է� ���ڿ��� ���ڷ� ��ȯ
                for (char c : userInput) {
                    if (isdigit(c)) {
                        answer.push_back(c - '0');
                    }
                }

                // ���� �Է°� ����
                if (numberPuzzle->setAnswer(answer)) {
                    RenderManager::setRenderDialog(nullptr);
                    RenderManager::ClearRenderPuzzleDetail();
                    flag = 0; // �ڵ鸵 ����
                }

                userInput.clear(); // �Է� �ʱ�ȭ
            }
            });

        bindInput(VK_BACK, [&]() {
            if (!userInput.empty()) {
                userInput.pop_back(); // �Է� ���ڿ����� ������ ���� ����
            }
        });

        bindInput(VK_ESCAPE, [&]() {
            RenderManager::setRenderDialog(nullptr);
            RenderManager::ClearRenderPuzzleDetail();
            flag = 0; // �ڵ鸵 ����
        });


        // ���� Ű �Է� ���ε�
        for (int key = '0'; key <= '9'; ++key) {
            bindInput(key, [&, key]() {
                userInput += static_cast<char>(key);
            });
        }

        // �ڵ鸵 ����
        // 
        const auto& art = GameObjectManager::getDialog("NUMBER_WINDOW")->getRenderArray(); // ASCII ��Ʈ ��������
        DoubleBufferManager::ScreenFlipping();

        COORD pos = { 0, 0 };
        pos.X = GameObjectManager::getDialog("NUMBER_WINDOW")->getX();
        pos.Y = GameObjectManager::getDialog("NUMBER_WINDOW")->getY();

        // ��ü�� ASCII ��Ʈ�� Ư�� ��ġ�� ������
        for (int y = 0; y < art->height; y++)
        {
            pos.Y = GameObjectManager::getDialog("NUMBER_WINDOW")->getY() + y;
            DoubleBufferManager::ScreenPrint(GameObjectManager::getDialog("NUMBER_WINDOW")->getX(), pos.Y, art->ASCIIArtArr[y]);
        }

        DoubleBufferManager::ScreenFlipping();
        Sleep(10);

        while (flag) {
 

            for (int key = '0'; key <= '9'; ++key) {
                if (GetAsyncKeyState(key) & 0x8000) {
                    processInput(key);
                }
            }

            if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                processInput(VK_BACK);
            }

            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                processInput(VK_RETURN);
            }

            if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                processInput(VK_ESCAPE);
            }

            // CPU ���ϸ� ���̱� ���� ª�� ��� �߰�
            this_thread::sleep_for(chrono::milliseconds(50));
        }

        eventDispatcher->dispatch(CHANGE_MAP_HANDLE);
        return;
    }
};

#endif

