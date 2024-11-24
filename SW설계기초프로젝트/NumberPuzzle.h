#ifndef _NUMBERPUZZLE_H_
#define _NUMBERPUZZLE_H_

#include <string>
#include "ItemManager.h"
#include "Puzzle.h"
#include "Character.h"

class NumberPuzzle : public Puzzle
{
	int correctAnswer[4];
	int userAnswer[4];
	int correctAnswerIdx;
	int userAnswerIdx;

public:
	NumberPuzzle(string _id) : Puzzle(_id) {
		correctAnswerIdx = 0;
		userAnswerIdx = 0;
		for (int i = 0; i < puzzleCount; ++i) {
			correctAnswer[i] = 0;
			userAnswer[i] = 0;
		}
	}

	void setCorrectAnswer(int n) {
		if (correctAnswerIdx >= 4) return;

		correctAnswer[correctAnswerIdx] = n;
		correctAnswerIdx++;
	}

	bool setAnswer(const vector<int>& answer) {
		int size = answer.size();

		if (size > correctAnswerIdx) {
			return false;
		}

		userAnswerIdx = size;
		for(int i = 0; i < size; i++)
			userAnswer[i] = answer[i];

		return true;
	}

	bool isSatisfyCondition() {
		int cnt = 0;
		if (correctAnswerIdx != userAnswerIdx) 
			return false;

		for(int i = 0; i < correctAnswerIdx; i++) {
			if (correctAnswer[i] == userAnswer[i])
				cnt++;
		}

		if (cnt == correctAnswerIdx)
			return true;
		else
			return false;

	}
};

#endif
