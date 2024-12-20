#ifndef _RENDERMANAGER_H
#define _RENDERMANAGER_H

#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<String.h>
#include <unordered_map>

#include "Map.h"
#include "GameObjectManager.h"
#include "Puzzle.h"
#include "Dialog.h"
#include "ScreenInfo.h"
#include "DoubleBufferManager.h"

using namespace std;

class RenderManager {
private:
    static Map* currentMap; //���� �׷����� ��
    static unordered_map<string, GameObject*> objectMap; // �������� ��ü ����Ʈ
    static unordered_map<string, Puzzle*> puzzleMap; // �������� ��ü ����Ʈ
    static GameObject* renderDetail;
    static Dialog * renderLog;
    static EventDispatcher* eventDispatcher;

public:
    static void setEventDispatcher(EventDispatcher* dispatcher) {
        eventDispatcher = dispatcher;
    }

    static void addObject(GameObject* object); // �������� ��ü �߰�
    static void removeObject(GameObject* object); // �������� ��ü ����

    static void addPuzzle(Puzzle* puzzle); // �������� ���� �߰�
    static void removePuzzle(Puzzle* puzzle); // �������� ���� ����

    static void setRenderDetail(string key);
    static void setRenderDetail(GameObject* object);
    static void setRenderDialog(Dialog* dialog);
    static void ClearRenderDialog();
    static void ClearRenderDetail();

    static void renderMap();
    static void renderObject(); // ��� ��ü ������
    static void renderPuzzle(); // ��� ��ü ������
    static void renderScreenDetail(); // ��� ��ü ������
    static void renderDialog(); // ��ȭâ ������
    static void clearObject(); //ȭ�鿡�� ��ü ����� (�� �׸���)
    static void renderInputText(string& input, int x, int y, int height = 90);

    static void renderClear();

    static void render();
    static void objectClear(); // ������ ť �ʱ�ȭ
    static void puzzleClear(); // ������ ť �ʱ�ȭ
    static void ScreenInit(); //ȭ���ʱ�ȭ
    static void setRenderMap(Map* map);

    static GameObject* getRenderDetail();
    static Map* getRenderMap();
    static Dialog* getRenderDialog();

    static GameObject* getRenderObject(string key);
};



#endif 