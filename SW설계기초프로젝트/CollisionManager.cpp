#include "CollisionManager.h"

bool CollisionManager::checkCollision(GameObject obj1, GameObject obj2) {
    return (obj1.getX() < obj2.getX() + obj2.getWidth() &&
        obj1.getX() + obj1.getWidth() > obj2.getX() &&
        obj1.getY() < obj2.getY() + obj2.getHeight() &&
        obj1.getY() + obj1.getHeight() > obj2.getY());
}

bool CollisionManager::checkMapCollision(GameObject object, Map map) {
    int objectX = object.getX() + object.getDx();
    int objectY = object.getY() + object.getDy();

    for (int y = 0; y < object.getHeight(); ++y) {
        for (int x = 0; x < object.getWidth(); ++x) {
            if ((map.isWall(objectX + x, objectY + y) || map.isFloor(objectX + x, objectY + y))) {
                return true; // 벽 또는 바닥에 충돌함
            }
        }
    }
    return false;
}

bool CollisionManager::checkWallCollision(GameObject object, Map map) {
    int objectX = object.getX() + object.getDx();
    int objectY = object.getY() + object.getDy();

    for (int y = 0; y < object.getHeight(); ++y) {
        for (int x = 0; x < object.getWidth(); ++x) {
            if (map.isWall(objectX + x, objectY + y)) {
                return true;
            }
        }
    }
    return false;
}


bool CollisionManager::checkFloorCollision(GameObject object, Map map) {
    int objectX = object.getX() + object.getDx();
    int objectY = object.getY() + object.getDy();

    for (int y = 0; y < object.getHeight(); ++y) {
        for (int x = 0; x < object.getWidth(); ++x) {
            if (map.isFloor(objectX + x, objectY + y)) {
                return true;
            }
        }
    }

    return false; // 바닥과 충돌하지 않음
}

bool CollisionManager::checkTrapCollision(GameObject object, JumpMap* jumpMap) {
    if (!jumpMap) return false;

    int objectX = object.getFootX() - object.getWidth() / 2;
    int objectY = object.getFootY() - object.getHeight() - 3;

    for (int y = 0; y < object.getHeight(); ++y) {
        for (int x = 0; x < object.getWidth(); ++x) {
            if (jumpMap->isTrap(objectX + x, objectY + y)) {
                return true;
            }
        }
    }

    return false;
}
