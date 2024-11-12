
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include<unordered_map>
#include "Scene.h"

using namespace std;

class SceneMananger
{
	static unordered_map<string, Scene> scenes;
	static unordered_map<string, bool> scenePlayed;
public:
	static void addScene(string id, Scene scene) { //¾À Ãß°¡
		scenes.insert({ id, scene });
		scenePlayed[id] = false;
	}
	static Scene* getScene(string id) {
		if (scenePlayed[id]) return nullptr;
		scenePlayed[id] = true;
		return &scenes[id];
	}
};

#endif

