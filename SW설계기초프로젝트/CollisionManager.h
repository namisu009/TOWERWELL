#ifndef _COLLISIONMANAGER_H_
#define _COLLISIONMANAGER_H_

#include "Map.h"
#include "JumpMap.h"
#include "GameObject.h"

class CollisionManager
{
public:
    static bool checkCollision(GameObject obj1, GameObject obj2); // �� ��ü�� �浹 üũ
    static bool checkMapCollision(GameObject object, Map map);
    static bool checkFloorCollision(GameObject* object, Map map);
    static bool checkWallCollision(GameObject* object, Map map);
    static bool checkTrapCollision(GameObject object, JumpMap* jumpMap);
    static bool checkWallAdjacent(GameObject object, JumpMap* map);

};


#endif