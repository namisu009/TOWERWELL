#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "GameObject.h"
#include "AnimationManager.h"
#include "ItemManager.h"
#include <chrono>

using namespace std;

class Character : public GameObject
{
    unordered_map<string, Item*> Inventory;

    bool isJumping; // 점프 상태 여부
    bool isDash; // 대쉬 상태 여부
    bool canDoubleJump = false;
    bool isWallClimbing = false;
    float jumpStrength = -13.0f; // 점프 강도
    float dashStrength = 12.0f;

    int dash_counter;

    AnimationManager* animationManager;
    chrono::steady_clock::time_point lastJumpTime;
    const int doubleJumpTimeWindow = 900;



public:
    Character(string _id) : GameObject(_id) {
        dash_counter = 0;
        isJumping = false; isDash = false;        
        animationManager = new AnimationManager();
        lastJumpTime = chrono::steady_clock::now();
    }

    bool getCanDoubleJump() const { return canDoubleJump; }
    bool getIsJumping() const { return isJumping; }
    void enableDoubleJump() {
        canDoubleJump = true;
    }

    void disableDoubleJump() {
        canDoubleJump = false;
    }

    void initializeFromASCII(const char* filename)
    {
        setAnimation("IDLE_RIGHT", filename, filename);
        setRenderArray(animationManager->getRenderArray("IDLE_RIGHT"));
        setWidth(getRenderArray()->width);
        setHeight(getRenderArray()->height);
    }

    void addInventory(string key) {
        if (key != "") {
            Item* item = ItemManager::getItems(key);
            if (item != nullptr && Inventory.find(item->getItemName()) == Inventory.end()) {
                Inventory[item->getItemName()] = item;
            }
        }
    }

    void uesItem(string name) {
        if (Inventory.find(name) != Inventory.end()) {
            Inventory[name]->useItem();
            if (!Inventory[name]->getUseCount()) { //아이템을 다 사용했을 경우
                Inventory.erase(name);
            }
        }
    }

    bool getisItem(string name) { //아이템이 있는지
        if (Inventory.find(name) != Inventory.end())
            return true;

        return false;
    }

    bool getisJumping() { return isJumping; }
    bool getisDash() { return isDash; }

    void setJumpStrength(float j) {
        jumpStrength = -j;
    }

    void setisJumping(bool j) { isJumping = j; }

    void setAnimationStatus(const char* id) {
        setRenderArray(animationManager->getRenderArray(id));
    }

    void setAnimationToggle(int toggle) {
        animationManager->setAnimationToggle(toggle);
    }

    void setAnimation(const char* id, int toggle, const char* filename) {
        animationManager->setAnimation(id, toggle, filename);
    }

    void setAnimation(const char* id, const char* filename1, const char* filename2) {
        animationManager->addAnimaion(id, filename1, filename2);
    }

    void setDx(float _dx) {

        if (_dx < 0)
            setAnimationStatus("LEFT");
        else if (_dx > 0)
            setAnimationStatus("RIGHT");
        else
            setAnimationStatus("IDLE");

        GameObject::setDx(_dx);

    }
	void jump() {
		if (!isJumping && !isDash) { // 점프 중이지 않으면 점프 시작
			setDy(jumpStrength); // 위로 이동하는 속도 설정
			isJumping = true; // 점프 상태 설정
		}
	}

    void jump(bool t) {
        auto now = chrono::steady_clock::now();
        int elapsed = chrono::duration_cast<chrono::milliseconds>(now - lastJumpTime).count();

        if (!isJumping && !isDash) { // 점프 중이지 않으면 점프 시작
            setDy(jumpStrength);
            isJumping = true;
            canDoubleJump = true;

        }
        else if (elapsed <= doubleJumpTimeWindow && canDoubleJump) {
            setDy(jumpStrength * 1.1f);
            canDoubleJump = false;
        }
        lastJumpTime = now;

    }


    void dash() {
        if (!isDash && isJumping) { // 점프 중이지 않으면 점프 시작
            if (getDx() != 0)
                setDy(jumpStrength / 2); // 위로 이동하는 속도 설정
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
        canDoubleJump = false;
    }
    
    void startWallClimbing() {
        setDx(0);
        setDy(0);
        isWallClimbing = true;

    }

    void stopWallClimbing() {
        isWallClimbing = false;
    }

    void climbUp() {
        setDy(-1);
    }

    void climbDown() {
        setDy(1);
    }

    bool getIsWallClimbing() const {
        return isWallClimbing;
    }


};

#endif