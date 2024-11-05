#ifndef _RENDERSTRUCT_H
#define _RENDERSTRUCT_H

typedef struct RenderArray {
	int width;
	int height;

	char** ASCIIArtArr; //아스키아트를 저장하는 배열
	int** drawornotArr; //화면상에 그림을 그릴지 말지 결정하는 배열 (그려야하는 곳은 1, 안 그려도 되는 곳은 0)
} RenderArray;

typedef struct ScreenArray { //게입 화면 정보를 저장하는 구조체
	//캐릭터 시작 위치 (없을 경우 -1)
	int init_x;
	int init_y; 

	int width;
	int height;
	int** MapInfo; //맵 정보를 저장하는 구조체 
	//-> 퍼즐맵: 0은 빈 공간, 1은 벽, 2는 배경, 101, 102, 103, 104, 105 << 퍼즐이 담길 곳
	//-> 점프맵: 0은 빈 공간, 1은 벽, 2는 배경, 3는 닿으면 죽는 곳 등 . .
	int** CharInfo; //캐릭터 정보를 저장하는 구조체
	//-> 1은 주인공, 2는 여동생, 3은 할아버지, 4는 복면남

	//우선은 벽과 배경, 빈 공간 등만 구분함
}ScreenArray;

#endif