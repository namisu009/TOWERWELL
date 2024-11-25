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

	//�������ϴ� �������
	// -> ���� �ذ� ������ �̸�
	//�������ϴ� �޼ҵ�
	// solvePuzzle
	//	-> isSolvedPuzzle && isSatisfyCondition && ��¼�� ��¼��
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
		//�ش� �̸��� �������� �÷��̾�� �����ϴ��� Ȯ���ϰ� ������ true
		//������ false
		if (itemArrayIdx >= puzzleCount)
			return true;

		string name = puzzleItemArray[itemArrayIdx];
 		if (name == "" || name != "" && player->getisItem(name)) { //����ڿ��� ���� �� �Ǵ� ������ ������ ���� ��
			player->uesItem(name); //������ ����ϰ� �ϱ�
			itemArrayIdx++; //���� ������ �ʿ��� ���������� �Ѿ��
			return true;
		}
		
		return false;
	}
};

#endif
