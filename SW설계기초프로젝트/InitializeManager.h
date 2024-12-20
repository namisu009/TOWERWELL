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
        GameObjectManager::createObject("Character", "Hero", "src\\characters\\hero_idle_right_01.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE_RIGHT", 1, "src\\characters\\hero_idle_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("IDLE_LEFT", "src\\characters\\hero_idle_left_01.png", "src\\characters\\hero_idle_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("RIGHT", "src\\characters\\hero_right_01.png", "src\\characters\\hero_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("LEFT", "src\\characters\\hero_left_01.png", "src\\characters\\hero_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CLIMB_RIGHT", "src\\characters\\hero_climb_right_01.png", "src\\characters\\hero_climb_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CLIMB_LEFT", "src\\characters\\hero_climb_left_01.png", "src\\characters\\hero_climb_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CARRY_IDLE_RIGHT", "src\\characters\\hero_carry_right_01.png", "src\\characters\\hero_carry_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CARRY_IDLE_LEFT", "src\\characters\\hero_carry_left_01.png", "src\\characters\\hero_carry_left_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CARRY_RIGHT", "src\\characters\\hero_carry_right_01.png", "src\\characters\\hero_carry_right_02.png");
        GameObjectManager::getCharacter("Hero")->setAnimation("CARRY_LEFT", "src\\characters\\hero_carry_left_01.png", "src\\characters\\hero_carry_left_02.png");



        GameObjectManager::createObject("Character", "Sister", "src\\characters\\sister_idle_right_01.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_RIGHT", 1, "src\\characters\\sister_idle_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("IDLE_LEFT", "src\\characters\\sister_idle_left_01.png", "src\\characters\\sister_idle_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("RIGHT", "src\\characters\\sister_right_01.png", "src\\characters\\sister_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("LEFT", "src\\characters\\sister_left_01.png", "src\\characters\\sister_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("CLIMB_RIGHT", "src\\characters\\sister_climb_right_01.png", "src\\characters\\sister_climb_right_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("CLIMB_LEFT", "src\\characters\\sister_climb_left_01.png", "src\\characters\\sister_climb_left_02.png");
        GameObjectManager::getCharacter("Sister")->setAnimation("DEATH", "src\\characters\\sister_dead.png", "src\\characters\\sister_dead.png");


        GameObjectManager::createObject("Character", "Hood", "src\\characters\\hood_idle_right_01.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("IDLE_RIGHT", 1, "src\\characters\\hood_idle_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("IDLE_LEFT", "src\\characters\\hood_idle_left_01.png", "src\\characters\\hood_idle_left_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("RIGHT", "src\\characters\\hood_right_01.png", "src\\characters\\hood_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("LEFT", "src\\characters\\hood_left_01.png", "src\\characters\\hood_left_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("HERO_IDLE_RIGHT", "src\\characters\\hero_idle_right_01.png", "src\\characters\\hero_idle_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("HERO_IDLE_LEFT", "src\\characters\\hero_idle_left_01.png", "src\\characters\\hero_idle_left_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("HERO_RIGHT", "src\\characters\\hero_right_01.png", "src\\characters\\hero_right_02.png");
        GameObjectManager::getCharacter("Hood")->setAnimation("HERO_LEFT", "src\\characters\\hero_left_01.png", "src\\characters\\hero_left_02.png");




        //Dialoginit

        //E
        GameObjectManager::createObject("Dialog", "NUMBER_WINDOW", "");
        GameObjectManager::createObject("Dialog", "PZ_NCL_DL", "문이 열리지 않아...");

        GameObjectManager::createObject("Dialog", "S1_M1_DPZ1_DL_00_00", "먼지가 수북이 쌓인 책장이다.");
        GameObjectManager::createObject("Dialog", "S1_M1_DPZ1_DL_00_01", "이 탑의 주인은 청소에는 관심이 없었나보다...");
        GameObjectManager::createObject("Dialog", "S1_M1_DPZ2_DL_00_00", "아름답게 빛나는 랜턴이다.");

        GameObjectManager::createObject("Dialog", "S2_M1_DPZ1_DL_00_00", "회전 목마 모형이 여기 왜 있을까?");
        GameObjectManager::createObject("Dialog", "S2_M1_DPZ1_DL_00_01", "버튼을 눌러보니 돌아가다 곧 꺼진다...");

        GameObjectManager::createObject("Dialog", "S3_M1_DPZ1_DL_00_00", "새장이다. 이런 곳에 새가 살 수 있나..?");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ1_DL_00_01", "새치고는 상당히 인간다운 표정을 짓는다...");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ1_DL_00_02", "리안: 이 새 뭔가 기분 나쁜데...");

        GameObjectManager::createObject("Dialog", "S3_M1_DPZ2_DL_00_00", "평범해보이는 괘종시계다.");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ2_DL_00_01", "아니... 자세히 보니 시계가 반대로 돌아가는 느낌이다...");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ2_DL_00_02", "리안: 성에 관리하는 사람이 없던게 분명해.");

        //H

        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_00", "히로: 문이 열리지 않아... 열쇠가 필요할 거 같아.");
        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_01", "열쇠를 사용한다.");

        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_00", "먼지가 쌓여있는 책장이다...");
        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_01", "책 한 권이 눈에 들어온다.");
        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_02", " * ... 너의 삶이 지금 이 순간 그대로 무한히 반복된다고 상상해 보라. 어떤 선택을 할 것인가? ... *");
        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_03", "히로: ... 빨리 올라가자.");

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

        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_00", "평범해보이는 회전목마다.");
        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_01", "버튼을 눌러보니 돌아간...다...?");
        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_02", "히로: 이게 무슨 소용이 있을까?");
        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_03", "회전목마는 곧 꺼졌다...");

        GameObjectManager::createObject("Dialog", "S7_M2_DPZ1_DL_00_00", "다가가니 음흉한 빛이 나는 꽃이다.");
        GameObjectManager::createObject("Dialog", "S7_M2_DPZ1_DL_00_01", "히로: ... 이런 빛은 아닐거 같은데");
        GameObjectManager::createObject("Dialog", "S7_M2_DPZ1_DL_00_02", "꽃은 곧 꺼졌다...");

        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_00", "히로: 아까 그 새장이네.");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_01", "???: 난 그저 날고 싶었을 뿐이야! 까악!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_02", "히로: 뭐야. 너가 말한거야?");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_03", "까마귀는 아닌 것: 그래! 너도 그 \"우물 새끼\"한테 소원을 빈 모양이구나! 까악!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_04", "히로: 우물 새끼..? 너 뭔가 아는게 있는거야?");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_05", "까마귀는 아닌 것: 절대로 믿지마! 거짓말쟁이니까! 까악!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_06", "까마귀는 아닌 것: 날고 싶었을 뿐인데! 새장에 가둬두고 방치했어!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_07", "히로: 그럼... 내 소원도 이런 식으로...?");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_08", "까마귀는 아닌 것: 까악! 너도 곧 비참한 결말을 겪겠지 까악!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_09", "히로: ... 난 너와는 달라.");

        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_00", "괘종시계이다.");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_01", "... 시계의 몸통 쪽에 뭔가가 적혀있다.");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_02", " \"시간의 흐름을 탐닉한 자. 원없이 시간을 돌리다.\"");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_03", "히로: ... 빨리 올라가야겠어.");

        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_00", "소름끼치게 생긴 그림이다...");
        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_01", "금방이라도 움직일듯한 느낌...");
        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_02", "아까와 다르게 그림이 더욱 일렁인다...");
        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_03", "히로: 빨리 올라가야만 해...");


        GameObjectManager::createObject("Dialog", "NUM_PZ_NCL_DL", "비밀번호가 틀렸습니다.");
        GameObjectManager::createObject("Dialog", "NUM_PZ_CL_DL", "비밀번호가 맞았습니다.");

    };

    static void SceneInit() {
        Scene S0_SC1, S0_SC2, S1_SC1, S1_SC2, S1_SC3, S1_SC4, S2_SC1, S2_SC2, S3_SC1, S3_SC2, S3_SC3, S4_SC1, S4_SC2, S5_SC1, S5_SC2,
            S0_SC3, S1_SC5, S1_SC6, S2_SC3, S3_SC4, S4_SC3, S4_SC4, S4_SC5, S4_SC6, S5_SC3;

        //S0_SC1 프롤로그
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_01", "* 대사창 넘기기, 물체와 상호작용은 스페이스키로 가능합니다. *");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_02", "오래전부터 전해 마을에 내려오는 전설이 있다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_03", "깊은 숲 속, 시간마저 멈춘 듯한 고요한 탑.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_04", "누가 세웠는지, 언제 세워졌는지조차 잊힌 채 탑은 그 자리에 있을 뿐이다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_05", "탑의 가장 꼭대기, 신비로운 우물에 소원을 빌면, 그 어떤 바람도 이루어진다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_06", "오직 한 미신만이 내려져 오며 탑의 존재조차 희미해져 갔다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_07", "허나 한 사람에게는 이 오래된 전설이 마지막 희망이었으니..");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_08", "저 거대한 문이 천천히 열리고, 운명을 바꿀 여정이 시작된다.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_09", "히로: 나는 어머니를 위해 끝까지 올라갈 거야.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_10", "히로: 여기가 탑의 입구인가…");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_11", "???: 잠깐만!!");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_12", "히로: 리안!? 너 왜 여기에…");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_13", "리안: 언니, 이게 무슨 짓이야?! 혼자 여기까지 온 거야?");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_14", "히로: 리안, 너 여기 오면 안 돼. 이 탑은 너무 위험할지도 모른다고 했잖아.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_15", "리안: 언니 혼자선 보낼 수 없어. 둘이서라면 해낼 수 있을 거야.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_16", "히로: 좋아, 같이 가자.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_17", "리안: 응! 같이 가자, 언니!");


        S0_SC1.setRenderCharacter("Sister");

        
        S0_SC1.setCharacterStartPosition("Sister", "S0_P_MAP_01", 310);
        S0_SC1.setCharacterStartPosition("Hero", "S0_P_MAP_01", 50);

        S0_SC1.setDetail("src\\scene\\S0_SC1\\S0_SC1_00.png");
        S0_SC1.setDelay("Sister", 1000);

        for (int i = 1; i <= 7; i++)
        {
            string s = "S0_SC1_DL_0" + to_string(i);
            S0_SC1.setDialog(s);
        }

        S0_SC1.setDetail("");

        S0_SC1.setAction("Hero", ACTION_MOVE_X, 3, 9);
        S0_SC1.setDelay("Hero", 1000);
        S0_SC1.setDialog("S0_SC1_DL_08");

        S0_SC1.setAction("Hero", ACTION_MOVE_X, 4, 30);
        S0_SC1.setDelay("Hero", 1000);
        S0_SC1.setDetail("src\\characters\\Hero_default.png");
        S0_SC1.setDialog("S0_SC1_DL_09");
        S0_SC1.setDelay("Hero", 1000);
        S0_SC1.setDetail("");
        S0_SC1.setAction("Hero", ACTION_MOVE_X, 4, 3);
        S0_SC1.setDelay("Hero", 1000);

        S0_SC1.setDialog("S0_SC1_DL_10");

        S0_SC1.setDelay("Sister", 1000);
        S0_SC1.setAction("Sister", ACTION_MOVE_X, -3, 2);
        S0_SC1.setDelay("Sister", 1500);
        S0_SC1.setAction("Sister", ACTION_MOVE_X, -3, 9);
        S0_SC1.setDelay("Sister", 2000);

        for (int i = 11; i <= 17; i++)
        {
            string s = "S0_SC1_DL_" + to_string(i);
            S0_SC1.setDialog(s);
        }



        //S0_SC2.setDetail("src\\S0_SC2_00.png"); //여기는 탑의 입구임. 이거 그려야해

        S1_SC1.setDetail("src\\scene\\STAGE1.png");
        S1_SC1.setDelay("Hero", 3000);
        S1_SC1.setDetail("");
        S1_SC1.setDelay("Sister", 500);
        //S1_SC1 퍼즐1층 씬 (석판을 보기전)
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_01", "리안: 분위기가 심상치가 않네... 마을에서 못 보던 물건들도 많고 말이야.");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_02", "리안: 여기 이거 봐! 뭔가 적혀있어!");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_03", " * 벽에 걸려있는 그림과 상호작용하려면 스페이스 바를 눌러보세요. * ");


        S1_SC1.setAction("Sister", ACTION_MOVE_X, 6, 15);
        S1_SC1.setDelay("Sister", 3000);
        S1_SC1.setAction("Sister", ACTION_MOVE_X, 6, 15);
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
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_04", "* 이동과 점프 : ← ↑ ↓ → , 대쉬 : 스페이스바 * ");

        GameObjectManager::createObject("Dialog", "SISTER_CARRY01", "리안: 힘을 쓰니까 너무 힘들어...");
        GameObjectManager::createObject("Dialog", "SISTER_CARRY02", "히로: 괜찮아? 무리 하지마. 내가 업어줄게.");
        GameObjectManager::createObject("Dialog", "SISTER_CARRY03", "리안: 고마워 언니.");

        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_01.png");

        S1_SC3.setDelay("Sister", 700);
        S1_SC3.setDialog("S1_SC3_DL_01");
        S1_SC3.setDialog("S1_SC3_DL_02");
        S1_SC3.setAction("Sister", ACTION_MOVE_X, 3, 6);
        //S1_SC3 얼음 작렬
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_01.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_02.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_03.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_04.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_05.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_06.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_07.png");
        S1_SC3.setDelay("Sister", 70);
        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_08.png");
        S1_SC3.setDelay("Sister", 70);

        S1_SC3.setDialog("S1_SC3_DL_03");
        S1_SC3.setDialog("S1_SC3_DL_04");


        //S1_SC4 계단층 씬
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_01", "리안: 왜 성 안에 저런 길이 있을까? 어쨌든 내가 있으니 걱정하지마.");
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_02", "리안: 우리 없는 동안에 엄마는 괜찮겠지? 빨리 집으로 돌아가고 싶다…");
        S1_SC4.setDelay("Sister", 700);
        S1_SC4.setDialog("S1_SC4_DL_01");
        S1_SC4.setDialog("S1_SC4_DL_02");

        //S2_SC1 퍼즐2층 씬
        S2_SC1.setDetail("src\\scene\\STAGE2.png");
        S2_SC1.setDelay("Hero", 3000);
        S2_SC1.setDetail("");
        S2_SC1.setDelay("Sister", 500);

        GameObjectManager::createObject("Dialog", "S2_SC1_DL_01", "리안: 돌 부스러기…? 여기저기 막 부서져 있네 ? ");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_02", "리안: 성이라고 하기엔 관리가 제대로 안 된 것 같아.");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_03", "리안: 자, 어서 가보자!");

        S2_SC1.setDelay("Sister", 700);
        S2_SC1.setAction("Sister", ACTION_MOVE_X, 6, 15); //석상 앞에 여동생이 가게끔 조정
        S2_SC1.setDialog("S2_SC1_DL_01");
        S2_SC1.setDialog("S2_SC1_DL_02");
        S2_SC1.setDialog("S2_SC1_DL_03");


        //S2_SC2 점프2층 씬
        S2_SC2.setScreen("src\\scene\\S2_SC2\\S2_SC2_01.png");
        S2_SC2.setDelay("Sister", 700);
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_01", "리안: 여기도 상당히 위험하네.");
        S2_SC2.setDialog("S2_SC2_DL_01");
        S2_SC2.setAction("Sister", ACTION_MOVE_X, 5, 3);
        S2_SC2.setDelay("Sister", 1000);


        for (int i = 1; i <= 34; i++)
        {
            string s = "src\\scene\\S2_SC2\\S2_SC2_";
            if (i < 10) s += "0";
            s += to_string(i) + ".png";
            S2_SC2.setScreen(s.c_str());
        }

        GameObjectManager::createObject("Dialog", "S2_SC2_DL_02", "리안: 자, 이러면 가기 쉬울거야.");
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_03", " * 특정 벽은 \"F키\"로 벽타기를 할 수 있습니다. * ");



        S2_SC2.setDialog("S2_SC2_DL_02");
        S2_SC2.setDialog("S2_SC2_DL_03");

        //힘들다는 대사와 함께 여동생 쓰러짐
        S2_SC2.setDeath("Sister", true);
        S2_SC2.setDialog("SISTER_CARRY01");
        S2_SC2.setDialog("SISTER_CARRY02");
        //내가 업어줄게 대사
        S2_SC2.removeRenderCharacter("Sister");
        S2_SC2.setCarry("Hero", true); //업어주기
        S2_SC2.setDialog("SISTER_CARRY03");


        //S3_SC1
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_01", "리안: 계속 올라오면서 느낀 건데…");
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_02", "리안: 이 탑의 이상한 장치들이 전부 다 작동하지 않는 것 같아.");
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_03", "리안: 이 층도 마찬가지고… 뭐가 있어야 할 자리가 텅 비어 있는 느낌이야.");
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_04", "리안: 혹시 어떤 함정이 있었을지도 모르는데! 그래도 우리에겐 행운인 거겠지? 빨리빨리 우물로 가자!");

        S3_SC1.setCarry("Hero", false); //내리기
        S3_SC1.setDeath("Sister", false);
        S3_SC1.setRenderCharacter("Sister");

        S3_SC1.setDetail("src\\scene\\STAGE3.png");
        S3_SC1.setDelay("Hero", 3000);
        S3_SC1.setDetail("");
        S3_SC1.setDelay("Sister", 500);

        S3_SC1.setAction("Sister", ACTION_MOVE_X, 5, 5);
        S3_SC1.setDialog("S3_SC1_DL_01");
        S3_SC1.setDialog("S3_SC1_DL_02");
        S3_SC1.setDialog("S3_SC1_DL_03");
        S3_SC1.setDialog("S3_SC1_DL_04");



        //S3_SC2
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_01", "리안: 우와… 여긴 정말 위험해 보이네.");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_02", "리안: 지금까지 봤던 곳들과는 완전히 다르잖아. 넘어갈 수 있을까?");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_03", " * 지금까지 배운 것을 활용하여 방을 클리어해보세요. * ");

        S3_SC2.setScreen("src\\scene\\S3_SC2\\S3_SC2_01.png");

        S3_SC2.setDelay("Sister", 700);

        S3_SC2.setDialog("S3_SC2_DL_01");
        S3_SC2.setDialog("S3_SC2_DL_02");

        S3_SC2.setAction("Sister", ACTION_MOVE_X, 5);
        S3_SC2.setDelay("Sister", 100);

        for (int i = 1; i <= 60; i++)
        {
            string str = "src\\scene\\S3_SC2\\S3_SC2_";
            if (i < 10) str += "0";
            str += to_string(i) + ".png";
            S3_SC2.setScreen(str.c_str());
        }


        S3_SC2.setDialog("S3_SC2_DL_03");




        //S3_SC3
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_01", "리안: 이 성은 구조도 참 이상하고, 본 적도 들은 적도 없는 물건들로 가득하네.");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_02", "리안: 도대체 누가, 왜 이런 성을 만든 걸까?");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_03", "리안: 우물에 대한 소문도 이 정도면 정말 사실일 것 같아! 빨리 가보자!");

        S3_SC3.setDelay("Sister", 700);
        S3_SC3.setDialog("S3_SC3_DL_01");
        S3_SC3.setDialog("S3_SC3_DL_02");
        S3_SC3.setDialog("S3_SC3_DL_03");

        //S4_SC1
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_01", "리안: 여기도 뭔가 이상한 구조물이 있어… 그리고 또 이미 문이 열려있어.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_02", "리안: 흠… 뭔가 으스스 해…");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_03", "리안: 빨리 소원을 빌고 나가자!");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_04", "그래. 일단 움직여야겠다.");


        S4_SC1.setDetail("src\\scene\\STAGE4.png");
        S4_SC1.setDelay("Hero", 3000);
        S4_SC1.setDetail("");
        S4_SC1.setDelay("Sister", 500);


        S4_SC1.setAction("Sister", ACTION_MOVE_X, 10, 9);
        S4_SC1.setDelay("Sister", 700);
        S4_SC1.setAction("Sister", ACTION_MOVE_X, -1);
        S4_SC1.setDialog("S4_SC1_DL_01");
        S4_SC1.setDialog("S4_SC1_DL_02");
        S4_SC1.setDelay("Sister", 700);
        S4_SC1.setAction("Sister", ACTION_MOVE_X, -10, 9);
        S4_SC1.setDialog("S4_SC1_DL_03");
        S4_SC1.setDialog("S4_SC1_DL_04");
        S4_SC1.setDelay("Sister", 700);

        //S5_SC1
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_01", "리안: 드디어 우물이 보인다!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_02", "리안: 정말 신비롭다… 이렇게 가까이 오다니 믿기지 않아.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_03", "우물은 그 자체로도 신비로워보이고, 물에 월광이 비쳐 더욱 영롱해보인다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_04", "리안: 빨리 소원을 빌자! 엄마를 고치는거야!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_05", "두건녀: ……");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_06", "두건을 쓴 여자가 무언갈 중얼거리는 듯 하다.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_07", "히로: 리안!! 안 돼!!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_08", "뒤늦게 손을 뻗어보지만 칼은 이미 깊게 리안을 관통할 뿐이다.");
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


        //추가하기 애매해서 40 41 42
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_40", "리안: ...언니...?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_41", "두건녀: ...로... 해....");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_42", "히로: 리안!!");



        S5_SC1.setCarry("Hero", false); //내리기
        S5_SC1.setDeath("Sister", false);
        S5_SC1.setAction("Hero", ACTION_MOVE_X, 1);
        S5_SC1.setAction("Sister", ACTION_MOVE_X, 1);

        S5_SC1.setCharacterStartPosition("Sister", "S5_P_MAP_01", 70);
        S5_SC1.setCharacterStartPosition("Hero", "S5_P_MAP_01", 50);


        S5_SC1.setRenderCharacter("Sister");

        S5_SC1.setDialog("S5_SC1_DL_01");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_02");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setAction("Sister", ACTION_MOVE_X, 3, 30);
        S5_SC1.setAction("Hero", ACTION_MOVE_X, 3, 30);

        S5_SC1.setDialog("S5_SC1_DL_03");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_04");
        S5_SC1.setDelay("Sister", 300);

        S5_SC1.setCharacterStartPosition("Hood", "S5_P_MAP_01", 300);
        //S5_SC1.setCharacterPosition("Hood", 300, 0);
        S5_SC1.setAction("Hood", ACTION_MOVE_X, -1);
        S5_SC1.setRenderCharacter("Hood");
        S5_SC1.setDelay("Sister", 600);
        S5_SC1.setDialog("S5_SC1_DL_05");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_06");
        S5_SC1.setDelay("Sister", 300);

        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_blank.png");
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setAction("Hood", ACTION_MOVE_X, -40);
        S5_SC1.setDetail("");
        S5_SC1.setDelay("Sister", 1000);
        S5_SC1.setDialog("S5_SC1_DL_40");
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_blank.png");
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setAction("Hood", ACTION_MOVE_X, -40);
        S5_SC1.setDetail("");
        S5_SC1.setDelay("Sister", 1000);
        S5_SC1.setDialog("S5_SC1_DL_41");
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_blank.png");
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setAction("Hood", ACTION_MOVE_X, -50);
        S5_SC1.setDetail("");
        S5_SC1.setDelay("Sister", 1000);
        S5_SC1.setDialog("S5_SC1_DL_42");
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_SC1.png"); // 상당히 깨짐
        S5_SC1.setDelay("Sister", 700);
        S5_SC1.setDeath("Sister", true);
        S5_SC1.setDialog("S5_SC1_DL_07");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_08");
        S5_SC1.setDelay("Sister", 300);

        S5_SC1.setCharacterStartPosition("Hood", "S5_P_MAP_01", 180);
        //S5_SC1.setCharacterPosition("Hood", 180, 0);
        S5_SC1.setDetail("");
        S5_SC1.setDelay("Sister", 500);
        S5_SC1.setAction("Hood", ACTION_MOVE_X, 3, 6);
        S5_SC1.setAction("Hood", ACTION_MOVE_Y, -5, 8);
        S5_SC1.setAction("Hood", ACTION_MOVE_Y, 5, 4);
        S5_SC1.removeRenderCharacter("Hood"); //여기까지 후드 칼찌
        // 여기에 여동생 죽은 모션 넣기 *어케하는지 까먹음 ㅎㅎ;;;;;;;

        S5_SC1.setDialog("S5_SC1_DL_09");
        S5_SC1.setDelay("Sister", 300);

        S5_SC1.setDetail("src\\scene\\S5_SC1\\herosister_dead.png");
        S5_SC1.setDelay("Sister", 1500);
        S5_SC1.setDialog("S5_SC1_DL_10");
        S5_SC1.setDetail("");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_11");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_12");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_13");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well.png");
        S5_SC1.setDialog("S5_SC1_DL_14");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_15");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_16");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_17");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_18");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_19");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_02.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_03.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_04.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_05.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_06.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_07.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_08.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_09.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_10.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_11.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_12.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_13.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_14.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_15.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_16.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_17.png");
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_18.png");
        S5_SC1.setDialog("S5_SC1_DL_20");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_21");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDetail("");



        //이거 마지막 씬에 우물이 나옴.
        //새로운 맵을 그려서 밑에 빛이 있고 거기에 상호작용하면 다음맵.


        //S0_SC3
         //S5_SC1 히로 우물안에
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_01", "깊은 우물 속으로 가라앉고 있다.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_02", "죽을 것 같다.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_03", "많은 정보들이 머리 속을 헤집는 느낌이다.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_04", "내 여동생을 구해야만 해… 반드시… 리안…");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_05", "깊은 고요 속에서 주인공은 정신을 잃는다.");

        GameObjectManager::createObject("Dialog", "S0_SC3_DL_06", "히로: …여긴…?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_07", "익숙한 탑의 입구가 눈앞에 들어온다.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_08", "히로: 아직… 아무도 오지 않은 것 같아. 시간을 돌려보낸 건가…?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_09", "히로: 리안을 구하려면 서둘러야 해. 내가 먼저 탑으로 들어가야 해.");



        S0_SC3.setDetail("src\\scene\\S0_SC3\\S0_blank.png");
        S0_SC3.removeRenderCharacter("Sister");
        S0_SC3.setDelay("Hero", 1500);


        S0_SC3.setCarry("Hero", false); //내리기
        S0_SC3.setDeath("Sister", true);
        S0_SC3.setAction("Hero", ACTION_MOVE_X, 1);

        // 우물 안에서 고통받는 주인공이 나왔으면 좋겠어요.
        S0_SC3.setDetail("src\\scene\\S0_SC3\\S0_SC3_hero_drowning_01.png");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDialog("S0_SC3_DL_01");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDialog("S0_SC3_DL_02");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDetail("src\\scene\\S0_SC3\\S0_SC3_hero_drowning_02.png");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDialog("S0_SC3_DL_03");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDialog("S0_SC3_DL_04");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDialog("S0_SC3_DL_05");
        S0_SC3.setDelay("Hero", 500);
        S0_SC3.setDetail("src\\scene\\S0_SC3\\S0_SC3_hero_drowning_03.png");
        S0_SC3.setDelay("Hero", 1500);


        S0_SC3.setDetail("src\\scene\\S0_SC3\\S0_Title.png");
        S0_SC3.setDelay("Hero", 4000);
        S0_SC3.setDetail("");

        S0_SC3.setDelay("Hero", 3000);

        S0_SC3.setDialog("S0_SC3_DL_06");
        S0_SC3.setDialog("S0_SC3_DL_07");
        S0_SC3.setDialog("S0_SC3_DL_08");
        S0_SC3.setDialog("S0_SC3_DL_09");

        //S1_SC5
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_01", "여기는…");
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_02", "탑의 1층... 일단 얼른 움직이자.");
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_03", "빛나는 것을 한시라도 빨리 찾아서 우물로 가야해.");

        S1_SC5.setDetail("src\\scene\\STAGE5.png");
        S1_SC5.setDelay("Hero", 3000);
        S1_SC5.setDetail("");
        S1_SC5.setDelay("Hero", 500);

        S1_SC5.setDialog("S1_SC5_DL_01");
        S1_SC5.setDialog("S1_SC5_DL_02");
        S1_SC5.setDialog("S1_SC5_DL_03");

        //S1_SC6
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_01", "히로: 이제는 리안의 도움이 없겠네.");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_02", "히로: 이 탑을 빠져나가기 위해서는…");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_03", "히로: 빛나는 것을 찾아야겠어.");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_04", "히로: 그리고 그것을 우물로 가져가야겠지.");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_05", "히로: 리안 꼭 구하러갈게.");

        S1_SC6.setAction("Hero", ACTION_MOVE_X, 5, 5);
        S1_SC6.setDelay("Hero", 700);
        S1_SC6.setDialog("S1_SC6_DL_01");
        S1_SC6.setDelay("Hero", 500);
        S1_SC6.setDialog("S1_SC6_DL_02");
        S1_SC6.setDelay("Hero", 500);
        S1_SC6.setDialog("S1_SC6_DL_03");
        S1_SC6.setDelay("Hero", 500);
        S1_SC6.setDialog("S1_SC6_DL_04");
        S1_SC6.setDelay("Hero", 500);
        S1_SC6.setDialog("S1_SC6_DL_05");
        S1_SC6.setDelay("Hero", 500);

        //S2_SC3
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_01", "히로: 아까의 돌부스러기가...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_02", " * 석상에게 미세한 움직임이 보인다. *");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_03", "히로: 뭔가 이상한데…");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_04", "히로: 이 석상 뒤에 문이 있는데....");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_05", "???: 반갑네... 소녀여...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_06", "히로: 누구야!");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_07", "기사: 나는 시간에 묶인 자...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_08", "기사: 허나 이 돌 속에서도 나는 꿈꾼다.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_09", "기사: 누군가가 이 고통을 끝내 줄 날을...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_10", "히로: 어떻게 하면 비켜줄거지? 나는 소중한 사람을 지켜야해.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_11", "기사: 고귀한 정신을 가진 자로군...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_12", "기사: ... 바깥 세상이 가물가물하군...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_13", "기사: ... 내게 바깥 세상을 보여줘다오.");

        S2_SC3.setDetail("src\\scene\\STAGE6.png");
        S2_SC3.setDelay("Hero", 3000);
        S2_SC3.setDetail("");
        S2_SC3.setDelay("Hero", 500);

        S2_SC3.setDelay("Hero", 700);
        S2_SC3.setAction("Hero", ACTION_MOVE_X, 11, 30);
        S2_SC3.setDialog("S2_SC3_DL_01");
        S2_SC3.setDialog("S2_SC3_DL_02");
        S2_SC3.setDialog("S2_SC3_DL_03");
        S2_SC3.setDelay("Hero", 700);
        S2_SC3.setAction("Hero", ACTION_MOVE_X, -1, 3);
        S2_SC3.setDelay("Hero", 700);
        S2_SC3.setAction("Hero", ACTION_MOVE_X, 1, 3);
        S2_SC3.setDelay("Hero", 700);
        S2_SC3.setDialog("S2_SC3_DL_04");
        S2_SC3.setDelay("Hero", 1000);
        S2_SC3.setDialog("S2_SC3_DL_05");
        S2_SC3.setAction("Hero", ACTION_MOVE_X, -3, 10);
        S2_SC3.setAction("Hero", ACTION_MOVE_Y, -10, 3);
        S2_SC3.setAction("Hero", ACTION_MOVE_Y, 7, 3);
        S2_SC3.setAction("Hero", ACTION_MOVE_X, 1);
        S2_SC3.setDelay("Hero", 700);
        S2_SC3.setDialog("S2_SC3_DL_06");
        S2_SC3.setDialog("S2_SC3_DL_07");
        S2_SC3.setDialog("S2_SC3_DL_08");
        S2_SC3.setDialog("S2_SC3_DL_09");
        S2_SC3.setDialog("S2_SC3_DL_10");
        S2_SC3.setDialog("S2_SC3_DL_11");
        S2_SC3.setDialog("S2_SC3_DL_12");
        S2_SC3.setDialog("S2_SC3_DL_13");


        //S3_SC4
        GameObjectManager::createObject("Dialog", "S3_SC4_DL_01", "히로: 아까 그 석상은 뭐였지..?");
        GameObjectManager::createObject("Dialog", "S3_SC4_DL_02", "히로: 이 탑에는 정말 이상한 것들이 많아.");
        GameObjectManager::createObject("Dialog", "S3_SC4_DL_03", "히로: 마치 무언가를 말하고자 하는 듯한 느낌...");

        S3_SC4.setDetail("src\\scene\\STAGE7.png");
        S3_SC4.setDelay("Hero", 3000);
        S3_SC4.setDetail("");
        S3_SC4.setDelay("Hero", 500);

        S3_SC4.setDialog("S3_SC4_DL_01");
        S3_SC4.setDialog("S3_SC4_DL_02");
        S3_SC4.setDialog("S3_SC4_DL_03");

        //S4_SC3
        S4_SC2.setDetail("src\\scene\\STAGE8.png");
        S4_SC2.setDelay("Hero", 3000);
        S4_SC2.setDetail("");
        S4_SC2.setDelay("Hero", 500);

        //S4_SC3
        GameObjectManager::createObject("Dialog", "S4_SC3_DL_01", "상당히 낡아보이는 일기장이다.");
        GameObjectManager::createObject("Dialog", "S4_SC3_DL_02", "표지를 펼치자 웃고있는 여성의 사진이 떨어진다.");
        GameObjectManager::createObject("Dialog", "S4_SC3_DL_03", "... 얼른 서두르자.");
        //딜레이 처리

        S4_SC3.setDialog("S4_SC3_DL_01");
        S4_SC3.setDialog("S4_SC3_DL_02");
        S4_SC3.setDetail("src\\scene\\S4_SC3\\S4_SC3_DT_00.png");
        S4_SC3.setVKSPACE();
        S4_SC3.setDetail("src\\scene\\S4_SC3\\S4_SC3_DT_01.png");
        S4_SC3.setVKSPACE();
        S4_SC3.setDetail("src\\scene\\S4_SC3\\S4_SC3_DT_02.png");
        S4_SC3.setVKSPACE();
        S4_SC3.setDetail("");
        S4_SC3.setDialog("S4_SC3_DL_03");


        //S4_SC4
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_01", "히로: … 흔적들… 일기장… 그리고 이 탑.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_02", "???: 많은 이들이 이곳에 발을 들였지. 저마다 자신의 바람을 이루기 위해.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_03", "히로: 넌 그걸 모두 지켜보고 있었겠지.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_04", "???: 선택의 순간은 언제나 흥미롭지. 희망과 절망이 교차하는 찰나를 보는 것만큼 흥미로운 일은 없으니까.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_05", "히로: 기사… 그의 기록을 읽었어. 그는 결국 이 탑을 떠나지 못했지.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_06", "???: 그는 떠날 수 없었던 게 아니라, 떠나지 않기를 선택했을 뿐이다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_07", "히로: 그의 선택… 넌 그 선택을 비틀지 않았다고 말할 수 있어?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_08", "???: 선택은 강요되지 않는다. 나는 단지 길을 비출 뿐이다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_09", "히로: 그 길이 비극으로 이어졌다면? 그건 네 책임 아니야?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_10", "???: 비극이라… 그것은 네가 붙인 이름일 뿐. 선택의 결과는 언제나 받아들인 자에게 달려 있다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_11", "히로: 받아들인다… 선택의 결과를?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_12", "???: 그렇다. 모든 선택은 대가를 요구한다. 소중한 것을 지키려면 더 소중한 것을 내놓아야 할 때도 있지.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_13", "히로: 대가라니. 소중한 것을 잃지 않고는 리안을 구할 수 없다는 거야?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_14", "???: 그것을 결정하는 것은 너다. 나는 진실을 드러낼 뿐, 답을 내리지는 않는다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_15", "히로: 그럼 두건을 쓴 여자는… 그녀는 대체 누구지?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_16", "???: 네가 묻는 그 질문이야말로 답으로 가는 첫걸음이다. 탑은 너의 진짜 모습을 비추는 거울이다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_17", "히로: 진짜 모습이라니… 그게 무슨 의미야.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_18", "???: 진실은 네가 그것을 직면할 준비가 되었을 때 드러난다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_19", "히로: 리안을 구하기 위해서라면 어떤 대가도 치를 거야. 너의 말이 무엇을 감추고 있든.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_20", "???: 그렇다면 가라. 탑에서 [가장 빛나는 것]을 찾아라. 그것이 너의 소원을 이루는 열쇠다.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_21", "???은 눈 앞에서 사라졌다…");

        S4_SC4.setDialog("S4_SC4_DL_01");
        S4_SC4.setDialog("S4_SC4_DL_02");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc01.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc02.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc03.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc04.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc05.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc06.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc07.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc08.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc09.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc10.png");
        S4_SC4.setDialog("S4_SC4_DL_03");
        S4_SC4.setDialog("S4_SC4_DL_04");
        S4_SC4.setDialog("S4_SC4_DL_05");
        S4_SC4.setDialog("S4_SC4_DL_06");
        S4_SC4.setDialog("S4_SC4_DL_07");
        S4_SC4.setDialog("S4_SC4_DL_08");
        S4_SC4.setDialog("S4_SC4_DL_09");
        S4_SC4.setDialog("S4_SC4_DL_10");
        S4_SC4.setDialog("S4_SC4_DL_11");
        S4_SC4.setDialog("S4_SC4_DL_12");
        S4_SC4.setDialog("S4_SC4_DL_13");
        S4_SC4.setDialog("S4_SC4_DL_14");
        S4_SC4.setDialog("S4_SC4_DL_15");
        S4_SC4.setDialog("S4_SC4_DL_16");
        S4_SC4.setDialog("S4_SC4_DL_17");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc11.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc12.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc13.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc14.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc15.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc16.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc17.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc18.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc19.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc20.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc21.png");
        S4_SC4.setDetail("src\\scene\\S4_SC4\\sc22.png");
        S4_SC4.setDialog("S4_SC4_DL_18");
        S4_SC4.setDialog("S4_SC4_DL_19");
        S4_SC4.setDialog("S4_SC4_DL_20");
        S4_SC4.setDialog("S4_SC4_DL_21");
        S4_SC4.setDetail("");

        //S4_SC4.setClearedPuzzle("S9_P_MAP_");
        //S4_SC5

        S4_SC5.setRenderCharacter("Sister");
        S4_SC5.setScreen("src\\scene\\S4_SC5\\S4_SC5_ (1).PNG");
        S4_SC5.setDelay("Sister", 70);
        S4_SC5.setAction("Sister", ACTION_MOVE_X, -2, 5);
        S4_SC5.setDelay("Sister", 100);


        for (int i = 1; i <= 57; i++)
        {
            string str = "src\\scene\\S4_SC5\\S4_SC5_ (" + to_string(i) + ").PNG";
            S4_SC5.setScreen(str.c_str());
            //S4_SC5.setDelay("Sister", 70);
        }

        //힘들다는 대사와 함께 여동생 쓰러짐
        S4_SC5.setDeath("Sister", true);
        S4_SC5.setDialog("SISTER_CARRY01");
        S4_SC5.setDialog("SISTER_CARRY02");
        //내가 업어줄게 대사
        S4_SC5.removeRenderCharacter("Sister");
        S4_SC5.setCarry("Hero", true); //업어주기
        S4_SC5.setDialog("SISTER_CARRY03");

        //S4_SC6 심장 애니매이션 추가하면
        GameObjectManager::createObject("Dialog", "S4_SC6_DL_01", "그림이... 조금... 이상하다..?");
        GameObjectManager::createObject("Dialog", "S4_SC6_DL_02", "...리안...");
        S4_SC6.setAction("Hero", ACTION_MOVE_X, 5, 5);
        S4_SC6.setDelay("Hero", 700);
        S4_SC6.setDialog("S4_SC6_DL_01");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_01.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_02.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_03.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_04.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_05.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_06.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_07.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_08.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_09.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_10.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_11.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_12.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_13.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_14.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_15.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_16.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_17.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_18.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_19.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_20.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_21.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_22.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_23.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_24.png");
        S4_SC6.setDetail("src\\scene\\S4_SC6\\S4_SC6_DT_25.png");
        S4_SC6.setDelay("Hero", 700);
        S4_SC6.setDetail("");
        S4_SC6.setDialog("S4_SC6_DL_02");



        //S5_SC3
        // S5_SC3: 과거의 시간으로 돌아온 히로, 옥상의 우물에서
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_01", "히로: 우물이 원하는 게 대체 뭘까…");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_02", "히로: 난 탑의 모든 걸 뒤졌어. 하지만 아무것도 찾지 못했어.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_03", "???: 그래서 내게 화를 낼 참인가?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_04", "히로: 네가 나를 속였잖아. 애초부터 아무것도 없었던 거 아니야?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_05", "???: 속이다니, 무슨 소리를. 나는 소원을 이루는 우물이다. 이룰 방법은 네게 달려 있지.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_06", "히로: 네가 [가장 빛나는 것]을 가져오라고 했잖아! 네가 원하는 게 뭔지도 모르고 헤맸다고!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_07", "???: 너는 이미 알고 있을지도 모르지.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_08", "계단 쪽에서 발소리가 들린다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_09", "???: 이런. 손님이 온 모양이군.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_10", "리안: 드디어 우물이 보인다!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_11", "리안: 정말 신비롭다… 이렇게 가까이 오다니 믿기지 않아.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_12", "히로: \'벌써 올라왔다니... 아직 찾지도 못했는데...\'");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_13", "리안: 언니, 여기에 이상한 기운이 느껴져. 뭔가 있나 봐.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_14", "과거의 히로: 조심해, 리안. 괜히 건드리지 마.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_15", "리안의 심장 부근에서 영롱하고 아름다운 빛이 새어나온다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_16", "히로: 저건…?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_17", "리안: 언니, 여기 누군가 있는 것 같아!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_18", "과거의 히로: 리안, 뒤로 물러나.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_19", "히로: ...");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_20", "리안: ...언니...?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_21", "히로: 미안… 리안.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_22", "히로: ... 날 탓해줘 리안. 널 해쳐야만 해.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_23", "리안: 언니, 뭐 하는…?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_24", "히로: 리안!!!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_25", "탑에서 [가장 빛나는 것]을 획득했다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_26", "과거의 히로: 리안!! 안 돼!!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_27", "???: 네 선택은 끝났다.약속대로 이제 소원은 이루어진다.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_28", "히로: 리안… 내가 갈게…");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_29", "히로: 대가… 탑에서 가장 빛나는 것…?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_30", "히로: 네가 없는 세상은 의미가 없어. 어떤 대가라도 치르겠어.");


        //히로가 둘이서 존재가 가능해요?!?!??!?!?
        S5_SC3.removeRenderCharacter("Hero");
        //S5_SC3.removeRenderCharacter("Sister");

        S5_SC3.setRenderHood("Hood", false);
        //S5_SC3.setCharacterPositionX("Hood", 50);
        //S5_SC3.setCharacterPosition("Hood", 50, -1); //처음에는 히로로 그려져야함
        S5_SC3.setCharacterStartPosition("Hood", "S10_P_MAP_01", 50); //처음에는 히로로 그려져야함

        S5_SC3.setRenderCharacter("Hood");
        S5_SC3.setDialog("S5_SC3_DL_01");
        S5_SC3.setDialog("S5_SC3_DL_02");
        S5_SC3.setDialog("S5_SC3_DL_03");
        S5_SC3.setDialog("S5_SC3_DL_04");
        S5_SC3.setDialog("S5_SC3_DL_05");
        S5_SC3.setDialog("S5_SC3_DL_06");
        S5_SC3.setDialog("S5_SC3_DL_07");
        S5_SC3.setDialog("S5_SC3_DL_08");
        S5_SC3.setDialog("S5_SC3_DL_09");
        S5_SC3.setAction("Hood", ACTION_MOVE_X, 7, 30);
        S5_SC3.setDelay("Hood", 500);

        //여기서 히로가 두명으로 나와야함

        S5_SC3.setDialog("S5_SC3_DL_10");
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_SC3_01.png");
        S5_SC3.setRenderCharacter("Hero");
        S5_SC3.setRenderCharacter("Sister");

        S5_SC3.setCharacterStartPosition("Hero", "S10_P_MAP_01", 24); //처음에는 히로로 그려져야함
        S5_SC3.setCharacterStartPosition("Sister", "S10_P_MAP_01", 26); //처음에는 히로로 그려져야함

        /*
        S5_SC1.setDialog("S5_SC1_DL_01");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setDialog("S5_SC1_DL_02");
        S5_SC1.setDelay("Sister", 300);
        S5_SC1.setAction("Sister", ACTION_MOVE_X, 3, 30);
        S5_SC1.setAction("Hero", ACTION_MOVE_X, 3, 30);
        */
        S5_SC3.setDelay("Hero", 600);
        S5_SC3.setDetail("");
        S5_SC3.setDialog("S5_SC3_DL_11");
        S5_SC3.setAction("Sister", ACTION_MOVE_X, 3, 50);
        S5_SC3.setDelay("Sister", 500);
        S5_SC3.setAction("Hero", ACTION_MOVE_X, 3, 40);
        S5_SC3.setDelay("Hero", 500);
        S5_SC3.setDialog("S5_SC3_DL_12");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDialog("S5_SC3_DL_13");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDialog("S5_SC3_DL_14");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_SC3_03.png");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDialog("S5_SC3_DL_15");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_SC3_03.png");
        S5_SC3.setDialog("S5_SC3_DL_16");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDetail("");
        S5_SC3.setDelay("Hero", 500);
        S5_SC3.setDialog("S5_SC3_DL_17");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDialog("S5_SC3_DL_18");
        S5_SC3.setDelay("Hero", 300);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_SC3_04.png");
        S5_SC3.setRenderHood("Hood", true);
        S5_SC3.setDialog("S5_SC3_DL_19");
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_blank.png");
        S5_SC3.setDelay("Sister", 700);
        S5_SC3.setAction("Hood", ACTION_MOVE_X, -25);
        S5_SC3.setDetail("");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDialog("S5_SC3_DL_20");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_blank.png");
        S5_SC3.setDelay("Sister", 700);
        S5_SC3.setAction("Hood", ACTION_MOVE_X, -25);
        S5_SC3.setDetail("");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDialog("S5_SC3_DL_21");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_blank.png");
        S5_SC3.setDelay("Sister", 700);
        S5_SC3.setAction("Hood", ACTION_MOVE_X, -25);
        S5_SC3.setDetail("");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDialog("S5_SC3_DL_22");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDialog("S5_SC3_DL_23");
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_SC1.png");
        S5_SC3.setDeath("Sister", true);

        S5_SC3.setDelay("Sister", 1500);
        S5_SC3.setDialog("S5_SC3_DL_24");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDialog("S5_SC3_DL_25");
        S5_SC3.setDialog("S5_SC3_DL_26");
        S5_SC3.setDelay("Sister", 1000);
        S5_SC3.setDetail("");
        S5_SC3.setDialog("S5_SC3_DL_27");
        S5_SC3.setDialog("S5_SC3_DL_28");
        S5_SC3.setAction("Hood", ACTION_MOVE_X, 3, 6);
        S5_SC3.setAction("Hood", ACTION_MOVE_Y, -5, 8);
        S5_SC3.setAction("Hood", ACTION_MOVE_Y, 5, 4);
        S5_SC3.removeRenderCharacter("Hood");
        S5_SC3.setDelay("Hero", 5000);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_blank.png");
        S5_SC3.setDelay("Hero", 3000);
        S5_SC3.setDialog("S5_SC3_DL_29");
        S5_SC3.setDelay("Hero", 3000);
        S5_SC3.setDetail("src\\scene\\S5_SC1\\S5_sad_hero_vs_well_18.png");
        S5_SC3.setDialog("S5_SC3_DL_30");
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_Title.png");
        S5_SC3.setDelay("Hero", 1500);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_Ending.png");
        S5_SC3.setDelay("Hero", 1500);
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_Ending2.png");

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
        SceneMananger::addScene("S1_SC6", S1_SC6);
        SceneMananger::addScene("S2_SC3", S2_SC3);
        SceneMananger::addScene("S3_SC4", S3_SC4);
        SceneMananger::addScene("S4_SC3", S4_SC3);
        SceneMananger::addScene("S4_SC4", S4_SC4);
        SceneMananger::addScene("S4_SC5", S4_SC5);
        SceneMananger::addScene("S4_SC6", S4_SC6);
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

        //E_S1_P
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE); //석판
        PuzzleManager::createPuzzle("S1_M1_DPZ_01", TYPE_READ_PUZZLE);//더미1
        PuzzleManager::createPuzzle("S1_M1_DPZ_02", TYPE_READ_PUZZLE);//더미2
        PuzzleManager::setCompletedObjectASCII("S1_M1_DPZ_01", "src\\maps\\S1\\dummy_S1_01.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_DPZ_01", "S1_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S1_M1_DPZ_01", "S1_M1_DPZ1_DL_00_01");
        //PuzzleManager::setCompletedObjectASCII("S1_M1_DPZ_02", "src\\maps\\S1\\dummy_S1_02.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_DPZ_02", "S1_M1_DPZ2_DL_00_00");
        PuzzleManager::setCompletedDetailASCII("S1_M1_PZ_01", "src\\maps\\S1\\S1_M1_PZ_DT_01.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_PZ_01", "S1_SC2_DL_01");

        //E_S2_P

        PuzzleManager::createPuzzle("S2_M1_PZ_01", TYPE_READ_PUZZLE); //석상에 가로막힌 문
        PuzzleManager::setCompletedObjectASCII("S2_M1_PZ_01", "src\\maps\\S2\\S2_M1_PZ_01_02.png"); //석상에 가로막힌 문
        PuzzleManager::setCompletedSceneDialog("S2_M1_PZ_01", "S7_M1_PZ1_DL_00_02");

        PuzzleManager::createPuzzle("S2_M1_DPZ_01", TYPE_READ_PUZZLE);//더미 회전목마
        PuzzleManager::setCompletedObjectASCII("S2_M1_DPZ_01", "src\\maps\\S2\\dummy_S2_01.png");
        PuzzleManager::setCompletedSceneDialog("S2_M1_DPZ_01", "S2_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S2_M1_DPZ_01", "S2_M1_DPZ1_DL_00_01");

        //E_S3_P
        PuzzleManager::createPuzzle("S3_M1_PZ_01", TYPE_READ_PUZZLE); //피아노 보여주기
        PuzzleManager::setCompletedDetailASCII("S3_M1_PZ_01", "src\\maps\\S3\\S3_M1_PZ_DT_02_01.png");

        PuzzleManager::createPuzzle("S3_M1_DPZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S3_M1_DPZ_01", "src\\maps\\S3\\dummy_S3_01.png");
        PuzzleManager::setCompletedSceneDialog("S3_M1_DPZ_01", "S3_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S3_M1_DPZ_01", "S3_M1_DPZ1_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S3_M1_DPZ_01", "S3_M1_DPZ1_DL_00_02");

        PuzzleManager::createPuzzle("S3_M1_DPZ_02", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S3_M1_DPZ_02", "src\\maps\\S3\\dummy_S3_02.png");

        PuzzleManager::setCompletedSceneDialog("S3_M1_DPZ_02", "S3_M1_DPZ2_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S3_M1_DPZ_02", "S3_M1_DPZ2_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S3_M1_DPZ_02", "S3_M1_DPZ2_DL_00_02");


        //H_S1_P
        PuzzleManager::createPuzzle("S6_M1_PZ_01", TYPE_NUMBER_PUZZLE); //석판을 보고 비밀번호 입력 부분

        PuzzleManager::setPuzzleDetailASCII("S6_M1_PZ_01", 0, "src\\maps\\S1\\S1_M1_PZ_DT_02.png");

        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 4);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 0);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 3);

        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S6_M1_PZ_02", TYPE_READ_PUZZLE); //석판
        PuzzleManager::setCompletedDetailASCII("S6_M1_PZ_02", "src\\maps\\S6\\S6_M1_PZ_DT_01.png");

        PuzzleManager::createPuzzle("S6_M1_DPZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S6_M1_DPZ_01", "src\\maps\\S6\\dummy_S6_01.png");

        PuzzleManager::setCompletedSceneDialog("S6_M1_DPZ_01", "S6_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S6_M1_DPZ_01", "S6_M1_DPZ1_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S6_M1_DPZ_01", "S6_M1_DPZ1_DL_00_02");
        PuzzleManager::setCompletedSceneDialog("S6_M1_DPZ_01", "S6_M1_DPZ1_DL_00_03");


        PuzzleManager::createPuzzle("S6_M1_DPZ_02", TYPE_READ_PUZZLE);
        //PuzzleManager::setCompletedObjectASCII("S6_M1_DPZ_02", "src\\maps\\S6\\dummy_S6_02.png");

        //H_S2_P
        PuzzleManager::createPuzzle("S7_M1_PZ_01", TYPE_ITEM_PUZZLE); //석상
        PuzzleManager::setPuzzleObjectASCII("S7_M1_PZ_01", 0, "src\\maps\\S7\\S7_M1_PZ_01_01.png");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_NCL_DL, "S7_M1_PZ1_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_CL_DL, "S7_M1_PZ1_DL_00_01");
        PuzzleManager::setPuzzleConditionItem("S7_M1_PZ_01", 0, "S7_M2_PZ_FLOWER");
        PuzzleManager::setCompletedObjectASCII("S7_M1_PZ_01", "src\\maps\\S7\\S7_M1_PZ_01_02.png");
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
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 0, "src\\maps\\S7\\S7_M3_PZ_01_01.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 1, "src\\maps\\S7\\S7_M3_PZ_01_02.png");
        PuzzleManager::setPuzzleConditionItem("S7_M3_PZ_01", 0, "S7_M2_PZ_SEED");
        PuzzleManager::setPuzzleReward("S7_M3_PZ_01", 1, "S7_M2_PZ_POT");

        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_NCL_DL, "S7_M3_PZ1_DL_00_00"); //텅 빈 화분이다
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_CL_DL, "S7_M3_PZ1_DL_00_01"); //화분에다 씨앗을 심었다.
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 1, TYPE_CL_DL, "S7_M3_PZ1_DL_00_02"); //화분을 얻었다.
        PuzzleManager::setCompletedObjectASCII("S7_M3_PZ_01", "src\\maps\\S7\\S7_M3_PZ_01_03.png");

        PuzzleManager::createPuzzle("S7_M3_PZ_02", TYPE_ITEM_PUZZLE); //균열 서랍
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_02", 0, "src\\maps\\S7\\S7_M3_PZ_02_01.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_02", 1, "src\\maps\\S7\\S7_M3_PZ_02_02.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_02", 2, "src\\maps\\S7\\S7_M3_PZ_02_03.png");
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


        PuzzleManager::createPuzzle("S7_M1_DPZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S7_M1_DPZ_01", "src\\maps\\S7\\dummy_S7_01_01.png");

        PuzzleManager::setCompletedSceneDialog("S7_M1_DPZ_01", "S7_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S7_M1_DPZ_01", "S7_M1_DPZ1_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S7_M1_DPZ_01", "S7_M1_DPZ1_DL_00_02");
        PuzzleManager::setCompletedSceneDialog("S7_M1_DPZ_01", "S7_M1_DPZ1_DL_00_03");

        PuzzleManager::createPuzzle("S7_M2_DPZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S7_M2_DPZ_01", "src\\maps\\S7\\dummy_S7_02_01.png");

        PuzzleManager::setCompletedSceneDialog("S7_M2_DPZ_01", "S7_M2_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S7_M2_DPZ_01", "S7_M2_DPZ1_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S7_M2_DPZ_01", "S7_M2_DPZ1_DL_00_02");

        //GameObjectManager::getCharacter("Hero")->addInventory("S7_M2_PZ_FLOWER");
        //GameObjectManager::getCharacter("Hero")->addInventory("S7_M2_PZ_LIGHTER");
        //GameObjectManager::getCharacter("Hero")->addInventory("S7_M2_PZ_POT");

        //H_S3_P
        PuzzleManager::createPuzzle("S8_M1_PZ_01", TYPE_NUMBER_PUZZLE);
        PuzzleManager::setPuzzleDetailASCII("S8_M1_PZ_01", 0, "src\\maps\\S8\\S8_M1_PZ_DT_01_01.png");

        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 6);
        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 2);
        PuzzleManager::setCorrectAnswer("S8_M1_PZ_01", 1);

        PuzzleManager::setPuzzleSceneDialog("S8_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S8_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S8_M1_PZ_02", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedDetailASCII("S8_M1_PZ_02", "src\\maps\\S8\\S8_M1_PZ_DT_02_01.png");

        PuzzleManager::createPuzzle("S8_M1_DPZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S8_M1_DPZ_01", "src\\maps\\S8\\dummy_S8_01.png");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_02");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_03");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_04");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_05");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_06");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_07");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_08");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_01", "S8_M1_DPZ1_DL_00_09");

        PuzzleManager::createPuzzle("S8_M1_DPZ_02", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedObjectASCII("S8_M1_DPZ_02", "src\\maps\\S8\\dummy_S8_02.png");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_02", "S8_M1_DPZ2_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_02", "S8_M1_DPZ2_DL_00_01");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_02", "S8_M1_DPZ2_DL_00_02");
        PuzzleManager::setCompletedSceneDialog("S8_M1_DPZ_02", "S8_M1_DPZ2_DL_00_03");

        //H_S4_P
        PuzzleManager::createPuzzle("S9_M1_PZ_01", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_01", "S9_M1_PZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_01", "S9_M1_PZ1_DL_00_01");
        PuzzleManager::createPuzzle("S9_M1_PZ_02", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_02", "S9_M1_PZ1_DL_00_02");
        PuzzleManager::createPuzzle("S9_M1_PZ_03", TYPE_READ_PUZZLE);
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_03", "S9_M1_PZ1_DL_00_03");

        PuzzleManager::createPuzzle("S9_M1_PZ_04", TYPE_READ_PUZZLE); //일기장
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_04", "S9_M1_PZ1_DL_00_03");

        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_04", "S4_SC3_DL_01");
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_04", "S4_SC3_DL_02");
        PuzzleManager::setCompletedSceneDetail("S9_M1_PZ_04", "src\\scene\\S4_SC3\\S4_SC3_DT_00.png");
        PuzzleManager::setCompletedSceneVKSPACE("S9_M1_PZ_04");
        PuzzleManager::setCompletedSceneDetail("S9_M1_PZ_04", "src\\scene\\S4_SC3\\S4_SC3_DT_01.png");
        PuzzleManager::setCompletedSceneVKSPACE("S9_M1_PZ_04");
        PuzzleManager::setCompletedSceneDetail("S9_M1_PZ_04", "src\\scene\\S4_SC3\\S4_SC3_DT_02.png");
        PuzzleManager::setCompletedSceneVKSPACE("S9_M1_PZ_04");
        PuzzleManager::setCompletedSceneDetail("S9_M1_PZ_04", "");
        PuzzleManager::setCompletedSceneDialog("S9_M1_PZ_04", "S4_SC3_DL_03");

    };

    static void MapInit() {
        MapManager::createMap("S0_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S0\\S0_MAP.png", "src\\maps\\S0\\S0_MAP_INFO.png");
        MapManager::createMap("S1_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S1\\S1_P_MAP_01.png", "src\\maps\\S1\\S1_P_MAP_INFO_01.png");
        MapManager::createMap("S1_J_MAP_01", TYPE_JUMP, "src\\maps\\S1\\S1_J_MAP_01.png", "src\\maps\\S1\\S1_J_MAP_INFO_01.png");
        MapManager::createMap("S2_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S2\\S2_P_MAP_01.png", "src\\maps\\S2\\S2_P_MAP_INFO_01.png");
        MapManager::createMap("S2_J_MAP_01", TYPE_JUMP, "src\\maps\\S2\\S2_J_MAP_01.png", "src\\maps\\S2\\S2_J_MAP_INFO_01.png");
        MapManager::createMap("S3_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S3\\S3_P_MAP_01.png", "src\\maps\\S3\\S3_P_MAP_INFO_01.png");
        MapManager::createMap("S3_J_MAP_01", TYPE_JUMP, "src\\maps\\S3\\S3_J_MAP_01.png", "src\\maps\\S3\\S3_J_MAP_INFO_01.png");
        MapManager::createMap("S4_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S4\\S4_P_MAP_01.png", "src\\maps\\S4\\S4_P_MAP_INFO_01.png");
        MapManager::createMap("S4_J_MAP_01", TYPE_JUMP, "src\\maps\\S4\\S4_J_MAP_01.png", "src\\maps\\S4\\S4_J_MAP_INFO_02.png");
        MapManager::createMap("S5_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S5\\S5_MAP_01.png", "src\\maps\\S5\\S5_MAP_INFO_01_TEST.png");
        MapManager::createMap("S6_P_MAP_00", TYPE_PUZZLE, "src\\maps\\S0\\S0_MAP.png", "src\\maps\\S0\\S0_MAP_INFO.png");
        MapManager::createMap("S6_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S6\\S6_P_MAP_01.png", "src\\maps\\S6\\S6_P_MAP_INFO_01.png");
        MapManager::createMap("S6_J_MAP_01", TYPE_JUMP, "src\\maps\\S6\\S6_J_MAP_01.png", "src\\maps\\S6\\S6_J_MAP_INFO_01.png");
        MapManager::createMap("S7_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S7\\S7_P_MAP_01.png", "src\\maps\\S7\\S7_P_MAP_INFO_01.png");
        MapManager::createMap("S7_P_MAP_02", TYPE_PUZZLE, "src\\maps\\S7\\S7_P_MAP_02.png", "src\\maps\\S7\\S7_P_MAP_INFO_02.png");
        MapManager::createMap("S7_P_MAP_03", TYPE_PUZZLE, "src\\maps\\S7\\S7_P_MAP_03.png", "src\\maps\\S7\\S7_P_MAP_INFO_03.png");
        MapManager::createMap("S7_J_MAP_01", TYPE_JUMP, "src\\maps\\S7\\S7_J_MAP_01.png", "src\\maps\\S7\\S7_J_MAP_INFO_01.png");
        MapManager::createMap("S8_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S8\\S8_P_MAP_01.png", "src\\maps\\S8\\S8_P_MAP_INFO_01.png");
        MapManager::createMap("S8_J_MAP_01", TYPE_JUMP, "src\\maps\\S8\\S8_J_MAP_01.png", "src\\maps\\S8\\S8_J_MAP_INFO_01.png");
        MapManager::createMap("S9_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_01.png", "src\\maps\\S9\\S9_P_MAP_INFO_01.png");
        MapManager::createMap("S9_P_MAP_01_02", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_01_02.png", "src\\maps\\S9\\S9_P_MAP_INFO_01_02.png");
        MapManager::createMap("S9_P_MAP_01_03", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_01_03.png", "src\\maps\\S9\\S9_P_MAP_INFO_01_03.png");
        MapManager::createMap("S9_P_MAP_02", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_02.png", "src\\maps\\S9\\S9_P_MAP_INFO_02.png");
        MapManager::createMap("S9_P_MAP_03_0", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_03_0.png", "src\\maps\\S9\\S9_P_MAP_INFO_03_0.png");
        MapManager::createMap("S9_P_MAP_03_1", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_03_1.png", "src\\maps\\S9\\S9_P_MAP_INFO_03_1.png");
        MapManager::createMap("S9_P_MAP_03_2", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_03_2.png", "src\\maps\\S9\\S9_P_MAP_INFO_03_2.png");
        MapManager::createMap("S9_P_MAP_03_3", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_03_3.png", "src\\maps\\S9\\S9_P_MAP_INFO_03_3.png");
        MapManager::createMap("S9_P_MAP_04", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_04.png", "src\\maps\\S9\\S9_P_MAP_INFO_04.png");
        MapManager::createMap("S9_P_MAP_05", TYPE_PUZZLE, "src\\maps\\S9\\S9_P_MAP_05.png", "src\\maps\\S9\\S9_P_MAP_INFO_05.png");
        MapManager::createMap("S9_J_MAP_01", TYPE_JUMP, "src\\maps\\S9\\S9_J_MAP_01.png", "src\\maps\\S9\\S9_J_MAP_INFO_01.png");
        MapManager::createMap("S10_P_MAP_01", TYPE_PUZZLE, "src\\maps\\S10\\S10_MAP_01.png", "src\\maps\\S10\\S10_MAP_INFO_01_TEST.png");
    };


    static void StageInit(EventDispatcher* eventDispathcer) {
        for (int i = 0; i < 12; i++) {
            StageManager::addStage(i, eventDispathcer);
        }
        //E_S0
        StageManager::addMap(0, MapManager::getMap("S0_P_MAP_01"));

        StageManager::setDoorID(0, "S0_P_MAP_01", MAP_EXIT, "EXIT");
        StageManager::setScene(0, "S0_P_MAP_01", "S0_SC1");
        //E_S1
        StageManager::addMap(1, MapManager::getMap("S1_P_MAP_01"));
        StageManager::addMap(1, MapManager::getMap("S1_J_MAP_01"));

        StageManager::setDoorID(1, "S1_P_MAP_01", MAP_EXIT, "S1_J_MAP_01");
        StageManager::setDoorID(1, "S1_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(1, "S1_P_MAP_01", PUZZLE_OBJ_02, "S1_M1_PZ_01");
        StageManager::setPuzzleId(1, "S1_P_MAP_01", PUZZLE_OBJ_05, "S1_M1_DPZ_01");
        StageManager::setPuzzleId(1, "S1_P_MAP_01", PUZZLE_OBJ_06, "S1_M1_DPZ_02");
        //S1_SC2 퍼즐1층 씬 (석판을 보고난 후)

        StageManager::setScene(1, "S1_P_MAP_01", "S1_SC1");
        StageManager::setScene(1, "S1_J_MAP_01", "S1_SC3");

        //E_S2
        StageManager::addMap(2, MapManager::getMap("S2_P_MAP_01"));
        StageManager::addMap(2, MapManager::getMap("S2_J_MAP_01"));

        StageManager::setDoorID(2, "S2_P_MAP_01", MAP_EXIT, "S2_J_MAP_01");
        StageManager::setDoorID(2, "S2_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(2, "S2_P_MAP_01", PUZZLE_OBJ_01, "S2_M1_PZ_01");
        StageManager::setPuzzleId(2, "S2_P_MAP_01", PUZZLE_OBJ_05, "S2_M1_DPZ_01");

        StageManager::setScene(2, "S2_P_MAP_01", "S2_SC1");
        StageManager::setScene(2, "S2_J_MAP_01", "S2_SC2");

        //E_S3
        StageManager::addMap(3, MapManager::getMap("S3_P_MAP_01"));
        StageManager::addMap(3, MapManager::getMap("S3_J_MAP_01"));

        StageManager::setDoorID(3, "S3_P_MAP_01", MAP_EXIT, "S3_J_MAP_01");
        StageManager::setDoorID(3, "S3_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(3, "S3_P_MAP_01", PUZZLE_OBJ_02, "S3_M1_PZ_01");
        StageManager::setPuzzleId(3, "S3_P_MAP_01", PUZZLE_OBJ_05, "S3_M1_DPZ_01");
        StageManager::setPuzzleId(3, "S3_P_MAP_01", PUZZLE_OBJ_06, "S3_M1_DPZ_02");

        StageManager::setScene(3, "S3_P_MAP_01", "S3_SC1");
        StageManager::setScene(3, "S3_J_MAP_01", "S3_SC2");

        //E_S4
        StageManager::addMap(4, MapManager::getMap("S4_P_MAP_01"));
        StageManager::addMap(4, MapManager::getMap("S4_J_MAP_01"));

        StageManager::setDoorID(4, "S4_P_MAP_01", MAP_EXIT, "S4_J_MAP_01");
        StageManager::setDoorID(4, "S4_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setScene(4, "S4_P_MAP_01", "S4_SC1");
        StageManager::setScene(4, "S4_J_MAP_01", "S4_SC5");

        //E_S5
        StageManager::addMap(5, MapManager::getMap("S5_P_MAP_01"));
        StageManager::setDoorID(5, "S5_P_MAP_01", MAP_EXIT, "EXIT");
        StageManager::setScene(5, "S5_P_MAP_01", "S5_SC1");


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
        StageManager::setPuzzleId(6, "S6_P_MAP_01", PUZZLE_OBJ_05, "S6_M1_DPZ_01");

        StageManager::setScene(6, "S6_P_MAP_00", "S0_SC3");
        StageManager::setScene(6, "S6_P_MAP_01", "S1_SC5");
        StageManager::setScene(6, "S6_J_MAP_01", "S1_SC6");
        //StageManager::setPuzzleId(6, "S6_P_MAP_01", PUZZLE_OBJ_06, "S6_M1_DPZ_02");

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
        StageManager::setPuzzleId(7, "S7_P_MAP_01", PUZZLE_OBJ_05, "S7_M1_DPZ_01");
        StageManager::setPuzzleId(7, "S7_P_MAP_02", PUZZLE_OBJ_05, "S7_M2_DPZ_01");

        StageManager::setScene(7, "S7_P_MAP_01", "S2_SC3");
        //H_S3
        StageManager::addMap(8, MapManager::getMap("S8_P_MAP_01"));
        StageManager::addMap(8, MapManager::getMap("S8_J_MAP_01"));

        StageManager::setDoorID(8, "S8_P_MAP_01", MAP_EXIT, "S8_J_MAP_01");
        StageManager::setDoorID(8, "S8_J_MAP_01", MAP_EXIT, "EXIT");

        StageManager::setPuzzleId(8, "S8_P_MAP_01", PUZZLE_OBJ_01, "S8_M1_PZ_01");
        StageManager::setPuzzleId(8, "S8_P_MAP_01", PUZZLE_OBJ_02, "S8_M1_PZ_02");
        StageManager::setPuzzleId(8, "S8_P_MAP_01", PUZZLE_OBJ_05, "S8_M1_DPZ_01");
        StageManager::setPuzzleId(8, "S8_P_MAP_01", PUZZLE_OBJ_06, "S8_M1_DPZ_02");

        StageManager::setScene(8, "S8_P_MAP_01", "S3_SC4");

        //H_S4
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_01"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_02"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_01_02"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_01_03"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_0"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_1"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_2"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_03_3"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_04"));
        StageManager::addMap(9, MapManager::getMap("S9_P_MAP_05"));
        StageManager::addMap(9, MapManager::getMap("S9_J_MAP_01"));

        StageManager::setPuzzleId(9, "S9_P_MAP_01", PUZZLE_OBJ_01, "S9_M1_PZ_01");
        StageManager::setPuzzleId(9, "S9_P_MAP_01_02", PUZZLE_OBJ_01, "S9_M1_PZ_02");
        StageManager::setPuzzleId(9, "S9_P_MAP_04", PUZZLE_OBJ_02, "S9_M1_PZ_04");
        StageManager::setPuzzleId(9, "S9_P_MAP_01_03", PUZZLE_OBJ_01, "S9_M1_PZ_03");



        StageManager::setDoorID(9, "S9_P_MAP_01", MAP_DOOR_01, "S9_P_MAP_02");
        StageManager::setDoorID(9, "S9_P_MAP_01_02", MAP_DOOR_01, "S9_P_MAP_03_0");
        StageManager::setDoorID(9, "S9_P_MAP_01_03", MAP_EXIT, "S9_J_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_03_0", MAP_DOOR_01, "S9_P_MAP_03_1");
        StageManager::setDoorID(9, "S9_P_MAP_03_1", MAP_DOOR_01, "S9_P_MAP_03_2");
        StageManager::setDoorID(9, "S9_P_MAP_03_2", MAP_DOOR_01, "S9_P_MAP_05");
        StageManager::setDoorID(9, "S9_P_MAP_03_0", MAP_DOOR_02, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_03_1", MAP_DOOR_02, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_03_2", MAP_DOOR_02, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_03_0", MAP_EXIT, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_03_1", MAP_EXIT, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_03_2", MAP_EXIT, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_03_3", MAP_EXIT, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_02", MAP_EXIT, "S9_P_MAP_01");
        StageManager::setDoorID(9, "S9_P_MAP_02", MAP_DOOR_02, "S9_P_MAP_04");
        StageManager::setDoorID(9, "S9_P_MAP_04", MAP_EXIT, "S9_P_MAP_01_02");
        StageManager::setDoorID(9, "S9_P_MAP_05", MAP_EXIT, "S9_P_MAP_01_03");
        StageManager::setDoorID(9, "S9_J_MAP_01", MAP_EXIT, "EXIT");


        //StageManager::setScene(9, "S9_P_MAP_04", "S4_SC3");
        StageManager::setScene(9, "S9_P_MAP_01", "S4_SC2");
        StageManager::setScene(9, "S9_P_MAP_05", "S4_SC4");
        StageManager::setScene(9, "S9_P_MAP_01_03", "S4_SC6");

        //H_S5
        StageManager::addMap(10, MapManager::getMap("S10_P_MAP_01"));
        StageManager::setDoorID(10, "S10_P_MAP_01", MAP_EXIT, "EXIT");
        StageManager::setScene(10, "S10_P_MAP_01", "S5_SC3");

        //setMapASCII
        MapManager::setMapASCII("S0_P_MAP_01");
        MapManager::setMapASCII("S1_P_MAP_01");
        MapManager::setMapASCII("S1_J_MAP_01");
        MapManager::setMapASCII("S2_P_MAP_01");
        MapManager::setMapASCII("S2_J_MAP_01");
        MapManager::setMapASCII("S3_P_MAP_01");
        MapManager::setMapASCII("S3_J_MAP_01");
        MapManager::setMapASCII("S4_P_MAP_01");
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
        MapManager::setMapASCII("S9_P_MAP_01_02");
        MapManager::setMapASCII("S9_P_MAP_01_03");
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