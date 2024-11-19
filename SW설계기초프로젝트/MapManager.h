#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_

#include<unordered_map>
#include "Map.h"
#include "PuzzleMap.h"
#include "JumpMap.h"

using namespace std;

class MapManager
{
private:
	static unordered_map<string, Map*> maps;

public:
	static void createMap(string id, int type, const char* filename1, const char* filename2) {
		Map* map = nullptr;
		if (type == TYPE_PUZZLE) {
			map = new PuzzleMap();
		}
		else if (type == TYPE_JUMP) {
			map = new JumpMap();
		}
		else
			return;

		map->setType(type);
		map->setFile(filename1, filename2);
		addMap(id, map);
	}
	static void addMap(string id, Map* map) { //¸Ê Ãß°¡
		map->setMapId(id);
		maps.insert({ id, map });
	}
	static Map* getMap(string id) {
		return maps[id];
	}
	static PuzzleMap* getPuzzleMap(string id) {
		if (maps[id]->getType() == TYPE_PUZZLE)
			return (PuzzleMap*) maps[id];

		return nullptr;
	}
	static void setMapASCII(string id) {
		maps[id]->initializeFromASCII();
		maps[id]->initializeFromScreen();
	}
};

#endif