#ifndef _GAMEOBJECTMANAGER_H
#define _GAMEOBJECTMANAGER_H

#include<unordered_map>
#include<string>
#include "GameObject.h"
#include "Character.h"
#include "Dialog.h"

using namespace std;

class GameObjectManager
{
private:
	static unordered_map<string, GameObject*> objects;

public:
	static void createObejct(const char* type, string id, const char* filename) {
		GameObject* object = NULL;
		if (type == "Character") {
			object = new Character(id);
			object->setType(TYPE_CHARACTER);
		}
		else if (type == "Dialog") {
			object = new Dialog(id);
			object->setType(TYPE_DIALOG);
		}
		else {
			return;
		}

		object->initializeFromASCII(filename);
		addGameObject(id, object);
	}
	static void addGameObject(string id, GameObject* object) {
		objects[id] = object;
	}
	static GameObject* getObejct(string id) {
		return objects[id];
	}
	static Character* getCharacter(string id) {
		return (Character*) objects[id];
	}
	static Dialog* getDialog(string id) {
		return (Dialog*)objects[id];
	}
};


#endif