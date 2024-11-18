#pragma once
#ifndef _READONLYPUZZLE_H_
#define _READONLYPUZZLE_H_

#include "Puzzle.h"
class ReadOnlyPuzzle : public Puzzle
{
public: //해결조건 -> 그냥 읽기 (겟퍼즐아이디하면 끝 ㅇㅇ)
	ReadOnlyPuzzle(string _id) : Puzzle(_id) {

	}

public:
	bool isSatisfyCondition() {
		// 읽기 전용이기 때문에 항상 true
		return true;
	}
};

#endif