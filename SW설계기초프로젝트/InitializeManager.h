#ifndef _INITIALIZEMANAGER_H_
#define _INITIALIZEMANAGER_H_

#include "StageManager.h"
#include "MapManager.h"
#include "SceneMananger.h"
#include "PuzzleManager.h"
#include "GameObjectManager.h"

class InitializeManager
{
private:
    static void ObjectInit() {
        // 캐릭터 생성 및 초기화
        GameObjectManager::createObejct("Character", "Hero", "src\\hero_idle_01.png");
        GameObjectManager::getCharacter("Hero");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE", 1, "src\\hero_idle_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("RIGHT", "src\\hero_right_01.png", "src\\hero_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("LEFT", "src\\hero_left_01.png", "src\\hero_left_02.png");

        GameObjectManager::createObejct("Character", "Sister", "src\\sister_idle_01.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE", 1, "src\\sister_idle_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");


        //Dialoginit
        GameObjectManager::createObejct("Dialog", "SC1_DL_01", "src\\dialog1.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_02", "src\\dialog2.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_03", "src\\dialog3.png");
        GameObjectManager::createObejct("Dialog", "PZ_NCL_DL", "src\\PZ_NCL_DL.png");
    };

    static void SceneInit() {

    }

    static void PuzzleInit() {
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleDetailASCII(0, "src\\SC3_PZ_01.png");
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleSceneDialog(0, "SC1_DL_03");
    };

    static void MapInit() {
        MapManager::createMap("S1_PZ_MAP_01", TYPE_PUZZLE, "src\\S1_PUZZLE_MAP_01.png", "src\\S1_PUZZLE_MAP_INFO_01.png");
        MapManager::createMap("S1_JP_MAP_01", TYPE_JUMP, "src\\S1_JUMP_MAP_01.png", "src\\S1_JUMP_MAP_INFO_01.png");
    };

    static void StageInit(EventDispatcher *eventDispathcer) {
        for (int i = 0; i < 4; i++) {
            StageManager::addStage(i, eventDispathcer);
        }

        StageManager::addMap(0, MapManager::getMap("S1_PZ_MAP_01"));
        StageManager::addMap(0, MapManager::getMap("S1_JP_MAP_01"));
        StageManager::setDoorID(0, "S1_PZ_MAP_01", MAP_EXIT, "S1_JP_MAP_01");
        StageManager::setDoorID(0, "S1_JP_MAP_01", MAP_EXIT, "S1_PZ_MAP_01");
        StageManager::setPuzzleId(0, "S1_PZ_MAP_01", PUZZLE_OBJ_01, "S1_M1_PZ_01");

    };
public:
	static void init(EventDispatcher* eventDispatcher) {
        ObjectInit();
        SceneInit();
        PuzzleInit();
        MapInit();
        StageInit(eventDispatcher);

        //순서
        //오브젝트 생성
        //씬 생성
        //퍼즐 생성
        //퍼즐에 씬 연결
        //맵 생성
        //맵에 퍼즐 연결 -> 자동으로 맵 인포 확장 및 수정
        //스테이지에 맵, DoorID, 퍼즐 연결
	}
};

#endif