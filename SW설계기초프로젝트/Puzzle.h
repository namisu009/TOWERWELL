#pragma once
#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <string>
#include "GameObject.h"

class Scene;

class Puzzle : public GameObject {
    RenderArray* puzzleObjectArray[3];
    RenderArray* puzzleDetailArray[3];
    Scene* puzzleSceneArray[3];
    string puzzleRewardArray[3];

    int objectArrayIdx;
    int detailArrayIdx;
    int sceneArrayIdx;
    int rewardArrayIdx;

    int solvedPuzzleCount;
    int solvedThreshold;

    bool isSolved;

protected:
    static const int puzzleCount = 3;

public:
    Puzzle(std::string _id);
    ~Puzzle();

    void setPuzzleSceneDialog(int key, std::string cmd);
    void setPuzzleSceneAction(int key, std::string cmd, ActionType command, int dt);
    void setPuzzleSceneAction(int key, std::string cmd, ActionType command, int dt, int repeat);
    void setPuzzleSceneDelay(int key, std::string cmd, int time);
    bool isPuzzleSolved();
    void showPuzzleDetail();
    void setSolvedThreshold(int key);
    void setPuzzleReward(int key, string item);
    string getPuzzleReward();
    void setPuzzleObjectASCII(int key, const char* filename);
    void setPuzzleDetailASCII(int key, const char* filename);

    virtual void solvePuzzle();
    virtual bool isSatisfyCondition() { return false; };

    RenderArray* getObjectArray();
    RenderArray* getDetailArray();
};
#endif
