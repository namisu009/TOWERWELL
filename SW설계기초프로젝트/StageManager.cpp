#include "StageManager.h"

int StageManager::currentStageId = 1;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����