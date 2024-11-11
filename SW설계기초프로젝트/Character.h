#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "GameObject.h"

class Character : public GameObject
{
	bool isJumping; // 점프 상태 여부
	bool isDash; // 대쉬 상태 여부

	const float jumpStrength = -10.0f; // 점프 강도
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
		if (!isJumping) { // 점프 중이지 않으면 점프 시작
			setDy(jumpStrength); // 위로 이동하는 속도 설정
			isJumping = true; // 점프 상태 설정
		}
	}

	void dash() {
		if (!isDash) { // 점프 중이지 않으면 점프 시작
			setDy(jumpStrength); // 위로 이동하는 속도 설정
			dash_counter = 10;
			isDash = true; // 점프 상태 설정
		}
	}

	void dashState() {
		if (isDash) {
			setDx(getDx() > 0 ? dashStrength : (getDx() < 0 ? -dashStrength : 0));
			dash_counter--; // 대쉬 카운터 감소
			if (dash_counter <= 0) {
				isDash = 0; // 대쉬 상태 해제
			}
		}
	}


	void land() {
		isJumping = false; // 점프 상태 종료
		//dy = 0; // Y축 속도 초기화
	}

};

#endif