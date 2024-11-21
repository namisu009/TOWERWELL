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
        GameObjectManager::createObejct("Character", "Hero", "src\\hero_idle_right_01.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE_RIGHT", 1, "src\\hero_idle_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE_LEFT", "src\\hero_idle_left_01.png", "src\\hero_idle_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("RIGHT", "src\\hero_right_01.png", "src\\hero_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("LEFT", "src\\hero_left_01.png", "src\\hero_left_02.png");

        /*
        GameObjectManager::createObejct("Character", "Sister", "src\\sister_idle_01.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE", 1, "src\\sister_idle_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");
        */

        //Dialoginit
        GameObjectManager::createObejct("Dialog", "SC1_DL_01", "src\\dialog1.png");
        GameObjectManager::createObejct("Dialog", "SC1_DL_02", "열쇠를 얻었다");
        GameObjectManager::createObejct("Dialog", "SC1_DL_03", "여동생: 소문이 사실인가봐! 저기 끝에 문이 있는 거 같은데 한 번 가보자.");
        GameObjectManager::createObejct("Dialog", "PZ_NCL_DL", "히로: 문이 열리지 않아...");

        
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_01", "열쇠를 사용한다.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_02", "문이 열리면서 균열이 생겼다.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_01_01", "문 틈 사이로 물줄기가 나왔다.");
        GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_02_01", "문 틈 사이로 물줄기가 나온다. 화분을 가져다 놓으면 좋을 거 같다.");



    };

    static void SceneInit() {

    }


    static void Iteminit() {
        ItemManager::addItems("S1_M1_PZ_02_KEY", 1);
        //ItemManager::addItems("S1_M1_PZ_02_KEY", 1);
    }

    static void PuzzleInit() {
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setPuzzleDetailASCII("S1_M1_PZ_01", 0, "src\\SC3_PZ_01.png");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_01", TYPE_CL_DL, 0, "SC1_DL_02");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_01", TYPE_CL_DL, 0, "SC1_DL_03");
        PuzzleManager::setPuzzleReward("S1_M1_PZ_01", 0, "S1_M1_PZ_02_KEY");

        PuzzleManager::createPuzzle("S1_M1_PZ_02", TYPE_ITEM_PUZZLE);
        PuzzleManager::setPuzzleObjectASCII("S1_M1_PZ_02", 0, "src\\GATE1.png");
        PuzzleManager::setPuzzleObjectASCII("S1_M1_PZ_02", 1, "src\\GATE2.png");
        PuzzleManager::setPuzzleObjectASCII("S1_M1_PZ_02", 2, "src\\GATE3.png");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_02", TYPE_NCL_DL, 0, "S1_M1_PZ2_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_02", TYPE_CL_DL, 0, "S1_M1_PZ2_DL_00_01");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_02", TYPE_CL_DL, 0, "S1_M1_PZ2_DL_00_02");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_02", TYPE_CL_DL, 1, "S1_M1_PZ2_DL_01_01");
        PuzzleManager::setPuzzleSceneDialog("S1_M1_PZ_02", TYPE_CL_DL, 2, "S1_M1_PZ2_DL_02_01");
        PuzzleManager::setPuzzleConditionItem("S1_M1_PZ_02", 0, "S1_M1_PZ_02_KEY");
    };

    static void MapInit() {
        MapManager::createMap("S1_JP_MAP_03", TYPE_JUMP, "src\\S3_J_MAP_01.png", "src\\S3_J_MAP_INFO_01.png");
        MapManager::createMap("S1_PZ_MAP_01", TYPE_PUZZLE, "src\\TEST_MAP_01.png", "src\\TEST_MAP_INFO_01.png");
        MapManager::createMap("S1_JP_MAP_01", TYPE_JUMP, "src\\S1_J_MAP_01.png", "src\\S1_J_MAP_01_STAGE_INFO.png");
        MapManager::createMap("S1_JP_MAP_TEST", TYPE_JUMP, "src\\TEST_JUMP_MAP_01.png", "src\\TEST_JUMP_MAP_INFO_01.png");
    };

    static void StageInit(EventDispatcher *eventDispathcer) {
        for (int i = 0; i < 4; i++) {
            StageManager::addStage(i, eventDispathcer);
        }
        StageManager::addMap(0, MapManager::getMap("S1_PZ_MAP_01"));
        StageManager::addMap(0, MapManager::getMap("S1_JP_MAP_03"));
        StageManager::addMap(0, MapManager::getMap("S1_JP_MAP_01"));
        StageManager::setDoorID(0, "S1_PZ_MAP_01", MAP_EXIT, "S1_JP_MAP_01");
        StageManager::setDoorID(0, "S1_JP_MAP_01", MAP_EXIT, "S1_PZ_MAP_01");
        StageManager::setPuzzleId(0, "S1_PZ_MAP_01", PUZZLE_OBJ_01, "S1_M1_PZ_01");
        StageManager::setPuzzleId(0, "S1_PZ_MAP_01", PUZZLE_OBJ_02, "S1_M1_PZ_02");
        MapManager::setMapASCII("S1_PZ_MAP_01");
        MapManager::setMapASCII("S1_JP_MAP_01");
        MapManager::setMapASCII("S1_JP_MAP_03");
        MapManager::setMapASCII("S1_JP_MAP_TEST");
    };
public:
	static void init(EventDispatcher* eventDispatcher) {
        Iteminit();
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