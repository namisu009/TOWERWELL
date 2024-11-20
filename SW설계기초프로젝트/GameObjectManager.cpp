#include "GameObjectManager.h"

unordered_map<string, GameObject*> GameObjectManager::objects;
EventDispatcher* GameObjectManager::eventDispatcher;
