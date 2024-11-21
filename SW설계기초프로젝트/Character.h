#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "GameObject.h"
#include "AnimationManager.h"
#include "ItemManager.h"

class Character : public GameObject
{
	unordered_map<string, Item*> Inventory;

	bool isJumping; // ���� ���� ����
	bool isDash; // �뽬 ���� ����

	float jumpStrength = -12.0f; // ���� ����
	float dashStrength = 11.0f;

	int dash_counter;

	AnimationManager* animationManager;

public:
	Character(string _id) : GameObject(_id) {
		dash_counter = 0;
		isJumping = false; isDash = false;
		animationManager = new AnimationManager();
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
			if (!Inventory[name]->getUseCount()) { //�������� �� ������� ���
				Inventory.erase(name);
			}
		}
	}

	bool getisItem(string name) { //�������� �ִ���
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
		else if(_dx > 0)
			setAnimationStatus("RIGHT");
		else
			setAnimationStatus("IDLE");

		GameObject::setDx(_dx);

	}

	void jump() {
		if (!isJumping) { // ���� ������ ������ ���� ����
			setDy(jumpStrength); // ���� �̵��ϴ� �ӵ� ����
			isJumping = true; // ���� ���� ����
		}
	}

	void dash() {
		if (!isDash) { // ���� ������ ������ ���� ����
			if(getDx() != 0)
				setDy(jumpStrength / 2); // ���� �̵��ϴ� �ӵ� ����
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