#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include<vector>
#include "RenderStruct.h"
#include "ArtLoadManager.h"

class GameObject
{
private:
	RenderArray renderArray;
	int type;
	int width; 
	int height;
	float x, y;
	float dx, dy;

public:
	ArtLoadManager* artLoadManager;
	GameObject() { 
		width = 0; height = 0; x = 0; y = 0; dx = 0; dy = 0; artLoadManager = artLoadManager->GetInstance();
	}
	void initializeFromASCII(const char* filename)
	{
		if (type == TYPE_DIALOG) {
			artLoadManager->DialogRenderArrayLoad(&renderArray, filename);
			setWidth(renderArray.width);
			setHeight(renderArray.height);
			SetStartPosition(DIALOG_X, DIALOG_Y);
		}
		else {
			artLoadManager->RenderArrayLoad(&renderArray, filename);
			setWidth(renderArray.width);
			setHeight(renderArray.height);
		}
	}
	RenderArray& getRenderArray() { return renderArray; }
	int getX() { return x; };
	int getY() { return y; };
	int getDx() { return dx; };
	int getDy() { return dy; };

	int getWidth() { return width; };
	int getHeight() { return height; };

	int getType() { return type; }

	void setDx(float _dx) { dx = _dx; }
	void setDy(float _dy) { dy = _dy; }

	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }

	void setType(int _type) { type = _type; }

	void setPosition(float _x, float _y) { x = _x; y = _y; }
	void SetStartPosition(float init_x, float init_y) {
		int dw = -width / 2;
		int dh = -(height);

		x = init_x + dw;
		y = init_y + dh;

		if (x < 0) x = 0;
		if (y < 0) y = 0;
	}

	void move() {
		setPosition(getX() + dx, getY() + dy);
	}

	int getFootY() {
		return y + height; // 발바닥 위치는 현재 Y 위치 + 캐릭터 높이
	}

};

#endif

