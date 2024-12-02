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

    int offset = 7;
    int threadTime = 32;
    int renderTime = 32;

    float sisterSpeed = 3.0f;

    unordered_map<pair<int, int>, playerAction, pair_hash> actionPositions;
    Map* currentMap;

    int currentStageId = 0;

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
            StageManager::moveToNextStage(); // 다음 스테이지로 이동
            setMap(StageManager::getCurrentStage()->getCurrentMap());  // 첫 맵 실행
        });
    }

    void initialize() {
        InitializeManager::init(&eventDispatcher);

        playerCharacter = GameObjectManager::getCharacter("Hero");
        sisterCharacter = GameObjectManager::getCharacter("Sister");
        currentMap = StageManager::getCurrentStage()->getCurrentMap();
        setMap(currentMap);
        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        sisterCharacter->SetStartPosition(currentMap->getInitX() - 0, currentMap->getInitY());
        RenderManager::ScreenInit();

        RenderManager::setRenderMap(currentMap);
        RenderManager::addObject(playerCharacter);
        RenderManager::addObject(sisterCharacter);

        RenderManager::render();

        //테스트씬
        //
        //SceneManager::createScene("Afdsafad");
        //SceneManager::setAaction("Afdsafad", "Sister", ACTION_MOVE_X, 6, 10);
        Scene newScene;

        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_01", "히로: … 흔적들… 일기장… 그리고 이 탑.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_02", "???: 많은 이들이 이곳에 발을 들였지.저마다 자신의 바람을 이루기 위해.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_03", "히로: 넌 그걸 모두 지켜보고 있었겠지.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_04", "???: 선택의 순간은 언제나 흥미롭지.희망과 절망이 교차하는 찰나를 보는 것만큼 흥미로운 일은 없으니까.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_05", "히로: 기사… 그의 기록을 읽었어.그는 결국 이 탑을 떠나지 못했지.");


        newScene.setDetail("src\\sc6\\sc01.png");
        newScene.setDelay("Sister", 700);
        newScene.setDialog("S6_SC1_DL_01");
        //newScene.setDetail("src\\sc6\\sc02.png");
        newScene.setDetail("src\\sc6\\sc03.png");
        //newScene.setDetail("src\\sc6\\sc04.png");
        newScene.setDetail("src\\sc6\\sc05.png");
        //newScene.setDetail("src\\sc6\\sc06.png");
        newScene.setDetail("src\\sc6\\sc07.png");
        //newScene.setDetail("src\\sc6\\sc08.png");
        newScene.setDetail("src\\sc6\\sc09.png");
        //newScene.setDetail("src\\sc6\\sc10.png");
        newScene.setDetail("src\\sc6\\sc11.png");
        //newScene.setDetail("src\\sc6\\sc12.png");
        newScene.setDetail("src\\sc6\\sc13.png");
        newScene.setDelay("Sister", 700);
        newScene.setDialog("S6_SC1_DL_02");
        newScene.setDetail("src\\sc6\\sc14.png");
        newScene.setDetail("src\\sc6\\sc15.png");
        newScene.setDetail("src\\sc6\\sc16.png");
        newScene.setDetail("src\\sc6\\sc17.png");
        newScene.setDetail("src\\sc6\\sc18.png");
        newScene.setDetail("src\\sc6\\sc19.png");
        newScene.setDetail("src\\sc6\\sc20.png");
        newScene.setDetail("src\\sc6\\sc21.png");
        newScene.setDetail("src\\sc6\\sc22.png");
        newScene.setDelay("Sister", 700);
        newScene.setDialog("S6_SC1_DL_03");
        newScene.setDialog("S6_SC1_DL_02");
        newScene.setDetail("");

        /*
        newScene.setScreen("src\\testani01.png");
        newScene.setScreen("src\\testani02.png");
        newScene.setScreen("src\\testani03.png");
        newScene.setScreen("src\\testani04.png");
        newScene.setScreen("src\\testani05.png");

        newScene.setAction("Sister", ACTION_MOVE_X, 6, 10);

        newScene.setDelay("Sister", 64);
        newScene.setAction("Sister", ACTION_MOVE_X, -1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, 1);
        newScene.setDelay("Sister", 700);

        newScene.setDetail("src\\export.png");
        newScene.setDelay("Sister", 1000);

        newScene.setDialog("SC1_DL_01");
        newScene.setDialog("SC1_DL_02");
        newScene.setDetail("");

        */

        newScene.display();

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

        if (StageManager::getCurrentStage()->hasSceneForMap(currentMap->getMapId())) {
            StageManager::getCurrentStage()->playScene();
        }

        RenderManager::setRenderMap(currentMap);
        RenderManager::render();
    }

    // 물리 연산 루프5
    void physicsLoop() {
        chrono::steady_clock::time_point lastJumpTime;
        int jumpCooldown = 500;

        while (isRunning) {
            mtx.lock();
            int flag = 0;

            playerCharacter->setDx(0);


            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                HandlerManager::processInput(VK_RIGHT);
                flag = 1;
            }
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                HandlerManager::processInput(VK_LEFT);
                flag = 1;
            }
            if (GetAsyncKeyState(VK_UP) & 0x8000) {


                auto now = chrono::steady_clock::now();
                int elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastJumpTime).count();

                if (elapsed >= jumpCooldown) {
                    // 쿨타임이 지나면 점프
                    HandlerManager::processInput(VK_UP);
                    lastJumpTime = now;

                    if (currentMap->getType() == TYPE_JUMP)
                        actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_JUMP, playerCharacter->getDx() };
                }

                flag = 1;
            }
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                HandlerManager::processInput(VK_SPACE);

                if (currentMap->getType() == TYPE_JUMP)
                    actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_DASH, playerCharacter->getDx() };

                flag = 1;
            }

            if (_kbhit()) {
                int key = _getch();
                if(key == 70 || key == 102)
                    HandlerManager::processInput(0x46);
            }

            playerCharacter->dashState();

            if (currentMap->getType() == TYPE_JUMP) {
                handleTrapCollision(playerCharacter);
                handleTrapCollision(sisterCharacter);
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

            mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(threadTime));
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
                sisterCharacter->setDx(sisterSpeed);  // 플레이어 왼쪽에 있을 때 오른쪽으로 이동
            }
            else if (sisterCharacter->getFootX() > targetRight) {
                sisterCharacter->setDx(-sisterSpeed); // 플레이어 오른쪽에 있을 때 왼쪽으로 이동
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
        //auto sisterPos = make_pair(sisterCharacter->getX(), sisterCharacter->getY());
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

    void handleTrapCollision(GameObject * object) {
        if (CollisionManager::checkTrapCollision(*object, (JumpMap*)currentMap)) {
            resetPlayerAndSisterPositions();
        }
    }

    void resetPlayerAndSisterPositions() {
        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        playerCharacter->setDx(0);
        playerCharacter->setDy(0);
        playerCharacter->land();

        sisterCharacter->SetStartPosition(currentMap->getInitX() - offset, currentMap->getInitY());
        sisterCharacter->setDx(0);
        sisterCharacter->setDy(0);
        sisterCharacter->land();
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
            mtx.lock();
            RenderManager::render();
            mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(renderTime)); // 약 threadTime FPS
        }
    }

    // 게임 시작
    void start() {
        // 물리 연산 및 렌더링 스레드 시작
        thread physicsThread(&GameManager::physicsLoop, this);
        thread renderThread(&GameManager::renderLoop, this);

        // 게임 종료 조건 처리
        //cin.get(); // 엔터 입력 시 종료
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