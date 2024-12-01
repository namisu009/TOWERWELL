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
        delete puzzleObjectArray[i]; // 동적 메모리 해제
        puzzleObjectArray[i] = nullptr; // 이중 해제 방지

        delete puzzleDetailArray[i]; // 동적 메모리 해제
        puzzleDetailArray[i] = nullptr; // 이중 해제 방지

        delete puzzleCLSceneArray[i]; // 동적 메모리 해제
        puzzleCLSceneArray[i] = nullptr; // 이중 해제 방지

        delete puzzleNCLSceneArray[i]; // 동적 메모리 해제
        puzzleNCLSceneArray[i] = nullptr; // 이중 해제 방지
    }
}

// 중간 해결 상태 확인
bool Puzzle::isIntermediateSolved() {
    return currentStep > solvedThreshold;
}

bool Puzzle::getIsSolved() {
    return isSolved;
}

// 최종 해결 상태 확인
bool Puzzle::isPuzzleSolved() {
    if (getIsSolved()) //해결이 다 됐지만 씬이 계속 재생되어도 될 경우
        showSolvedState();

    return isSolved;
}

bool Puzzle::progressPuzzle() {
    if (isSolved)
        return false; // 이미 최종 해결된 경우

    if (!isSolved && puzzleCLSceneArray[currentStep] != nullptr) {
        puzzleCLSceneArray[cl_sceneArrayIdx]->display(); // 중간 해결 장면 출력
        currentStep++;

        // 상태 업데이트
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
        return true; // 중간 해결 성공
    }

    return false; // 중간 해결 실패
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
            eventDispatcher->dispatch(PUZZLE_SOLVED); // 최종 해결 이벤트

            artLoadManager->ExpandThePuzzleInfo(this, &StageManager::getCurrentStage()->getCurrentMap()->getScreenArray());

            setWidth(solvedObjectArray->width);
            setHeight(solvedObjectArray->height);
        }else {
            isSolved = true;
            eventDispatcher->dispatch(PUZZLE_SOLVED); // 최종 해결 이벤트
        }
    }
    return isSolved; // 최종 해결 조건이 충족되지 않음
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
