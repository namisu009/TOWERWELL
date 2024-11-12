#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <string>
#include "ArtLoadManager.h";
class Puzzle
{
	ArtLoadManager* artLoadManager;
	RenderArray* renderArray[5];
	int puzzleCount;
	int type;
	int width;
	int height;
	float x, y;
	float dx, dy;
public:
	Puzzle() {
		puzzleCount = 0;
		artLoadManager->GetInstance();
	}

	void initializeFromASCII(const char* filename) {
		if (puzzleCount >= 5)
			return;

		artLoadManager->RenderArrayLoad(renderArray[puzzleCount], filename);
	}

	void setType(int _type)
	{
		type = _type;
	}
	
};

#endif
