#include "StageManager.h"

int StageManager::currentStageId = 2;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����