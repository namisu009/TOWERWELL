#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include<vector>
#include "RenderStruct.h"
#include "ArtLoadManager.h"

class GameObject
{
private:
	RenderArray renderArray;
	int width; 
	int height;
	float x, y;
	float dx, dy;

	bool isJumping; // ���� ���� ����
	bool isDash; // �뽬 ���� ����

	const float jumpStrength = -10.0f; // ���� ����
	const float dashStrength = 13.0f;

	int dash_counter;

	ArtLoadManager* artLoadManager;

public:
	GameObject() { 
		x = 0; y = 0; dx = 0; dy = 0; artLoadManager = artLoadManager->GetInstance(); isJumping = false; isDash = false;
	}
	void initializeFromASCII(const char* filename)
	{
		artLoadManager->RenderArrayLoad(&renderArray, filename);
		width = renderArray.width;
		height = renderArray.height;
	}
	RenderArray& getRenderArray() { return renderArray; }
	int getX() { return x; };
	int getY() { return y; };
	int getDx() { return dx; };
	int getDy() { return dy; };
	int getWidth() { return width; };
	int getHeight() { return height; };
	bool getisJumping() { return isJumping; }
	bool getisDash() { return isDash; }
	
	void setDx(float _dx) { dx = _dx; }
	void setDy(float _dy) { dy = _dy; }
	void setisJumping(bool j) { isJumping = j; }
	void setPosition(float _x, float _y) { x = _x; y = _y; }
	void SetStartPosition(float init_x, float init_y) {
		int dw = -width / 2;
		int dh = -(height);

		x = init_x + dw;
		y = init_y + dh;

		if (x < 0) x = 0;
		if (y < 0) y = 0;

		dx = 0;
		dy = 0; 
	}

	void move() {
		x += dx;
		y += dy;
	}

	void jump() {
		if (!isJumping) { // ���� ������ ������ ���� ����
			dy = jumpStrength; // ���� �̵��ϴ� �ӵ� ����
			isJumping = true; // ���� ���� ����
		}
	}

	void dash() {
		if (!isDash) { // ���� ������ ������ ���� ����
			dy = jumpStrength; // ���� �̵��ϴ� �ӵ� ����
			dash_counter = 10;
			isDash = true; // ���� ���� ����
		}
	}

	void dashState() {
		if (isDash) {
			dx = (dx > 0 ? dashStrength : (dx < 0 ? -dashStrength : 0));
			dash_counter--; // �뽬 ī���� ����
			if (dash_counter <= 0) {
				isDash = 0; // �뽬 ���� ����
			}
		}
	}
	

	void land() {
		isJumping = false; // ���� ���� ����
		//dy = 0; // Y�� �ӵ� �ʱ�ȭ
	}

	int getFootY() {
		return y + height; // �߹ٴ� ��ġ�� ���� Y ��ġ + ĳ���� ����
	}

};

#endif

