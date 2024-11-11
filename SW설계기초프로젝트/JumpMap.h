#ifndef _JUMPMAP_H_
#define _JUMPMAP_H_
#include "Map.h"

class JumpMap : public Map
{
public:
	bool isTrap(int x, int y) {
		ScreenArray myScreen = getScreenArray();
		if (myScreen.MapInfo[y + 1][x] == JUMP_TRAP) return true;
		return false;
	}
};

#endif
