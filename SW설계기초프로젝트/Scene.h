#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <queue>
#include "Command.h"
#include "GameObjectManager.h"
#include "RenderManager.h"
#include <thread>

class Puzzle; // 穿号 識情
class StageManager; // 穿号 識情

using namespace std;

class Scene {
private:
    bool sceneLoop;
    queue<Command> commands;

public:
    Scene();
    void setSceneLoop(bool _b);
    int getCmdSize();
    void setRenderCharacter(string key);
    void removeRenderCharacter(string key);
    void setDialog(string key);
    void setDeath(string key, bool t);
    void setCarry(string key, bool t);
    void setVKSPACE();
    void setScreen(const char* key);
    void setDetail(const char* key);
    void setCharacterPositionX(string key, int x);
    void setCharacterStartPosition(string key, int x);
    void setCharacterPosition(string key, int x, int y);
    void setAction(string key, ActionType command, int dt, int repeat);
    void setAction(string key, ActionType command, int dt);
    void setAction(string key1, string key2, ActionType command, int dt);
    void setAction(string key1, string key2, ActionType command, int dt, int repeat);
    void setDelay(string key, int time);
    void setRenderHood(string key, bool t);
    Command popCommand();
    void clearInputBuffer();
    void display();
};

#endif // _SCENE_H_
