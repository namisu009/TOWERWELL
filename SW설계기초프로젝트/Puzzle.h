#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <string>
#include "ArtLoadManager.h";
#include "EventDispatcher.h";

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
	EventDispatcher& eventDispatcher;
public:
	Puzzle(EventDispatcher& dispatcher) : eventDispatcher(dispatcher) {
		puzzleCount = 0;
		artLoadManager->GetInstance();
	}

	void solvePuzzle() {
		// ������ �ذ�� ��� ó��
		eventDispatcher.dispatch(PUZZLE_SOLVED); // PUZZLE_SOLVED �̺�Ʈ ����
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
