#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "GameObject.h"

class Character : public GameObject
{
	bool isJumping; // ���� ���� ����
	bool isDash; // �뽬 ���� ����

	const float jumpStrength = -10.0f; // ���� ����
	const float dashStrength = 13.0f;

	int dash_counter;

public:
	Character() {
		dash_counter = 0;
		isJumping = false; isDash = false;
		
	}

	bool getisJumping() { return isJumping; }
	bool getisDash() { return isDash; }


	void setisJumping(bool j) { isJumping = j; }

	void jump() {
		if (!isJumping) { // ���� ������ ������ ���� ����
			setDy(jumpStrength); // ���� �̵��ϴ� �ӵ� ����
			isJumping = true; // ���� ���� ����
		}
	}

	void dash() {
		if (!isDash) { // ���� ������ ������ ���� ����
			setDy(jumpStrength); // ���� �̵��ϴ� �ӵ� ����
			dash_counter = 10;
			isDash = true; // ���� ���� ����
		}
	}

	void dashState() {
		if (isDash) {
			setDx(getDx() > 0 ? dashStrength : (getDx() < 0 ? -dashStrength : 0));
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

};

#endif