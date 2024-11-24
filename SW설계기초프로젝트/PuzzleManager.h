#ifndef _PUZZLEMANAGER_H_
#define _PUZZLEMANAGER_H_

#include "Puzzle.h"
#include "RenderStruct.h"
#include "ReadOnlyPuzzle.h"
#include "ItemPuzzle.h"
#include "NumberPuzzle.h"
#include <unordered_map>
#include <string>

using namespace std;
class PuzzleManager
{
	static unordered_map<string, Puzzle*> puzzles;

public:
	static void createPuzzle(string id, int type) {
        Puzzle* puzzle = NULL;

		if (type == TYPE_READ_PUZZLE) {
            puzzle = new ReadOnlyPuzzle(id);
		}
		else if (type == TYPE_ITEM_PUZZLE) {
            puzzle = new ItemPuzzle(id);
		}
		else if (type == TYPE_NUMBER_PUZZLE) {
            puzzle = new NumberPuzzle(id);
		}

        puzzle->setType(type);
        addPuzzle(id, puzzle);
	}

    static void addPuzzle(string id, Puzzle* puzzle) {
        puzzles[id] = puzzle;
    }

    static Puzzle* getPuzzle(string id) {

        if (puzzles.find(id) != puzzles.end()) {
            return puzzles[id];
        }
        else {
            return nullptr;
        }
    }

    static ItemPuzzle* getItemPuzzle(string id) {
        if (puzzles.find(id) != puzzles.end() && puzzles[id]->getType() == TYPE_ITEM_PUZZLE) {
            return (ItemPuzzle*)puzzles[id];
        }
        else {
            return nullptr;
        }
    }


    static void setEventDispatcher(string id, EventDispatcher* dispatcher) {
        puzzles[id]->setEventDispatcher(dispatcher);
    }

    static void setPuzzleObjectASCII(string id, int key, const char* filename) {
        puzzles[id]->setPuzzleObjectASCII(key, filename);
        puzzles[id]->setSolvedThreshold(key);
    }

    static void setPuzzleDetailASCII(string id, int key, const char* filename) {
        puzzles[id]->setPuzzleDetailASCII(key, filename);
        puzzles[id]->setSolvedThreshold(key);
    }

    static void setPuzzleSceneDialog(string id, int type, int key, string cmd) {
        puzzles[id]->setPuzzleSceneDialog(type, key, cmd);
        puzzles[id]->setSolvedThreshold(key);
    }

    static void setPuzzleSceneAction(string id, int type, int key, string cmd, ActionType command, int dt) {
        puzzles[id]->setPuzzleSceneAction(type, key, cmd, command, dt);
        puzzles[id]->setSolvedThreshold(key);
    }

    static void setPuzzleSceneAction(string id, int type, int key, string cmd, ActionType command, int dt, int repeat) {
        puzzles[id]->setPuzzleSceneAction(type, key, cmd, command, dt, repeat);
        puzzles[id]->setSolvedThreshold(key);
    }

    static void setPuzzleSceneDelay(string id, int type, int key, string cmd, int time) {
        puzzles[id]->setPuzzleSceneDelay(type, key, cmd, time);
        puzzles[id]->setSolvedThreshold(key);
    }

    static void setPuzzleReward(string id, int key, string reward) {
        puzzles[id]->setPuzzleReward(key, reward);
    }

    static void setPuzzleConditionItem(string id, int key, string name) {
        if (puzzles[id]->getType() == TYPE_ITEM_PUZZLE) {
            ((ItemPuzzle*)puzzles[id])->setPuzzleConditionItem(key, name);
        }
    }

    static void setCorrectAnswer(string id, int n) {
        if (puzzles[id]->getType() == TYPE_NUMBER_PUZZLE) {
            ((NumberPuzzle*)puzzles[id])->setCorrectAnswer(n);
        }
    }

};

#endif
