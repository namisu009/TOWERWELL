#include "StageManager.h"

int StageManager::currentStageId = 0;// ���� �������� ID
unordered_map<int, Stage> StageManager::stages;// �������� ����