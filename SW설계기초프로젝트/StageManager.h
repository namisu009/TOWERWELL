#ifndef _STAGEMANAGER_H
#define _STAGEMANAGER_H

#include <unordered_map>
#include "Stage.h"

using namespace std;

class StageManager {
private:
    int currentStageId;// ���� �������� ID
    unordered_map<int, Stage> stages;// �������� ����

public:
    void initializeStages();// �������� �ʱ�ȭ
    void setCurrentStage(int id); //���� �������� ����
    void addStage(int id, const Stage& stage); // �������� �߰�
    Stage* getCurrentStage();// ���� �������� ��������
    Stage* getStage(int stageId);// Ư�� �������� ��������
};

#endif