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
	static EventDispatcher* eventDispatcher;

public:
	static void setEventDispatcher(EventDispatcher* dispatcher) {
		eventDispatcher = dispatcher;
	}
	static void createObject(const char* type, string id, const char* filename) {
		GameObject* object = NULL;
		if (type == "Character") {
			object = new Character(id);
			object->setType(TYPE_CHARACTER);
			object->initializeFromASCII(filename);
		}
		else if (type == "Dialog") {
			object = new Dialog(id, filename);
			object->initializeFromASCII("src\\SPEECH_WINDOW2.png");
			object->setType(TYPE_DIALOG);
		}
		else {
			return;
		}

		object->setEventDispatcher(eventDispatcher);
		addGameObject(id, object);
	}
	static void addGameObject(string id, GameObject* object) {
		objects[id] = object;
	}
	static GameObject* getObejct(string id) {
		return objects[id];
	}
	static Character* getCharacter(string id) {
		return dynamic_cast<Character*>(objects[id]);
	}

	static Dialog* getDialog(string id) {
		return dynamic_cast<Dialog*>(objects[id]);
	}

	
};


#endif