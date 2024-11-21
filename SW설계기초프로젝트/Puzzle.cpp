#include "Puzzle.h"
#include "Scene.h"
#include "RenderManager.h"

Puzzle::Puzzle(string _id) : GameObject(_id) {
    objectArrayIdx = 0;
    detailArrayIdx = 0;
    cl_sceneArrayIdx = 0;
    ncl_sceneArrayIdx = 0;
    rewardArrayIdx = 0;
    solvedThreshold = 0;
    solvedPuzzleCount = 0;
    isSolved = false;
    for (int i = 0; i < puzzleCount; ++i) {
        puzzleObjectArray[i] = nullptr;
        puzzleDetailArray[i] = nullptr;
        puzzleCLSceneArray[i] = nullptr;
        puzzleNCLSceneArray[i] = nullptr;
        puzzleRewardArray[i] = "";
    }
}

Puzzle::~Puzzle() {
    for (int i = 0; i < puzzleCount; ++i) {
        delete puzzleObjectArray[i]; // ���� �޸� ����
        puzzleObjectArray[i] = nullptr; // ���� ���� ����

        delete puzzleDetailArray[i]; // ���� �޸� ����
        puzzleDetailArray[i] = nullptr; // ���� ���� ����

        delete puzzleCLSceneArray[i]; // ���� �޸� ����
        puzzleCLSceneArray[i] = nullptr; // ���� ���� ����

        delete puzzleNCLSceneArray[i]; // ���� �޸� ����
        puzzleNCLSceneArray[i] = nullptr; // ���� ���� ����
    }
}

// �߰� �ذ� ���� Ȯ��
bool Puzzle::isIntermediateSolved() {
    return currentStep >= solvedThreshold;
}

// ���� �ذ� ���� Ȯ��
bool Puzzle::isPuzzleSolved() {
    if (!isSolved && currentStep >= puzzleCount) {
        isSolved = true;
        eventDispatcher->dispatch(PUZZLE_SOLVED); // ���� �ذ� �̺�Ʈ
    }
    else if (isSolved) {
        if (puzzleCLSceneArray[currentStep] != nullptr)
            puzzleCLSceneArray[cl_sceneArrayIdx]->display();
    }
    return isSolved;
}

bool Puzzle::progressPuzzle() {
    if (isSolved)
        return false; // �̹� ���� �ذ�� ���
    
    if (currentStep < puzzleCount && puzzleCLSceneArray[currentStep] != nullptr) {
        puzzleCLSceneArray[cl_sceneArrayIdx]->display(); // �߰� �ذ� ��� ���
        currentStep++;

        // ���� ������Ʈ
        if (objectArrayIdx < puzzleCount && puzzleObjectArray[objectArrayIdx + 1] != nullptr) {
            objectArrayIdx++;
            setWidth(puzzleObjectArray[objectArrayIdx]->width);
            setHeight(puzzleObjectArray[objectArrayIdx]->height);
        }

        if (detailArrayIdx < puzzleCount && puzzleDetailArray[detailArrayIdx + 1] != nullptr) {
            detailArrayIdx++;
        }

        if (cl_sceneArrayIdx < puzzleCount) {
            cl_sceneArrayIdx++;
            ncl_sceneArrayIdx++;
        }

        solvePuzzle();
        return true; // �߰� �ذ� ����
    }
    
    return false; // �߰� �ذ� ����
}

void Puzzle::PuzzleNCLSceneDisplay() {
    if(puzzleNCLSceneArray[ncl_sceneArrayIdx] != nullptr)
        puzzleNCLSceneArray[ncl_sceneArrayIdx]->display();
}

bool Puzzle::solvePuzzle() {
    if (isIntermediateSolved() && !isSolved) {
        isSolved = true;
        eventDispatcher->dispatch(PUZZLE_SOLVED); // ���� �ذ� �̺�Ʈ
        return true;
    }
    return false; // ���� �ذ� ������ �������� ����
}

void Puzzle::setPuzzleReward(int key, string name) {
    puzzleRewardArray[key] = name;
}

string Puzzle::getPuzzleReward() {
    if (rewardArrayIdx > solvedThreshold) {
        return "";
    }

    string n = puzzleRewardArray[rewardArrayIdx];
    rewardArrayIdx++;
    return n;
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

    setSolvedThreshold(key);
    artLoadManager->RenderArrayLoad(puzzleObjectArray[key], filename);
    setWidth(puzzleObjectArray[key]->width);
    setHeight(puzzleObjectArray[key]->height);
}

// ���� ������ ASCII ���� �Լ�
void Puzzle::setPuzzleDetailASCII(int key, const char* filename) {
    if (key >= puzzleCount || key < 0)
        return;

    if (puzzleDetailArray[key] == nullptr)
        puzzleDetailArray[key] = new RenderArray();

    setSolvedThreshold(key);
    artLoadManager->RenderArrayLoad(puzzleDetailArray[key], filename);
}


void Puzzle::setPuzzleSceneDialog(int type, int key, string cmd) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL && puzzleCLSceneArray[key] == nullptr)
    {
        puzzleCLSceneArray[key] = new Scene();
        puzzleCLSceneArray[key]->setDialog(cmd);
    }
    else if (type == TYPE_NCL_DL && puzzleNCLSceneArray[key] == nullptr)
    {
        puzzleNCLSceneArray[key] = new Scene();
        puzzleNCLSceneArray[key]->setDialog(cmd);
    }

    setSolvedThreshold(key);
}

void Puzzle::setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL && puzzleCLSceneArray[key] == nullptr)
    {
        puzzleCLSceneArray[key] = new Scene();
        puzzleCLSceneArray[key]->setAction(cmd, command, dt);
    }
    else if (type == TYPE_NCL_DL && puzzleNCLSceneArray[key] == nullptr)
    {
        puzzleNCLSceneArray[key] = new Scene();
        puzzleNCLSceneArray[key]->setAction(cmd, command, dt);
    }

    setSolvedThreshold(key);
}

void Puzzle::setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt, int repeat) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL && puzzleCLSceneArray[key] == nullptr)
    {
        puzzleCLSceneArray[key] = new Scene();
        puzzleCLSceneArray[key]->setAction(cmd, command, dt, repeat);
    }
    else if (type == TYPE_NCL_DL && puzzleNCLSceneArray[key] == nullptr)
    {
        puzzleNCLSceneArray[key] = new Scene();
        puzzleNCLSceneArray[key]->setAction(cmd, command, dt, repeat);
    }

    setSolvedThreshold(key);
    
}

void Puzzle::setPuzzleSceneDelay(int type, int key, string cmd, int time) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL && puzzleCLSceneArray[key] == nullptr)
    {
        puzzleCLSceneArray[key] = new Scene();
        puzzleCLSceneArray[key]->setDelay(cmd, time);
    }
    else if (type == TYPE_NCL_DL && puzzleNCLSceneArray[key] == nullptr)
    {
        puzzleNCLSceneArray[key] = new Scene();
        puzzleNCLSceneArray[key]->setDelay(cmd, time);
    }

    setSolvedThreshold(key);
    
}


RenderArray* Puzzle::getObjectArray() {
    return puzzleObjectArray[objectArrayIdx];
}

RenderArray* Puzzle::getDetailArray() {
    return puzzleDetailArray[detailArrayIdx];
}
