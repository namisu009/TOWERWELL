#include "CollisionManager.h"
#include "Character.h"

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

bool CollisionManager::checkWallCollision(GameObject* object, Map map) {
    int objectX = object->getX() + object->getDx();
    int objectY = object->getY() + object->getDy();

    object->setColX(0);
    object->setColY(0);

    for (int y = 0; y < object->getHeight(); ++y) {
        for (int x = 0; x < object->getWidth(); ++x) {
            if (map.isWall(objectX + x, objectY + y)){
                object->setColX(objectX + x);
                object->setColY(objectY + y);

                return true;
            }
        }
    }
    return false;
}


bool CollisionManager::checkFloorCollision(GameObject* object, Map map) {
    int objectX = object->getX() + object->getDx();
    int objectY = object->getY() + object->getDy();

    object->setColX(0);
    object->setColY(0);

    for (int y = 0; y < object->getHeight(); ++y) {
        for (int x = 0; x < object->getWidth(); ++x) {
            if (map.isFloor(objectX + x, objectY + y)) {
                object->setColX(objectX + x);
                object->setColY(objectY + y);
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
bool CollisionManager::checkWallAdjacent(GameObject object, JumpMap* map) {
    int objectX = object.getFootX();
    int objectY = object.getY();
    int objectWidth = object.getWidth() / 2;
    int objectHeight = object.getHeight();

    for (int y = 0; y < objectHeight; ++y) {
        for (int i = 0; i < 2; i++)
        {
            if (map->isClimbWall(objectX - objectWidth - i, objectY + y)) {
                return true;
            }
            if (map->isClimbWall(objectX + objectWidth + i, objectY + y)) {
                return true;
            }
        }
    }

    return false;
}
