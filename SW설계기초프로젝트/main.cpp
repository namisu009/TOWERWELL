#include "RenderManager.h"
#include "ArtLoadManager.h"
#include "MapManager.h"
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include "Character.h"
#include "Scene.h"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>
#include <functional>

std::atomic<bool> isRunning(true); // 프로그램 실행 상태 관리

// 물리 연산 함수 (별도 스레드에서 실행)
void physicsLoop(Character* object, Map* map) {
	while (isRunning) {
		object->setDx(0);

		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			object->setDx(4); // 오른쪽 이동
		}

		if (GetAsyncKeyState(VK_LEFT) != 0) {
			object->setDx(-4); // 왼쪽 이동
		}

		if (GetAsyncKeyState(VK_UP) != 0) {
			object->jump();
		}

		if (GetAsyncKeyState(VK_SPACE) != 0) {
			object->dash();
		}

		object->dashState();

		/* 여기서 지연 발생하는 것으로 확인 */
		// X축 충돌 체크
		while (CollisionManager::checkWallCollision(*object, *map)) {
			if (object->getDx() < 0)
				object->setDx(object->getDx() + 1);
			else if (object->getDx() > 0)
				object->setDx(object->getDx() - 1);

			if (object->getDy() < 0)
				object->setDy(object->getDy() + 1);
			else if (object->getDy() > 0)
				object->setDy(object->getDy() - 1);
		}

		PhysicsManager::applyGravity(object, map); // 중력 처리

		while (CollisionManager::checkFloorCollision(*object, *map)) {
			if (object->getDx() < 0)
				object->setDx(object->getDx() + 1);
			else if (object->getDx() > 0)
				object->setDx(object->getDx() - 1);

			if (object->getDy() < 0)
				object->setDy(object->getDy() + 1);
			else if (object->getDy() > 0)
				object->setDy(object->getDy() - 1);
		}

		object->move();

		// 간단한 대기 (과도한 CPU 점유 방지)
		std::this_thread::sleep_for(std::chrono::milliseconds(24));
	}
}


// 렌더링 함수 (별도 스레드에서 실행)
void renderLoop() {
	while (isRunning) {
		RenderManager::render();
		// 간단한 대기 (렌더링 속도 제한)
		std::this_thread::sleep_for(std::chrono::milliseconds(24)); // 약 60 FPS
	}
}


int main() {
	MapManager::createMap(0, "c:\\ImageTemp\\map01.png");
	Map* map = MapManager::getMap(0);
	map->initializeFromScreen("c:\\ImageTemp\\mapInfo01.png");

	RenderManager::ScreenInit();
	RenderManager::setRenderMap(map);
	RenderManager::renderMap();
	DoubleBufferManager::ScreenFlipping();
	RenderManager::renderMap();

	GameObjectManager::createObejct("Character", "Hero", "c:\\ImageTemp\\ch01.png");
	GameObjectManager::createObejct("Dialog", "SC1_DL_01", "c:\\ImageTemp\\dialog.png");
	GameObjectManager::createObejct("Dialog", "SC1_DL_02", "c:\\ImageTemp\\dialog2.png");
	GameObjectManager::createObejct("Dialog", "SC1_DL_03", "c:\\ImageTemp\\dialog3.png");
	Character* object = GameObjectManager::getCharacter("Hero");
	object->SetStartPosition(map->getInitX(), map->getInitY());

	RenderManager::addObject(object);
	RenderManager::renderObject();

	Scene scene01;

	vector <Command> cmds;
	Command cmd;

	cmd.addObject(object);
	for (int i = 0; i < 10; i++)
	{
		cmd.setAction((function<void()>)  [object]() { object->setDx(4); });
		cmds.push_back(cmd);
		cmd.setAction((function<void()>)  [object]() { object->move(); });
		cmds.push_back(cmd);
	}

	for (int i = 0; i < 10; i++)
	{
		cmd.setAction((function<void()>)  [object]() { object->setDx(0); });
		cmds.push_back(cmd);
		cmd.setAction((function<void()>)  [object]() { object->move(); });
		cmds.push_back(cmd);
	}

	for (int i = 0; i < 10; i++)
	{
		cmd.setAction((function<void()>)  [object]() { object->setDx(-4); });
		cmds.push_back(cmd);
		cmd.setAction((function<void()>)  [object]() { object->move(); });
		cmds.push_back(cmd);
	}

	cmd.addObject(GameObjectManager::getObejct("SC1_DL_01"));
	cmds.push_back(cmd);
	cmd.addObject(GameObjectManager::getObejct("SC1_DL_02"));
	cmds.push_back(cmd);
	cmd.addObject(GameObjectManager::getObejct("SC1_DL_03"));
	cmds.push_back(cmd);


	for (Command c : cmds) {
		scene01.addCommand(c);
	}

	scene01.display();

	// 물리 연산 및 렌더링을 별도 스레드에서 시작
	//std::thread physicsThread(physicsLoop, object, map);
	std::thread renderThread(renderLoop);

	// 종료 조건 처리
	//std::cin.get(); // 엔터 입력 시 종료
	//isRunning = false;

	// 스레드 종료 대기
	//physicsThread.join();
	renderThread.join();
}
