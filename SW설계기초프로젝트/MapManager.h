#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_

#include<unordered_map>
#include "Map.h"

using namespace std;

class MapManager
{
private:
	static unordered_map<int, Map> maps;

public:
	static void createMap(int id, const char* filename) {
		Map map;
		map.initializeFromASCII(filename);
		addMap(id, map);
	}
	static void addMap(int id, Map map) { //¸ã Ãß°¡
		maps.insert({ id, map });
	}
	static Map* getMap(int id) {
		return &maps[id];
	}
};

#endif