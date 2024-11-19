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
        puzzleObjectArray[i] = nullptr; // 포인터 초기화
        puzzleDetailArray[i] = nullptr; // 포인터 초기화
        puzzleSceneArray[i] = nullptr; // 포인터 초기화
        puzzleRewardArray[i] = "";
    }
}

Puzzle::~Puzzle() {
    for (int i = 0; i < puzzleCount; ++i) {
        delete puzzleObjectArray[i]; // 동적 메모리 해제
        puzzleObjectArray[i] = nullptr; // 이중 해제 방지

        delete puzzleDetailArray[i]; // 동적 메모리 해제
        puzzleDetailArray[i] = nullptr; // 이중 해제 방지

        delete puzzleSceneArray[i]; // 동적 메모리 해제
        puzzleSceneArray[i] = nullptr; // 이중 해제 방지
    }
}

// 중간 해결 상태 확인
bool Puzzle::isIntermediateSolved() {
    return currentStep >= solvedThreshold;
}

// 최종 해결 상태 확인
bool Puzzle::isPuzzleSolved() {
    if (!isSolved && currentStep >= puzzleCount) {
        isSolved = true;
        eventDispatcher->dispatch(PUZZLE_SOLVED); // 최종 해결 이벤트
    }
    return isSolved;
}

bool Puzzle::progressPuzzle() {
    if (isSolved) return false; // 이미 최종 해결된 경우

    if (currentStep < puzzleCount && puzzleSceneArray[currentStep] != nullptr) {
        puzzleSceneArray[currentStep]->display(); // 중간 해결 장면 출력
        currentStep++;

        // 상태 업데이트
        if (objectArrayIdx < puzzleCount && puzzleObjectArray[objectArrayIdx + 1] != nullptr) {
            objectArrayIdx++;
            setWidth(puzzleObjectArray[objectArrayIdx]->width);
            setHeight(puzzleObjectArray[objectArrayIdx]->height);
        }

        if (detailArrayIdx < puzzleCount && puzzleDetailArray[detailArrayIdx + 1] != nullptr) {
            detailArrayIdx++;
        }

        if (sceneArrayIdx < puzzleCount) {
            sceneArrayIdx++;
        }

        solvePuzzle();
        return true; // 중간 해결 성공
    }

    return false; // 중간 해결 실패
}

bool Puzzle::solvePuzzle() {
    if (isIntermediateSolved() && !isSolved) {
        isSolved = true;
        eventDispatcher->dispatch(PUZZLE_SOLVED); // 최종 해결 이벤트
        return true;
    }
    return false; // 최종 해결 조건이 충족되지 않음
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

// 퍼즐 디테일 ASCII 설정 함수
void Puzzle::setPuzzleDetailASCII(int key, const char* filename) {
    if (key >= puzzleCount || key < 0)
        return;

    if (puzzleDetailArray[key] == nullptr)
        puzzleDetailArray[key] = new RenderArray();

    setSolvedThreshold(key);
    artLoadManager->RenderArrayLoad(puzzleDetailArray[key], filename);
}


void Puzzle::setPuzzleSceneDialog(int key, string cmd) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    setSolvedThreshold(key);
    puzzleSceneArray[key]->setDialog(cmd);
}

void Puzzle::setPuzzleSceneAction(int key, string cmd, ActionType command, int dt) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    setSolvedThreshold(key);
    puzzleSceneArray[key]->setAction(cmd, command, dt);
}

void Puzzle::setPuzzleSceneAction(int key, string cmd, ActionType command, int dt, int repeat) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    setSolvedThreshold(key);
    puzzleSceneArray[key]->setAction(cmd, command, dt, repeat);
}

void Puzzle::setPuzzleSceneDelay(int key, string cmd, int time) {
    if (key < 0 || key >= puzzleCount) {
        return;
    }

    if (puzzleSceneArray[key] == nullptr)
        puzzleSceneArray[key] = new Scene();

    setSolvedThreshold(key);
    puzzleSceneArray[key]->setDelay(cmd, time);
}




RenderArray* Puzzle::getObjectArray() {
    return puzzleObjectArray[objectArrayIdx];
}

RenderArray* Puzzle::getDetailArray() {
    return puzzleDetailArray[detailArrayIdx];
}
