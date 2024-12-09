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
            StageManager::moveToNextStage(); // ���� ���������� �̵�
            setMap(StageManager::getCurrentStage()->getCurrentMap());  // ù �� ����
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

        //�׽�Ʈ��
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
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_01", "����: ���� �칰�� ���δ�!");
        newScene.setDialog("S5_SC1_DL_01");

        newScene.setAction("Sister", ACTION_MOVE_X, 3, 7);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_02", "����: ���� �ź�Ӵ١� �̷��� ������ ���ٴ� �ϱ��� �ʾ�.");
        newScene.setDialog("S5_SC1_DL_02");

        //���� �����̱�
        newScene.setCharacterPosition("Hood", 200, GameObjectManager::getCharacter("Hero")->getY());
        newScene.setRenderCharacter("Hood");
        newScene.setAction("Hood", ACTION_MOVE_X, -3, 2);
        newScene.setDelay("Hood", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_03", "����: ���������� ������ �ִٰ� ���ϴ� ��ȭâ");
        newScene.setDialog("S5_SC1_DL_03");

        //�θ��� �Ÿ��� ������
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, -1, 1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, 1, 1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, -1, 1);
        newScene.setDelay("Sister", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_04", "����: ��? ���?");
        newScene.setDialog("S5_SC1_DL_04");

        newScene.setDelay("Hood", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_05", "???: ����");
        newScene.setDialog("S5_SC1_DL_05");
        // (���ڱ� ������ �ٰ����� �����. ���δ� ���� ���Ƽ� �Ϸ� ������ ������ �̸� �ܼ��� ��ġ�� ������ ���.)
        //�� ������

        newScene.setAction("Hood", ACTION_MOVE_X, -18, 5);
        //newScene.setAction("Hero", ACTION_MOVE_X, 5, 5);
        newScene.setAction("Sister", ACTION_MOVE_X, -1, 3);
        newScene.setAction("Hood", ACTION_MOVE_X, -3);
        newScene.setDelay("Hood", 100);
        newScene.setDetail("src\\testsc.png");
        newScene.setDelay("Hood", 700);
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_06", "����: (���)");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_07", "����: ����!! �� ��!!");
        newScene.setDialog("S5_SC1_DL_06");
        newScene.setDialog("S5_SC1_DL_07");
        //(������ ���ΰ��� ��� ���� ���а� ����ġ�� �������) setAction
        newScene.setDetail("");

        newScene.setAction("Hood", ACTION_MOVE_X, 12, 6);
        newScene.removeRenderCharacter("Hood");

        newScene.setDelay("Hood", 700);


        //���� ���� ���
        newScene.setDetail("src\\testsc2.png");
        newScene.setDelay("Hood", 700);

        GameObjectManager::createObject("Dialog", "S5_SC1_DL_08", "����: �� ");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_09", "����: ���ȡ� ���� �Ͼ�ࡦ ���� ����!");
        newScene.setDialog("S5_SC1_DL_08");
        newScene.setDialog("S5_SC1_DL_09");
        newScene.setDetail("");

        GameObjectManager::createObject("Dialog", "S5_SC1_DL_10", "???: ���ϱ⵵ ����.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_11", "???: ���ϱ⵵ ����.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_12", "�칰���� �ź�ο쳪 ������ ��Ҹ��� ����´�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_13", "����: ���������� ��! �װ� �ٹ� �����ݾ�! �� �ΰ��� �� ����?!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_14", "???: ���� ���������� �� ���� �����ߴ� �칰�� ���̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_15", "�칰: �׸��� ���� ���� �ҿ��� ����ִ� �칰�μ� ���⿡ ���� ���̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_16", "����: �׵� �� ����, ���� ������ �����!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_17", "�칰: ��� �ҿ����� �밡�� ������. �� �������� �츮�� �ʹٸ顦");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_18", "�칰: ž���� ���� ������ ���� ������ �칰 ������ ��������.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_19", "�칰: �׸��ϸ� ���� ������ ���̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_20", "����: �밡�� ž���� ���� ������ �͡�?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_21", "����: �װ� ���� ������ �ǹ̰� ����. � �밡�� ġ���ھ�.");

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
                
                if (!(GetAsyncKeyState(0x46) & 0x8000) || // FŰ���� �� ��
                    !(GetAsyncKeyState(VK_LEFT) & 0x8000) ||
                    !(GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
                    playerCharacter->stopWallClimbing();
                }
            }
            // ��Ÿ�� Ȱ��ȭ ���� Ȯ��
            else {
                if (GetAsyncKeyState(0x46) & 0x8000) { // FŰ ����
                    if (currentMap->getType() == TYPE_JUMP &&
                        CollisionManager::checkWallAdjacent(*playerCharacter, (JumpMap*)currentMap)) { // Ư�� �� Ȯ��
                        playerCharacter->startWallClimbing();
                    }
                }
                // �Ϲ� �̵� ó��
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

            // �浹 ó�� �� ���� ����
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