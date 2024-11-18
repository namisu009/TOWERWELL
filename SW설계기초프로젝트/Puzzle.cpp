#include "Puzzle.h"
#include "Scene.h"
#include "RenderManager.h"

Puzzle::Puzzle(string _id) : GameObject(_id) {
    objectArrayIdx = 0;
    detailArrayIdx = 0;
    sceneArrayIdx = 0;
    rewardArrayIdx = 0;
    solvedThreshold = 0;
    solvedPuzzleCount = 0;
    isSolved = false;
    for (int i = 0; i < puzzleCount; ++i) {
        puzzleObjectArray[i] = nullptr; // ������ �ʱ�ȭ
        puzzleDetailArray[i] = nullptr; // ������ �ʱ�ȭ
        puzzleSceneArray[i] = nullptr; // ������ �ʱ�ȭ
        puzzleRewardArray[i] = "";
    }
}

Puzzle::~Puzzle() {
    for (int i = 0; i < puzzleCount; ++i) {
        delete puzzleObjectArray[i]; // ���� �޸� ����
        puzzleObjectArray[i] = nullptr; // ���� ���� ����

        delete puzzleDetailArray[i]; // ���� �޸� ����
        puzzleDetailArray[i] = nullptr; // ���� ���� ����

        delete puzzleSceneArray[i]; // ���� �޸� ����
        puzzleSceneArray[i] = nullptr; // ���� ���� ����
    }
}


void Puzzle::solvePuzzle() {
    if (!isPuzzleSolved() && solvedPuzzleCount < puzzleCount && puzzleSceneArray[solvedPuzzleCount] != nullptr) {
        puzzleSceneArray[solvedPuzzleCount]->display();
        solvedPuzzleCount++;

        if (objectArrayIdx < 2 && puzzleObjectArray[objectArrayIdx + 1] != nullptr)
            objectArrayIdx++;

        if (detailArrayIdx < 2 && puzzleDetailArray[detailArrayIdx + 1] != nullptr)
            detailArrayIdx++;

        if (sceneArrayIdx < 2)
            sceneArrayIdx++;

        isPuzzleSolved();
    }
}

void Puzzle::setPuzzleReward(int key, string name) {
    puzzleRewardArray[key] = name;
}

string Puzzle::getPuzzleReward() {
    if (rewardArrayIdx >= solvedThreshold) {
        return "";
    }

    string n = puzzleRewardArray[rewardArrayIdx];
    rewardArrayIdx++;
    return n;
}

bool Puzzle::isPuzzleSolved() {
    if (!isSolved && solvedThreshold < solvedPuzzleCount) {
        isSolved = true;
        eventDispatcher->dispatch(PUZZLE_SOLVED); // PUZZLE_SOLVED �̺�Ʈ ����
    }
    return isSolved;
}

void Puzzle::showPuzzleDetail() {
    RenderManager::setRenderPuzzleDetail(getId());
    RenderManager::render();
}

void Puzzle::setSolvedThreshold(int key) {
    if (solvedThreshold < key)
        solvedThreshold = key;
}

void Puzzle::setPuzzleObjectASCII(int key, const char* filename) {
    if (key >= puzzleCount || key < 0)
        return;

    if (puzzleObjectArray[key] == nullptr)
        puzzleObjectArray[key] = new RenderArray();

    artLoadManager->RenderArrayLoad(puzzleObjectArray[key], filename);
}

// ���� ������ ASCII ���� �Լ�
void Puzzle::setPuzzleDetailASCII(int key, const char* filename) {
    if (key >= puzzleCount || key < 0)
        return;

    if (puzzleDetailArray[key] == nullptr)
        puzzleDetailArray[key] = new RenderArray();

    artLoadManager->RenderArrayLoad(puzzleDetailArray[key], filename);
}


void Puzzle::setPuzzleSceneDialog(int key, string cmd) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    puzzleSceneArray[key]->setDialog(cmd);
}

void Puzzle::setPuzzleSceneAction(int key, string cmd, ActionType command, int dt) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    puzzleSceneArray[key]->setAction(cmd, command, dt);
}

void Puzzle::setPuzzleSceneAction(int key, string cmd, ActionType command, int dt, int repeat) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    puzzleSceneArray[key]->setAction(cmd, command, dt, repeat);
}

void Puzzle::setPuzzleSceneDelay(int key, string cmd, int time) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    puzzleSceneArray[key]->setDelay(cmd, time);
}


RenderArray* Puzzle::getObjectArray() {
    return puzzleObjectArray[objectArrayIdx];
}

RenderArray* Puzzle::getDetailArray() {
    return puzzleDetailArray[detailArrayIdx];
}
