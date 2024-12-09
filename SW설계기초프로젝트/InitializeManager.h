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
        GameObjectManager::createObject("Dialog", "PZ_NCL_DL", "���� ������ �ʾ�...");

        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_00", "����: ���� ������ �ʾ�... ���谡 �ʿ��� �� ����.");
        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_01", "���踦 ����Ѵ�.");

        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_00", "����: ���� ���� ���� �ٱ� ������ �����ؿԴ�...");
        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_01", "����: ���� ������ ä���־� ����... ����... �ɰ� ���� �״뿩...");
        GameObjectManager::createObject("Dialog", "S7_M1_PZ1_DL_00_02", "����: ���� ���� ���� �� ���� ����");

        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_00", "����: ���� ������ �ʾ�... ���谡 �ʿ��� �� ����.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_01", "[����]�� ����Ѵ�.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_02", "[��ġ]�� �����.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ1_DL_00_03", "�������� ���̻� ���� ���� ����δ�.");

        GameObjectManager::createObject("Dialog", "S7_M2_PZ2_DL_00_00", "[����]�� �����.");
        GameObjectManager::createObject("Dialog", "S7_M2_PZ2_DL_00_01", "�� �̻� ���� ���� ����δ�.");

        GameObjectManager::createObject("Dialog", "S7_M3_PZ1_DL_00_00", "��ۿ� ���� �� �� ȭ���̴�.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ1_DL_00_01", "ȭ�п� ������ �ɾ����� ���� ��ٷ� �ڶ���.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ1_DL_00_02", "[������ ���� ȭ��]�� �����");

        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_00", "���� �����鼭 [�տ�]�� �����.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_01", "���� �� ���̷� [����]�� �����.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_02", "[��ġ]�� ���ٴ��� �տ��� ������.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_03", "�� ƴ ���̷� [���ٱ�]�� ���Դ�.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_04", "ȭ���� ������ ������ ���� �� ����.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_05", "[���ٱ�]�� [ȭ��]�� ���ٴ�� ���� ���.");
        GameObjectManager::createObject("Dialog", "S7_M3_PZ2_DL_00_06", "[���� �� ȭ��]�� �����.");

        GameObjectManager::createObject("Dialog", "NUM_PZ_NCL_DL", "��й�ȣ�� Ʋ�Ƚ��ϴ�.");
        GameObjectManager::createObject("Dialog", "NUM_PZ_CL_DL", "��й�ȣ�� �¾ҽ��ϴ�.");

    };

    static void SceneInit() {
        Scene S0_SC1, S0_SC2, S1_SC1, S1_SC2, S1_SC3, S1_SC4, S2_SC1, S2_SC2, S2_SC3, S3_SC1, S3_SC2, S3_SC3, S4_SC1, S4_SC2, S5_SC1, S5_SC2,
            S0_SC3, S1_SC5, S2_SC4, S4_SC3, S4_SC4, S5_SC3;

        //S0_SC1 ���ѷα�
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_01", "���������� ���� ������ �������� ������ �ִ�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_02", "���� �� ��, �ð����� ���� ���� ����� ž.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_03", "���� ��������, ���� �������������� ���� ä ž�� �� �ڸ��� ���� ���̴�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_04", "ž�� ���� �����, �ź�ο� �칰�� �ҿ��� ����, �� � �ٶ��� �̷������.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_05", "���� �� �̽Ÿ��� ������ ���� ž�� �������� ������� ����.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_06", "�㳪 �� ������Դ� �� ������ ������ ������ ����̾�����..");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_07", "�� �Ŵ��� ���� õõ�� ������, ����� �ٲ� ������ ���۵ȴ�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_08", "����: ���� ��Ӵϸ� ���� ������ �ö� �ž�.");

        S0_SC1.setDetail("src\\S0_SC1_00.png");
        S0_SC1.setDialog("S0_SC1_DL_01");
        S0_SC1.setDialog("S0_SC1_DL_02");
        S0_SC1.setDialog("S0_SC1_DL_03");
        S0_SC1.setDialog("S0_SC1_DL_04");
        S0_SC1.setDialog("S0_SC1_DL_05");
        S0_SC1.setDialog("S0_SC1_DL_06");
        S0_SC1.setDialog("S0_SC1_DL_07");
        S0_SC1.setDialog("S0_SC1_DL_08");

        //S0_SC2.setDetail("src\\S0_SC2_00.png"); //����� ž�� �Ա���. �̰� �׷�����


        //S1_SC1 ����1�� �� (������ ������)
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_01", "����: �����Ⱑ �ɻ�ġ�� �ʳ�... �������� �� ���� ���ǵ鵵 ���� ���̾�.");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_02", "����: ���� �̰� ��! ���� �����־�!");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_03", "���� �ɷ��ִ� �׸��� ��ȣ�ۿ��Ϸ��� F Ű�� ����������.");

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

        //S1_SC2 ����1�� �� (������ ���� �� ��)
        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "����: �ҹ��� ����ΰ���. ���� ���� ���� �ִ°� ������ ������!");

        //S1_SC3 ����1�� ��
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_01", "����: ���� ����. ��û �����غ����ݾ�.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_02", "����: ��ø�, �̰� �׳� �Ǹ����� �������ڴٰ� ? ");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_03", "����: �� �̷��� �����ϰ� �� �� �����ž�.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_04", "�����¿�� �����̽��ٷ� �̵��� ����, �׸��� �뽬�� �� �� �ֽ��ϴ�.");

        S1_SC3.setDelay("Sister", 700);
        S1_SC3.setDialog("S1_SC3_DL_01");
        S1_SC3.setDialog("S1_SC3_DL_02");
        S1_SC3.setAction("Sister", ACTION_MOVE_X, 2, 1);
        //S1_SC3 ���� �۷�
        S1_SC3.setDialog("S1_SC3_DL_03");
        S1_SC3.setDialog("S1_SC3_DL_04");

        //S1_SC4 ����� ��
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_01", "����: �� �� �ȿ� ���� ���� ������? ��·�� ���� ������ ����������.");
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_02", "����: �츮 ���� ���ȿ� ������ ��������? ���� ������ ���ư��� �ʹ١�");
        S1_SC4.setDelay("Sister", 700);
        S1_SC4.setDialog("S1_SC4_DL_01");
        S1_SC4.setDialog("S1_SC4_DL_02");

        //S2_SC1 ����2�� ��

        GameObjectManager::createObject("Dialog", "S2_SC1_DL_01", "����: �� �ν����⡦? �������� �� �μ��� �ֳ� ? ");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_02", "����: ���̶�� �ϱ⿣ ������ ����� �� �� �� ����.");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_03", "����: ��, � ������!");

        S2_SC1.setDelay("Sister", 700);
        S2_SC1.setAction("Sister", ACTION_MOVE_X, 6, 15); //���� �տ� �������� ���Բ� ����
        S2_SC1.setDialog("S2_SC1_DL_01");
        S2_SC1.setDialog("S2_SC1_DL_02");
        S2_SC1.setDialog("S2_SC1_DL_03");


        //S2_SC2 ����2�� ��
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_01", "����: ���⵵ ����� �����ϳ�.");
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_02", "Ư�� ���� \"Ű\"�� ��Ÿ�⸦ �� �� �ֽ��ϴ�.");
        S2_SC2.setDelay("Sister", 700);
        S2_SC2.setDialog("S2_SC2_DL_01");
        S2_SC2.setDialog("S2_SC2_DL_02");

        //S2_SC3 ����2�� ��
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_01", "����: �칰�� ���� ���� �ҿ��� ����ִ� �� �°���?");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_02", "����: �����ε� ������ �̷� ������ �� �������� ���� �̻���.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_03", "����: �������� ���� �ǵ帰 ������ �ִ� �� ����.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_04", "����: ���� �־�� �� �� ���� �����̾�... ���� ���� �������ɱ?");

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
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_01", "����: ��͡� ���� ���� ������ ���̳�.");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_02", "����: ���ݱ��� �ô� ������� ������ �ٸ��ݾ�. �Ѿ �� ������?");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_03", "���ݱ��� ��� ���� Ȱ���Ͽ� ���� Ŭ�����غ�����.");

        S2_SC3.setDelay("Sister", 700);
        S2_SC3.setDialog("S3_SC2_DL_01");
        S2_SC3.setDialog("S3_SC2_DL_02");
        S2_SC3.setDialog("S3_SC2_DL_03");

        //S3_SC3
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_01", "����: �� ���� ������ �� �̻��ϰ�, �� ���� ���� ���� ���� ���ǵ�� �����ϳ�.");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_02", "����: ����ü ����, �� �̷� ���� ���� �ɱ�?");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_03", "����: �칰�� ���� �ҹ��� �� ������ ���� ����� �� ����! ���� ������!");

        S3_SC3.setDelay("Sister", 700);
        S3_SC3.setDialog("S3_SC3_DL_01");
        S3_SC3.setDialog("S3_SC3_DL_02");
        S3_SC3.setDialog("S3_SC3_DL_03");

        //S4_SC1
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_01", "����: ���⵵ ���� �̻��� �������� �־ �׸��� �� �̹� Ǯ���ֳ�.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_02", "����: �졦 ���� ������ �ء�");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_03", "����: ���� ��ٸ��ڴ�! �� ��������.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_04", "����: �׷�. �ϴ� �������߰ڴ�.");

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
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_01", "����: ���� �칰�� ���δ�!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_02", "����: ���� �ź�Ӵ١� �̷��� ������ ���ٴ� �ϱ��� �ʾ�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_03", "���� ������ �����١�");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_04", "����: ��? ���?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_05", "�ΰǳ�: ����");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_06", "�ΰ��� �� ���ڰ� ���� �߾�Ÿ��� �� �ϴ�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_07", "����: ����!! �� ��!!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_08", "����: ��ϡ� ");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_09", "����: ���ȡ� ���� �Ͼ�ࡦ ���� ����!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_10", "�̹� ������ �� ���� ������ ���� �� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_11", "???: ���ϱ⵵ ����.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_12", "�칰���� �ź�ο쳪 ������ ��Ҹ��� ����´�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_13", "����: �װ� �ٹ� ������! �� �ΰ��� �� ����?!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_14", "???: ���� ���������� �� ���� �����ߴ� �칰�� ���̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_15", "???: ���� ���� �ҿ��� ����ִ� �칰�μ� ���⿡ ���� ���̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_16", "����: �׵� �� ����, ���� ������ �����!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_17", "???: ��� �ҿ����� �밡�� ������. �� �������� �츮�� �ʹٸ顦");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_18", "???: ž���� ���� ������ ���� ������ �칰 ������ ��������.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_19", "???: �׸��ϸ� ���� ������ ���̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_20", "����: �밡�� ž���� ���� ������ �͡�?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_21", "����: �װ� ���� ������ �ǹ̰� ����. � �밡�� ġ���ھ�.");

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
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_01", "���� �칰 ������ ����ɰ� �ִ�.");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_02", "���� �� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_03", "���� �������� �Ӹ� ���� ������ �����̴�.");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_04", "�� �������� ���ؾ߸� �ء� �ݵ�á� ���ȡ�");
        GameObjectManager::createObject("Dialog", "S5_SC2_DL_05", "���� ��� �ӿ��� ���ΰ��� ������ �Ҵ´�.");
        // �칰 �ȿ��� ����޴� ���ΰ��� �������� ���ھ��.
        S5_SC2.setDialog("S5_SC2_DL_01");
        S5_SC2.setDialog("S5_SC2_DL_02");
        S5_SC2.setDialog("S5_SC2_DL_03");
        S5_SC2.setDialog("S5_SC2_DL_04");
        S5_SC2.setDialog("S5_SC2_DL_05");

        //S0_SC3

        GameObjectManager::createObject("Dialog", "S0_SC3_DL_01", "����: �����䡦?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_02", "�ͼ��� ž�� �Ա��� ���տ� ���´�.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_03", "����: ������ �ƹ��� ���� ���� �� ����. �ð��� �������� �ǰ���?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_04", "����: ������ ���Ϸ��� ���ѷ��� ��. ���� ���� ž���� ���� ��.");

        S0_SC3.setDialog("S0_SC3_DL_01");
        S0_SC3.setDialog("S0_SC3_DL_02");
        S0_SC3.setDialog("S0_SC3_DL_03");
        S0_SC3.setDialog("S0_SC3_DL_04");

        //S1_SC5
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_01", "����¡�");
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_02", "ž�� 1��... �ϴ� �� ��������. ������ ���� �ѽö� ���� ã�Ƽ� �칰�� ������.");

        S1_SC5.setDialog("S1_SC5_DL_01");
        S1_SC5.setDialog("S1_SC5_DL_02");
        //S2_SC4


        //S4_SC3


        //S4_SC4


        //S5_SC3
        // S5_SC3: ������ �ð����� ���ƿ� ����, ������ �칰����
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_01", "����: �칰�� ���ϴ� �� ��ü ���");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_02", "����: �� ž�� ��� �� ������. �ƹ��͵� ã�� ���߾�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_03", "???: �׷��� ���� ȭ�� �� ���ΰ�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_04", "����: �װ� ���� �ӿ��ݾ�. ���ʺ��� �ƹ��͵� ������ �� �ƴϾ�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_05", "???: ���̴ٴ�, ���� �Ҹ���. ���� �ҿ��� �̷�� �칰�̴�. �̷� ����� �װ� �޷� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_06", "����: �װ� [���� ������ ��]�� ��������� ���ݾ�! �װ� ���ϴ� �� ������ �𸣰� ��̴ٰ�!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_07", "???: �ʴ� �̹� �˰� �������� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_08", "��� �ʿ��� �߼Ҹ��� �鸰��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_09", "???: �̷�. �մ��� �� ����̱�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_10", "����: ���� �칰�� ���δ�!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_11", "����: ���� �ź�Ӵ١� �̷��� ������ ���ٴ� �ϱ��� �ʾ�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_12", "���δ� �칰 �ڷ� ���� �����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_13", "����: ���, ���⿡ �̻��� ����� ������. ���� �ֳ� ��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_14", "������ ����: ������, ����. ���� �ǵ帮�� ��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_15", "������ ���� �αٿ��� �����ϰ� �Ƹ��ٿ� ���� ����´�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_16", "����: ���ǡ�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_17", "����: ���, ���� ������ �ִ� �� ����!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_18", "������ ����: ����, �ڷ� ������.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_19", "�ΰ��� �� ���ΰ� õõ�� ����� �巯����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_20", "����: �� �������?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_21", "����: �̾ȡ� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_22", "���δ� Į�� �̾Ƶ�� ���ȿ��� �ٰ�����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_23", "����: ���, �� �ϴ¡�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_24", "����: ���ƾ�!!!");
		GameObjectManager::createObject("Dialog", "S5_SC3_DL_25", "ž���� [���� ������ ��]�� ȹ���ߴ�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_26", "������ ����: ����!! �� ��!!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_27", "???: �� ������ ������.��Ӵ�� ���� �ҿ��� �̷������.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_28", "����: ���ȡ� ���� ���ԡ�");

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

        /*GameObjectManager::createObejct("Dialog", "S6_SC1_DL_01", "����: �� �����顦 �ϱ��塦 �׸��� �� ž.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_02", "???: ���� �̵��� �̰��� ���� �鿴��.������ �ڽ��� �ٶ��� �̷�� ����.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_03", "����: �� �װ� ��� ���Ѻ��� �־�����.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_04", "???: ������ ������ ������ ��̷���.����� ������ �����ϴ� ������ ���� �͸�ŭ ��̷ο� ���� �����ϱ�.");
        GameObjectManager::createObejct("Dialog", "S6_SC1_DL_05", "����: ��硦 ���� ����� �о���.�״� �ᱹ �� ž�� ������ ������.");


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

        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "����: �ҹ��� ����ΰ���. ���� ���� ���� �ִ°� ������ ������!");
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE); //����
        PuzzleManager::setCompletedDetailASCII("S1_M1_PZ_01", "src\\S6_M1_PZ_DT_01.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_PZ_01", "S1_SC2_DL_01");

        PuzzleManager::createPuzzle("S2_M1_PZ_01", TYPE_READ_PUZZLE); //���� ���θ��� ��
        PuzzleManager::setCompletedObjectASCII("S2_M1_PZ_01", "src\\S2_M1_PZ_01_02.png"); //���� ���θ��� ��
        PuzzleManager::setCompletedSceneDialog("S2_M1_PZ_01", "S7_M1_PZ1_DL_00_02");
        PuzzleManager::setCompletedSceneLoop("S2_M1_PZ_01", true);

        PuzzleManager::createPuzzle("S3_M1_PZ_01", TYPE_READ_PUZZLE); //�ǾƳ� �����ֱ�
        PuzzleManager::setCompletedDetailASCII("S3_M1_PZ_01", "src\\S8_M1_PZ_DT_02_01.png");



        PuzzleManager::createPuzzle("S6_M1_PZ_01", TYPE_NUMBER_PUZZLE); //������ ���� ��й�ȣ �Է� �κ�

        PuzzleManager::setPuzzleDetailASCII("S6_M1_PZ_01", 0, "src\\S1_M1_PZ_DT_02.png");

        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 0);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 4);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 3);

        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S6_M1_PZ_02", TYPE_READ_PUZZLE); //����
        PuzzleManager::setCompletedDetailASCII("S6_M1_PZ_02", "src\\S6_M1_PZ_DT_01.png");

        PuzzleManager::createPuzzle("S7_M1_PZ_01", TYPE_ITEM_PUZZLE); //����
        PuzzleManager::setPuzzleObjectASCII("S7_M1_PZ_01", 0, "src\\S7_M1_PZ_01_01.png");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_NCL_DL, "S7_M1_PZ1_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_CL_DL, "S7_M1_PZ1_DL_00_01");
        PuzzleManager::setPuzzleConditionItem("S7_M1_PZ_01", 0, "S7_M2_PZ_FLOWER");
        PuzzleManager::setCompletedObjectASCII("S7_M1_PZ_01", "src\\S7_M1_PZ_01_02.png");
        PuzzleManager::setCompletedSceneDialog("S7_M1_PZ_01", "S7_M1_PZ1_DL_00_02");

        PuzzleManager::createPuzzle("S7_M2_PZ_01", TYPE_ITEM_PUZZLE); //����
        PuzzleManager::setPuzzleConditionItem("S7_M2_PZ_01", 0, "S7_M1_PZ_KEY");
        PuzzleManager::setPuzzleReward("S7_M2_PZ_01", 0, "S7_M2_PZ_LIGHTER");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_01", 0, TYPE_NCL_DL, "S7_M2_PZ1_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_01", 0, TYPE_CL_DL, "S7_M2_PZ1_DL_00_01");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_01", 0, TYPE_CL_DL, "S7_M2_PZ1_DL_00_02");
        PuzzleManager::setCompletedSceneDialog("S7_M2_PZ_01", "S7_M2_PZ1_DL_00_03");

        PuzzleManager::createPuzzle("S7_M2_PZ_02", TYPE_READ_PUZZLE); //����
        PuzzleManager::setPuzzleReward("S7_M2_PZ_02", 0, "S7_M2_PZ_SEED");
        PuzzleManager::setPuzzleSceneDialog("S7_M2_PZ_02", 0, TYPE_CL_DL, "S7_M2_PZ2_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S7_M2_PZ_02", "S7_M2_PZ2_DL_00_01"); //���̻� ���� ���� ����δ�.

        PuzzleManager::createPuzzle("S7_M3_PZ_01", TYPE_ITEM_PUZZLE); //ȭ��
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 0, "src\\S7_M3_PZ_01_01.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 1, "src\\S7_M3_PZ_01_02.png");
        PuzzleManager::setPuzzleConditionItem("S7_M3_PZ_01", 0, "S7_M2_PZ_SEED");
        PuzzleManager::setPuzzleReward("S7_M3_PZ_01", 1, "S7_M2_PZ_POT");

        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_NCL_DL, "S7_M3_PZ1_DL_00_00"); //�� �� ȭ���̴�
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_CL_DL, "S7_M3_PZ1_DL_00_01"); //ȭ�п��� ������ �ɾ���.
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 1, TYPE_CL_DL, "S7_M3_PZ1_DL_00_02"); //ȭ���� �����.
        PuzzleManager::setCompletedObjectASCII("S7_M3_PZ_01", "src\\S7_M3_PZ_01_03.png");

        PuzzleManager::createPuzzle("S7_M3_PZ_02", TYPE_ITEM_PUZZLE); //�տ� ����
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
        //S1_SC2 ����1�� �� (������ ���� ��)

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