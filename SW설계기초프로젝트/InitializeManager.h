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
        // ĳ���� ���� �� �ʱ�ȭ
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
        GameObjectManager::createObejct("Dialog", "SC1_DL_02", "���踦 �����");
        GameObjectManager::createObejct("Dialog", "SC1_DL_03", "������: �ҹ��� ����ΰ���! ���� ���� ���� �ִ� �� ������ �� �� ������.");
        GameObjectManager::createObejct("Dialog", "PZ_NCL_DL", "����: ���� ������ �ʾ�...");

        
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_01", "���踦 ����Ѵ�.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_02", "���� �����鼭 �տ��� �����.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_01_01", "�� ƴ ���̷� ���ٱⰡ ���Դ�.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_02_01", "�� ƴ ���̷� ���ٱⰡ ���´�.");

    };

    static void SceneInit() {

    }


    static void Iteminit() {
        ItemManager::addItems("S1_M1_PZ_02_KEY", 1);
        //ItemManager::addItems("S1_M1_PZ_02_KEY", 1);
    }

    static void PuzzleInit() {
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleDetailASCII(0, "src\\SC3_PZ_01.png");
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleSceneDialog(0, "SC1_DL_02");
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleSceneDialog(0, "SC1_DL_03");
        PuzzleManager::getPuzzle("S1_M1_PZ_01")->setPuzzleReward(0, "S1_M1_PZ_02_KEY");

        PuzzleManager::createPuzzle("S1_M1_PZ_02", TYPE_ITEM_PUZZLE);
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleObjectASCII(0, "src\\GATE1.png");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleObjectASCII(1, "src\\GATE2.png");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleObjectASCII(2, "src\\GATE3.png");
        //PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleDetailASCII(0, "src\\DL.png");
        //PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleDetailASCII(1, "src\\DL.png");
        //PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleDetailASCII(2, "src\\DL.png");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleSceneDialog(0, "S1_M1_PZ2_DL_00_01");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleSceneDialog(0, "S1_M1_PZ2_DL_00_02");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleSceneDialog(1, "S1_M1_PZ2_DL_01_01");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleSceneDialog(1, "S1_M1_PZ2_DL_02_01");
        PuzzleManager::getItemPuzzle("S1_M1_PZ_02")->setPuzzleConditionItem(0, "S1_M1_PZ_02_KEY");
       

    };

    static void MapInit() {
        MapManager::createMap("S1_PZ_MAP_01", TYPE_PUZZLE, "src\\TEST_MAP_01.png", "src\\TEST_MAP_INFO_01.png");
        MapManager::createMap("S1_JP_MAP_01", TYPE_JUMP, "src\\S1_J_MAP_01.png", "src\\S1_J_MAP_01_STAGE_INFO.png");
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
        StageManager::setPuzzleId(0, "S1_PZ_MAP_01", PUZZLE_OBJ_02, "S1_M1_PZ_02");
        MapManager::setMapASCII("S1_PZ_MAP_01");
        MapManager::setMapASCII("S1_JP_MAP_01");
    };
public:
	static void init(EventDispatcher* eventDispatcher) {
        Iteminit();
        ObjectInit();
        SceneInit();
        PuzzleInit();
        MapInit();
        StageInit(eventDispatcher);

        //����
        //������Ʈ ����
        //�� ����
        //���� ����
        //���� �� ����
        //�� ����
        //�ʿ� ���� ���� -> �ڵ����� �� ���� Ȯ�� �� ����
        //���������� ��, DoorID, ���� ����
	}
};

#endif