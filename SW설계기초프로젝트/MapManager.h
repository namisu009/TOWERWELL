#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_

#include<unordered_map>
#include "Map.h"

using namespace std;

class MapManager
{
private:
	static unordered_map<string, Map> maps;

public:
	static void createMap(string id, int type, const char* filename1, const char* filename2) {
		Map map;
		map.setType(type);
		map.initializeFromASCII(filename1);
		map.initializeFromScreen(filename2);
		addMap(id, map);
	}
	static void addMap(string id, Map map) { //¸ã Ãß°¡
		maps.insert({ id, map });
	}
	static Map* getMap(string id) {
		return &maps[id];
	}
};

#endif