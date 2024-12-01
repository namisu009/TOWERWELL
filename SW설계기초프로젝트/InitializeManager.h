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


		GameObjectManager::createObejct("Character", "Sister", "src\\sister_idle_right_01.png");
		GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_RIGHT", 1, "src\\sister_idle_right_02.png");
		GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_LEFT", "src\\sister_idle_left_01.png", "src\\sister_idle_left_02.png");
		GameObjectManager::getCharacter("Sister")->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
		GameObjectManager::getCharacter("Sister")->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");


		//Dialoginit
		GameObjectManager::createObejct("Dialog", "NUMBER_WINDOW", "");
		GameObjectManager::createObejct("Dialog", "PZ_NCL_DL", "문이 열리지 않아...");
		GameObjectManager::createObejct("Dialog", "SC1_DL_01", "테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트테스트");
		GameObjectManager::createObejct("Dialog", "SC1_DL_02", "씬 테스트 대사입니다2");
	
		GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
		GameObjectManager::createObejct("Dialog", "S1_M1_PZ2_DL_00_01", "열쇠를 사용한다.");

		GameObjectManager::createObejct("Dialog", "S2_M1_PZ1_DL_00_00", "석상: 바깥 세상이 보고싶어...");
		GameObjectManager::createObejct("Dialog", "S2_M1_PZ1_DL_00_01", "석상: 바깥 세상을 보여줘서 고마워");
		GameObjectManager::createObejct("Dialog", "S2_M1_PZ1_DL_00_02", "히로: 석상에 문이 막혀 들어갈 수가 없어");

		GameObjectManager::createObejct("Dialog", "S2_M2_PZ1_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
		GameObjectManager::createObejct("Dialog", "S2_M2_PZ1_DL_00_01", "[열쇠]를 사용한다.");
		GameObjectManager::createObejct("Dialog", "S2_M2_PZ1_DL_00_02", "[라이터]를 얻었다.");
		GameObjectManager::createObejct("Dialog", "S2_M2_PZ1_DL_00_03", "서랍에서 더이상 얻을 것이 없어보인다.");

		GameObjectManager::createObejct("Dialog", "S2_M2_PZ2_DL_00_00", "[씨앗]을 얻었다.");
		GameObjectManager::createObejct("Dialog", "S2_M2_PZ2_DL_00_01", "더 이상 얻을 것이 없어보인다.");

		GameObjectManager::createObejct("Dialog", "S2_M3_PZ1_DL_00_00", "흙밖에 없는 텅 빈 화분이다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ1_DL_00_01", "화분에 씨앗을 심었더니 싹이 곧바로 자랐다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ1_DL_00_02", "[씨앗을 심은 화분]을 얻었다");

		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_00", "문이 열리면서 [균열]이 생겼다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_01", "열린 문 사이로 [열쇠]를 얻었다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_02", "[라이터]를 갖다대자 균열이 깨졌다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_03", "문 틈 사이로 [물줄기]가 나왔다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_04", "화분을 가져다 놓으면 좋을 거 같다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_05", "[물줄기]에 [화분]을 갖다대니 꽃이 폈다.");
		GameObjectManager::createObejct("Dialog", "S2_M3_PZ2_DL_00_06", "[꽃이 핀 화분]을 얻었다.");

		GameObjectManager::createObejct("Dialog", "S3_M1_PZ1_DL_00_00", "비밀번호가 틀렸습니다.");
		GameObjectManager::createObejct("Dialog", "S3_M1_PZ1_DL_01_00", "비밀번호가 맞았습니다.");


	};

	static void SceneInit() {

	}


	static void Iteminit() {
		ItemManager::addItems("S2_M1_PZ_KEY", 1);
		ItemManager::addItems("S2_M2_PZ_SEED", 1);
		ItemManager::addItems("S2_M2_PZ_LIGHTER", 1);
		ItemManager::addItems("S2_M2_PZ_POT", 1);
		ItemManager::addItems("S2_M2_PZ_FLOWER", 1);
	}

	static void PuzzleInit() {
		PuzzleManager::createPuzzle("S2_M1_PZ_01", TYPE_ITEM_PUZZLE); //석상
		PuzzleManager::setPuzzleObjectASCII("S2_M1_PZ_01", 0, "src\\S2_M1_PZ_01_01.png");
		PuzzleManager::setPuzzleSceneDialog("S2_M1_PZ_01", 0, TYPE_NCL_DL, "S2_M1_PZ1_DL_00_00");
		PuzzleManager::setPuzzleSceneDialog("S2_M1_PZ_01", 0, TYPE_CL_DL, "S2_M1_PZ1_DL_00_01");
		PuzzleManager::setPuzzleConditionItem("S2_M1_PZ_01", 0, "S2_M2_PZ_FLOWER");
		PuzzleManager::setCompletedObjectASCII("S2_M1_PZ_01", "src\\S2_M1_PZ_01_02.png");
		PuzzleManager::setCompletedSceneDialog("S2_M1_PZ_01", "S2_M1_PZ1_DL_00_02");
		
		PuzzleManager::createPuzzle("S2_M2_PZ_01", TYPE_ITEM_PUZZLE); //서랍
		PuzzleManager::setPuzzleConditionItem("S2_M2_PZ_01", 0, "S2_M1_PZ_KEY");
		PuzzleManager::setPuzzleReward("S2_M2_PZ_01", 0, "S2_M2_PZ_LIGHTER");
		PuzzleManager::setPuzzleSceneDialog("S2_M2_PZ_01", 0, TYPE_NCL_DL, "S2_M2_PZ1_DL_00_00");
		PuzzleManager::setPuzzleSceneDialog("S2_M2_PZ_01", 0, TYPE_CL_DL, "S2_M2_PZ1_DL_00_01");
		PuzzleManager::setPuzzleSceneDialog("S2_M2_PZ_01", 0, TYPE_CL_DL, "S2_M2_PZ1_DL_00_02");
		PuzzleManager::setCompletedSceneDialog("S2_M2_PZ_01", "S2_M2_PZ1_DL_00_03");


		PuzzleManager::createPuzzle("S2_M2_PZ_02", TYPE_READ_PUZZLE); //씨앗
		PuzzleManager::setPuzzleReward("S2_M2_PZ_02", 0, "S2_M2_PZ_SEED");
		PuzzleManager::setPuzzleSceneDialog("S2_M2_PZ_02", 0, TYPE_CL_DL, "S2_M2_PZ2_DL_00_00");
		PuzzleManager::setCompletedSceneDialog("S2_M2_PZ_02", "S2_M2_PZ2_DL_00_01"); //더이상 얻을 것이 없어보인다.

		PuzzleManager::createPuzzle("S2_M3_PZ_01", TYPE_ITEM_PUZZLE); //화분
		PuzzleManager::setPuzzleObjectASCII("S2_M3_PZ_01", 0, "src\\S2_M3_PZ_01_01.png");
		PuzzleManager::setPuzzleObjectASCII("S2_M3_PZ_01", 1, "src\\S2_M3_PZ_01_02.png");
		PuzzleManager::setPuzzleConditionItem("S2_M3_PZ_01", 0, "S2_M2_PZ_SEED");
		PuzzleManager::setPuzzleReward("S2_M3_PZ_01", 1, "S2_M2_PZ_POT");

		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_01", 0, TYPE_NCL_DL, "S2_M3_PZ1_DL_00_00"); //텅 빈 화분이다
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_01", 0, TYPE_CL_DL, "S2_M3_PZ1_DL_00_01"); //화분에다 씨앗을 심었다.
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_01", 1, TYPE_CL_DL, "S2_M3_PZ1_DL_00_02"); //화분을 얻었다.

		PuzzleManager::setCompletedObjectASCII("S2_M3_PZ_01", "src\\S2_M3_PZ_01_03.png");


		PuzzleManager::createPuzzle("S2_M3_PZ_02", TYPE_ITEM_PUZZLE); //균열 서랍
		PuzzleManager::setPuzzleObjectASCII("S2_M3_PZ_02", 0, "src\\S2_M3_PZ_02_01.png");
		PuzzleManager::setPuzzleObjectASCII("S2_M3_PZ_02", 1, "src\\S2_M3_PZ_02_02.png");
		PuzzleManager::setPuzzleObjectASCII("S2_M3_PZ_02", 2, "src\\S2_M3_PZ_02_03.png");
		PuzzleManager::setPuzzleReward("S2_M3_PZ_02", 0, "S2_M1_PZ_KEY");
		PuzzleManager::setPuzzleConditionItem("S2_M3_PZ_02", 1, "S2_M2_PZ_LIGHTER");
		PuzzleManager::setPuzzleReward("S2_M3_PZ_02", 2, "S2_M2_PZ_FLOWER");
		PuzzleManager::setPuzzleConditionItem("S2_M3_PZ_02", 2, "S2_M2_PZ_POT");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 0, TYPE_CL_DL, "S2_M3_PZ2_DL_00_00");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 0, TYPE_CL_DL, "S2_M3_PZ2_DL_00_01");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 1, TYPE_CL_DL, "S2_M3_PZ2_DL_00_02");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 1, TYPE_CL_DL, "S2_M3_PZ2_DL_00_03");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 2, TYPE_NCL_DL, "S2_M3_PZ2_DL_00_04");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 2, TYPE_CL_DL, "S2_M3_PZ2_DL_00_05");
		PuzzleManager::setPuzzleSceneDialog("S2_M3_PZ_02", 2, TYPE_CL_DL, "S2_M3_PZ2_DL_00_06");

		//GameObjectManager::getCharacter("Hero")->addInventory("S2_M2_PZ_FLOWER");
		//GameObjectManager::getCharacter("Hero")->addInventory("S2_M2_PZ_LIGHTER");
		//GameObjectManager::getCharacter("Hero")->addInventory("S2_M2_PZ_POT");

		PuzzleManager::createPuzzle("S3_M1_PZ_01", TYPE_NUMBER_PUZZLE);
		PuzzleManager::setPuzzleDetailASCII("S3_M1_PZ_01", 0, "src\\S3_M1_PZ_DT_01_01.png");

		PuzzleManager::setCorrectAnswer("S3_M1_PZ_01", 6);
		PuzzleManager::setCorrectAnswer("S3_M1_PZ_01", 1);
		PuzzleManager::setCorrectAnswer("S3_M1_PZ_01", 2);
		PuzzleManager::setCorrectAnswer("S3_M1_PZ_01", 1);

		PuzzleManager::setPuzzleSceneDialog("S3_M1_PZ_01", 0, TYPE_NCL_DL, "S3_M1_PZ1_DL_00_00");
		PuzzleManager::setPuzzleSceneDialog("S3_M1_PZ_01", 0, TYPE_CL_DL, "S3_M1_PZ1_DL_01_00");

		PuzzleManager::createPuzzle("S3_M1_PZ_02", TYPE_READ_PUZZLE);
		PuzzleManager::setCompletedDetailASCII("S3_M1_PZ_02", "src\\S3_M1_PZ_DT_02_01.png");
	};

	static void MapInit() {

		MapManager::createMap("S2_J_MAP_01", TYPE_JUMP, "src\\S3_J_MAP_01.png", "src\\S3_J_MAP_INFO_01.png");
		MapManager::createMap("S2_P_MAP_01", TYPE_PUZZLE, "src\\S2_P_MAP_01.png", "src\\S2_P_MAP_INFO_01.png");
		MapManager::createMap("S2_P_MAP_02", TYPE_PUZZLE, "src\\S2_P_MAP_02.png", "src\\S2_P_MAP_INFO_02.png");
		MapManager::createMap("S2_P_MAP_03", TYPE_PUZZLE, "src\\S2_P_MAP_03.png", "src\\S2_P_MAP_INFO_03.png");
		MapManager::createMap("S3_J_MAP_01", TYPE_JUMP, "src\\S3_J_MAP_01.png", "src\\S3_J_MAP_INFO_01.png");
		MapManager::createMap("S3_P_MAP_01", TYPE_PUZZLE, "src\\S3_P_MAP_01.png", "src\\S3_P_MAP_INFO_01.png");
	};

	static void StageInit(EventDispatcher* eventDispathcer) {
		for (int i = 0; i < 4; i++) {
			StageManager::addStage(i, eventDispathcer);
		}


		StageManager::addMap(0, MapManager::getMap("S2_P_MAP_01"));
		StageManager::addMap(0, MapManager::getMap("S2_P_MAP_02"));
		StageManager::addMap(0, MapManager::getMap("S2_P_MAP_03"));
		StageManager::addMap(0, MapManager::getMap("S2_J_MAP_01"));
		StageManager::addMap(0, MapManager::getMap("S3_P_MAP_01"));
		StageManager::addMap(0, MapManager::getMap("S3_J_MAP_01"));


		StageManager::setDoorID(0, "S2_P_MAP_01", MAP_EXIT, "S2_J_MAP_01");
		StageManager::setDoorID(0, "S2_P_MAP_01", MAP_DOOR_01, "S2_P_MAP_02");
		StageManager::setDoorID(0, "S2_P_MAP_01", MAP_DOOR_02, "S2_P_MAP_03");
		StageManager::setDoorID(0, "S2_P_MAP_02", MAP_DOOR_02, "S2_P_MAP_01");
		StageManager::setDoorID(0, "S2_P_MAP_03", MAP_DOOR_02, "S2_P_MAP_01");
		StageManager::setDoorID(0, "S2_J_MAP_01", MAP_EXIT, "S3_P_MAP_01");
		StageManager::setDoorID(0, "S3_P_MAP_01", MAP_EXIT, "S3_J_MAP_01");

		StageManager::setPuzzleId(0, "S2_P_MAP_01", PUZZLE_OBJ_01, "S2_M1_PZ_01");

		StageManager::setPuzzleId(0, "S2_P_MAP_02", PUZZLE_OBJ_01, "S2_M2_PZ_01");
		StageManager::setPuzzleId(0, "S2_P_MAP_02", PUZZLE_OBJ_02, "S2_M2_PZ_02");

		StageManager::setPuzzleId(0, "S2_P_MAP_03", PUZZLE_OBJ_01, "S2_M3_PZ_01");
		StageManager::setPuzzleId(0, "S2_P_MAP_03", PUZZLE_OBJ_02, "S2_M3_PZ_02");

		StageManager::setPuzzleId(0, "S3_P_MAP_01", PUZZLE_OBJ_01, "S3_M1_PZ_01");
		StageManager::setPuzzleId(0, "S3_P_MAP_01", PUZZLE_OBJ_02, "S3_M1_PZ_02");

		MapManager::setMapASCII("S2_P_MAP_01");
		MapManager::setMapASCII("S2_P_MAP_02");
		MapManager::setMapASCII("S2_P_MAP_03");
		MapManager::setMapASCII("S2_J_MAP_01");
		MapManager::setMapASCII("S3_J_MAP_01");
		MapManager::setMapASCII("S3_P_MAP_01");
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