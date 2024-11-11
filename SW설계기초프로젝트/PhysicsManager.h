#ifndef _PHYSICSMANAGER_H_
#define _PHYSICSMANAGER_H_

#include "GameObject.h"
#include "Character.h"
#include "CollisionManager.h"


class PhysicsManager {
public:
    static void applyGravity(Character* object, Map* map) {
        const float gravity = 2.0f; // 중력의 세기

    
         object->setDy(object->getDy() + gravity); // 중력을 더해 Y 속도 증가
        
        if (CollisionManager::checkFloorCollision(*object, *map)) { // 바닥일 때
            object->setDy(object->getDy() - gravity);
            object->land(); // 착지 처리
        }
    }
};

#endif