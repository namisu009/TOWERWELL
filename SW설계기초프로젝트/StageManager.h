#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include <unordered_map>
#include "Stage.h"

using namespace std;

class StageManager {
private:
    int currentStageId;// 현재 스테이지 ID
    unordered_map<int, Stage> stages;// 스테이지 관리

public:
    void initializeStages();// 스테이지 초기화
    void setCurrentStage(int id); //현재 스테이지 갱신
    void addStage(int id, const Stage& stage); // 스테이지 추가
    Stage* getCurrentStage();// 현재 스테이지 가져오기
    Stage* getStage(int stageId);// 특정 스테이지 가져오기
};

#endif