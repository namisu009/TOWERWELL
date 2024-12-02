#ifndef _JUMPMAP_H_
#define _JUMPMAP_H_
#include "Map.h"
#include "Map.h"

class JumpMap : public Map
{
public:
	JumpMap() {
		setType(TYPE_JUMP);
	}

    bool isTrap(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        return myScreen.MapInfo[y][x] == JUMP_TRAP;
    }

    bool isClimbWall(int x, int y) {
        ScreenArray myScreen = getScreenArray();
        return myScreen.MapInfo[y][x] == JUMP_WALL;
    }

};

#endif
