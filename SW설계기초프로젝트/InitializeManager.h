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
        GameObjectManager::createObject("Character", "Hero", "src\\hero_idle_right_01.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE_RIGHT", 1, "src\\hero_idle_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE_LEFT", "src\\hero_idle_left_01.png", "src\\hero_idle_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("RIGHT", "src\\hero_right_01.png", "src\\hero_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("LEFT", "src\\hero_left_01.png", "src\\hero_left_02.png");


        GameObjectManager::createObject("Character", "Sister", "src\\sister_idle_right_01.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_RIGHT", 1, "src\\sister_idle_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_LEFT", "src\\sister_idle_left_01.png", "src\\sister_idle_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");


        //Dialoginit

        GameObjectManager::createObject("Dialog", "NUMBER_WINDOW", "");
        GameObjectManager::createObject("Dialog", "PZ_NCL_DL", "문이 열리지 않아...");

        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_01", "열쇠를 사용한다.");

        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_00", "석상: 바깥 세상이 보고싶어...");
        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_01", "석상: 바깥 세상을 보여줘서 고마워");
        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_02", "히로: 석상에 문이 막혀 들어갈 수가 없어");

        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_01", "[열쇠]를 사용한다.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_02", "[망치]를 얻었다.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_03", "서랍에서 더이상 얻을 것이 없어보인다.");

        GameObjectManager::createObject("Dialog", "S7_M2_PZ2_DL_00_00", "[씨앗]을 얻었다.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ2_DL_00_01", "더 이상 얻을 것이 없어보인다.");

        GameObjectManager::createObject("Dialog", "S7_M3_PZ1_DL_00_00", "흙밖에 없는 텅 빈 화분이다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ1_DL_00_01", "화분에 씨앗을 심었더니 싹이 곧바로 자랐다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ1_DL_00_02", "[씨앗을 심은 화분]을 얻었다");

        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_00", "문이 열리면서 [균열]이 생겼다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_01", "열린 문 사이로 [열쇠]를 얻었다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_02", "[망치]를 갖다대자 균열이 깨졌다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_03", "문 틈 사이로 [물줄기]가 나왔다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_04", "화분을 가져다 놓으면 좋을 거 같다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_05", "[물줄기]에 [화분]을 갖다대니 꽃이 폈다.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_06", "[꽃이 핀 화분]을 얻었다.");

        GameObjectManager::createObject("Dialog", "NUM_PZ_NCL_DL", "비밀번호가 틀렸습니다.");
        GameObjectManager::createObject("Dialog", "NUM_PZ_CL_DL", "비밀번호가 맞았습니다.");

    };

    static void SceneInit() {
        Scene S0_SC1, S0_SC2, S1_SC1, S1_SC2, S1_SC3, S1_SC4, S2_SC1, S2_SC2, S2_SC3, S3_SC1, S3_SC2, S3_SC3, S4_SC1, S4_SC2, S5_SC1, S5_SC2;

        //S0_SC1 프롤로그
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_01", "오래전부터 전해 마을에 내려오는 전설이 있다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_02", "깊은 숲 속, 시간마저 멈춘 듯한 고요한 탑.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_03", "누가 세웠는지, 언제 세워졌는지조차 잊힌 채 탑은 그 자리에 있을 뿐이다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_04", "탑의 가장 꼭대기, 신비로운 우물에 소원을 빌면, 그 어떤 바람도 이루어진다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_05", "오직 한 미신만이 내려져 오며 탑의 존재조차 희미해져 갔다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_06", "허나 한 사람에게는 이 오래된 전설이 마지막 희망이었으니..");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_07", "저 거대한 문이 천천히 열리고, 운명을 바꿀 여정이 시작된다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_08", "히로: 나는 어머니를 위해 끝까지 올라갈 거야.");

        S0_SC1.setDetail("src\\S0_SC1_00.png");
        S0_SC1.setDialog("S0_SC1_DL_01");
        S0_SC1.setDialog("S0_SC1_DL_02");
        S0_SC1.setDialog("S0_SC1_DL_03");
        S0_SC1.setDialog("S0_SC1_DL_04");
        S0_SC1.setDialog("S0_SC1_DL_05");
        S0_SC1.setDialog("S0_SC1_DL_06");
        S0_SC1.setDialog("S0_SC1_DL_07");
        S0_SC1.setDialog("S0_SC1_DL_08");

        //S0_SC2.setDetail("src\\S0_SC2_00.png"); //여기는 탑의 입구임. 이거 그려야해


        //S1_SC1 퍼즐1층 씬 (석판을 보기전)
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_01", "리안: 분위기가 심상치가 않네... 마을에서 못 보던 물건들도 많고 말이야.");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_02", "리안: 여기 이거 봐! 뭔가 적혀있어!");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_03", "벽에 걸려있는 그림과 상호작용하려면 F 키를 눌러보세요.");

        S1_SC1.setAction("Sister", ACTION_MOVE_X, 6, 10);

        S1_SC1.setDelay("Sister", 64);
        S1_SC1.setAction("Sister", ACTION_MOVE_X, -1);
        S1_SC1.setDelay("Sister", 700);
        S1_SC1.setAction("Sister", ACTION_MOVE_X, 1);
        S1_SC1.setDelay("Sister", 700);

        S1_SC1.setDetail("src\\export.png");
        S1_SC1.setDelay("Sister", 1000);

        S1_SC1.setDialog("S1_SC1_DL_01");
        S1_SC1.setDialog("S1_SC1_DL_02");
        S1_SC1.setDialog("S1_SC1_DL_03");
        S1_SC1.setDetail("");

        //S1_SC2 퍼즐1층 씬 (석판을 보고난 후)
        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "리안: 소문이 사실인가봐. 저기 끝에 문이 있는거 같은데 가보자!");

        S1_SC2.setDialog("S1_SC2_DL_01");

        //S1_SC3 점프1층 씬
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_01", "리안: 여긴 뭐야. 엄청 위험해보이잖아.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_02", "리안: 잠시만, 이걸 그냥 맨몸으로 지나가겠다고 ? ");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_03", "리안: 자 이러면 안전하게   갈 수 있을거야.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_04", "상하좌우와 스페이스바로 이동과 점프, 그리고 대쉬를 할 수 있습니다.");

        S1_SC3.setDelay("Sister", 700);
        S1_SC3.setDialog("S1_SC3_DL_01");
        S1_SC3.setDialog("S1_SC3_DL_02");
        S1_SC3.setAction("Sister", ACTION_MOVE_X, 2, 4);
        //S1_SC3 얼음 작렬
        S1_SC3.setDialog("S1_SC3_DL_03");
        S1_SC3.setDialog("S1_SC3_DL_04");

        //S1_SC4 계단층 씬
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_01", "리안: 왜 성 안에 저런 길이 있을까? 어쨌든 내가 있으니 걱정하지마.");
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_02", "리안: 우리 없는 동안에 엄마는 괜찮겠지? 빨리 집으로 돌아가고 싶다…");
        S1_SC4.setDelay("Sister", 700);
        S1_SC4.setDialog("S1_SC4_DL_01");
        S1_SC4.setDialog("S1_SC4_DL_02");

        //S2_SC1 퍼즐2층 씬

        GameObjectManager::createObject("Dialog", "S2_SC1_DL_01", "리안: 돌 부스러기…? 여기저기 막 부서져 있네 ? ");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_02", "리안: 성이라고 하기엔 관리가 제대로 안 된 것 같아.");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_03", "리안: 자, 어서 가보자!");

        S1_SC3.setDelay("Sister", 700);
        S1_SC3.setAction("Sister", ACTION_MOVE_X, 6, 15); //석상 앞에 여동생이 가게끔 조정
        S2_SC1.setDialog("S2_SC1_DL_01");
        S2_SC1.setDialog("S2_SC1_DL_02");
        S2_SC1.setDialog("S2_SC1_DL_03");


        //S2_SC2 점프2층 씬
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_01", "리안: 여기도 상당히 위험   하네.");
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_02", "특정 벽은 \"키\"로 벽타기를 할 수 있습니다.");
        S2_SC2.setDelay("Sister", 700);
        S2_SC2.setDialog("S2_SC2_DL_01");
        S2_SC2.setDialog("S2_SC2_DL_02");

        //S2_SC3 점프2층 씬
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_01", "리안: 우물로 가면 정말 소원을 들어주는 거 맞겠지?");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_02", "리안: 앞으로도 층마다 이런 구조일 것 같은데… 뭔가 이상해.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_03", "리안: 여기저기 뭔가 건드린 흔적이 있는 것 같아.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_04", "리안: 뭔가 있어야 할 게 없는 느낌이야... 누가 먼저 지나간걸까…?");

        S2_SC3.setAction("Sister", ACTION_MOVE_X, 6, 5);
        S2_SC3.setDialog("S2_SC3_DL_01");
        S2_SC3.setDialog("S2_SC3_DL_02");
        S2_SC3.setAction("Hero", ACTION_MOVE_X, 6, 5);
        S2_SC3.setDelay("Sister", 700);
        S2_SC3.setAction("Sister", ACTION_MOVE_X, -1);
        S2_SC3.setDelay("Sister", 700);
        S2_SC3.setAction("Sister", ACTION_MOVE_X, 1);
        S2_SC3.setDelay("Sister", 700);
        S2_SC3.setDialog("S2_SC3_DL_03");
        S2_SC3.setDialog("S2_SC3_DL_04");
        S2_SC3.setDelay("Sister", 700);

        //S3_SC2
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_01", "리안: 우와… 여긴 정말 위험해 보이네.");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_02", "리안: 지금까지 봤던 곳들과는 완전히 다르잖아. 넘어갈 수 있을까?");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_03", "지금까지 배운 것을 활용하여 방을 클리어해보세요.");

        S2_SC3.setDelay("Sister", 700);
        S2_SC3.setDialog("S3_SC2_DL_01");
        S2_SC3.setDialog("S3_SC2_DL_02");
        S2_SC3.setDialog("S3_SC2_DL_03");

        //S3_SC3
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_01", "리안: 이 성은 구조도 참 이상하고, 본 적도 들은 적도 없는 물건들로 가득하네.");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_02", "리안: 도대체 누가, 왜 이런 성을 만든 걸까?");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_03", "리안: 우물에 대한 소문도 이 정도면 정말 사실일 것 같아! 빨리 가보자!");

        S3_SC3.setDelay("Sister", 700);
        S3_SC3.setDialog("S3_SC3_DL_01");
        S3_SC3.setDialog("S3_SC3_DL_02");
        S3_SC3.setDialog("S3_SC3_DL_03");

        //S4_SC1
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_01", "리안: 여기도 뭔가 이상한 구조물이 있어… 그리고 또 이미 풀려있네.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_02", "리안: 흠… 뭔가 으스스 해…");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_03", "리안: 엄마 기다리겠다! 얼른 움직이자.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_04", "히로: 그래. 일단 움직여야겠다.");

        S4_SC1.setAction("Sister", ACTION_MOVE_X, 6, 5);
        S4_SC1.setDialog("S4_SC1_DL_01");
        S4_SC1.setDialog("S4_SC1_DL_02");
        S4_SC1.setAction("Hero", ACTION_MOVE_X, 6, 5);
        S4_SC1.setDelay("Sister", 700);
        S4_SC1.setAction("Sister", ACTION_MOVE_X, -1);
        S4_SC1.setDelay("Sister", 700);
        S4_SC1.setAction("Sister", ACTION_MOVE_X, 1);
        S4_SC1.setDelay("Sister", 700);
        S4_SC1.setDialog("S4_SC1_DL_03");
        S4_SC1.setDialog("S4_SC1_DL_04");
        S4_SC1.setDelay("Sister", 700);

        //S4_SC1
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_01", "리안: 여기도 뭔가 이상한 구조물이 있어… 그리고 또 이미 풀려있네.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_02", "리안: 흠… 뭔가 으스스 해…");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_03", "리안: 엄마 기다리겠다! 얼른 움직이자.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_04", "히로: 그래. 일단 움직여야겠다.");
        /*GameObjectManager::createObejct("Dialog", "S6_SC1_DL_01", "히로: … 흔적들… 일기장… 그리고 이 탑.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_02", "???: 많은 이들이 이곳에 발을 들였지.저마다 자신의 바람을 이루기 위해.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_03", "히로: 넌 그걸 모두 지켜보고 있었겠지.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_04", "???: 선택의 순간은 언제나 흥미롭지.희망과 절망이 교차하는 찰나를 보는 것만큼 흥미로운 일은 없으니까.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_05", "히로: 기사… 그의 기록을 읽었어.그는 결국 이 탑을 떠나지 못했지.");


        newScene.setDetail("src\\sc6\\sc01.png");
        newScene.setDelay("Sister", 700);
        newScene.setDialog("S6_SC1_DL_01");
        //newScene.setDetail("src\\sc6\\sc02.png");
        newScene.setDetail("src\\sc6\\sc03.png");
        //newScene.setDetail("src\\sc6\\sc04.png");
        newScene.setDetail("src\\sc6\\sc05.png");
        //newScene.setDetail("src\\sc6\\sc06.png");
        newScene.setDetail("src\\sc6\\sc07.png");
        //newScene.setDetail("src\\sc6\\sc08.png");
        newScene.setDetail("src\\sc6\\sc09.png");
        //newScene.setDetail("src\\sc6\\sc10.png");
        newScene.setDetail("src\\sc6\\sc11.png");
        //newScene.setDetail("src\\sc6\\sc12.png");
        newScene.setDetail("src\\sc6\\sc13.png");
        newScene.setDelay("Sister", 700);
        newScene.setDialog("S6_SC1_DL_02");
        newScene.setDetail("src\\sc6\\sc14.png");
        newScene.setDetail("src\\sc6\\sc15.png");
        newScene.setDetail("src\\sc6\\sc16.png");
        newScene.setDetail("src\\sc6\\sc17.png");
        newScene.setDetail("src\\sc6\\sc18.png");
        newScene.setDetail("src\\sc6\\sc19.png");
        newScene.setDetail("src\\sc6\\sc20.png");
        newScene.setDetail("src\\sc6\\sc21.png");
        newScene.setDetail("src\\sc6\\sc22.png");
        newScene.setDelay("Sister", 700);
        newScene.setDialog("S6_SC1_DL_03");
        newScene.setDialog("S6_SC1_DL_02");
        newScene.setDetail("");



        newScene.setAction("Sister", ACTION_MOVE_X, 6, 10);

        newScene.setDelay("Sister", 64);
        newScene.setAction("Sister", ACTION_MOVE_X, -1);
        newScene.setDelay("Sister", 700);
        newScene.setAction("Sister", ACTION_MOVE_X, 1);
        newScene.setDelay("Sister", 700);

        newScene.setDetail("src\\export.png");
        newScene.setDelay("Sister", 1000);

        newScene.setDialog("SC1_DL_01");
        newScene.setDialog("SC1_DL_02");
        newScene.setDetail("");


        newScene.display();
        */
        SceneMananger::addScene("S0_SC1", S0_SC1);
        SceneMananger::addScene("S0_SC2", S0_SC2);
        SceneMananger::addScene("S1_SC1", S1_SC1);
        SceneMananger::addScene("S1_SC2", S1_SC2);
        SceneMananger::addScene("S1_SC3", S1_SC3);
        SceneMananger::addScene("S1_SC4", S1_SC4);
        SceneMananger::addScene("S2_SC1", S2_SC1);
        SceneMananger::addScene("S2_SC2", S2_SC2);
        SceneMananger::addScene("S2_SC3", S2_SC3);
        SceneMananger::addScene("S3_SC1", S3_SC1);
        SceneMananger::addScene("S3_SC2", S3_SC2);
        SceneMananger::addScene("S3_SC3", S3_SC3);
        SceneMananger::addScene("S4_SC1", S4_SC1);
        SceneMananger::addScene("S4_SC2", S4_SC2);
        SceneMananger::addScene("S5_SC1", S5_SC1);
        SceneMananger::addScene("S5_SC2", S5_SC2);
    }


    static void Iteminit() {
        ItemManager::addItems("S7_M1_PZ_KEY", 1);
        ItemManager::addItems("S7_M2_PZ_SEED", 1);
        ItemManager::addItems("S7_M2_PZ_LIGHTER", 1);
        ItemManager::addItems("S7_M2_PZ_POT", 1);
        ItemManager::addItems("S7_M2_PZ_FLOWER", 1);
    }

    static void PuzzleInit() {

        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE); //석판
        PuzzleManager::setCompletedObjectASCII("S1_M1_PZ_01", "src\\S6_M1_PZ_DT_01.png");

        PuzzleManager::createPuzzle("S2_M1_PZ_01", TYPE_READ_PUZZLE); //석상에 가로막힌 문
        PuzzleManager::setCompletedSceneDialog("S2_M1_PZ_01", "S7_M1_PZ1_DL_00_02");

        PuzzleManager::createPuzzle("S3_M1_PZ_01", TYPE_READ_PUZZLE); //피아노 보여주기
        PuzzleManager::setCompletedDetailASCII("S3_M1_PZ_01", "src\\S8_M1_PZ_DT_02_01.png");
        PuzzleManager::createPuzzle("S6_M1_PZ_01", TYPE_NUMBER_PUZZLE); //석판을 보고 비밀번호 입력 부분

        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 0);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 4);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 3);

        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S6_M1_PZ_02", TYPE_READ_PUZZLE); //석판
        PuzzleManager::setPuzzleDetailASCII("S6_M1_PZ_02", 0, "src\\S6_M1_PZ_DT_01.png");

        PuzzleManager::createPuzzle("S7_M1_PZ_01", TYPE_ITEM_PUZZLE); //석상
        PuzzleManager::setPuzzleObjectASCII("S7_M1_PZ_01", 0, "src\\S7_M1_PZ_01_01.png");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_NCL_DL, "S7_M1_PZ1_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_CL_DL, "S7_M1_PZ1_DL_00_01");
        PuzzleManager::setPuzzleConditionItem("S7_M1_PZ_01", 0, "S7_M2_PZ_FLOWER");
        PuzzleManager::setCompletedObjectASCII("S7_M1_PZ_01", "src\\S7_M1_PZ_01_02.png");
        PuzzleManager::setCompletedSceneDialog("S7_M1_PZ_01", "S7_M1_PZ1_DL_00_02");

        PuzzleManager::createPuzzle("S7_M2_PZ_01", TYPE_ITEM_PUZZLE); //서랍
        PuzzleManager::setPuzzleConditionItem("S7_M2_PZ_01", 0, "S7_M1_PZ_KEY");
        PuzzleManager::setPuzzleReward("S7_M2_PZ_01", 0, "S7_M2_PZ_LIGHTER");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_01", 0, TYPE_NCL_DL, "S7_M2_PZ1_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_01", 0, TYPE_CL_DL, "S7_M2_PZ1_DL_00_01");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_01", 0, TYPE_CL_DL, "S7_M2_PZ1_DL_00_02");
        PuzzleManager::setCompletedSceneDialog("S7_M2_PZ_01", "S7_M2_PZ1_DL_00_03");

        PuzzleManager::createPuzzle("S7_M2_PZ_02", TYPE_READ_PUZZLE); //씨앗
        PuzzleManager::setPuzzleReward("S7_M2_PZ_02", 0, "S7_M2_PZ_SEED");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_02", 0, TYPE_CL_DL, "S7_M2_PZ2_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S7_M2_PZ_02", "S7_M2_PZ2_DL_00_01"); //더이상 얻을 것이 없어보인다.

        PuzzleManager::createPuzzle("S7_M3_PZ_01", TYPE_ITEM_PUZZLE); //화분
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 0, "src\\S7_M3_PZ_01_01.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 1, "src\\S7_M3_PZ_01_02.png");
        PuzzleManager::setPuzzleConditionItem("S7_M3_PZ_01", 0, "S7_M2_PZ_SEED");
        PuzzleManager::setPuzzleReward("S7_M3_PZ_01", 1, "S7_M2_PZ_POT");

        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_NCL_DL, "S7_M3_PZ1_DL_00_00"); //텅 빈 화분이다
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_CL_DL, "S7_M3_PZ1_DL_00_01"); //화분에다 씨앗을 심었다.
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 1, TYPE_CL_DL, "S7_M3_PZ1_DL_00_02"); //화분을 얻었다.

        PuzzleManager::setCompletedObjectASCII("S7_M3_PZ_01", "src\\S7_M3_PZ_01_03.png");

        PuzzleManager::createPuzzle("S7_M3_PZ_02", TYPE_ITEM_PUZZLE); //균열 서랍
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_02", 0, "src\\S7_M3_PZ_02_01.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_02", 1, "src\\S7_M3_PZ_02_02.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_02", 2, "src\\S7_M3_PZ_02_03.png");
        PuzzleManager::setPuzzleReward("S7_M3_PZ_02", 0, "S7_M1_PZ_KEY");
        PuzzleManager::setPuzzleConditionItem("S7_M3_PZ_02", 1, "S7_M2_PZ_LIGHTER");
        PuzzleManager::setPuzzleReward("S7_M3_PZ_02", 2, "S7_M2_PZ_FLOWER");
        PuzzleManager::setPuzzleConditionItem("S7_M3_PZ_02", 2, "S7_M2_PZ_POT");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 0, TYPE_CL_DL, "S7_M3_PZ2_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 0, TYPE_CL_DL, "S7_M3_PZ2_DL_00_01");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 1, TYPE_CL_DL, "S7_M3_PZ2_DL_00_02");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 1, TYPE_CL_DL, "S7_M3_PZ2_DL_00_03");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 2, TYPE_NCL_DL, "S7_M3_PZ2_DL_00_04");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 2, TYPE_CL_DL, "S7_M3_PZ2_DL_00_05");
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_02", 2, TYPE_CL_DL, "S7_M3_PZ2_DL_00_06");

        //GameObjectManager::getCharacter("Hero")->addInventory("S7_M2_PZ_FLOWER");
        //GameObjectManager::getCharacter("Hero")->addInventory("S7_M2_PZ_LIGHTER");
        //GameObjectManager::getCharacter("Hero")->addInventory("S7_M2_PZ_POT");

        PuzzleManager::createPuzzle("S8_M1_PZ_01", TYPE_NUMBER_PUZZLE);
        PuzzleManager::setPuzzleDetailASCII("S8_M1_PZ_01", 0, "src\\S8_M1_PZ_DT_01_01.png");

        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 6);
        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 2);
        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 1);

        PuzzleManager::setPuzzleSceneDialog("S8_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S8_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S8_M1_PZ_02", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedDetailASCII("S8_M1_PZ_02", "src\\S8_M1_PZ_DT_02_01.png");
    };

    static void MapInit() {
        MapManager::createMap("S1_P_MAP_01", TYPE_PUZZLE, "src\\S1_P_MAP_01.png", "src\\S1_P_MAP_INFO_01.png");
        MapManager::createMap("S1_J_MAP_01", TYPE_JUMP, "src\\S1_J_MAP_01.png", "src\\S1_J_MAP_INFO_01.png");
        MapManager::createMap("S2_P_MAP_01", TYPE_PUZZLE, "src\\S2_P_MAP_01.png", "src\\S2_P_MAP_INFO_01.png");
        MapManager::createMap("S2_J_MAP_01", TYPE_JUMP, "src\\S2_J_MAP_01.png", "src\\S2_J_MAP_INFO_01.png");
        MapManager::createMap("S3_P_MAP_01", TYPE_PUZZLE, "src\\S3_P_MAP_01.png", "src\\S3_P_MAP_INFO_01.png");
        MapManager::createMap("S3_J_MAP_01", TYPE_JUMP, "src\\S3_J_MAP_01.png", "src\\S3_J_MAP_INFO_01.png");

        MapManager::createMap("S6_P_MAP_01", TYPE_PUZZLE, "src\\S6_P_MAP_01.png", "src\\S6_P_MAP_INFO_01.png");
        MapManager::createMap("S6_J_MAP_01", TYPE_JUMP, "src\\S6_J_MAP_01.png", "src\\S6_J_MAP_INFO_01.png");
        MapManager::createMap("S7_P_MAP_01", TYPE_PUZZLE, "src\\S7_P_MAP_01.png", "src\\S7_P_MAP_INFO_01.png");
        MapManager::createMap("S7_P_MAP_02", TYPE_PUZZLE, "src\\S7_P_MAP_02.png", "src\\S7_P_MAP_INFO_02.png");
        MapManager::createMap("S7_P_MAP_03", TYPE_PUZZLE, "src\\S7_P_MAP_03.png", "src\\S7_P_MAP_INFO_03.png");
        MapManager::createMap("S7_J_MAP_01", TYPE_JUMP, "src\\S7_J_MAP_01.png", "src\\S7_J_MAP_INFO_01.png");
        MapManager::createMap("S8_J_MAP_01", TYPE_JUMP, "src\\S8_J_MAP_01.png", "src\\S8_J_MAP_INFO_01.png");
        MapManager::createMap("S8_P_MAP_01", TYPE_PUZZLE, "src\\S8_P_MAP_01.png", "src\\S8_P_MAP_INFO_01.png");
    };


    static void StageInit(EventDispatcher* eventDispathcer) {
        for (int i = 1; i < 10; i++) {
            StageManager::addStage(i, eventDispathcer);
        }
        //E_S1
        StageManager::addMap(1, MapManager::getMap("S1_P_MAP_01"));
        StageManager::addMap(1, MapManager::getMap("S1_J_MAP_01"));

        StageManager::setDoorID(1, "S1_P_MAP_01", MAP_EXIT, "S1_J_MAP_01");
        StageManager::setDoorID(1, "S1_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(1, "S1_P_MAP_01", PUZZLE_OBJ_02, "S1_M1_PZ_01");

        //E_S2
        StageManager::addMap(2, MapManager::getMap("S2_P_MAP_01"));
        StageManager::addMap(2, MapManager::getMap("S2_J_MAP_01"));

        StageManager::setDoorID(2, "S2_P_MAP_01", MAP_EXIT, "S2_J_MAP_01");
        StageManager::setDoorID(2, "S2_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(2, "S2_P_MAP_01", PUZZLE_OBJ_01, "S2_M1_PZ_01");

        //E_S3
        StageManager::addMap(3, MapManager::getMap("S3_P_MAP_01"));
        StageManager::addMap(3, MapManager::getMap("S3_J_MAP_01"));

        StageManager::setDoorID(3, "S3_P_MAP_01", MAP_EXIT, "S3_J_MAP_01");
        StageManager::setDoorID(3, "S3_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(3, "S3_P_MAP_01", PUZZLE_OBJ_02, "S3_M1_PZ_01");

        //H_S1
        StageManager::addMap(5, MapManager::getMap("S6_P_MAP_01"));
        StageManager::addMap(5, MapManager::getMap("S6_J_MAP_01"));

        StageManager::setDoorID(5, "S6_P_MAP_01", MAP_EXIT, "S6_J_MAP_01");
        StageManager::setDoorID(5, "S6_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(5, "S6_P_MAP_01", PUZZLE_OBJ_01, "S6_M1_PZ_01");
        StageManager::setPuzzleId(5, "S6_P_MAP_01", PUZZLE_OBJ_02, "S6_M1_PZ_02");

        //H_S2
        StageManager::addMap(6, MapManager::getMap("S7_P_MAP_01"));
        StageManager::addMap(6, MapManager::getMap("S7_P_MAP_02"));
        StageManager::addMap(6, MapManager::getMap("S7_P_MAP_03"));
        StageManager::addMap(6, MapManager::getMap("S7_J_MAP_01"));

        StageManager::setDoorID(6, "S7_P_MAP_01", MAP_DOOR_01, "S7_P_MAP_02");
        StageManager::setDoorID(6, "S7_P_MAP_01", MAP_DOOR_02, "S7_P_MAP_03");
        StageManager::setDoorID(6, "S7_P_MAP_02", MAP_DOOR_02, "S7_P_MAP_01");
        StageManager::setDoorID(6, "S7_P_MAP_03", MAP_DOOR_02, "S7_P_MAP_01");
        StageManager::setDoorID(6, "S7_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(6, "S7_P_MAP_01", PUZZLE_OBJ_01, "S7_M1_PZ_01");
        StageManager::setPuzzleId(6, "S7_P_MAP_02", PUZZLE_OBJ_01, "S7_M2_PZ_01");
        StageManager::setPuzzleId(6, "S7_P_MAP_02", PUZZLE_OBJ_02, "S7_M2_PZ_02");
        StageManager::setPuzzleId(6, "S7_P_MAP_03", PUZZLE_OBJ_01, "S7_M3_PZ_01");
        StageManager::setPuzzleId(6, "S7_P_MAP_03", PUZZLE_OBJ_02, "S7_M3_PZ_02");

        //H_S3
        StageManager::addMap(7, MapManager::getMap("S8_P_MAP_01"));
        StageManager::addMap(7, MapManager::getMap("S8_J_MAP_01"));

        StageManager::setDoorID(7, "S8_P_MAP_01", MAP_EXIT, "S8_J_MAP_01");

        StageManager::setPuzzleId(7, "S8_P_MAP_01", PUZZLE_OBJ_01, "S8_M1_PZ_01");
        StageManager::setPuzzleId(7, "S8_P_MAP_01", PUZZLE_OBJ_02, "S8_M1_PZ_02");

        //setMapASCII
        MapManager::setMapASCII("S1_P_MAP_01");
        MapManager::setMapASCII("S1_J_MAP_01");
        MapManager::setMapASCII("S2_P_MAP_01");
        MapManager::setMapASCII("S2_J_MAP_01");
        MapManager::setMapASCII("S3_P_MAP_01");
        MapManager::setMapASCII("S3_J_MAP_01");
        MapManager::setMapASCII("S6_P_MAP_01");
        MapManager::setMapASCII("S6_J_MAP_01");
        MapManager::setMapASCII("S7_P_MAP_01");
        MapManager::setMapASCII("S7_P_MAP_02");
        MapManager::setMapASCII("S7_P_MAP_03");
        MapManager::setMapASCII("S7_J_MAP_01");
        MapManager::setMapASCII("S8_J_MAP_01");
        MapManager::setMapASCII("S8_P_MAP_01");
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