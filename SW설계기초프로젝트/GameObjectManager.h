#ifndef _GAMEOBJECTMANAGER_H
#define _GAMEOBJECTMANAGER_H

#include<unordered_map>
#include "GameObject.h"

using namespace std;

class GameObjectManager
{
private:
	static unordered_map<const char*, GameObject*> objects;

public:
	static void createObejct(const char* id, const char* filename) {
		GameObject* object = new GameObject();
		object->initializeFromASCII(filename);
		addGameObject(id, object);
	}
	static void addGameObject(const char* id, GameObject* object) {
		objects[id] = object;
	}
	static GameObject* getObejct(const char* id) {
		return objects[id];
	}
};

#endif