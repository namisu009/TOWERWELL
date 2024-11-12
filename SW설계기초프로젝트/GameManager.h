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

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2; // XOR�� ����Ͽ� �ؽ� ����
    }
};


class GameManager
{
    atomic<bool> isRunning;

    EventDispatcher eventDispatcher;
    HandlerManager handlerManager;
    Character* playerCharacter;
    Character* sisterCharacter;

    int offset = 15;

    std::unordered_map<std::pair<int, int>, ActionType, pair_hash> actionPositions;
    Map* currentMap;

public:
    GameManager() : isRunning(true), playerCharacter(nullptr), sisterCharacter(nullptr), currentMap(nullptr) {
        HandlerManager::setEventDispatcher(&eventDispatcher);
    }

    void initialize() {
        // �� �ʱ�ȭ
        MapManager::createMap("S1_JP_MAP_01", TYPE_JUMP, "src\\S1_JUMP_MAP_01.png", "src\\S1_JUMP_MAP_INFO_01.png");
        MapManager::createMap("S1_PZ_MAP_01", TYPE_PUZZLE, "src\\S1_PUZZLE_MAP_01.png", "src\\S1_PUZZLE_MAP_INFO_01.png");
        currentMap = (PuzzleMap*)(MapManager::getMap("S1_PZ_MAP_01"));
        currentMap = (JumpMap*)(MapManager::getMap("S1_JP_MAP_01"));

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
        playerCharacter->SetStartPosition(currentMap->getInitX(), currentMap->getInitY());

        GameObjectManager::createObejct("Character", "Sister", "src\\sister_idle_01.png");
        sisterCharacter = GameObjectManager::getCharacter("Sister");
            
        sisterCharacter->setAnimation("IDLE", 1, "src\\sister_idle_02.png");
        sisterCharacter->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
        sisterCharacter->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");
        sisterCharacter->SetStartPosition(currentMap->getInitX() - 18, currentMap->getInitY());
        sisterCharacter->setJumpStrength(13.5f);

        GameObjectManager::createObejct("Dialog", "SC1_DL_01", "src\\dialog1.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_02", "src\\dialog2.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_03", "src\\dialog3.png");


        RenderManager::addObject(sisterCharacter);
        RenderManager::addObject(playerCharacter);

        setMap(currentMap);

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
            HandlerManager::getPuzzleMapHandle(playerCharacter, (PuzzleMap*)currentMap);
        }
        else if (currentMap->getType() == TYPE_JUMP) {
            HandlerManager::getJumpMapHandle(playerCharacter, (JumpMap*)currentMap);
        }
    }

    // ���� ���� ����
    void physicsLoop() {
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
                HandlerManager::processInput(VK_UP);
                actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = ACTION_JUMP;
                flag = 1;
            }
            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                HandlerManager::processInput(VK_SPACE);
                actionPositions[{playerCharacter->getFootX(), playerCharacter->getFootY()}] = ACTION_DASH;
                flag = 1;
            }

            playerCharacter->dashState();

            if (!flag) {
                playerCharacter->setDx(0);
            }

            // �浹 ó�� �� ���� ����
            while (CollisionManager::checkWallCollision(*playerCharacter, *currentMap)) {
                adjustPositionForCollision(playerCharacter);
            }
            PhysicsManager::applyGravity(playerCharacter, currentMap);

            while (CollisionManager::checkFloorCollision(*playerCharacter, *currentMap)) {
                adjustPositionForCollision(playerCharacter);
            }

            playerCharacter->move();
            updateSisterPosition();

            std::this_thread::sleep_for(std::chrono::milliseconds(60));
        }
    }

    // �������� �÷��̾� ĳ���͸� ���󰡵��� ��ġ ������Ʈ
    void updateSisterPosition() {
        // ����: �������� �÷��̾ ���� �Ÿ� �ڵ��� �̵��ϰ� ��
        int targetLeft = playerCharacter->getFootX() - offset;
        int targetRight = playerCharacter->getFootX() + offset;

        // �������� �÷��̾��� ���� �ȿ� �ִ��� Ȯ��
        if (sisterCharacter->getFootX() < targetLeft) {
            sisterCharacter->setDx(2);  // �÷��̾� ���ʿ� ���� �� ���������� �̵�
        }
        else if (sisterCharacter->getFootX() > targetRight) {
            sisterCharacter->setDx(-2); // �÷��̾� �����ʿ� ���� �� �������� �̵�
        }
        else {
            sisterCharacter->setDx(0);  // ���� ���� ���� �� ����
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
        auto sisterPos = std::make_pair(sisterCharacter->getX(), sisterCharacter->getY());
        int sisterX = sisterCharacter->getFootX();
        for (auto it = actionPositions.begin(); it != actionPositions.end();) {
            int actionX = it->first.first;

            // x ��ǥ�� �ٻ� �񱳸� ���� (tolerance�� 5�� ����)
            if (abs(sisterX - actionX) < 3) {
                sisterCharacter->setDx(playerCharacter->getX() - offset > sisterCharacter->getX() ? 4 : -4);
                if (it->second == ACTION_JUMP) {
                    sisterCharacter->jump();
                }
                else if (it->second == ACTION_DASH) {
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


    // ������ ����
    void renderLoop() {
        while (isRunning) {
            RenderManager::render();
            std::this_thread::sleep_for(std::chrono::milliseconds(60)); // �� 60 FPS
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