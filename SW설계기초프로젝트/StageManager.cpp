#include "StageManager.h"

int StageManager::currentStageId = 9;// ���� �������� ID
unordered_map<int, Stage*> StageManager::stages;// �������� ����	 