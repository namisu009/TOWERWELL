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
    Scene* puzzleNCLSceneArray[3]; //Ŭ���� �� ��
    

    string puzzleRewardArray[3];

    int objectArrayIdx;
    int detailArrayIdx;
    int cl_sceneArrayIdx;
    int ncl_sceneArrayIdx;
    int rewardArrayIdx;

    int solvedPuzzleCount;    // ������� �ذ�� ���� �ܰ� ��
    int solvedThreshold;      // �߰� �ذ� ���� �Ӱ谪
    int currentStep;          // ���� ���� ���� ���� �ܰ�

    bool isSolved;            // ���� �ذ� ����

protected:    
    
    RenderArray* solvedObjectArray;
    RenderArray* solvedDetailArray;
    Scene* completedScene;         // ���� ��ü �Ϸ� �� ������ Scene

    static const int puzzleCount = 3;


public:
    // ������ �� �Ҹ���
    Puzzle(string _id);
    ~Puzzle();

    // ���� Ȯ�� �޼���
    virtual bool isIntermediateSolved();  // �߰� �ذ� ���� ���� ���� Ȯ��

    // ���� ���� �޼���
    bool progressPuzzle();        // �߰� �ذ� ����
    bool solvePuzzle();           // ���� �ذ�
    bool isPuzzleSolved();        // ���� �ذ� ���� Ȯ��
    bool getIsSolved();        // ���� �ذ� ���� Ȯ��
    void PuzzleNCLSceneDisplay(); //�ذ� ������ �� ��������� ��

    // ���� ������ �� ���� ����
    void showPuzzleDetail();
    void setSolvedThreshold(int key);
    void setPuzzleReward(int key, string item);
    string getPuzzleReward();

    // ���� ���� ������ ����
    void setPuzzleObjectASCII(int key, const char* filename);
    void setPuzzleDetailASCII(int key, const char* filename);
    void setPuzzleSceneDialog(int type, int key, string cmd);
    void setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt);
    void setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt, int repeat);
    void setPuzzleSceneDelay(int type, int key, string cmd, int time);
    void setPuzzleSceneLoop(int type, int key, bool loop);

    void SetStartPosition(float init_x, float init_y) {
        setPosition(init_x, init_y);
    }

    void setCompletedObjectASCII(const char* filename);
    void setCompletedDetailASCII(const char* filename);
    void setCompletedSceneDetail(const char* filename);
    
    void setCompletedSceneDialog(string cmd);
    void setCompletedSceneAction(string cmd, ActionType command, int dt);
    void setCompletedSceneAction(string cmd, ActionType command, int dt, int repeat);
    void setCompletedSceneDelay(string cmd, int time);

    void setCompletedSceneVKSPACE();
    void setCompletedSceneLoop(bool loop);

    void showSolvedState();

    // ���� Ȯ�� �� �ذ�
    virtual bool isSatisfyCondition() { return false; }; // ���� ���� ���� Ȯ��
    RenderArray* getObjectArray();                       // ���� ������Ʈ �迭 ��������
    RenderArray* getDetailArray();                       // ���� ������ �迭 ��������
};

#endif
