#ifndef _GAMEOBJECTMANAGER_H
#define _GAMEOBJECTMANAGER_H

#include<unordered_map>
#include "GameObject.h"
#include "Character.h"
#include "Dialog.h"

using namespace std;

class GameObjectManager
{
private:
	static unordered_map<const char*, GameObject*> objects;

public:
	static void createObejct(const char* type, const char* id, const char* filename) {
		GameObject* object = NULL;
		if (type == "Character") {
			object = new Character();
			object->setType(TYPE_CHARACTER);
		}
		else if (type == "Dialog") {
			object = new Dialog();
			object->setType(TYPE_DIALOG);
		}
		else {
			return;
		}

		object->initializeFromASCII(filename);
		addGameObject(id, object);
	}
	static void addGameObject(const char* id, GameObject* object) {
		objects[id] = object;
	}
	static GameObject* getObejct(const char* id) {
		return objects[id];
	}
	static Character* getCharacter(const char* id) {
		return (Character*) objects[id];
	}
	static Dialog* getDialog(const char* id) {
		return (Dialog*)objects[id];
	}
};


#endif