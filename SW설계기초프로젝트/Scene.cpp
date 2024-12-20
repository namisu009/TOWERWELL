#include "scene.h"
#include "StageManager.h"
#include <thread>
#include <conio.h>
#include <windows.h>

Scene::Scene() : sceneLoop(true) {}

void Scene::setSceneLoop(bool _b) {
    sceneLoop = _b;
}

int Scene::getCmdSize() {
    return commands.size();
}

void Scene::setRenderCharacter(string key) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key]() mutable { RenderManager::addObject(GameObjectManager::getCharacter(key)); });
    commands.push(cmd);
}

void Scene::removeRenderCharacter(string key) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key]() mutable { RenderManager::removeObject(GameObjectManager::getCharacter(key)); });
    commands.push(cmd);
}

void Scene::setDialog(string key) {
    Command cmd;
    cmd.setObject(GameObjectManager::getDialog(key));
    commands.push(cmd);
}

void Scene::setDeath(string key, bool t) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key, t]() mutable {
        GameObjectManager::getCharacter(key)->setDeathState(t);
        int _y = GameObjectManager::getCharacter("Hero")->getY();
        _y += GameObjectManager::getCharacter("Hero")->getHeight();
        _y = _y - GameObjectManager::getCharacter("Sister")->getHeight();
        GameObjectManager::getCharacter(key)->setY(_y);
        });
    commands.push(cmd);
}

void Scene::setCarry(string key, bool t) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key, t]() mutable {
        GameObjectManager::getCharacter(key)->setCarryState(t);
        });
    commands.push(cmd);
}

void Scene::setVKSPACE() {
    Command cmd;
    cmd.setType(TYPE_SCREEN);
    cmd.setAction([cmd]() mutable {
        while (_kbhit()) {
            _getch();
        }
        while (1) {
            if (_kbhit()) {
                int key = _getch();
                if (key == 32) {
                    break;
                }
            }
        }
        });
    commands.push(cmd);
}

void Scene::setScreen(const char* key) {
    Command cmd;

    Map* map = new Map();
    map->initializeFromASCII(key);
    map->setMapId("SCREEN");

    cmd.setMap(map);
    cmd.setType(TYPE_SCREEN);
    cmd.setAction([cmd]() mutable {
        RenderManager::setRenderMap(cmd.getMap());
        });

    commands.push(cmd);
}

void Scene::setDetail(const char* key) {
    Command cmd;

    GameObject* obj = nullptr;

    if (key != "") {
        obj = new GameObject("Detail");
        obj->initializeFromASCII(key);
        obj->SetStartPosition(0, 0);
        obj->setType(TYPE_DETAIL);
        cmd.setObject(obj);
    }

    cmd.setType(TYPE_DETAIL);
    commands.push(cmd);
}

void Scene::setCharacterPositionX(string key, int x) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key, x]() mutable {
        if (x >= 0)
            cmd.getObject()->setX(x);
        });
    commands.push(cmd);
}

void Scene::setCharacterStartPosition(string key, int x) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key, x]() mutable {
        Map* map = StageManager::getCurrentStage()->getCurrentMap();
        int ix = map->getInitX();
        int iy = map->getInitY();
        GameObjectManager::getCharacter(key)->SetStartPosition(ix, iy);
        GameObjectManager::getCharacter(key)->setX(x);
        });
    commands.push(cmd);
}

void Scene::setCharacterPosition(string key, int x, int y) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key, x, y]() mutable {
        if (y == 0 && key == "Hood") {
            int _y = GameObjectManager::getCharacter("Hero")->getY();
            _y += GameObjectManager::getCharacter("Hero")->getHeight();
            y = _y - GameObjectManager::getCharacter("Hood")->getHeight();
        }
        else if (y == 0) {
            y = GameObjectManager::getCharacter(key)->getY();
        }

        if (y >= 0)
            cmd.getObject()->setY(y);
        if (x >= 0)
            cmd.getObject()->setX(x);
        });
    commands.push(cmd);
}

void Scene::setAction(string key, ActionType command, int dt, int repeat) {
    for (int i = 0; i < repeat; i++)
        setAction(key, command, dt);
}

void Scene::setAction(string key, ActionType command, int dt) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    if (command == ACTION_MOVE_X)
        cmd.setAction([cmd, dt]() mutable { cmd.getObject()->setDx(dt); });
    else if (command == ACTION_MOVE_Y)
        cmd.setAction([cmd, dt]() mutable { cmd.getObject()->setDy(dt); });
    else
        return;

    commands.push(cmd);

    cmd.setAction([cmd, dt]() mutable { cmd.getObject()->move(); });
    commands.push(cmd);
}

void Scene::setAction(string key1, string key2, ActionType command, int dt) {
    Command cmd1, cmd2;
    cmd1.setObject(GameObjectManager::getCharacter(key1));
    cmd2.setObject(GameObjectManager::getCharacter(key2));
    if (command == ACTION_MOVE_X) {
        cmd1.setAction([cmd1, dt]() mutable { cmd1.getObject()->setDx(dt); });
        cmd2.setAction([cmd2, dt]() mutable { cmd2.getObject()->setDx(dt); });
    }
    else if (command == ACTION_MOVE_Y) {
        cmd1.setAction([cmd1, dt]() mutable { cmd1.getObject()->setDy(dt); });
        cmd2.setAction([cmd2, dt]() mutable { cmd2.getObject()->setDy(dt); });
    }
    else {
        return;
    }

    commands.push(cmd1);
    commands.push(cmd2);

    cmd1.setAction([cmd1, dt]() mutable { cmd1.getObject()->move(); });
    cmd2.setAction([cmd2, dt]() mutable { cmd2.getObject()->move(); });

    commands.push(cmd1);
    commands.push(cmd2);
}

void Scene::setAction(string key1, string key2, ActionType command, int dt, int repeat) {
    for (int i = 0; i < repeat; i++)
        setAction(key1, key2, command, dt);
}

void Scene::setDelay(string key, int time) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, time]() mutable { Sleep(time); });
    commands.push(cmd);
}

void Scene::setRenderHood(string key, bool t) {
    Command cmd;
    cmd.setObject(GameObjectManager::getCharacter(key));
    cmd.setAction([cmd, key, t]() mutable {
        GameObjectManager::getCharacter(key)->setHood(t);
        });
    commands.push(cmd);
}

Command Scene::popCommand() {
    Command cmd = commands.front();
    commands.pop();

    if (sceneLoop) {
        commands.push(cmd);
    }

    return cmd;
}

void Scene::clearInputBuffer() {
    while (_kbhit()) {
        _getch();
    }
}

void Scene::display() {
    int size = commands.size();
    clearInputBuffer();

    while (size) {
        Command cmd = popCommand();

        if (cmd.getType() == TYPE_CHARACTER || cmd.getType() == TYPE_SCREEN) {
            if (!sceneLoop && cmd.getType() == TYPE_SCREEN && RenderManager::getRenderMap()->getMapId() == "SCREEN") {
                // delete RenderManager::getRenderMap();
            }

            cmd.getAction()();
            Sleep(10);
        }   
        else if (cmd.getType() == TYPE_DIALOG) {
            RenderManager::setRenderDialog((Dialog*)cmd.getObject());
            clearInputBuffer();
        }
        else if (cmd.getType() == TYPE_DETAIL) {
            if (cmd.getObject() == nullptr && !sceneLoop) {
                // delete RenderManager::getRenderDetail();
            }
            RenderManager::setRenderDetail(cmd.getObject());
            Sleep(100);
        }

        RenderManager::render();
        RenderManager::setRenderDialog(nullptr);

        size--;
    }
    clearInputBuffer();
}
