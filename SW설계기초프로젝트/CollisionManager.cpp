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
                return true; // �� �Ǵ� �ٴڿ� �浹��
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
            if (map.isWall(objectX + x, objectY + y)) {
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

    return false; // �ٴڰ� �浹���� ����
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
    int objectX = object.getX();
    int objectY = object.getY();
    int objectWidth = object.getWidth();
    int objectHeight = object.getHeight();
    if (objectX < 0 || objectY < 0 || objectX + objectWidth - 2 > map->getWidth() || objectY + objectHeight >= map->getHeight() || objectX + (objectWidth / 2) > map->getWidth()) {
        return false;
    }

    for (int y = 0; y < objectHeight; ++y) {
        if (map->isClimbWall(objectX + objectWidth, objectY + y)) {
            return true;
        }
        if (map->isClimbWall(objectX - 1, objectY + y)) {
            return true;
        }
    }



    return false;
}
