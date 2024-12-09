#ifndef _RENDERSTRUCT_H
#define _RENDERSTRUCT_H

#include "ScreenInfo.h"

typedef struct RenderArray {
	int width;
	int height;
	char** ASCIIArtArr; //아스키아트를 저장하는 배열
	int** drawornotArr; //화면상에 그림을 그릴지 말지 결정하는 배열 (그려야하는 곳은 1, 안 그려도 되는 곳은 0)
} RenderArray;

typedef struct ScreenArray {
	int init_x;
	int init_y; 
	int width;
	int height;
	int** MapInfo;
	int** ObjectInfo;
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
	MAP_FIRST_OBJECT,
}; 

enum JumpMapInfo
{
	JUMP_TRAP = 200,
	JUMP_DOUBLEJUMP,
	JUMP_WALL
};

enum PuzzleMapInfo
{
	PUZZLE_OBJ_01 = 101,
	PUZZLE_OBJ_02,
	PUZZLE_OBJ_03,
	PUZZLE_OBJ_04,
	PUZZLE_OBJ_05,
	PUZZLE_OBJ_06,
	PUZZLE_OBJ_07,
	PUZZLE_OBJ_08,
	PUZZLE_OBJ_09,
	PUZZLE_OBJ_10,
};

enum MapType {
	TYPE_JUMP,
	TYPE_PUZZLE,
};

enum GameObjectType {
	TYPE_CHARACTER,
	TYPE_DIALOG,
	TYPE_SCREEN,
	TYPE_DETAIL,
};

enum PuzzleType {
	TYPE_READ_PUZZLE,
	TYPE_ITEM_PUZZLE,
	TYPE_NUMBER_PUZZLE,
};

enum ActionType {
	ACTION_MOVE_X,
	ACTION_MOVE_Y,
	ACTION_JUMP,
	ACTION_DASH,
	ACTION_CLIMB,
};

enum PuzzleSceneType {
	TYPE_NCL_DL,
	TYPE_CL_DL
};

const int DIALOG_X = cmdWidth / 2;
const int DIALOG_Y = cmdHeight;

#endif