#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <string>
#include "ArtLoadManager.h";
#include "EventDispatcher.h";
#include "Scene.h";

class Puzzle
{
	static const int puzzleCount = 3;
	ArtLoadManager* artLoadManager;
	RenderArray* puzzleObejctArray[puzzleCount]; //ÆÛÁñ ¿ÀºêÁ§Æ® (¸Ê¿¡ ±×·ÁÁú ÆÛÁñ)
	RenderArray* puzzleDetailArray[puzzleCount]; //ÆÛÁñ »ó¼¼ Á¤º¸
	Scene* puzzleSceneArray[puzzleCount]; //ÆÛÁñ ¾À
	int solvedPuzzleCount;
	int type;
	int width;
	int height;
	float x, y;
	float dx, dy;
	EventDispatcher& eventDispatcher;
public:
	Puzzle(EventDispatcher& dispatcher) : eventDispatcher(dispatcher) {
		solvedPuzzleCount = 0;
		width = 0; height = 0;
		x = 0; y = 0; dx = 0; dy = 0;
		artLoadManager->GetInstance();
	}

	void setCondition() {
		
	}

	void solvePuzzle() {
		// ÆÛÁñÀÌ ÇØ°áµÈ °æ¿ì Ã³¸®
		eventDispatcher.dispatch(PUZZLE_SOLVED); // PUZZLE_SOLVED ÀÌº¥Æ® Àü¼Û
	}

	void initializeFromObjectASCII(int cnt, const char* filename) {
		if (cnt >= puzzleCount)
			return;

		artLoadManager->RenderArrayLoad(puzzleObejctArray[cnt], filename); // 0 1 2
	}

	void initializeFromDetailASCII(int cnt, const char* filename) {
		if (cnt >= puzzleCount)
			return;

		artLoadManager->RenderArrayLoad(puzzleDetailArray[cnt], filename); // 0 1 2
	}

	void initializeFromScene(int cnt, const char* filename) {
		if (cnt >= puzzleCount)
			return;

		artLoadManager->RenderArrayLoad(puzzleObejctArray[cnt], filename); // 0 1 2
	}

	void setType(int _type)
	{
		type = _type;
	}
	
};

#endif
