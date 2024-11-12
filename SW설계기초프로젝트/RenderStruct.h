#ifndef _RENDERSTRUCT_H
#define _RENDERSTRUCT_H

#include "ScreenInfo.h"

typedef struct RenderArray {
	int width;
	int height;
	char** ASCIIArtArr; //�ƽ�Ű��Ʈ�� �����ϴ� �迭
	int** drawornotArr; //ȭ��� �׸��� �׸��� ���� �����ϴ� �迭 (�׷����ϴ� ���� 1, �� �׷��� �Ǵ� ���� 0)
} RenderArray;

typedef struct ScreenArray {
	int init_x;
	int init_y; 
	int width;
	int height;
	int** MapInfo;
}ScreenArray;

enum MapInfo
{
	MAP_WALL = 1,
	MAP_FLOOR,
	MAP_BACKGROUND,
	MAP_EXIT,
	MAP_DOOR_01,
	MAP_DOOR_02,
	MAP_START,
}; 

enum JumpMapInfo
{
	JUMP_TRAP,
	JUMP_DOUBLEJUMP,
};

enum PuzzleMapInfo
{
	PUZZLE_OBJ_01 = 101,
	PUZZLE_OBJ_02,
	PUZZLE_OBJ_03,
	PUZZLE_OBJ_04,
	PUZZLE_OBJ_05,
};

enum MapType {
	TYPE_JUMP,
	TYPE_PUZZLE,
};

enum GameObjectType {
	TYPE_CHARACTER,
	TYPE_DIALOG,
};

enum PuzzleType {
	TYPE_READ_PUZZLE,
	TYPE_ITEM_PUZZLE,
	TYPE_NUMBER_PUZZLE,
};

enum ActionType {
	ACTION_JUMP,
	ACTION_DASH,
};


const int DIALOG_X = cmdWidth / 2;
const int DIALOG_Y = cmdHeight;

#endif