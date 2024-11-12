#include "StageManager.h"

int StageManager::currentStageId = 0;// 현재 스테이지 ID
unordered_map<int, Stage> StageManager::stages;// 스테이지 관리