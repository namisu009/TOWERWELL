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
	RenderArray* puzzleObejctArray[puzzleCount]; //���� ������Ʈ (�ʿ� �׷��� ����)
	RenderArray* puzzleDetailArray[puzzleCount]; //���� �� ����
	Scene* puzzleSceneArray[puzzleCount]; //���� ��
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
		// ������ �ذ�� ��� ó��
		eventDispatcher.dispatch(PUZZLE_SOLVED); // PUZZLE_SOLVED �̺�Ʈ ����
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
