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
            StageManager::moveToNextStage(); // 다음 스테이지로 이동
            setMap(StageManager::getCurrentStage()->getCurrentMap());  // 첫 맵 실행
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
        RenderManager::addObject(sisterCharacter);

        setMap(currentMap);

        //테스트씬
        //
        //SceneManager::createScene("Afdsafad");
        //SceneManager::setAaction("Afdsafad", "Sister", ACTION_MOVE_X, 6, 10);
        Scene newScene;

        GameObjectManager::createObject("Character", "Hood", "src\\hero_idle_right_01.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("IDLE_RIGHT", 1, "src\\hero_idle_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("IDLE_LEFT", "src\\hero_idle_left_01.png", "src\\hero_idle_left_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("RIGHT", "src\\hero_right_01.png", "src\\hero_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("LEFT", "src\\hero_left_01.png", "src\\hero_left_02.png");
        newScene.setDelay("Sister", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_01", "리안: 드디어 우물이 보인다!");
        newScene.setDialog("S5_SC1_DL_01");

        newScene.setAction("Sister", ACTION_MOVE_X, 3, 7);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_02", "리안: 정말 신비롭다… 이렇게 가까이 오다니 믿기지 않아.");
        newScene.setDialog("S5_SC1_DL_02");

        //복면 움직이기
        newScene.setCharacterPosition("Hood", 200, GameObjectManager::getCharacter("Hero")->getY());
        newScene.setRenderCharacter("Hood");
        newScene.setAction("Hood", ACTION_MOVE_X, -3, 2);
        newScene.setDelay("Hood", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_03", "히로: 여동생한테 누군가 있다고 말하는 대화창");
        newScene.setDialog("S5_SC1_DL_03");

        //두리번 거리는 여동생
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, -1, 1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, 1, 1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, -1, 1);
        newScene.setDelay("Sister", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_04", "리안: 뭐? 어디?");
        newScene.setDialog("S5_SC1_DL_04");

        newScene.setDelay("Hood", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_05", "???: ……");
        newScene.setDialog("S5_SC1_DL_05");
        // (갑자기 빠르게 다가오는 복면녀. 히로는 앞을 막아서 하려 하지만 복면녀는 이를 단숨에 제치고 리안을 찌른다.)
        //씬 디테일

        newScene.setAction("Hood", ACTION_MOVE_X, -18, 5);
        //newScene.setAction("Hero", ACTION_MOVE_X, 5, 5);
        newScene.setAction("Sister", ACTION_MOVE_X, -1, 3);
        newScene.setAction("Hood", ACTION_MOVE_X, -3);
        newScene.setDelay("Hood", 100);
        newScene.setDetail("src\\testsc.png");
        newScene.setDelay("Hood", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_06", "리안: (비명)");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_07", "히로: 리안!! 안 돼!!");
        newScene.setDialog("S5_SC1_DL_06");
        newScene.setDialog("S5_SC1_DL_07");
        //(복면녀는 주인공이 놀란 사이 어디론가 도망치듯 사라진다) setAction
        newScene.setDetail("");

        newScene.setAction("Hood", ACTION_MOVE_X, 12, 6);
        newScene.removeRenderCharacter("Hood");

        newScene.setDelay("Hood", 700);


        //리안 죽은 장면
        newScene.setDetail("src\\testsc2.png");
        newScene.setDelay("Hood", 700);

        GameObjectManager::createObject("Dialog", "S5_SC1_DL_08", "리안: … ");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_09", "히로: 리안… 제발 일어나줘… 눈을 떠봐!");
        newScene.setDialog("S5_SC1_DL_08");
        newScene.setDialog("S5_SC1_DL_09");
        newScene.setDetail("");

        GameObjectManager::createObject("Dialog", "S5_SC1_DL_10", "???: 딱하기도 하지.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_11", "???: 딱하기도 하지.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_12", "우물에서 신비로우나 공허한 목소리가 들려온다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_13", "히로: 거짓말하지 마! 네가 꾸민 짓이잖아! 그 두건은 또 뭐야?!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_14", "???: 나는 오래전부터 이 옥상에 존재했던 우물일 뿐이다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_15", "우물: 그리고 나는 그저 소원을 들어주는 우물로서 여기에 있을 뿐이다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_16", "히로: 그딴 말 말고, 당장 리안을 살려내!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_17", "우물: 모든 소원에는 대가가 따른다. 네 여동생을 살리고 싶다면…");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_18", "우물: 탑에서 가장 빛나는 것을 가지고 우물 앞으로 가져오게.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_19", "우물: 그리하면 내가 응답할 것이다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_20", "히로: 대가… 탑에서 가장 빛나는 것…?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_21", "히로: 네가 없는 세상은 의미가 없어. 어떤 대가라도 치르겠어.");

        for (int i = 10; i <= 21;i++)
        {
            string c = "S5_SC1_DL_";
            c += to_string(i);
            newScene.setDialog(c.c_str());
        }
        

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

       //newScene.display();

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
        RenderManager::render();

        if (StageManager::getCurrentStage()->hasSceneForMap(currentMap->getMapId())) {
            StageManager::getCurrentStage()->playScene();
        }

        actionPositions.clear();

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
            if (playerCharacter->getIsWallClimbing()) {
                playerCharacter->setDy(0);

                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                    playerCharacter->climbUp();
                }
                if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                    playerCharacter->climbDown();
                }
                
                if (!(GetAsyncKeyState(0x46) & 0x8000) || // F키에서 손 뗌
                    !(GetAsyncKeyState(VK_LEFT) & 0x8000) ||
                    !(GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
                    playerCharacter->stopWallClimbing();
                }
            }
            // 벽타기 활성화 조건 확인
            else {
                if (GetAsyncKeyState(0x46) & 0x8000) { // F키 누름
                    if (currentMap->getType() == TYPE_JUMP &&
                        CollisionManager::checkWallAdjacent(*playerCharacter, (JumpMap*)currentMap)) { // 특정 벽 확인
                        playerCharacter->startWallClimbing();
                    }
                }
                // 일반 이동 처리
                if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                    HandlerManager::processInput(VK_RIGHT);
                }
                if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                    HandlerManager::processInput(VK_LEFT);
                }
                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                    auto now = chrono::steady_clock::now();
                    int elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastJumpTime).count();

                    if (elapsed >= jumpCooldown) {
                        HandlerManager::processInput(VK_UP);
                        lastJumpTime = now;
                    }
                }
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
            while (CollisionManager::checkWallCollision(playerCharacter, *currentMap)) {

                //&& CollisionManager::checkWallAdjacent(*playerCharacter, (JumpMap*)currentMap) && playerCharacter->getIsWallClimbing()
                adjustPositionForCollision(playerCharacter);
                //playerCharacter->setDx(0);
                //playerCharacter->setDy(0);
            }
            PhysicsManager::applyGravity(playerCharacter, currentMap);

            while (CollisionManager::checkFloorCollision(playerCharacter, *currentMap)) {
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

            // x 좌표의 근사 비교를 수행 (tolerance는 5로 설정)
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

        sisterCharacter->SetStartPosition(currentMap->getInitX() - 0, currentMap->getInitY());
        sisterCharacter->setDx(0);
        sisterCharacter->setDy(0);
        sisterCharacter->land();
    }


    /*
    void adjustPositionForCollision(Character* character) {
        int colX = character->getColX();
        int colY = character->getColY();
        int range = 15; // 검사 범위 (픽셀 단위)
        int width = character->getWidth();
        int height = character->getHeight();

        int moveLeft = range + 1;  // 초기화: 검사 범위를 넘어가도록 설정
        int moveRight = range + 1;

        // 좌측 검사
        for (int x = 1; x <= range; ++x) {
            if (!currentMap->isWall(colX - x, colY)) {
                moveLeft = x;
                break;
            }
        }

        // 우측 검사
        for (int x = 1; x <= range; ++x) {
            if (!currentMap->isWall(colX + x, colY)) {
                moveRight = x;
                break;
            }
        }

        // 최소 이동 거리 계산
        if (moveLeft <= moveRight) {
            character->setX(colX - moveLeft); // 왼쪽으로 이동
        }
        else {
            character->setX(colX + moveRight); // 오른쪽으로 이동
        }

        // dx와 dy를 초기화
        character->setDx(0);
        character->setDy(0);
    }
    */

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