#include "StageManager.h"

int StageManager::currentStageId = 5;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����	