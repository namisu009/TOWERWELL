#pragma once
#ifndef _READONLYPUZZLE_H_
#define _READONLYPUZZLE_H_

#include "Puzzle.h"
class ReadOnlyPuzzle : public Puzzle
{
public: //�ذ����� -> �׳� �б� (��������̵��ϸ� �� ����)
	ReadOnlyPuzzle(string _id) : Puzzle(_id) {

	}
};

#endif