#include "StageManager.h"

int StageManager::currentStageId = 10;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����	