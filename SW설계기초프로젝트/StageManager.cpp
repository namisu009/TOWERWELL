#include "StageManager.h"

int StageManager::currentStageId = 4;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����