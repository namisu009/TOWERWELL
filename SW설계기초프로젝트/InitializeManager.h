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
        GameObjectManager::getCharacter("Hero")->setAnimation("CLIMB_LEFT", "src\\hero_climb_left_01.png", "src\\hero_climb_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CLIMB_RIGHT", "src\\hero_climb_right_01.png", "src\\hero_climb_right_02.png");


        GameObjectManager::createObject("Character", "Sister", "src\\sister_idle_right_01.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_RIGHT", 1, "src\\sister_idle_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_LEFT", "src\\sister_idle_left_01.png", "src\\sister_idle_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("RIGHT", "src\\sister_right_01.png", "src\\sister_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("LEFT", "src\\sister_left_01.png", "src\\sister_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("CLIMB_LEFT", "src\\sister_climb_left_01.png", "src\\sister_climb_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("CLIMB_RIGHT", "src\\sister_climb_right_01.png", "src\\sister_climb_right_02.png");


        GameObjectManager::createObject("Character", "Hood", "src\\hood_idle_right_01.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("IDLE_RIGHT", 1, "src\\hood_idle_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("IDLE_LEFT", "src\\hood_idle_left_01.png", "src\\hood_idle_left_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("RIGHT", "src\\hood_right_01.png", "src\\hood_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("LEFT", "src\\hood_left_01.png", "src\\hood_left_02.png");



        //Dialoginit

        GameObjectManager::createObject("Dialog", "NUMBER_WINDOW", "");
        GameObjectManager::createObject("Dialog", "PZ_NCL_DL", "문이 열리지 않아...");

        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_01", "열쇠를 사용한다.");

        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_00", "석상: 오랜 세월 동안 바깥 세상을 갈망해왔다...");
        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_01", "석상: 나의 갈망을 채워주어 고맙다... 메이... 꽃과 같던 그대여...");
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
        Scene S0_SC1, S0_SC2, S1_SC1, S1_SC2, S1_SC3, S1_SC4, S2_SC1, S2_SC2, S2_SC3, S3_SC1, S3_SC2, S3_SC3, S4_SC1, S4_SC2, S5_SC1, S5_SC2,
            S0_SC3, S1_SC5, S2_SC4, S4_SC3, S4_SC4, S5_SC3;

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
        S1_SC1.setDelay("Sister", 1000);

        S1_SC1.setDialog("S1_SC1_DL_01");
        S1_SC1.setDialog("S1_SC1_DL_02");
        S1_SC1.setDialog("S1_SC1_DL_03");

        //S1_SC2 퍼즐1층 씬 (석판을 보고 난 후)
        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "리안: 소문이 사실인가봐. 저기 끝에 문이 있는거 같은데 가보자!");

        //S1_SC3 점프1층 씬
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_01", "리안: 여긴 뭐야. 엄청 위험해보이잖아.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_02", "리안: 잠시만, 이걸 그냥 맨몸으로 지나가겠다고 ? ");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_03", "리안: 자 이러면 안전하게 갈 수 있을거야.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_04", "상하좌우와 스페이스바로 이동과 점프, 그리고 대쉬를 할 수 있습니다.");

        S1_SC3.setDelay("Sister", 700);
        S1_SC3.setDialog("S1_SC3_DL_01");
        S1_SC3.setDialog("S1_SC3_DL_02");
        S1_SC3.setAction("Sister", ACTION_MOVE_X, 2, 1);
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

        S2_SC1.setDelay("Sister", 700);
        S2_SC1.setAction("Sister", ACTION_MOVE_X, 6, 15); //석상 앞에 여동생이 가게끔 조정
        S2_SC1.setDialog("S2_SC1_DL_01");
        S2_SC1.setDialog("S2_SC1_DL_02");
        S2_SC1.setDialog("S2_SC1_DL_03");


        //S2_SC2 점프2층 씬
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_01", "리안: 여기도 상당히 위험하네.");
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

        //S5_SC1
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_01", "리안: 드디어 우물이 보인다!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_02", "리안: 정말 신비롭다… 이렇게 가까이 오다니 믿기지 않아.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_03", "무언가 있음을 느낀다…");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_04", "리안: 뭐? 어디?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_05", "두건녀: ……");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_06", "두건을 쓴 여자가 무언갈 중얼거리는 듯 하다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_07", "히로: 리안!! 안 돼!!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_08", "리안: 언니… ");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_09", "히로: 리안… 제발 일어나줘… 눈을 떠봐!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_10", "이미 리안은 그 밝은 눈빛을 잃은 것 같다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_11", "???: 딱하기도 하지.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_12", "우물에서 신비로우나 공허한 목소리가 들려온다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_13", "히로: 네가 꾸민 짓이지! 그 두건은 또 뭐야?!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_14", "???: 나는 오래전부터 이 옥상에 존재했던 우물일 뿐이다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_15", "???: 나는 그저 소원을 들어주는 우물로서 여기에 있을 뿐이다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_16", "히로: 그딴 말 말고, 당장 리안을 살려내!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_17", "???: 모든 소원에는 대가가 따른다. 네 여동생을 살리고 싶다면…");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_18", "???: 탑에서 가장 빛나는 것을 가지고 우물 앞으로 가져오게.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_19", "???: 그리하면 내가 응답할 것이다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_20", "히로: 대가… 탑에서 가장 빛나는 것…?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_21", "히로: 네가 없는 세상은 의미가 없어. 어떤 대가라도 치르겠어.");

        S5_SC1.setDialog("S5_SC1_DL_01");
        S5_SC1.setDialog("S5_SC1_DL_02");
        S5_SC1.setDialog("S5_SC1_DL_03");
        S5_SC1.setDialog("S5_SC1_DL_04");
        S5_SC1.setDialog("S5_SC1_DL_05");
        S5_SC1.setDialog("S5_SC1_DL_07");
        S5_SC1.setDetail("src\\S5_SC1.png");
        S5_SC1.setDialog("S5_SC1_DL_08");
        S5_SC1.setDialog("S5_SC1_DL_09");
        S5_SC1.setDialog("S5_SC1_DL_10");
        S5_SC1.setDialog("S5_SC1_DL_11");
        S5_SC1.setDialog("S5_SC1_DL_12");
        S5_SC1.setDialog("S5_SC1_DL_13");
        S5_SC1.setDialog("S5_SC1_DL_14");
        S5_SC1.setDialog("S5_SC1_DL_15");
        S5_SC1.setDialog("S5_SC1_DL_16");
        S5_SC1.setDialog("S5_SC1_DL_17");
        S5_SC1.setDialog("S5_SC1_DL_18");
        S5_SC1.setDialog("S5_SC1_DL_19");
        S5_SC1.setDialog("S5_SC1_DL_20");
        S5_SC1.setDialog("S5_SC1_DL_21");

        //S5_SC2
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_01", "깊은 우물 속으로 가라앉고 있다.");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_02", "죽을 것 같다.");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_03", "많은 정보들이 머리 속을 헤집는 느낌이다.");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_04", "내 여동생을 구해야만 해… 반드시… 리안…");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_05", "깊은 고요 속에서 주인공은 정신을 잃는다.");
        // 우물 안에서 고통받는 주인공이 나왔으면 좋겠어요.
        S5_SC2.setDialog("S5_SC2_DL_01");
        S5_SC2.setDialog("S5_SC2_DL_02");
        S5_SC2.setDialog("S5_SC2_DL_03");
        S5_SC2.setDialog("S5_SC2_DL_04");
        S5_SC2.setDialog("S5_SC2_DL_05");

        //S0_SC3

        GameObjectManager::createObject("Dialog", "S0_SC3_DL_01", "히로: …여긴…?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_02", "익숙한 탑의 입구가 눈앞에 들어온다.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_03", "히로: 아직… 아무도 오지 않은 것 같아. 시간을 돌려보낸 건가…?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_04", "히로: 리안을 구하려면 서둘러야 해. 내가 먼저 탑으로 들어가야 해.");

        S0_SC3.setDialog("S0_SC3_DL_01");
        S0_SC3.setDialog("S0_SC3_DL_02");
        S0_SC3.setDialog("S0_SC3_DL_03");
        S0_SC3.setDialog("S0_SC3_DL_04");

        //S1_SC5
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_01", "여기는…");
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_02", "탑의 1층... 일단 얼른 움직이자. 빛나는 것을 한시라도 빨리 찾아서 우물로 가야해.");

        S1_SC5.setDialog("S1_SC5_DL_01");
        S1_SC5.setDialog("S1_SC5_DL_02");
        //S2_SC4


        //S4_SC3


        //S4_SC4


        //S5_SC3
        // S5_SC3: 과거의 시간으로 돌아온 히로, 옥상의 우물에서
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_01", "히로: 우물이 원하는 게 대체 뭘까…");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_02", "히로: 난 탑의 모든 걸 뒤졌어. 아무것도 찾지 못했어.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_03", "???: 그래서 내게 화를 낼 참인가?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_04", "히로: 네가 나를 속였잖아. 애초부터 아무것도 없었던 거 아니야?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_05", "???: 속이다니, 무슨 소리를. 나는 소원을 이루는 우물이다. 이룰 방법은 네게 달려 있지.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_06", "히로: 네가 [가장 빛나는 것]을 가져오라고 했잖아! 네가 원하는 게 뭔지도 모르고 헤맸다고!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_07", "???: 너는 이미 알고 있을지도 모르지.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_08", "계단 쪽에서 발소리가 들린다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_09", "???: 이런. 손님이 온 모양이군.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_10", "리안: 드디어 우물이 보인다!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_11", "리안: 정말 신비롭다… 이렇게 가까이 오다니 믿기지 않아.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_12", "히로는 우물 뒤로 몸을 숨긴다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_13", "리안: 언니, 여기에 이상한 기운이 느껴져. 뭔가 있나 봐.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_14", "과거의 히로: 조심해, 리안. 괜히 건드리지 마.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_15", "리안의 심장 부근에서 영롱하고 아름다운 빛이 새어나온다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_16", "히로: 저건…?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_17", "리안: 언니, 여기 누군가 있는 것 같아!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_18", "과거의 히로: 리안, 뒤로 물러나.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_19", "두건을 쓴 히로가 천천히 모습을 드러낸다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_20", "리안: 저 사람은…?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_21", "히로: 미안… 리안.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_22", "히로는 칼을 뽑아들고 리안에게 다가간다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_23", "리안: 언니, 뭐 하는…?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_24", "리안: 꺄아악!!!");
		GameObjectManager::createObject("Dialog", "S5_SC3_DL_25", "탑에서 [가장 빛나는 것]을 획득했다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_26", "과거의 히로: 리안!! 안 돼!!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_27", "???: 네 선택은 끝났다.약속대로 이제 소원은 이루어진다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_28", "히로: 리안… 내가 갈게…");

		S5_SC3.setDialog("S5_SC3_DL_01");
		S5_SC3.setDialog("S5_SC3_DL_02");
		S5_SC3.setDialog("S5_SC3_DL_03");
		S5_SC3.setDialog("S5_SC3_DL_04");
		S5_SC3.setDialog("S5_SC3_DL_05");
		S5_SC3.setDialog("S5_SC3_DL_06");
		S5_SC3.setDialog("S5_SC3_DL_07");
		S5_SC3.setDialog("S5_SC3_DL_08");
		S5_SC3.setDialog("S5_SC3_DL_09");
		S5_SC3.setDialog("S5_SC3_DL_10");
		S5_SC3.setDialog("S5_SC3_DL_11");
		S5_SC3.setDialog("S5_SC3_DL_12");
		S5_SC3.setDialog("S5_SC3_DL_13");
		S5_SC3.setDialog("S5_SC3_DL_14");
		S5_SC3.setDialog("S5_SC3_DL_15");
		S5_SC3.setDialog("S5_SC3_DL_16");
		S5_SC3.setDialog("S5_SC3_DL_17");
		S5_SC3.setDialog("S5_SC3_DL_18");
		S5_SC3.setDialog("S5_SC3_DL_19");
		S5_SC3.setDialog("S5_SC3_DL_20");
		S5_SC3.setDialog("S5_SC3_DL_21");
		S5_SC3.setDialog("S5_SC3_DL_22");
		S5_SC3.setDialog("S5_SC3_DL_23");
		S5_SC3.setDialog("S5_SC3_DL_24");
		S5_SC3.setDialog("S5_SC3_DL_25");
		S5_SC3.setDialog("S5_SC3_DL_26");
		S5_SC3.setDialog("S5_SC3_DL_27");
		S5_SC3.setDialog("S5_SC3_DL_28");

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
        SceneMananger::addScene("S0_SC3", S0_SC3);
        SceneMananger::addScene("S1_SC5", S1_SC5);
        SceneMananger::addScene("S2_SC4", S2_SC4);
        SceneMananger::addScene("S4_SC3", S4_SC3);
        SceneMananger::addScene("S4_SC4", S4_SC4);
        SceneMananger::addScene("S5_SC3", S5_SC3);
    }



    static void Iteminit() {
        ItemManager::addItems("S7_M1_PZ_KEY", 1);
        ItemManager::addItems("S7_M2_PZ_SEED", 1);
        ItemManager::addItems("S7_M2_PZ_LIGHTER", 1);
        ItemManager::addItems("S7_M2_PZ_POT", 1);
        ItemManager::addItems("S7_M2_PZ_FLOWER", 1);
    }

    static void PuzzleInit() {

        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "리안: 소문이 사실인가봐. 저기 끝에 문이 있는거 같은데 가보자!");
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE); //석판
        PuzzleManager::setCompletedDetailASCII("S1_M1_PZ_01", "src\\S6_M1_PZ_DT_01.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_PZ_01", "S1_SC2_DL_01");

        PuzzleManager::createPuzzle("S2_M1_PZ_01", TYPE_READ_PUZZLE); //석상에 가로막힌 문
        PuzzleManager::setCompletedObjectASCII("S2_M1_PZ_01", "src\\S2_M1_PZ_01_02.png"); //석상에 가로막힌 문
        PuzzleManager::setCompletedSceneDialog("S2_M1_PZ_01", "S7_M1_PZ1_DL_00_02");
        PuzzleManager::setCompletedSceneLoop("S2_M1_PZ_01", true);

        PuzzleManager::createPuzzle("S3_M1_PZ_01", TYPE_READ_PUZZLE); //피아노 보여주기
        PuzzleManager::setCompletedDetailASCII("S3_M1_PZ_01", "src\\S8_M1_PZ_DT_02_01.png");



        PuzzleManager::createPuzzle("S6_M1_PZ_01", TYPE_NUMBER_PUZZLE); //석판을 보고 비밀번호 입력 부분

        PuzzleManager::setPuzzleDetailASCII("S6_M1_PZ_01", 0, "src\\S1_M1_PZ_DT_02.png");

        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 0);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 4);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 3);

        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S6_M1_PZ_02", TYPE_READ_PUZZLE); //석판
        PuzzleManager::setCompletedDetailASCII("S6_M1_PZ_02", "src\\S6_M1_PZ_DT_01.png");

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

        PuzzleManager::createPuzzle("S9_M3_PZ_01", TYPE_READ_PUZZLE);
        

    };

    static void MapInit() {
        MapManager::createMap("S0_P_MAP_01", TYPE_PUZZLE, "src\\S0_MAP.png", "src\\S0_MAP_INFO.png");
        MapManager::createMap("S1_P_MAP_01", TYPE_PUZZLE, "src\\S1_P_MAP_01.png", "src\\S1_P_MAP_01_INFO_01.png");
        MapManager::createMap("S1_J_MAP_01", TYPE_JUMP, "src\\S1_J_MAP_01.png", "src\\S1_J_MAP_INFO_01.png");
        MapManager::createMap("S2_P_MAP_01", TYPE_PUZZLE, "src\\S2_P_MAP_01.png", "src\\S2_P_MAP_INFO_01.png");
        MapManager::createMap("S2_J_MAP_01", TYPE_JUMP, "src\\S2_J_MAP_01.png", "src\\S2_J_MAP_INFO_01.png");
        MapManager::createMap("S3_P_MAP_01", TYPE_PUZZLE, "src\\S3_P_MAP_01.png", "src\\S3_P_MAP_INFO_01.png");
        MapManager::createMap("S3_J_MAP_01", TYPE_JUMP, "src\\S3_J_MAP_01.png", "src\\S3_J_MAP_INFO_01.png");
        MapManager::createMap("S4_P_MAP_01", TYPE_PUZZLE, "src\\S4_P_MAP_01.png", "src\\S4_P_MAP_INFO_01.png");
        MapManager::createMap("S4_P_MAP_02", TYPE_PUZZLE, "src\\S4_P_MAP_02.png", "src\\S4_P_MAP_INFO_02.png");
        MapManager::createMap("S4_P_MAP_03", TYPE_PUZZLE, "src\\S4_P_MAP_03_3.png", "src\\S4_P_MAP_INFO_03.png");
        MapManager::createMap("S4_J_MAP_01", TYPE_JUMP, "src\\S4_J_MAP_01.png", "src\\S4_J_MAP_INFO_01.png");
        MapManager::createMap("S5_P_MAP_01", TYPE_PUZZLE, "src\\S5_MAP_01.png", "src\\S5_MAP_INFO_01_TEST.png");
        MapManager::createMap("S6_P_MAP_00", TYPE_PUZZLE, "src\\S0_MAP.png", "src\\S0_MAP_INFO.png");
        MapManager::createMap("S6_P_MAP_01", TYPE_PUZZLE, "src\\S6_P_MAP_01.png", "src\\S6_P_MAP_01_INFO_01.png");
        MapManager::createMap("S6_J_MAP_01", TYPE_JUMP, "src\\S6_J_MAP_01.png", "src\\S6_J_MAP_INFO_01.png");
        MapManager::createMap("S7_P_MAP_01", TYPE_PUZZLE, "src\\S7_P_MAP_01.png", "src\\S7_P_MAP_INFO_01.png");
        MapManager::createMap("S7_P_MAP_02", TYPE_PUZZLE, "src\\S7_P_MAP_02.png", "src\\S7_P_MAP_INFO_02.png");
        MapManager::createMap("S7_P_MAP_03", TYPE_PUZZLE, "src\\S7_P_MAP_03.png", "src\\S7_P_MAP_INFO_03.png");
        MapManager::createMap("S7_J_MAP_01", TYPE_JUMP, "src\\S7_J_MAP_01.png", "src\\S7_J_MAP_INFO_01.png");
        MapManager::createMap("S8_P_MAP_01", TYPE_PUZZLE, "src\\S8_P_MAP_01.png", "src\\S8_P_MAP_INFO_01.png");
        MapManager::createMap("S8_J_MAP_01", TYPE_JUMP, "src\\S8_J_MAP_01.png", "src\\S8_J_MAP_INFO_01.png");
        MapManager::createMap("S9_P_MAP_01", TYPE_PUZZLE, "src\\S9_P_MAP_01.png", "src\\S9_P_MAP_INFO_01.png");
        MapManager::createMap("S9_P_MAP_02", TYPE_PUZZLE, "src\\S9_P_MAP_02.png", "src\\S9_P_MAP_INFO_02.png");
        MapManager::createMap("S9_P_MAP_03_0", TYPE_PUZZLE, "src\\S9_P_MAP_03_0.png", "src\\S9_P_MAP_INFO_03_0.png");
        MapManager::createMap("S9_P_MAP_03_1", TYPE_PUZZLE, "src\\S9_P_MAP_03_1.png", "src\\S9_P_MAP_INFO_03_1.png");
        MapManager::createMap("S9_P_MAP_03_2", TYPE_PUZZLE, "src\\S9_P_MAP_03_2.png", "src\\S9_P_MAP_INFO_03_2.png");
        MapManager::createMap("S9_P_MAP_03_3", TYPE_PUZZLE, "src\\S9_P_MAP_03_3.png", "src\\S9_P_MAP_INFO_03_3.png");
        MapManager::createMap("S9_P_MAP_04", TYPE_PUZZLE, "src\\S9_P_MAP_04.png", "src\\S9_P_MAP_INFO_04.png");
        MapManager::createMap("S9_P_MAP_05", TYPE_PUZZLE, "src\\S9_P_MAP_05.png", "src\\S9_P_MAP_INFO_05.png");
        MapManager::createMap("S9_J_MAP_01", TYPE_JUMP, "src\\S9_J_MAP_01.png", "src\\S9_J_MAP_INFO_01.png");
        MapManager::createMap("S10_P_MAP_01", TYPE_PUZZLE, "src\\S10_MAP_01.png", "src\\S5_MAP_INFO_01_TEST.png");
    };


    static void StageInit(EventDispatcher* eventDispathcer) {
        for (int i = 0; i < 12; i++) {
            StageManager::addStage(i, eventDispathcer);
        }
        //E_S0
        StageManager::addMap(0, MapManager::getMap("S0_P_MAP_01"));

        StageManager::setDoorID(0, "S0_P_MAP_01", MAP_EXIT, "EXIT");
        //E_S1
        StageManager::addMap(1, MapManager::getMap("S1_P_MAP_01"));
        StageManager::addMap(1, MapManager::getMap("S1_J_MAP_01"));

        StageManager::setDoorID(1, "S1_P_MAP_01", MAP_EXIT, "S1_J_MAP_01");
        StageManager::setDoorID(1, "S1_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(1, "S1_P_MAP_01", PUZZLE_OBJ_02, "S1_M1_PZ_01");
        //S1_SC2 퍼즐1층 씬 (석판을 보고난 후)

        StageManager::setScene(1, "S1_P_MAP_01", "S1_SC1");
        StageManager::setScene(1, "S1_J_MAP_01", "S1_SC3");

        //E_S2
        StageManager::addMap(2, MapManager::getMap("S2_P_MAP_01"));
        StageManager::addMap(2, MapManager::getMap("S2_J_MAP_01"));

        StageManager::setDoorID(2, "S2_P_MAP_01", MAP_EXIT, "S2_J_MAP_01");
        StageManager::setDoorID(2, "S2_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(2, "S2_P_MAP_01", PUZZLE_OBJ_01, "S2_M1_PZ_01");

        StageManager::setScene(2, "S2_P_MAP_01", "S2_SC1");
        StageManager::setScene(2, "S2_J_MAP_01", "S2_SC2");

        //E_S3
        StageManager::addMap(3, MapManager::getMap("S3_P_MAP_01"));
        StageManager::addMap(3, MapManager::getMap("S3_J_MAP_01"));

        StageManager::setDoorID(3, "S3_P_MAP_01", MAP_EXIT, "S3_J_MAP_01");
        StageManager::setDoorID(3, "S3_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(3, "S3_P_MAP_01", PUZZLE_OBJ_02, "S3_M1_PZ_01");

        //E_S4
        StageManager::addMap(4, MapManager::getMap("S4_P_MAP_01"));
        StageManager::addMap(4, MapManager::getMap("S4_P_MAP_02"));
        StageManager::addMap(4, MapManager::getMap("S4_P_MAP_03"));
        StageManager::addMap(4, MapManager::getMap("S4_J_MAP_01"));

        StageManager::setDoorID(4, "S4_P_MAP_01", MAP_EXIT, "S4_J_MAP_01");
        StageManager::setDoorID(4, "S4_P_MAP_01", MAP_DOOR_01, "S4_P_MAP_02");
        StageManager::setDoorID(4, "S4_P_MAP_01", MAP_DOOR_02, "S4_P_MAP_03");
        StageManager::setDoorID(4, "S4_P_MAP_02", MAP_EXIT, "S4_P_MAP_01");
        StageManager::setDoorID(4, "S4_P_MAP_03", MAP_EXIT, "S4_P_MAP_01");
        StageManager::setDoorID(4, "S4_J_MAP_01", MAP_EXIT, "EXIT");

        //E_S5
        StageManager::addMap(5, MapManager::getMap("S5_P_MAP_01"));

        StageManager::setDoorID(5, "S5_P_MAP_01", MAP_EXIT, "EXIT");

        //H_S0


        //H_S1
        StageManager::addMap(6, MapManager::getMap("S6_P_MAP_00"));
        StageManager::addMap(6, MapManager::getMap("S6_P_MAP_01"));
        StageManager::addMap(6, MapManager::getMap("S6_J_MAP_01"));

        StageManager::setDoorID(6, "S6_P_MAP_00", MAP_EXIT, "S6_P_MAP_01");
        StageManager::setDoorID(6, "S6_P_MAP_01", MAP_EXIT, "S6_J_MAP_01");
        StageManager::setDoorID(6, "S6_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(6, "S6_P_MAP_01", PUZZLE_OBJ_01, "S6_M1_PZ_01");
        StageManager::setPuzzleId(6, "S6_P_MAP_01", PUZZLE_OBJ_02, "S6_M1_PZ_02");

        //H_S2
        StageManager::addMap(7, MapManager::getMap("S7_P_MAP_01"));
        StageManager::addMap(7, MapManager::getMap("S7_P_MAP_02"));
        StageManager::addMap(7, MapManager::getMap("S7_P_MAP_03"));
        StageManager::addMap(7, MapManager::getMap("S7_J_MAP_01"));

        StageManager::setDoorID(7, "S7_P_MAP_01", MAP_DOOR_01, "S7_P_MAP_02");
        StageManager::setDoorID(7, "S7_P_MAP_01", MAP_EXIT, "S7_J_MAP_01");
        StageManager::setDoorID(7, "S7_P_MAP_01", MAP_DOOR_02, "S7_P_MAP_03");
        StageManager::setDoorID(7, "S7_P_MAP_02", MAP_DOOR_01, "S7_P_MAP_01");
        StageManager::setDoorID(7, "S7_P_MAP_03", MAP_DOOR_02, "S7_P_MAP_01");
        StageManager::setDoorID(7, "S7_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(7, "S7_P_MAP_01", PUZZLE_OBJ_01, "S7_M1_PZ_01");
        StageManager::setPuzzleId(7, "S7_P_MAP_02", PUZZLE_OBJ_01, "S7_M2_PZ_01");
        StageManager::setPuzzleId(7, "S7_P_MAP_02", PUZZLE_OBJ_02, "S7_M2_PZ_02");
        StageManager::setPuzzleId(7, "S7_P_MAP_03", PUZZLE_OBJ_01, "S7_M3_PZ_01");
        StageManager::setPuzzleId(7, "S7_P_MAP_03", PUZZLE_OBJ_02, "S7_M3_PZ_02");

        //H_S3
        StageManager::addMap(8, MapManager::getMap("S8_P_MAP_01"));
        StageManager::addMap(8, MapManager::getMap("S8_J_MAP_01"));

        StageManager::setDoorID(8, "S8_P_MAP_01", MAP_EXIT, "S8_J_MAP_01");
        StageManager::setDoorID(8, "S8_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(8, "S8_P_MAP_01", PUZZLE_OBJ_01, "S8_M1_PZ_01");
        StageManager::setPuzzleId(8, "S8_P_MAP_01", PUZZLE_OBJ_02, "S8_M1_PZ_02");

        //H_S4
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_01"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_02"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_0"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_1"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_2"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_3"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_04"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_05"));
        StageManager::addMap(9, MapManager::getMap("S9_J_MAP_01"));

        StageManager::setPuzzleId(9, "S9_P_MAP_04", PUZZLE_OBJ_01, "S9_M3_PZ_01");

        StageManager::setDoorID(9, "S9_P_MAP_01", MAP_DOOR_01, "S9_P_MAP_02");
        StageManager::setDoorID(9, "S9_P_MAP_01", MAP_DOOR_02, "S9_P_MAP_03_0");
        StageManager::setDoorID(9, "S9_P_MAP_01", MAP_EXIT, "S9_J_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_0", MAP_DOOR_01, "S9_P_MAP_03_1");
        StageManager::setDoorID(9, "S9_P_MAP_03_1", MAP_DOOR_01, "S9_P_MAP_03_2");
        StageManager::setDoorID(9, "S9_P_MAP_03_2", MAP_DOOR_01, "S9_P_MAP_03_5");
        StageManager::setDoorID(9, "S9_P_MAP_03_0", MAP_DOOR_02, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_1", MAP_DOOR_02, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_2", MAP_DOOR_02, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_0", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_1", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_2", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_3", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_02", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_02", MAP_DOOR_02, "S9_P_MAP_04");
        StageManager::setDoorID(9, "S9_P_MAP_04", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_05", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_J_MAP_01", MAP_EXIT, "EXIT");

        //H_S5
        StageManager::addMap(10, MapManager::getMap("S10_P_MAP_01"));

        StageManager::setDoorID(10, "S10_P_MAP_01", MAP_EXIT, "EXIT");

        //setMapASCII
        MapManager::setMapASCII("S0_P_MAP_01");
        MapManager::setMapASCII("S1_P_MAP_01");
        MapManager::setMapASCII("S1_J_MAP_01");
        MapManager::setMapASCII("S2_P_MAP_01");
        MapManager::setMapASCII("S2_J_MAP_01");
        MapManager::setMapASCII("S3_P_MAP_01");
        MapManager::setMapASCII("S3_J_MAP_01");
        MapManager::setMapASCII("S4_P_MAP_01");
        MapManager::setMapASCII("S4_P_MAP_02");
        MapManager::setMapASCII("S4_P_MAP_03");
        MapManager::setMapASCII("S4_J_MAP_01");
        MapManager::setMapASCII("S5_P_MAP_01");
        MapManager::setMapASCII("S6_P_MAP_00");
        MapManager::setMapASCII("S6_P_MAP_01");
        MapManager::setMapASCII("S6_J_MAP_01");
        MapManager::setMapASCII("S7_P_MAP_01");
        MapManager::setMapASCII("S7_P_MAP_02");
        MapManager::setMapASCII("S7_P_MAP_03");
        MapManager::setMapASCII("S7_J_MAP_01");
        MapManager::setMapASCII("S8_J_MAP_01");
        MapManager::setMapASCII("S8_P_MAP_01");
        MapManager::setMapASCII("S9_P_MAP_01");
        MapManager::setMapASCII("S9_P_MAP_02");
        MapManager::setMapASCII("S9_P_MAP_03_0");
        MapManager::setMapASCII("S9_P_MAP_03_1");
        MapManager::setMapASCII("S9_P_MAP_03_2");
        MapManager::setMapASCII("S9_P_MAP_03_3");
        MapManager::setMapASCII("S9_P_MAP_04");
        MapManager::setMapASCII("S9_P_MAP_05");
        MapManager::setMapASCII("S9_J_MAP_01");
        MapManager::setMapASCII("S10_P_MAP_01");
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