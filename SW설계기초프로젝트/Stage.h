#ifndef _STAGE_H
#define _STAGE_H

#include <unordered_map>
#include "Puzzle.h"
#include "Map.h"
using namespace std;

class Stage {
private:
    int stageId; // �������� ID
    Map* map;// �ش� ���������� ��
    bool isCleared; // �������� Ŭ���� ���� //������ �� Ǯ���� ��
    bool playedScene; //�ش� ���������� ���� �̹� ����������
    //EventDispatcher& eventDispatcher; // �̺�Ʈ ����ó ����

public:
    Stage(int id, string sceneId, string mapid); // ������  EventDispatcher& dispatcher
    void addPuzzle(Puzzle* puzzle); // ���� �߰�
    bool getIsCleared() {
        return isCleared;
    }
    void playScene() {
        
    }
    void onPuzzleSolved(); // ���� �ذ� �̺�Ʈ �ڵ鸵
};

#endif