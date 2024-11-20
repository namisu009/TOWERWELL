#pragma once
#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <string>
#include "GameObject.h"

class Scene;
using namespace std;

class Puzzle : public GameObject {
private:
    RenderArray* puzzleObjectArray[3];
    RenderArray* puzzleDetailArray[3];
    Scene* puzzleCLSceneArray[3];
    Scene* puzzleNCLSceneArray[3]; //클리어 전 씬
    string puzzleRewardArray[3];

    int objectArrayIdx;
    int detailArrayIdx;
    int cl_sceneArrayIdx;
    int ncl_sceneArrayIdx;
    int rewardArrayIdx;

    int solvedPuzzleCount;    // 현재까지 해결된 퍼즐 단계 수
    int solvedThreshold;      // 중간 해결 조건 임계값
    int currentStep;          // 현재 진행 중인 퍼즐 단계

    bool isSolved;            // 최종 해결 여부

protected:
    static const int puzzleCount = 3;

public:
    // 생성자 및 소멸자
    Puzzle(string _id);
    ~Puzzle();

    // 상태 확인 메서드
    bool isIntermediateSolved();  // 중간 해결 조건 충족 여부 확인
    bool isPuzzleSolved();        // 최종 해결 여부 확인

    // 퍼즐 진행 메서드
    bool progressPuzzle();        // 중간 해결 진행
    bool solvePuzzle();           // 최종 해결
    void PuzzleNCLSceneDisplay(); //해결 못했을 때 보여줘야할 씬


    // 퍼즐 디테일 및 보상 관리
    void showPuzzleDetail();
    void setSolvedThreshold(int key);
    void setPuzzleReward(int key, string item);
    string getPuzzleReward();

    // 퍼즐 관련 데이터 설정
    void setPuzzleObjectASCII(int key, const char* filename);
    void setPuzzleDetailASCII(int key, const char* filename);
    void setPuzzleSceneDialog(int type, int key, string cmd);
    void setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt);
    void setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt, int repeat);
    void setPuzzleSceneDelay(int type, int key, string cmd, int time);

    // 조건 확인 및 해결
    virtual bool isSatisfyCondition() { return false; }; // 조건 만족 여부 확인
    RenderArray* getObjectArray();                       // 현재 오브젝트 배열 가져오기
    RenderArray* getDetailArray();                       // 현재 디테일 배열 가져오기
};

#endif
