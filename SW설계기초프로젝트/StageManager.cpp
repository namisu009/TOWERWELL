#include "StageManager.h"

int StageManager::currentStageId = 3;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����	