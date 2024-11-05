#ifndef _RENDERSTRUCT_H
#define _RENDERSTRUCT_H

typedef struct RenderArray {
	int width;
	int height;

	char** ASCIIArtArr; //�ƽ�Ű��Ʈ�� �����ϴ� �迭
	int** drawornotArr; //ȭ��� �׸��� �׸��� ���� �����ϴ� �迭 (�׷����ϴ� ���� 1, �� �׷��� �Ǵ� ���� 0)
} RenderArray;

typedef struct ScreenArray { //���� ȭ�� ������ �����ϴ� ����ü
	//ĳ���� ���� ��ġ (���� ��� -1)
	int init_x;
	int init_y; 

	int width;
	int height;
	int** MapInfo; //�� ������ �����ϴ� ����ü 
	//-> �����: 0�� �� ����, 1�� ��, 2�� ���, 101, 102, 103, 104, 105 << ������ ��� ��
	//-> ������: 0�� �� ����, 1�� ��, 2�� ���, 3�� ������ �״� �� �� . .
	int** CharInfo; //ĳ���� ������ �����ϴ� ����ü
	//-> 1�� ���ΰ�, 2�� ������, 3�� �Ҿƹ���, 4�� ���鳲

	//�켱�� ���� ���, �� ���� � ������
}ScreenArray;

#endif