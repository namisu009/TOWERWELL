#include "StageManager.h"

int StageManager::currentStageId = 6;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����	 