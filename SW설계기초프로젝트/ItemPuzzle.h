#ifndef _ITEMPUZZLE_H_
#define _ITEMPUZZLE_H_

#include <string>
#include "ItemManager.h"
#include "Puzzle.h"
#include "Character.h"

class ItemPuzzle : public Puzzle
{
	string puzzleItemArray[3];
	int itemArrayIdx;

	//만들어야하는 멤버변수
	// -> 퍼즐 해결 아이템 이름
	//만들어야하는 메소드
	// solvePuzzle
	//	-> isSolvedPuzzle && isSatisfyCondition && 어쩌고 저쩌고
	// isSatisfyCondition()
public:
	ItemPuzzle(string _id) : Puzzle(_id) {
		itemArrayIdx = 0;
		for (int i = 0; i < puzzleCount; ++i) {
			puzzleItemArray[i] = "";
		}
	}

	void setPuzzleConditionItem(int key, string name) {
		puzzleItemArray[key] = name;
	}

	bool isSatisfyCondition(Character* player) {
		//해당 이름의 아이템이 플레이어에게 존재하는지 확인하고 있으면 true
		//없으면 false
		if (itemArrayIdx >= puzzleCount)
			return true;

		string name = puzzleItemArray[itemArrayIdx];
 		if (name == "" || name != "" && player->getisItem(name)) { //사용자에게 있을 때 또는 아이템 조건이 없을 때
			player->uesItem(name); //아이템 사용하게 하기
			itemArrayIdx++; //다음 문제의 필요한 아이템으로 넘어가기
			return true;
		}
		
		return false;
	}
};

#endif
