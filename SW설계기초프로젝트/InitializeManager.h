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
        GameObjectManager::createObject("Dialog", "PZ_NCL_DL", "���� ������ �ʾ�...");

        GameObjectManager::createObject("Dialog", "S1_M1_DPZ1_DL_00_00", "������ ������ ���� å���̴�.");
        GameObjectManager::createObject("Dialog", "S1_M1_DPZ1_DL_00_01", "�� ž�� ������ û�ҿ��� ������ ����������...");
        GameObjectManager::createObject("Dialog", "S1_M1_DPZ2_DL_00_00", "�Ƹ���� ������ �����̴�.");

        GameObjectManager::createObject("Dialog", "S2_M1_DPZ1_DL_00_00", "ȸ�� �� ������ ���� �� ������?");
        GameObjectManager::createObject("Dialog", "S2_M1_DPZ1_DL_00_01", "��ư�� �������� ���ư��� �� ������...");

        GameObjectManager::createObject("Dialog", "S3_M1_DPZ1_DL_00_00", "�����̴�. �̷� ���� ���� �� �� �ֳ�..?");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ1_DL_00_01", "��ġ��� ����� �ΰ��ٿ� ǥ���� ���´�...");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ1_DL_00_02", "����: �� �� ���� ��� ���۵�...");

        GameObjectManager::createObject("Dialog", "S3_M1_DPZ2_DL_00_00", "����غ��̴� �����ð��.");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ2_DL_00_01", "�ƴ�... �ڼ��� ���� �ð谡 �ݴ�� ���ư��� �����̴�...");
        GameObjectManager::createObject("Dialog", "S3_M1_DPZ2_DL_00_02", "����: ���� �����ϴ� ����� ������ �и���.");

        //H

        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_00", "����: ���� ������ �ʾ�... ���谡 �ʿ��� �� ����.");
        GameObjectManager::createObject("Dialog", "S6_M1_PZ2_DL_00_01", "���踦 ����Ѵ�.");

        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_00", "������ �׿��ִ� å���̴�...");
        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_01", "å �� ���� ���� ���´�.");
        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_02", " * ... ���� ���� ���� �� ���� �״�� ������ �ݺ��ȴٰ� ����� ����. � ������ �� ���ΰ�? ... *");
        GameObjectManager::createObject("Dialog", "S6_M1_DPZ1_DL_00_03", "����: ... ���� �ö���.");

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

        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_00", "����غ��̴� ȸ���񸶴�.");
        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_01", "��ư�� �������� ���ư�...��...?");
        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_02", "����: �̰� ���� �ҿ��� ������?");
        GameObjectManager::createObject("Dialog", "S7_M1_DPZ1_DL_00_03", "ȸ���񸶴� �� ������...");

        GameObjectManager::createObject("Dialog", "S7_M2_DPZ1_DL_00_00", "�ٰ����� ������ ���� ���� ���̴�.");
        GameObjectManager::createObject("Dialog", "S7_M2_DPZ1_DL_00_01", "����: ... �̷� ���� �ƴҰ� ������");
        GameObjectManager::createObject("Dialog", "S7_M2_DPZ1_DL_00_02", "���� �� ������...");

        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_00", "����: �Ʊ� �� �����̳�.");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_01", "???: �� ���� ���� �;��� ���̾�! ���!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_02", "����: ����. �ʰ� ���Ѱž�?");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_03", "��ʹ� �ƴ� ��: �׷�! �ʵ� �� \"�칰 ����\"���� �ҿ��� �� ����̱���! ���!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_04", "����: �칰 ����..? �� ���� �ƴ°� �ִ°ž�?");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_05", "��ʹ� �ƴ� ��: ����� ������! ���������̴ϱ�! ���!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_06", "��ʹ� �ƴ� ��: ���� �;��� ���ε�! ���忡 ���ֵΰ� ��ġ�߾�!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_07", "����: �׷�... �� �ҿ��� �̷� ������...?");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_08", "��ʹ� �ƴ� ��: ���! �ʵ� �� ������ �ḻ�� �ް��� ���!");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ1_DL_00_09", "����: ... �� �ʿʹ� �޶�.");

        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_00", "�����ð��̴�.");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_01", "... �ð��� ���� �ʿ� ������ �����ִ�.");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_02", " \"�ð��� �帧�� Ž���� ��. ������ �ð��� ������.\"");
        GameObjectManager::createObject("Dialog", "S8_M1_DPZ2_DL_00_03", "����: ... ���� �ö󰡾߰ھ�.");

        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_00", "�Ҹ���ġ�� ���� �׸��̴�...");
        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_01", "�ݹ��̶� �����ϵ��� ����...");
        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_02", "�Ʊ�� �ٸ��� �׸��� ���� �Ϸ��δ�...");
        GameObjectManager::createObject("Dialog", "S9_M1_PZ1_DL_00_03", "����: ���� �ö󰡾߸� ��...");


        GameObjectManager::createObject("Dialog", "NUM_PZ_NCL_DL", "��й�ȣ�� Ʋ�Ƚ��ϴ�.");
        GameObjectManager::createObject("Dialog", "NUM_PZ_CL_DL", "��й�ȣ�� �¾ҽ��ϴ�.");

    };

    static void SceneInit() {
        Scene S0_SC1, S0_SC2, S1_SC1, S1_SC2, S1_SC3, S1_SC4, S2_SC1, S2_SC2, S3_SC1, S3_SC2, S3_SC3, S4_SC1, S4_SC2, S5_SC1, S5_SC2,
            S0_SC3, S1_SC5, S1_SC6, S2_SC3, S3_SC4, S4_SC3, S4_SC4, S4_SC5, S4_SC6, S5_SC3;

        //S0_SC1 ���ѷα�
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_01", "* ���â �ѱ��, ��ü�� ��ȣ�ۿ��� �����̽�Ű�� �����մϴ�. *");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_02", "���������� ���� ������ �������� ������ �ִ�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_03", "���� �� ��, �ð����� ���� ���� ����� ž.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_04", "���� ��������, ���� �������������� ���� ä ž�� �� �ڸ��� ���� ���̴�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_05", "ž�� ���� �����, �ź�ο� �칰�� �ҿ��� ����, �� � �ٶ��� �̷������.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_06", "���� �� �̽Ÿ��� ������ ���� ž�� �������� ������� ����.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_07", "�㳪 �� ������Դ� �� ������ ������ ������ ����̾�����..");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_08", "�� �Ŵ��� ���� õõ�� ������, ����� �ٲ� ������ ���۵ȴ�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_09", "����: ���� ��Ӵϸ� ���� ������ �ö� �ž�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_10", "����: ���Ⱑ ž�� �Ա��ΰ���");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_11", "???: ���!!");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_12", "����: ����!? �� �� ���⿡��");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_13", "����: ���, �̰� ���� ���̾�?! ȥ�� ������� �� �ž�?");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_14", "����: ����, �� ���� ���� �� ��. �� ž�� �ʹ� ���������� �𸥴ٰ� ���ݾ�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_15", "����: ��� ȥ�ڼ� ���� �� ����. ���̼���� �س� �� ���� �ž�.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_16", "����: ����, ���� ����.");
        GameObjectManager::createObject("Dialog", "S0_SC1_DL_17", "����: ��! ���� ����, ���!");


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



        //S0_SC2.setDetail("src\\S0_SC2_00.png"); //����� ž�� �Ա���. �̰� �׷�����

        S1_SC1.setDetail("src\\scene\\STAGE1.png");
        S1_SC1.setDelay("Hero", 3000);
        S1_SC1.setDetail("");
        S1_SC1.setDelay("Sister", 500);
        //S1_SC1 ����1�� �� (������ ������)
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_01", "����: �����Ⱑ �ɻ�ġ�� �ʳ�... �������� �� ���� ���ǵ鵵 ���� ���̾�.");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_02", "����: ���� �̰� ��! ���� �����־�!");
        GameObjectManager::createObject("Dialog", "S1_SC1_DL_03", " * ���� �ɷ��ִ� �׸��� ��ȣ�ۿ��Ϸ��� �����̽� �ٸ� ����������. * ");


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

        //S1_SC2 ����1�� �� (������ ���� �� ��)
        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "����: �ҹ��� ����ΰ���. ���� ���� ���� �ִ°� ������ ������!");

        //S1_SC3 ����1�� ��
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_01", "����: ���� ����. ��û �����غ����ݾ�.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_02", "����: ��ø�, �̰� �׳� �Ǹ����� �������ڴٰ� ? ");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_03", "����: �� �̷��� �����ϰ� �� �� �����ž�.");
        GameObjectManager::createObject("Dialog", "S1_SC3_DL_04", "* �̵��� ���� : �� �� �� �� , �뽬 : �����̽��� * ");

        GameObjectManager::createObject("Dialog", "SISTER_CARRY01", "����: ���� ���ϱ� �ʹ� �����...");
        GameObjectManager::createObject("Dialog", "SISTER_CARRY02", "����: ������? ���� ������. ���� �����ٰ�.");
        GameObjectManager::createObject("Dialog", "SISTER_CARRY03", "����: ���� ���.");

        S1_SC3.setScreen("src\\scene\\S1_SC3\\S1_SC3_01.png");

        S1_SC3.setDelay("Sister", 700);
        S1_SC3.setDialog("S1_SC3_DL_01");
        S1_SC3.setDialog("S1_SC3_DL_02");
        S1_SC3.setAction("Sister", ACTION_MOVE_X, 3, 6);
        //S1_SC3 ���� �۷�
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


        //S1_SC4 ����� ��
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_01", "����: �� �� �ȿ� ���� ���� ������? ��·�� ���� ������ ����������.");
        GameObjectManager::createObject("Dialog", "S1_SC4_DL_02", "����: �츮 ���� ���ȿ� ������ ��������? ���� ������ ���ư��� �ʹ١�");
        S1_SC4.setDelay("Sister", 700);
        S1_SC4.setDialog("S1_SC4_DL_01");
        S1_SC4.setDialog("S1_SC4_DL_02");

        //S2_SC1 ����2�� ��
        S2_SC1.setDetail("src\\scene\\STAGE2.png");
        S2_SC1.setDelay("Hero", 3000);
        S2_SC1.setDetail("");
        S2_SC1.setDelay("Sister", 500);

        GameObjectManager::createObject("Dialog", "S2_SC1_DL_01", "����: �� �ν����⡦? �������� �� �μ��� �ֳ� ? ");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_02", "����: ���̶�� �ϱ⿣ ������ ����� �� �� �� ����.");
        GameObjectManager::createObject("Dialog", "S2_SC1_DL_03", "����: ��, � ������!");

        S2_SC1.setDelay("Sister", 700);
        S2_SC1.setAction("Sister", ACTION_MOVE_X, 6, 15); //���� �տ� �������� ���Բ� ����
        S2_SC1.setDialog("S2_SC1_DL_01");
        S2_SC1.setDialog("S2_SC1_DL_02");
        S2_SC1.setDialog("S2_SC1_DL_03");


        //S2_SC2 ����2�� ��
        S2_SC2.setScreen("src\\scene\\S2_SC2\\S2_SC2_01.png");
        S2_SC2.setDelay("Sister", 700);
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_01", "����: ���⵵ ����� �����ϳ�.");
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

        GameObjectManager::createObject("Dialog", "S2_SC2_DL_02", "����: ��, �̷��� ���� ����ž�.");
        GameObjectManager::createObject("Dialog", "S2_SC2_DL_03", " * Ư�� ���� \"FŰ\"�� ��Ÿ�⸦ �� �� �ֽ��ϴ�. * ");



        S2_SC2.setDialog("S2_SC2_DL_02");
        S2_SC2.setDialog("S2_SC2_DL_03");

        //����ٴ� ���� �Բ� ������ ������
        S2_SC2.setDeath("Sister", true);
        S2_SC2.setDialog("SISTER_CARRY01");
        S2_SC2.setDialog("SISTER_CARRY02");
        //���� �����ٰ� ���
        S2_SC2.removeRenderCharacter("Sister");
        S2_SC2.setCarry("Hero", true); //�����ֱ�
        S2_SC2.setDialog("SISTER_CARRY03");


        //S3_SC1
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_01", "����: ��� �ö���鼭 ���� �ǵ���");
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_02", "����: �� ž�� �̻��� ��ġ���� ���� �� �۵����� �ʴ� �� ����.");
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_03", "����: �� ���� ���������� ���� �־�� �� �ڸ��� �� ��� �ִ� �����̾�.");
        GameObjectManager::createObject("Dialog", "S3_SC1_DL_04", "����: Ȥ�� � ������ �־������� �𸣴µ�! �׷��� �츮���� ����� �Ű���? �������� �칰�� ����!");

        S3_SC1.setCarry("Hero", false); //������
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
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_01", "����: ��͡� ���� ���� ������ ���̳�.");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_02", "����: ���ݱ��� �ô� ������� ������ �ٸ��ݾ�. �Ѿ �� ������?");
        GameObjectManager::createObject("Dialog", "S3_SC2_DL_03", " * ���ݱ��� ��� ���� Ȱ���Ͽ� ���� Ŭ�����غ�����. * ");

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
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_01", "����: �� ���� ������ �� �̻��ϰ�, �� ���� ���� ���� ���� ���ǵ�� �����ϳ�.");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_02", "����: ����ü ����, �� �̷� ���� ���� �ɱ�?");
        GameObjectManager::createObject("Dialog", "S3_SC3_DL_03", "����: �칰�� ���� �ҹ��� �� ������ ���� ����� �� ����! ���� ������!");

        S3_SC3.setDelay("Sister", 700);
        S3_SC3.setDialog("S3_SC3_DL_01");
        S3_SC3.setDialog("S3_SC3_DL_02");
        S3_SC3.setDialog("S3_SC3_DL_03");

        //S4_SC1
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_01", "����: ���⵵ ���� �̻��� �������� �־ �׸��� �� �̹� ���� �����־�.");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_02", "����: �졦 ���� ������ �ء�");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_03", "����: ���� �ҿ��� ���� ������!");
        GameObjectManager::createObject("Dialog", "S4_SC1_DL_04", "�׷�. �ϴ� �������߰ڴ�.");


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
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_01", "����: ���� �칰�� ���δ�!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_02", "����: ���� �ź�Ӵ١� �̷��� ������ ���ٴ� �ϱ��� �ʾ�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_03", "�칰�� �� ��ü�ε� �ź�ο����̰�, ���� ������ ���� ���� �����غ��δ�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_04", "����: ���� �ҿ��� ����! ������ ��ġ�°ž�!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_05", "�ΰǳ�: ����");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_06", "�ΰ��� �� ���ڰ� ���� �߾�Ÿ��� �� �ϴ�.");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_07", "����: ����!! �� ��!!");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_08", "�ڴʰ� ���� ������� Į�� �̹� ��� ������ ������ ���̴�.");
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


        //�߰��ϱ� �ָ��ؼ� 40 41 42
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_40", "����: ...���...?");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_41", "�ΰǳ�: ...��... ��....");
        GameObjectManager::createObject("Dialog", "S5_SC1_DL_42", "����: ����!!");



        S5_SC1.setCarry("Hero", false); //������
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
        S5_SC1.setDetail("src\\scene\\S5_SC1\\S5_SC1.png"); // ����� ����
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
        S5_SC1.removeRenderCharacter("Hood"); //������� �ĵ� Į��
        // ���⿡ ������ ���� ��� �ֱ� *�����ϴ��� ����� ����;;;;;;;

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



        //�̰� ������ ���� �칰�� ����.
        //���ο� ���� �׷��� �ؿ� ���� �ְ� �ű⿡ ��ȣ�ۿ��ϸ� ������.


        //S0_SC3
         //S5_SC1 ���� �칰�ȿ�
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_01", "���� �칰 ������ ����ɰ� �ִ�.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_02", "���� �� ����.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_03", "���� �������� �Ӹ� ���� ������ �����̴�.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_04", "�� �������� ���ؾ߸� �ء� �ݵ�á� ���ȡ�");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_05", "���� ��� �ӿ��� ���ΰ��� ������ �Ҵ´�.");

        GameObjectManager::createObject("Dialog", "S0_SC3_DL_06", "����: �����䡦?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_07", "�ͼ��� ž�� �Ա��� ���տ� ���´�.");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_08", "����: ������ �ƹ��� ���� ���� �� ����. �ð��� �������� �ǰ���?");
        GameObjectManager::createObject("Dialog", "S0_SC3_DL_09", "����: ������ ���Ϸ��� ���ѷ��� ��. ���� ���� ž���� ���� ��.");



        S0_SC3.setDetail("src\\scene\\S0_SC3\\S0_blank.png");
        S0_SC3.removeRenderCharacter("Sister");
        S0_SC3.setDelay("Hero", 1500);


        S0_SC3.setCarry("Hero", false); //������
        S0_SC3.setDeath("Sister", true);
        S0_SC3.setAction("Hero", ACTION_MOVE_X, 1);

        // �칰 �ȿ��� ����޴� ���ΰ��� �������� ���ھ��.
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
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_01", "����¡�");
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_02", "ž�� 1��... �ϴ� �� ��������.");
        GameObjectManager::createObject("Dialog", "S1_SC5_DL_03", "������ ���� �ѽö� ���� ã�Ƽ� �칰�� ������.");

        S1_SC5.setDetail("src\\scene\\STAGE5.png");
        S1_SC5.setDelay("Hero", 3000);
        S1_SC5.setDetail("");
        S1_SC5.setDelay("Hero", 500);

        S1_SC5.setDialog("S1_SC5_DL_01");
        S1_SC5.setDialog("S1_SC5_DL_02");
        S1_SC5.setDialog("S1_SC5_DL_03");

        //S1_SC6
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_01", "����: ������ ������ ������ ���ڳ�.");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_02", "����: �� ž�� ���������� ���ؼ��¡�");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_03", "����: ������ ���� ã�ƾ߰ھ�.");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_04", "����: �׸��� �װ��� �칰�� �������߰���.");
        GameObjectManager::createObject("Dialog", "S1_SC6_DL_05", "����: ���� �� ���Ϸ�����.");

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
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_01", "����: �Ʊ��� ���ν����Ⱑ...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_02", " * ���󿡰� �̼��� �������� ���δ�. *");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_03", "����: ���� �̻��ѵ���");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_04", "����: �� ���� �ڿ� ���� �ִµ�....");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_05", "???: �ݰ���... �ҳ࿩...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_06", "����: ������!");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_07", "���: ���� �ð��� ���� ��...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_08", "���: �㳪 �� �� �ӿ����� ���� �޲۴�.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_09", "���: �������� �� ������ ���� �� ����...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_10", "����: ��� �ϸ� �����ٰ���? ���� ������ ����� ���Ѿ���.");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_11", "���: ����� ������ ���� �ڷα�...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_12", "���: ... �ٱ� ������ ���������ϱ�...");
        GameObjectManager::createObject("Dialog", "S2_SC3_DL_13", "���: ... ���� �ٱ� ������ ������ٿ�.");

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
        GameObjectManager::createObject("Dialog", "S3_SC4_DL_01", "����: �Ʊ� �� ������ ������..?");
        GameObjectManager::createObject("Dialog", "S3_SC4_DL_02", "����: �� ž���� ���� �̻��� �͵��� ����.");
        GameObjectManager::createObject("Dialog", "S3_SC4_DL_03", "����: ��ġ ���𰡸� ���ϰ��� �ϴ� ���� ����...");

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
        GameObjectManager::createObject("Dialog", "S4_SC3_DL_01", "����� ���ƺ��̴� �ϱ����̴�.");
        GameObjectManager::createObject("Dialog", "S4_SC3_DL_02", "ǥ���� ��ġ�� �����ִ� ������ ������ ��������.");
        GameObjectManager::createObject("Dialog", "S4_SC3_DL_03", "... �� ���θ���.");
        //������ ó��

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
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_01", "����: �� �����顦 �ϱ��塦 �׸��� �� ž.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_02", "???: ���� �̵��� �̰��� ���� �鿴��. ������ �ڽ��� �ٶ��� �̷�� ����.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_03", "����: �� �װ� ��� ���Ѻ��� �־�����.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_04", "???: ������ ������ ������ ��̷���. ����� ������ �����ϴ� ������ ���� �͸�ŭ ��̷ο� ���� �����ϱ�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_05", "����: ��硦 ���� ����� �о���. �״� �ᱹ �� ž�� ������ ������.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_06", "???: �״� ���� �� ������ �� �ƴ϶�, ������ �ʱ⸦ �������� ���̴�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_07", "����: ���� ���á� �� �� ������ ��Ʋ�� �ʾҴٰ� ���� �� �־�?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_08", "???: ������ ������� �ʴ´�. ���� ���� ���� ���� ���̴�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_09", "����: �� ���� ������� �̾����ٸ�? �װ� �� å�� �ƴϾ�?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_10", "???: ����̶� �װ��� �װ� ���� �̸��� ��. ������ ����� ������ �޾Ƶ��� �ڿ��� �޷� �ִ�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_11", "����: �޾Ƶ��δ١� ������ �����?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_12", "???: �׷���. ��� ������ �밡�� �䱸�Ѵ�. ������ ���� ��Ű���� �� ������ ���� �����ƾ� �� ���� ����.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_13", "����: �밡���. ������ ���� ���� �ʰ�� ������ ���� �� ���ٴ� �ž�?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_14", "???: �װ��� �����ϴ� ���� �ʴ�. ���� ������ �巯�� ��, ���� �������� �ʴ´�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_15", "����: �׷� �ΰ��� �� ���ڴ¡� �׳�� ��ü ������?");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_16", "???: �װ� ���� �� �����̾߸��� ������ ���� ù�����̴�. ž�� ���� ��¥ ����� ���ߴ� �ſ��̴�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_17", "����: ��¥ ����̶�ϡ� �װ� ���� �ǹ̾�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_18", "???: ������ �װ� �װ��� ������ �غ� �Ǿ��� �� �巯����.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_19", "����: ������ ���ϱ� ���ؼ���� � �밡�� ġ�� �ž�. ���� ���� ������ ���߰� �ֵ�.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_20", "???: �׷��ٸ� ����. ž���� [���� ������ ��]�� ã�ƶ�. �װ��� ���� �ҿ��� �̷�� �����.");
        GameObjectManager::createObject("Dialog", "S4_SC4_DL_21", "???�� �� �տ��� ������١�");

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

        //����ٴ� ���� �Բ� ������ ������
        S4_SC5.setDeath("Sister", true);
        S4_SC5.setDialog("SISTER_CARRY01");
        S4_SC5.setDialog("SISTER_CARRY02");
        //���� �����ٰ� ���
        S4_SC5.removeRenderCharacter("Sister");
        S4_SC5.setCarry("Hero", true); //�����ֱ�
        S4_SC5.setDialog("SISTER_CARRY03");

        //S4_SC6 ���� �ִϸ��̼� �߰��ϸ�
        GameObjectManager::createObject("Dialog", "S4_SC6_DL_01", "�׸���... ����... �̻��ϴ�..?");
        GameObjectManager::createObject("Dialog", "S4_SC6_DL_02", "...����...");
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
        // S5_SC3: ������ �ð����� ���ƿ� ����, ������ �칰����
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_01", "����: �칰�� ���ϴ� �� ��ü ���");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_02", "����: �� ž�� ��� �� ������. ������ �ƹ��͵� ã�� ���߾�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_03", "???: �׷��� ���� ȭ�� �� ���ΰ�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_04", "����: �װ� ���� �ӿ��ݾ�. ���ʺ��� �ƹ��͵� ������ �� �ƴϾ�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_05", "???: ���̴ٴ�, ���� �Ҹ���. ���� �ҿ��� �̷�� �칰�̴�. �̷� ����� �װ� �޷� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_06", "����: �װ� [���� ������ ��]�� ��������� ���ݾ�! �װ� ���ϴ� �� ������ �𸣰� ��̴ٰ�!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_07", "???: �ʴ� �̹� �˰� �������� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_08", "��� �ʿ��� �߼Ҹ��� �鸰��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_09", "???: �̷�. �մ��� �� ����̱�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_10", "����: ���� �칰�� ���δ�!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_11", "����: ���� �ź�Ӵ١� �̷��� ������ ���ٴ� �ϱ��� �ʾ�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_12", "����: \'���� �ö�Դٴ�... ���� ã���� ���ߴµ�...\'");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_13", "����: ���, ���⿡ �̻��� ����� ������. ���� �ֳ� ��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_14", "������ ����: ������, ����. ���� �ǵ帮�� ��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_15", "������ ���� �αٿ��� �����ϰ� �Ƹ��ٿ� ���� ����´�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_16", "����: ���ǡ�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_17", "����: ���, ���� ������ �ִ� �� ����!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_18", "������ ����: ����, �ڷ� ������.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_19", "����: ...");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_20", "����: ...���...?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_21", "����: �̾ȡ� ����.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_22", "����: ... �� ſ���� ����. �� ���ľ߸� ��.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_23", "����: ���, �� �ϴ¡�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_24", "����: ����!!!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_25", "ž���� [���� ������ ��]�� ȹ���ߴ�.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_26", "������ ����: ����!! �� ��!!");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_27", "???: �� ������ ������.��Ӵ�� ���� �ҿ��� �̷������.");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_28", "����: ���ȡ� ���� ���ԡ�");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_29", "����: �밡�� ž���� ���� ������ �͡�?");
        GameObjectManager::createObject("Dialog", "S5_SC3_DL_30", "����: �װ� ���� ������ �ǹ̰� ����. � �밡�� ġ���ھ�.");


        //���ΰ� ���̼� ���簡 �����ؿ�?!?!??!?!?
        S5_SC3.removeRenderCharacter("Hero");
        //S5_SC3.removeRenderCharacter("Sister");

        S5_SC3.setRenderHood("Hood", false);
        //S5_SC3.setCharacterPositionX("Hood", 50);
        //S5_SC3.setCharacterPosition("Hood", 50, -1); //ó������ ���η� �׷�������
        S5_SC3.setCharacterStartPosition("Hood", "S10_P_MAP_01", 50); //ó������ ���η� �׷�������

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

        //���⼭ ���ΰ� �θ����� ���;���

        S5_SC3.setDialog("S5_SC3_DL_10");
        S5_SC3.setDetail("src\\scene\\S5_SC3\\S5_SC3_01.png");
        S5_SC3.setRenderCharacter("Hero");
        S5_SC3.setRenderCharacter("Sister");

        S5_SC3.setCharacterStartPosition("Hero", "S10_P_MAP_01", 24); //ó������ ���η� �׷�������
        S5_SC3.setCharacterStartPosition("Sister", "S10_P_MAP_01", 26); //ó������ ���η� �׷�������

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

        GameObjectManager::createObject("Dialog", "S1_SC2_DL_01", "����: �ҹ��� ����ΰ���. ���� ���� ���� �ִ°� ������ ������!");

        //E_S1_P
        PuzzleManager::createPuzzle("S1_M1_PZ_01", TYPE_READ_PUZZLE); //����
        PuzzleManager::createPuzzle("S1_M1_DPZ_01", TYPE_READ_PUZZLE);//����1
        PuzzleManager::createPuzzle("S1_M1_DPZ_02", TYPE_READ_PUZZLE);//����2
        PuzzleManager::setCompletedObjectASCII("S1_M1_DPZ_01", "src\\maps\\S1\\dummy_S1_01.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_DPZ_01", "S1_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S1_M1_DPZ_01", "S1_M1_DPZ1_DL_00_01");
        //PuzzleManager::setCompletedObjectASCII("S1_M1_DPZ_02", "src\\maps\\S1\\dummy_S1_02.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_DPZ_02", "S1_M1_DPZ2_DL_00_00");
        PuzzleManager::setCompletedDetailASCII("S1_M1_PZ_01", "src\\maps\\S1\\S1_M1_PZ_DT_01.png");
        PuzzleManager::setCompletedSceneDialog("S1_M1_PZ_01", "S1_SC2_DL_01");

        //E_S2_P

        PuzzleManager::createPuzzle("S2_M1_PZ_01", TYPE_READ_PUZZLE); //���� ���θ��� ��
        PuzzleManager::setCompletedObjectASCII("S2_M1_PZ_01", "src\\maps\\S2\\S2_M1_PZ_01_02.png"); //���� ���θ��� ��
        PuzzleManager::setCompletedSceneDialog("S2_M1_PZ_01", "S7_M1_PZ1_DL_00_02");

        PuzzleManager::createPuzzle("S2_M1_DPZ_01", TYPE_READ_PUZZLE);//���� ȸ����
        PuzzleManager::setCompletedObjectASCII("S2_M1_DPZ_01", "src\\maps\\S2\\dummy_S2_01.png");
        PuzzleManager::setCompletedSceneDialog("S2_M1_DPZ_01", "S2_M1_DPZ1_DL_00_00");
        PuzzleManager::setCompletedSceneDialog("S2_M1_DPZ_01", "S2_M1_DPZ1_DL_00_01");

        //E_S3_P
        PuzzleManager::createPuzzle("S3_M1_PZ_01", TYPE_READ_PUZZLE); //�ǾƳ� �����ֱ�
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
        PuzzleManager::createPuzzle("S6_M1_PZ_01", TYPE_NUMBER_PUZZLE); //������ ���� ��й�ȣ �Է� �κ�

        PuzzleManager::setPuzzleDetailASCII("S6_M1_PZ_01", 0, "src\\maps\\S1\\S1_M1_PZ_DT_02.png");

        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 4);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 0);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 1);
        PuzzleManager::setCorrectAnswer("S6_M1_PZ_01", 3);

        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_NCL_DL, "NUM_PZ_NCL_DL");
        PuzzleManager::setPuzzleSceneDialog("S6_M1_PZ_01", 0, TYPE_CL_DL, "NUM_PZ_CL_DL");

        PuzzleManager::createPuzzle("S6_M1_PZ_02", TYPE_READ_PUZZLE); //����
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
        PuzzleManager::createPuzzle("S7_M1_PZ_01", TYPE_ITEM_PUZZLE); //����
        PuzzleManager::setPuzzleObjectASCII("S7_M1_PZ_01", 0, "src\\maps\\S7\\S7_M1_PZ_01_01.png");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_NCL_DL, "S7_M1_PZ1_DL_00_00");
        PuzzleManager::setPuzzleSceneDialog("S7_M1_PZ_01", 0, TYPE_CL_DL, "S7_M1_PZ1_DL_00_01");
        PuzzleManager::setPuzzleConditionItem("S7_M1_PZ_01", 0, "S7_M2_PZ_FLOWER");
        PuzzleManager::setCompletedObjectASCII("S7_M1_PZ_01", "src\\maps\\S7\\S7_M1_PZ_01_02.png");
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
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 0, "src\\maps\\S7\\S7_M3_PZ_01_01.png");
        PuzzleManager::setPuzzleObjectASCII("S7_M3_PZ_01", 1, "src\\maps\\S7\\S7_M3_PZ_01_02.png");
        PuzzleManager::setPuzzleConditionItem("S7_M3_PZ_01", 0, "S7_M2_PZ_SEED");
        PuzzleManager::setPuzzleReward("S7_M3_PZ_01", 1, "S7_M2_PZ_POT");

        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_NCL_DL, "S7_M3_PZ1_DL_00_00"); //�� �� ȭ���̴�
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 0, TYPE_CL_DL, "S7_M3_PZ1_DL_00_01"); //ȭ�п��� ������ �ɾ���.
        PuzzleManager::setPuzzleSceneDialog("S7_M3_PZ_01", 1, TYPE_CL_DL, "S7_M3_PZ1_DL_00_02"); //ȭ���� �����.
        PuzzleManager::setCompletedObjectASCII("S7_M3_PZ_01", "src\\maps\\S7\\S7_M3_PZ_01_03.png");

        PuzzleManager::createPuzzle("S7_M3_PZ_02", TYPE_ITEM_PUZZLE); //�տ� ����
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

        PuzzleManager::createPuzzle("S9_M1_PZ_04", TYPE_READ_PUZZLE); //�ϱ���
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
        //S1_SC2 ����1�� �� (������ ���� ��)

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