#include "StageManager.h"

int StageManager::currentStageId = 7;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����