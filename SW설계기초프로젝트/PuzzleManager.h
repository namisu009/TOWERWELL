#ifndef _PUZZLEMANAGER_H_
#define _PUZZLEMANAGER_H_

#include "Puzzle.h"
#include "RenderStruct.h"
#include <unordered_map>
#include <string>

using namespace std;
class PuzzleManager
{
	static unordered_map<string, Puzzle*> puzzles;

public:
	static void createPuzzle(string id, int type, const char * filename) {
		if (type == TYPE_READ_PUZZLE) {

		}
		else if (type == TYPE_ITEM_PUZZLE) {

		}
		else if (type == TYPE_NUMBER_PUZZLE) {

		}
	}
};

#endif
