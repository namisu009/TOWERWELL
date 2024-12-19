#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>
#include <functional>
#include <windows.h> 
#include <stdio.h>
#include <conio.h>

#include "EventDispatcher.h"
#include "HandlerManager.h"
#include "RenderManager.h"
#include "Scene.h"
#include "Command.h"

#include "GameObjectManager.h"
#include "MapManager.h"

#include "PhysicsManager.h"
#include "InitializeManager.h"
#include "StageManager.h"


using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // XOR�� ����Ͽ� �ؽ� ����
    }
};

struct playerAction {
    ActionType actionType;
    int direction;
};


class GameManager
{
    atomic<bool> isRunning;

    EventDispatcher eventDispatcher;
    HandlerManager handlerManager;

    Character* playerCharacter;
    Character* sisterCharacter;

    StageManager stageManager;

    int offset = 15;
    int threadTime = 32;
    int renderTime = 32;

    float sisterSpeed = 3.0f;

    unordered_map<pair<int, int>, playerAction, pair_hash> actionPositions;
    Map* currentMap;

    int currentStageId = 1;

    mutex mtx;

public:
    GameManager() : isRunning(true), playerCharacter(nullptr), currentMap(nullptr) {//sisterCharacter(nullptr),
        HandlerManager::setEventDispatcher(&eventDispatcher);
        RenderManager::setEventDispatcher(&eventDispatcher);

        eventDispatcher.subscribe(MOVE_MAP, [this]() {
            setMap(StageManager::getCurrentStage()->getCurrentMap());
            });
        eventDispatcher.subscribe(CHANGE_MAP_HANDLE, [this]() {
            changeMapHandle();
            });
        eventDispatcher.subscribe(STAGE_COMPLETED, [this]() {
            StageManager::moveToNextStage(); // ���� ���������� �̵�
            setMap(StageManager::getCurrentStage()->getCurrentMap());  // ù �� ����
            });
        eventDispatcher.subscribe(CLEAR_HANDLE, [this]() {
            HandlerManager::clearKeyMap();
            });
        eventDispatcher.subscribe(PUZZLE_HANDLE, [this]() {
            HandlerManager::getPuzzleMapHandle(playerCharacter, StageManager::getCurrentStage());
        });
    }

    void initialize() {
        InitializeManager::init(&eventDispatcher);

        playerCharacter = GameObjectManager::getCharacter("Hero");
        sisterCharacter = GameObjectManager::getCharacter("Sister");
        currentMap = StageManager::getCurrentStage()->getCurrentMap();

        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        sisterCharacter->SetStartPosition(currentMap->getInitX() - 0, currentMap->getInitY());
        RenderManager::ScreenInit();

        RenderManager::setRenderMap(currentMap);
        RenderManager::addObject(playerCharacter);
        //RenderManager::addObject(sisterCharacter);

        setMap(currentMap);

        RenderManager::setRenderMap(currentMap);
        //StageManager::.setScene("Scene_id_01");
    }

    void changeMapHandle() {
        switch (currentMap->getType()) {
        case TYPE_PUZZLE:
            HandlerManager::getPuzzleMapHandle(playerCharacter, StageManager::getCurrentStage());
            ((PuzzleMap*)currentMap)->addRenderPuzzle();
            break;

        case TYPE_JUMP:
            HandlerManager::getJumpMapHandle(playerCharacter, StageManager::getCurrentStage());
            break;
        default:
            break;
        }
    }

    void setMap(Map* _map) {
        currentMap = _map;

        changeMapHandle();

        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        sisterCharacter->SetStartPosition(currentMap->getInitX() - 0, currentMap->getInitY());

        RenderManager::setRenderMap(currentMap);

        if (StageManager::getCurrentStage()->hasSceneForMap(currentMap->getMapId())) {
            StageManager::getCurrentStage()->playScene();
        }

        RenderManager::render();


        actionPositions.clear();

        RenderManager::setRenderMap(currentMap);
        RenderManager::render();
    }

    // ���� ���� ����5
    void physicsLoop() {
        chrono::steady_clock::time_point lastJumpTime;
        int jumpCooldown = 500;

        while (isRunning) {
            mtx.lock();
            int flag = 0;



            playerCharacter->setDx(0);
            if (playerCharacter->getIsWallClimbing()) {
                playerCharacter->setDy(0);
                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                    playerCharacter->climbUp();
                }
                if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                    playerCharacter->climbDown();
                }
                if (!(GetAsyncKeyState(0x46) & 0x8000)
                    || !CollisionManager::checkWallAdjacent(*playerCharacter, (JumpMap*)currentMap)) {
                    playerCharacter->stopWallClimbing();
                }
            }
            else {
                int x = playerCharacter->getFootX();
                int y = playerCharacter->getFootY();
                if (GetAsyncKeyState(0x46) & 0x8000) { // FŰ ����
                    if (currentMap->getType() == TYPE_JUMP &&
                        CollisionManager::checkWallAdjacent(*playerCharacter, (JumpMap*)currentMap)) { // Ư�� �� Ȯ��
                        playerCharacter->startWallClimbing();
                    }
                }
                if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                    HandlerManager::processInput(VK_RIGHT);
                }
                if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                    HandlerManager::processInput(VK_LEFT);
                }

                if (_kbhit()) { // Ű �Է� Ȯ��
                    int key = _getch(); // Ű �Է� �б�      
                    if (key == 32) {
                        HandlerManager::processInput(VK_SPACE);
                        actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_DASH, playerCharacter->getDx() };
                    }
                }

                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                    auto now = chrono::steady_clock::now();
                    int elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastJumpTime).count();
                    if (elapsed >= jumpCooldown) {
                        HandlerManager::processInput(VK_UP);
                        actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_JUMP, playerCharacter->getDx() };
                        lastJumpTime = now;
                    }
                }
            }

            if (_kbhit()) {
                int key = _getch();
                //if (key == 70 || key == 102)
                    //HandlerManager::processInput(0x46);
            }

            playerCharacter->dashState();

            if (currentMap->getType() == TYPE_JUMP) {
                handleTrapCollision(playerCharacter);
                handleTrapCollision(sisterCharacter);
            }

            // �浹 ó�� �� ���� ����
            while (CollisionManager::checkWallCollision(playerCharacter, *currentMap)) {
                adjustPositionForCollision(playerCharacter);
            }
            PhysicsManager::applyGravity(playerCharacter, currentMap);

            while (CollisionManager::checkFloorCollision(playerCharacter, *currentMap)) {
                adjustPositionForCollision(playerCharacter);
            }

            playerCharacter->move();
            
            if(RenderManager::getRenderObject("Sister") && !sisterCharacter->getDeathState())
                updateSisterPosition();

            mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(threadTime));
        }
    }

    // �������� �÷��̾� ĳ���͸� ���󰡵��� ��ġ ������Ʈ
    void updateSisterPosition() {
        // ����: �������� �÷��̾ ���� �Ÿ� �ڵ��� �̵��ϰ� ��
        int targetLeft = playerCharacter->getFootX() - offset;    
        int targetRight = playerCharacter->getFootX() + offset;

        // �������� �÷��̾��� ���� �ȿ� �ִ��� Ȯ��
        if (!sisterCharacter->getisJumping())
        {
            if (sisterCharacter->getFootX() < targetLeft) {
                sisterCharacter->setDx(sisterSpeed);  // �÷��̾� ���ʿ� ���� �� ���������� �̵�
            }
            else if (sisterCharacter->getFootX() > targetRight) {
                sisterCharacter->setDx(-sisterSpeed); // �÷��̾� �����ʿ� ���� �� �������� �̵�
            }
            else {
                sisterCharacter->setDx(0);  // ���� ���� ���� �� ����
            }
        }

        handleSisterActions();

        sisterCharacter->dashState();

        while (CollisionManager::checkWallCollision(sisterCharacter, *currentMap)) {
            adjustPositionForCollision(sisterCharacter);
        }

        PhysicsManager::applyGravity(sisterCharacter, currentMap);

        while (CollisionManager::checkFloorCollision(sisterCharacter, *currentMap)) {
            adjustPositionForCollision(sisterCharacter);
        }

        sisterCharacter->move();
    }

    void handleSisterActions() {
        //auto sisterPos = make_pair(sisterCharacter->getX(), sisterCharacter->getY());
        int sisterX = sisterCharacter->getFootX();
        int sisterY = sisterCharacter->getFootY();
        for (auto it = actionPositions.begin(); it != actionPositions.end();) {
            int actionX = it->first.first;
            int actionY = it->first.second;

            // x ��ǥ�� �ٻ� �񱳸� ���� (tolerance�� 5�� ����)
            if (abs(sisterX - actionX) <= offset && abs(sisterY - actionY) <= offset / 2) {
                sisterCharacter->setDx(it->second.direction * 1.2);
                if (it->second.actionType == ACTION_JUMP) {
                    sisterCharacter->jump(true);
                }
                if (it->second.actionType == ACTION_CLIMB) {
                    sisterCharacter->jump(true);
                }
                else if (it->second.actionType == ACTION_DASH) {
                    sisterCharacter->dash();
                }
                // �������� �ൿ�� ���������� �ش� ��ġ�� ����
                it = actionPositions.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void handleTrapCollision(GameObject* object) {
        if (CollisionManager::checkTrapCollision(*object, (JumpMap*)currentMap)) {
            resetPlayerAndSisterPositions();
        }
    }

    void resetPlayerAndSisterPositions() {
        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        playerCharacter->setDx(0);
        playerCharacter->setDy(0);
        playerCharacter->land();

        sisterCharacter->SetStartPosition(currentMap->getInitX() - 0, currentMap->getInitY());
        sisterCharacter->setDx(0);
        sisterCharacter->setDy(0);
        sisterCharacter->land();
    }


    /*
    void adjustPositionForCollision(Character* character) {
        int colX = character->getColX();
        int colY = character->getColY();
        int range = 15; // �˻� ���� (�ȼ� ����)
        int width = character->getWidth();
        int height = character->getHeight();

        int moveLeft = range + 1;  // �ʱ�ȭ: �˻� ������ �Ѿ���� ����
        int moveRight = range + 1;

        // ���� �˻�
        for (int x = 1; x <= range; ++x) {
            if (!currentMap->isWall(colX - x, colY)) {
                moveLeft = x;
                break;
            }
        }

        // ���� �˻�
        for (int x = 1; x <= range; ++x) {
            if (!currentMap->isWall(colX + x, colY)) {
                moveRight = x;
                break;
            }
        }

        // �ּ� �̵� �Ÿ� ���
        if (moveLeft <= moveRight) {
            character->setX(colX - moveLeft); // �������� �̵�
        }
        else {
            character->setX(colX + moveRight); // ���������� �̵�
        }

        // dx�� dy�� �ʱ�ȭ
        character->setDx(0);
        character->setDy(0);
    }
    */

    // �浹 �߻� �� ��ġ ���� �Լ�
    void adjustPositionForCollision(Character* character) {
        if (character->getDx() < 0)
            character->setDx(character->getDx() + 1);
        else if (character->getDx() > 0)
            character->setDx(character->getDx() - 1);
        if (character->getDy() < 0)
            character->setDy(character->getDy() + 1);
        else if (character->getDy() > 0)
            character->setDy(character->getDy() - 1);
    }
    //��ϴ����� �����

    // ������ ����
    void renderLoop() {
        while (isRunning) {
            mtx.lock();
            RenderManager::render();
            mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(renderTime)); // �� threadTime FPS
        }
    }

    // ���� ����
    void start() {
        // ���� ���� �� ������ ������ ����
        initialize();
        thread physicsThread(&GameManager::physicsLoop, this);
        thread renderThread(&GameManager::renderLoop, this);

        // ���� ���� ���� ó��
        //cin.get(); // ���� �Է� �� ����
        //isRunning = false;

        // ������ ���� ���
        physicsThread.join();
        renderThread.join();
    }

    EventDispatcher& getEventDispatcher() {
        return eventDispatcher;
    }
};

#endif