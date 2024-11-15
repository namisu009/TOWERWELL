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
#include "StageManager.h"

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2; // XOR을 사용하여 해시 결합
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

    int offset = 16;
    int threadTime = 32;

    std::unordered_map<std::pair<int, int>, playerAction, pair_hash> actionPositions;
    Map* currentMap;

    int currentStageId = 0;

public:
    GameManager() : isRunning(true), playerCharacter(nullptr), sisterCharacter(nullptr), currentMap(nullptr) {
        HandlerManager::setEventDispatcher(&eventDispatcher);
        RenderManager::setEventDispatcher(&eventDispatcher);

        eventDispatcher.subscribe(MOVE_MAP, [this]() { 
            setMap(StageManager::getCurrentStage()->getCurrentMap());
        });
        eventDispatcher.subscribe(CHANGE_MAP_HANDLE, [this]() {
            changeMapHandle();
        });
    }

    void initialize() {
        for (int i = 0; i < 4; i++) {
            StageManager::addStage(i, &eventDispatcher);
        }
        // 캐릭터 생성 및 초기화
        GameObjectManager::createObejct("Character", "Hero", "src\\hero_idle_01.png");
        playerCharacter = GameObjectManager::getCharacter("Hero");
        playerCharacter->setAnimation("IDLE", 1, "src\\hero_idle_02.png");
        playerCharacter->setAnimation("RIGHT", "src\\hero_right_01.png", "src\\hero_right_02.png");
        playerCharacter->setAnimation("LEFT", "src\\hero_left_01.png", "src\\hero_left_02.png");

        GameObjectManager::createObejct("Character", "Sister", "src\\sister_idle_01.png");
        sisterCharacter = GameObjectManager::getCharacter("Sister");
        sisterCharacter->setAnimation("IDLE", 1, "src\\sister_idle_02.png");
        sisterCharacter->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
        sisterCharacter->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");

        GameObjectManager::createObejct("Dialog", "SC1_DL_01", "src\\dialog1.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_02", "src\\dialog2.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_03", "src\\dialog3.png");
        GameObjectManager::createObejct("Dialog", "PZ_NCL_DL", "src\\PZ_NCL_DL.png");

        // 맵 초기화
        MapManager::createMap("S1_PZ_MAP_01", TYPE_PUZZLE, "src\\S1_PUZZLE_MAP_01.png", "src\\S1_PUZZLE_MAP_INFO_01.png");
        MapManager::createMap("S1_JP_MAP_01", TYPE_JUMP, "src\\S1_JUMP_MAP_01.png", "src\\S1_JUMP_MAP_INFO_01.png");


        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleDetailASCII(0, "src\\SC3_PZ_01.png");
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleSceneDialog(0, "SC1_DL_03");


        StageManager::addMap(0, MapManager::getMap("S1_PZ_MAP_01"));
        StageManager::addMap(0, MapManager::getMap("S1_JP_MAP_01"));
        StageManager::setDoorID(0, "S1_PZ_MAP_01", MAP_EXIT, "S1_JP_MAP_01");
        StageManager::setDoorID(0, "S1_JP_MAP_01", MAP_EXIT, "S1_PZ_MAP_01");
        StageManager::setPuzzleId(0, "S1_PZ_MAP_01", PUZZLE_OBJ_01, "S1_M1_PZ_01");


        currentMap = StageManager::getCurrentStage()->getCurrentMap();

        // 렌더링 초기화
        RenderManager::ScreenInit();
        RenderManager::setRenderMap(currentMap);
        RenderManager::renderMap();
        DoubleBufferManager::ScreenFlipping();

        setMap(currentMap);

        RenderManager::addObject(playerCharacter);
        RenderManager::addObject(sisterCharacter);

        // 초기 화면 렌더링
        RenderManager::renderObject();
        
        //테스트씬
        Scene newScene;

        newScene.setAction("Sister", ACTION_MOVE_X, 4, 10);


        newScene.setDelay("Sister", 64);
        newScene.setAction("Sister", ACTION_MOVE_X, -1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, 1);
        newScene.setDelay("Sister", 700);

        newScene.setDialog("SC1_DL_01");

        newScene.setAction("Sister", ACTION_MOVE_X, 4, 6);
        newScene.setAction("Sister", ACTION_MOVE_X, 6, 10);
        newScene.setAction("Sister", ACTION_MOVE_X, -1);
        newScene.setAction("Sister", ACTION_MOVE_X, 0);
        newScene.setDelay("Sister", 500);
        newScene.setAction("Sister", ACTION_MOVE_Y, -3);
        newScene.setAction("Sister", ACTION_MOVE_Y, 3);
        newScene.setAction("Sister", ACTION_MOVE_Y, -3);
        newScene.setAction("Sister", ACTION_MOVE_Y, 3);
        newScene.setAction("Sister", ACTION_MOVE_Y, 0);
        
        newScene.setDelay("Sister", 800);

        newScene.setDialog("SC1_DL_02");

        newScene.setAction("Hero", ACTION_MOVE_X, 8, 10);

        //newScene.display();
      

    }

    void changeMapHandle() {
        if (currentMap->getType() == TYPE_PUZZLE) {
            HandlerManager::getPuzzleMapHandle(playerCharacter, StageManager::getCurrentStage());

            ((PuzzleMap*)currentMap)->addRenderPuzzle();
        }
        else if (currentMap->getType() == TYPE_JUMP) {
            HandlerManager::getJumpMapHandle(playerCharacter, StageManager::getCurrentStage());
        }
    }

    void setMap(Map* _map) {
        currentMap = _map;

        changeMapHandle();

        RenderManager::setRenderMap(currentMap);
        RenderManager::renderMap();

        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        sisterCharacter->SetStartPosition(currentMap->getInitX() - 18, currentMap->getInitY());
    }

    // 물리 연산 루프
    void physicsLoop() {
        std::chrono::steady_clock::time_point lastJumpTime;
        int jumpCooldown = 500;

        while (isRunning) {
            int flag = 0;

            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                HandlerManager::processInput(VK_RIGHT);
                flag = 1;
            }
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                HandlerManager::processInput(VK_LEFT);
                flag = 1;
            }
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                
                
                auto now = std::chrono::steady_clock::now();
                int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastJumpTime).count();

                if (elapsed >= jumpCooldown) {
                    // 쿨타임이 지나면 점프
                    HandlerManager::processInput(VK_UP);
                    lastJumpTime = now;

                    if (currentMap->getType() == TYPE_JUMP)
                        actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_JUMP, playerCharacter->getDx() };
                }
                else {
                    // 쿨타임이 안 지나면 점프하지 않음
                }

                flag = 1;
            }
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                HandlerManager::processInput(VK_SPACE);

                if (currentMap->getType() == TYPE_JUMP)
                    actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_DASH, playerCharacter->getDx() };
            
                flag = 1;
            }
            if (GetAsyncKeyState(0x46) & 0x8000) {
                HandlerManager::processInput(0x46);
            }

            playerCharacter->dashState();

            if (!flag) {
                playerCharacter->setDx(0);
            }

            // 충돌 처리 및 물리 연산
            while (CollisionManager::checkWallCollision(*playerCharacter, *currentMap)) {
                adjustPositionForCollision(playerCharacter);
                //playerCharacter->setDx(0);
                //playerCharacter->setDy(0);
            }
            PhysicsManager::applyGravity(playerCharacter, currentMap);

            while (CollisionManager::checkFloorCollision(*playerCharacter, *currentMap)) {
                adjustPositionForCollision(playerCharacter);
                //playerCharacter->setDx(0);
                //playerCharacter->setDy(0);
            }

            playerCharacter->move();
            updateSisterPosition();

            std::this_thread::sleep_for(std::chrono::milliseconds(threadTime));
        }
    }

    // 여동생이 플레이어 캐릭터를 따라가도록 위치 업데이트
    void updateSisterPosition() {
        // 예제: 여동생이 플레이어를 일정 거리 뒤따라 이동하게 함
        int targetLeft = playerCharacter->getFootX() - offset;
        int targetRight = playerCharacter->getFootX() + offset;

        // 여동생이 플레이어의 범위 안에 있는지 확인
        if (!sisterCharacter->getisJumping())
        {
            if (sisterCharacter->getFootX() < targetLeft) {
                sisterCharacter->setDx(2.5);  // 플레이어 왼쪽에 있을 때 오른쪽으로 이동
            }
            else if (sisterCharacter->getFootX() > targetRight) {
                sisterCharacter->setDx(-2.5); // 플레이어 오른쪽에 있을 때 왼쪽으로 이동
            }
            else {
                sisterCharacter->setDx(0);  // 범위 내에 있을 때 멈춤
            }
        }

        handleSisterActions();
        
        sisterCharacter->dashState();

        while (CollisionManager::checkWallCollision(*sisterCharacter, *currentMap)) {
            adjustPositionForCollision(sisterCharacter);

        }

        PhysicsManager::applyGravity(sisterCharacter, currentMap);

        while (CollisionManager::checkFloorCollision(*sisterCharacter, *currentMap)) {
            adjustPositionForCollision(sisterCharacter);
        }

        sisterCharacter->move();
    }

    void handleSisterActions() {
        //auto sisterPos = std::make_pair(sisterCharacter->getX(), sisterCharacter->getY());
        int sisterX = sisterCharacter->getFootX();
        int sisterY = sisterCharacter->getFootY();
        for (auto it = actionPositions.begin(); it != actionPositions.end();) {
            int actionX = it->first.first;
            int actionY = it->first.second;

            // x 좌표의 근사 비교를 수행 (tolerance는 5로 설정)
            if (abs(sisterX - actionX) <= offset && abs(sisterY - actionY) <= offset / 2) {
                sisterCharacter->setDx(it->second.direction * 1.2); 
                if (it->second.actionType == ACTION_JUMP) {
                    sisterCharacter->jump();
                }
                else if (it->second.actionType == ACTION_DASH) {
                    sisterCharacter->dash();
                }
                // 여동생이 행동을 수행했으면 해당 위치를 삭제
                it = actionPositions.erase(it);
            }
            else {
                ++it;
            }
        }
    }
    // 충돌 발생 시 위치 조정 함수
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
    //블록단위로 나누어서

    // 렌더링 루프
    void renderLoop() {
        while (isRunning) {
            RenderManager::render();
            std::this_thread::sleep_for(std::chrono::milliseconds(threadTime)); // 약 threadTime FPS
        }
    }

    // 게임 시작
    void start() {
        // 물리 연산 및 렌더링 스레드 시작
        std::thread physicsThread(&GameManager::physicsLoop, this);
        std::thread renderThread(&GameManager::renderLoop, this);

        // 게임 종료 조건 처리
        //std::cin.get(); // 엔터 입력 시 종료
        //isRunning = false;

        // 스레드 종료 대기
        physicsThread.join();
        renderThread.join();
    }

    EventDispatcher& getEventDispatcher() {
        return eventDispatcher;
    }
};

#endif