#ifndef _RENDERMANAGER_H
#define _RENDERMANAGER_H

#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<String.h>

#include <vector>
#include "Map.h"
#include "GameObject.h"
#include "Dialog.h"
#include "ScreenInfo.h"
#include "DoubleBufferManager.h"

using namespace std;

class RenderManager {
private:
    static Map* m_map; //���� �׷����� ��
    static vector<GameObject*> renderQueue; // �������� ��ü ����Ʈ
    static Dialog * renderLog;

public:

    static void addObject(GameObject* object); // �������� ��ü �߰�
    static void removeObject(GameObject* object); // �������� ��ü ����

    static void setRenderDialog(Dialog* dialog);
    static void ClearRenderDialog();

    static void renderMap();
    static void renderObject(); // ��� ��ü ������
    static void renderDialog(); // ��ȭâ ������
    static void clearObject(); //ȭ�鿡�� ��ü ����� (�� �׸���)

    static  void render();
    static void clear(); // ������ ť �ʱ�ȭ
    static void ScreenInit(); //ȭ���ʱ�ȭ
    static void setRenderMap(Map* map);
};



#endif