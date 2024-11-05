#ifndef _PHYSICSMANAGER_H_
#define _PHYSICSMANAGER_H_

#include "GameObject.h"
#include "CollisionManager.h"

class PhysicsManager {
public:
    static void applyGravity(GameObject* object, Map* map) {
        const float gravity = 2.0f; // �߷��� ����

    
         object->setDy(object->getDy() + gravity); // �߷��� ���� Y �ӵ� ����
        
        if (CollisionManager::checkFloorCollision(*object, *map)) { // �ٴ��� ��
            object->setDy(object->getDy() - gravity);
            object->land(); // ���� ó��
        }
    }
};

#endif