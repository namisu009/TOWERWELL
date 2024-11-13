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
    }

    void initialize() {
        for (int i = 0; i < 4; i++) {
            StageManager::addStage(i, &eventDispatcher);
        }

        // �� �ʱ�ȭ
        MapManager::createMap("S1_PZ_MAP_01", TYPE_PUZZLE, "src\\S1_PUZZLE_MAP_01.png", "src\\S1_PUZZLE_MAP_INFO_01.png");
        MapManager::createMap("S1_JP_MAP_01", TYPE_JUMP, "src\\S1_JUMP_MAP_01.png", "src\\S1_JUMP_MAP_INFO_01.png");
        MapManager::getMap("S1_PZ_MAP_01")->setDoorId(MAP_EXIT, "S1_JP_MAP_01");
        MapManager::getMap("S1_JP_MAP_01")->setDoorId(MAP_EXIT, "S1_PZ_MAP_01");
        
        StageManager::addMap(0, MapManager::getMap("S1_PZ_MAP_01"));
        StageManager::addMap(0, MapManager::getMap("S1_JP_MAP_01"));

        currentMap = StageManager::getCurrentStage()->getCurrentMap();

        // ������ �ʱ�ȭ
        RenderManager::ScreenInit();
        RenderManager::setRenderMap(currentMap);
        RenderManager::renderMap();
        DoubleBufferManager::ScreenFlipping();

        // ĳ���� ���� �� �ʱ�ȭ
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
        //sisterCharacter->setJumpStrength(14.0f);

        GameObjectManager::createObejct("Dialog", "SC1_DL_01", "src\\dialog1.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_02", "src\\dialog2.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_03", "src\\dialog3.png");

        setMap(currentMap);

        RenderManager::addObject(sisterCharacter);
        RenderManager::addObject(playerCharacter);

        // �ʱ� ȭ�� ������
        RenderManager::renderObject();
        
        //�׽�Ʈ��
        Scene newScene;
        vector<Command> newCmds;
        Command newCmd;

        newCmd.addObject(playerCharacter); // ��� ������Ʈ ����

        for (int i = 0; i < 8; i++) {
            newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(0); });
            newCmds.push_back(newCmd);
            newCmd.setAction((function<void()>) [this]() { playerCharacter->move(); });
            newCmds.push_back(newCmd);
        }

        newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(-1); });
        newCmds.push_back(newCmd);
        for (int i = 0; i < 5; i++) {
            newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(0); });
            newCmds.push_back(newCmd);
            newCmd.setAction((function<void()>) [this]() { playerCharacter->move(); });
            newCmds.push_back(newCmd);
        }

        // ���������� �̵�
        newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(1); });
        newCmds.push_back(newCmd);
        for (int i = 0; i < 5; i++) {
            newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(0); });
            newCmds.push_back(newCmd);
            newCmd.setAction((function<void()>) [this]() { playerCharacter->move(); });
            newCmds.push_back(newCmd);
        }

        // ���������� �̵�
        for (int i = 0; i < 5; i++) {
            newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(4); });
            newCmds.push_back(newCmd);
            newCmd.setAction((function<void()>) [this]() { playerCharacter->move(); });
            newCmds.push_back(newCmd);
        }

        // ����
        for (int i = 0; i < 5; i++) {
            newCmd.setAction((function<void()>) [this]() { playerCharacter->setDx(0); });
            newCmds.push_back(newCmd);
            newCmd.setAction((function<void()>) [this]() { playerCharacter->move(); });
            newCmds.push_back(newCmd);
        }

        newCmd.addObject(GameObjectManager::getCharacter("SC1_DL_01"));
        newCmds.push_back(newCmd);
        newCmd.addObject(GameObjectManager::getCharacter("SC1_DL_02"));
        newCmds.push_back(newCmd);
        newCmd.addObject(GameObjectManager::getCharacter("SC1_DL_03"));
        newCmds.push_back(newCmd);


        // ��� ����� newScene�� �߰�
        for (auto& cmd : newCmds) {
            newScene.addCommand(cmd);
        }


        newScene.display();
       
        //�׽�Ʈ�� ��

    }

    void setMap(Map* _map) {
        currentMap = _map;

        if (currentMap->getType() == TYPE_PUZZLE) {
            HandlerManager::getPuzzleMapHandle(playerCharacter, StageManager::getCurrentStage(), (PuzzleMap*)currentMap);
        }
        else if (currentMap->getType() == TYPE_JUMP) {
            HandlerManager::getJumpMapHandle(playerCharacter, StageManager::getCurrentStage(), (JumpMap*)currentMap);
        }

        RenderManager::setRenderMap(currentMap);
        RenderManager::renderMap();

        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());
        sisterCharacter->SetStartPosition(currentMap->getInitX() - 18, currentMap->getInitY());

    }

    // ���� ���� ����
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
                    // ��Ÿ���� ������ ����
                    HandlerManager::processInput(VK_UP);
                    lastJumpTime = now;

                    if (currentMap->getType() == TYPE_JUMP)
                        actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = { ACTION_JUMP, playerCharacter->getDx() };
                }
                else {
                    // ��Ÿ���� �� ������ �������� ����
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

            // �浹 ó�� �� ���� ����
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

    // �������� �÷��̾� ĳ���͸� ���󰡵��� ��ġ ������Ʈ
    void updateSisterPosition() {
        // ����: �������� �÷��̾ ���� �Ÿ� �ڵ��� �̵��ϰ� ��
        int targetLeft = playerCharacter->getFootX() - offset;
        int targetRight = playerCharacter->getFootX() + offset;

        // �������� �÷��̾��� ���� �ȿ� �ִ��� Ȯ��
        if (!sisterCharacter->getisJumping())
        {
            if (sisterCharacter->getFootX() < targetLeft) {
                sisterCharacter->setDx(2.5);  // �÷��̾� ���ʿ� ���� �� ���������� �̵�
            }
            else if (sisterCharacter->getFootX() > targetRight) {
                sisterCharacter->setDx(-2.5); // �÷��̾� �����ʿ� ���� �� �������� �̵�
            }
            else {
                sisterCharacter->setDx(0);  // ���� ���� ���� �� ����
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

            // x ��ǥ�� �ٻ� �񱳸� ���� (tolerance�� 5�� ����)
            if (abs(sisterX - actionX) <= offset && abs(sisterY - actionY) <= offset / 2) {
                sisterCharacter->setDx(it->second.direction * 1.2); 
                if (it->second.actionType == ACTION_JUMP) {
                    sisterCharacter->jump();
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
            RenderManager::render();
            std::this_thread::sleep_for(std::chrono::milliseconds(threadTime)); // �� threadTime FPS
        }
    }

    // ���� ����
    void start() {
        // ���� ���� �� ������ ������ ����
        std::thread physicsThread(&GameManager::physicsLoop, this);
        std::thread renderThread(&GameManager::renderLoop, this);

        // ���� ���� ���� ó��
        //std::cin.get(); // ���� �Է� �� ����
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