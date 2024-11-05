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
#include "ScreenInfo.h"
#include "DoubleBufferManager.h"

using namespace std;

class RenderManager {
private:
    static Map* m_map; //Áö±Ý ±×·Á¾ßÇÒ ¸Ê
    static vector<GameObject*> renderQueue; // ·»´õ¸µÇÒ °´Ã¼ ¸®½ºÆ®

public:

    static void addObject(GameObject* object); // ·»´õ¸µÇÒ °´Ã¼ Ãß°¡
    static void removeObject(GameObject* object); // ·»´õ¸µÇÒ °´Ã¼ Á¦°Å
    static void renderMap();
    static void renderObject(); // ¸ðµç °´Ã¼ ·»´õ¸µ
    static void clearObject(); //È­¸é¿¡¼­ °´Ã¼ Áö¿ì±â (¸Ê ±×¸®±â)
    static void clear(); // ·»´õ¸µ Å¥ ÃÊ±âÈ­
    static void ScreenInit(); //È­¸éÃÊ±âÈ­
    static void setRenderMap(Map* map);
};



#endif