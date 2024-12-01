#include "Puzzle.h"
#include "Scene.h"
#include "RenderManager.h"
#include "StageManager.h"

Puzzle::Puzzle(string _id) : GameObject(_id) {
    objectArrayIdx = 0;
    detailArrayIdx = 0;
    cl_sceneArrayIdx = 0;
    ncl_sceneArrayIdx = 0;
    rewardArrayIdx = 0;
    solvedThreshold = 0;
    solvedPuzzleCount = 0;
    isSolved = true;

    solvedObjectArray = nullptr;
    solvedDetailArray = nullptr;
    completedScene = nullptr;

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
    return currentStep > solvedThreshold;
}

bool Puzzle::getIsSolved() {
    return isSolved;
}

// ���� �ذ� ���� Ȯ��
bool Puzzle::isPuzzleSolved() {
    if (getIsSolved()) //�ذ��� �� ������ ���� ��� ����Ǿ �� ���
        showSolvedState();

    return isSolved;
}

bool Puzzle::progressPuzzle() {
    if (isSolved)
        return false; // �̹� ���� �ذ�� ���

    if (!isSolved && puzzleCLSceneArray[currentStep] != nullptr) {
        puzzleCLSceneArray[cl_sceneArrayIdx]->display(); // �߰� �ذ� ��� ���
        currentStep++;

        // ���� ������Ʈ
        if (objectArrayIdx < solvedThreshold && puzzleObjectArray[objectArrayIdx + 1] != nullptr) {
            artLoadManager->resetExpandThePuzzleInfo(this, &StageManager::getCurrentStage()->getCurrentMap()->getScreenArray());

            objectArrayIdx++;

            artLoadManager->ExpandThePuzzleInfo(this, &StageManager::getCurrentStage()->getCurrentMap()->getScreenArray());

            setWidth(puzzleObjectArray[objectArrayIdx]->width);
            setHeight(puzzleObjectArray[objectArrayIdx]->height);
        }

        if (detailArrayIdx < solvedThreshold && puzzleDetailArray[detailArrayIdx + 1] != nullptr) {
            detailArrayIdx++;
        }

        if (!isIntermediateSolved() && cl_sceneArrayIdx < puzzleCount) {
            cl_sceneArrayIdx++;
            ncl_sceneArrayIdx++;
        }

        solvePuzzle();
        return true; // �߰� �ذ� ����
    }

    return false; // �߰� �ذ� ����
}

void Puzzle::PuzzleNCLSceneDisplay() {
    if (puzzleNCLSceneArray[ncl_sceneArrayIdx] != nullptr)
        puzzleNCLSceneArray[ncl_sceneArrayIdx]->display();
}

bool Puzzle::solvePuzzle() {
     if (isIntermediateSolved() && !isSolved) {
        if(solvedObjectArray != nullptr){
            artLoadManager->resetExpandThePuzzleInfo(this, &StageManager::getCurrentStage()->getCurrentMap()->getScreenArray());

            isSolved = true;
            eventDispatcher->dispatch(PUZZLE_SOLVED); // ���� �ذ� �̺�Ʈ

            artLoadManager->ExpandThePuzzleInfo(this, &StageManager::getCurrentStage()->getCurrentMap()->getScreenArray());

            setWidth(solvedObjectArray->width);
            setHeight(solvedObjectArray->height);
        }else {
            isSolved = true;
            eventDispatcher->dispatch(PUZZLE_SOLVED); // ���� �ذ� �̺�Ʈ
        }
    }
    return isSolved; // ���� �ذ� ������ �������� ����
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
    isSolved = false;
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

    if (type == TYPE_CL_DL)
    {
        if (puzzleCLSceneArray[key] == nullptr)
            puzzleCLSceneArray[key] = new Scene();

        puzzleCLSceneArray[key]->setDialog(cmd);
    }
    else if (type == TYPE_NCL_DL)
    {
        if (puzzleNCLSceneArray[key] == nullptr)
            puzzleNCLSceneArray[key] = new Scene();

        puzzleNCLSceneArray[key]->setDialog(cmd);
    }

    setSolvedThreshold(key);
}

void Puzzle::setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL)
    {
        if (puzzleCLSceneArray[key] == nullptr)
            puzzleCLSceneArray[key] = new Scene();

        puzzleCLSceneArray[key]->setAction(cmd, command, dt);
    }
    else if (type == TYPE_NCL_DL)
    {
        if (puzzleNCLSceneArray[key] == nullptr)
            puzzleNCLSceneArray[key] = new Scene();

        puzzleNCLSceneArray[key]->setAction(cmd, command, dt);
    }

    setSolvedThreshold(key);
}

void Puzzle::setPuzzleSceneAction(int type, int key, string cmd, ActionType command, int dt, int repeat) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL)
    {
        if (puzzleCLSceneArray[key] == nullptr)
            puzzleCLSceneArray[key] = new Scene();

        puzzleCLSceneArray[key]->setAction(cmd, command, dt, repeat);
    }
    else if (type == TYPE_NCL_DL)
    {
        if (puzzleNCLSceneArray[key] == nullptr)
            puzzleNCLSceneArray[key] = new Scene();

        puzzleNCLSceneArray[key]->setAction(cmd, command, dt, repeat);
    }

    setSolvedThreshold(key);

}

void Puzzle::setPuzzleSceneDelay(int type, int key, string cmd, int time) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL)
    {
        if (puzzleCLSceneArray[key] == nullptr)
            puzzleCLSceneArray[key] = new Scene();

        puzzleCLSceneArray[key]->setDelay(cmd, time);
    }
    else if (type == TYPE_NCL_DL)
    {
        if (puzzleNCLSceneArray[key] == nullptr)
            puzzleNCLSceneArray[key] = new Scene();

        puzzleNCLSceneArray[key]->setDelay(cmd, time);
    }

    setSolvedThreshold(key);

}

void Puzzle::setPuzzleSceneLoop(int type, int key, bool loop) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (type == TYPE_CL_DL)
    {
        if (puzzleCLSceneArray[key] == nullptr)
            puzzleCLSceneArray[key] = new Scene();

        puzzleCLSceneArray[key]->setSceneLoop(loop);
    }
    else if (type == TYPE_NCL_DL)
    {
        if (puzzleNCLSceneArray[key] == nullptr)
            puzzleNCLSceneArray[key] = new Scene();

        puzzleNCLSceneArray[key]->setSceneLoop(loop);
    }
}

void Puzzle::showSolvedState() {
    if (completedScene)
        completedScene->display();
}

void Puzzle::setCompletedObjectASCII(const char* filename) {
    if (solvedObjectArray == nullptr)
        solvedObjectArray = new RenderArray();

    artLoadManager->RenderArrayLoad(solvedObjectArray, filename);
}

void Puzzle::setCompletedDetailASCII(const char* filename) {
    if (solvedDetailArray == nullptr)
        solvedDetailArray = new RenderArray();

    artLoadManager->RenderArrayLoad(solvedDetailArray, filename);
}

void Puzzle::setCompletedSceneDialog(string cmd) {
    if (completedScene == nullptr)
        completedScene = new Scene();

    completedScene->setDialog(cmd);
}
void Puzzle::setCompletedSceneAction(string cmd, ActionType command, int dt) {
    if (completedScene == nullptr)
        completedScene = new Scene();

    completedScene->setAction(cmd, command, dt);
}
void Puzzle::setCompletedSceneAction(string cmd, ActionType command, int dt, int repeat) {
    if (completedScene == nullptr)
        completedScene = new Scene();

    completedScene->setAction(cmd, command, dt, repeat);
}
void Puzzle::setCompletedSceneDelay(string cmd, int time) {
    if (completedScene == nullptr)
        completedScene = new Scene();

    completedScene->setDelay(cmd, time);
}
void Puzzle::setCompletedSceneLoop(bool loop) {
    if (completedScene == nullptr)
        completedScene = new Scene();

    completedScene->setSceneLoop(loop);
}

RenderArray* Puzzle::getObjectArray() {
    if (isSolved && solvedObjectArray != nullptr)
        return solvedObjectArray;

    return puzzleObjectArray[objectArrayIdx];
}

RenderArray* Puzzle::getDetailArray() {
    if (isSolved && solvedDetailArray != nullptr)
        return solvedDetailArray;

    return puzzleDetailArray[detailArrayIdx];
}
