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
#include "RenderStruct.h"

using namespace std;

class RenderManager {
private:
    static Map* currentMap; //Áö±Ý ±×·Á¾ßÇÒ ¸Ê
    static unordered_map<string, GameObject*> objectMap; // ·»´õ¸µÇÒ °´Ã¼ ¸®½ºÆ®
    static unordered_map<string, Puzzle*> puzzleMap; // ·»´õ¸µÇÒ °´Ã¼ ¸®½ºÆ®
    static Puzzle* renderPzl;
    static Dialog * renderLog;
    static EventDispatcher* eventDispatcher;

public:
    // EventDispatcher ¼³Á¤
    static void setEventDispatcher(EventDispatcher* dispatcher) {
        eventDispatcher = dispatcher;
    }

    static void addObject(GameObject* object); // ·»´õ¸µÇÒ °´Ã¼ Ãß°¡
    static void removeObject(GameObject* object); // ·»´õ¸µÇÒ °´Ã¼ Á¦°Å

    static void addPuzzle(Puzzle* puzzle); // ·»´õ¸µÇÒ ÆÛÁñ Ãß°¡
    static void removePuzzle(Puzzle* puzzle); // ·»´õ¸µÇÒ ÆÛÁñ Á¦°Å

    static void setRenderPuzzleDetail(string key);
    static void setRenderDialog(Dialog* dialog);
    static void ClearRenderDialog();
    static void ClearRenderPuzzleDetail();

    static void renderMap();
    static void renderObject(); // ¸ðµç °´Ã¼ ·»´õ¸µ
    static void renderPuzzle(); // ¸ðµç °´Ã¼ ·»´õ¸µ
    static void renderPuzzleDetail(); // ¸ðµç °´Ã¼ ·»´õ¸µ
    static void renderDialog(); // ´ëÈ­Ã¢ ·»´õ¸µ
    //static void clearObject(); //È­¸é¿¡¼­ °´Ã¼ Áö¿ì±â (¸Ê ±×¸®±â)

    static void renderClear();

    static void render();
    static void objectClear(); // ·»´õ¸µ Å¥ ÃÊ±âÈ­
    static void puzzleClear(); // ·»´õ¸µ Å¥ ÃÊ±âÈ­
    static void ScreenInit(); //È­¸éÃÊ±âÈ­
    static void setRenderMap(Map* map);
};



#endif