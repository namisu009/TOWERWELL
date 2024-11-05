#include "RenderManager.h"
#include "ArtLoadManager.h"
#include "MapManager.h"
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include "PhysicsManager.h"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>

std::atomic<bool> isRunning(true); // 프로그램 실행 상태 관리

// 물리 연산 함수 (별도 스레드에서 실행)
void physicsLoop(GameObject* object, Map* map) {
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
void renderLoop(GameObject* object) {
	while (isRunning) {
		RenderManager::renderMap();
		
		RenderManager::renderObject();

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

	GameObjectManager::createObejct("Hero", "c:\\ImageTemp\\ch01.png");
	GameObject* object = GameObjectManager::getObejct("Hero");
	object->SetStartPosition(map->getInitX(), map->getInitY());

	RenderManager::addObject(object);
	RenderManager::renderObject();

	// 물리 연산 및 렌더링을 별도 스레드에서 시작
	std::thread physicsThread(physicsLoop, object, map);
	std::thread renderThread(renderLoop, object);

	// 종료 조건 처리
	//std::cin.get(); // 엔터 입력 시 종료
	//isRunning = false;

	// 스레드 종료 대기
	physicsThread.join();
	renderThread.join();
}

/*

현재 문제점:

사양이 비교적 좋은 데스크탑에서는 이동거리 및 충돌처리, 렌더링, 화면 지우기 작업들을 동기적으로 작동해도
움직임에 지연이 없었으나, 노트북에서 실행시키니 지연이 보이고 프레임 드랍 현상이 확실히 보임.
급하게 멀티 쓰레딩으로 두 렌더링 작업이랑 충돌 처리 작업을 분리했으나, 화면을 지울때 아예 새롭게 그리는 것이 아니라
오브젝트의 이동 거리만큼 지우기 때문에, 충돌 처리등의 이동 거리를 확정시키는 작업이 끝나기도 전에 움직임을 입력받고
그 이후 이동 거리만큼 지우고 곧바로 렌더링 하기 때문에, 캐릭터가 그보다 더 많이 이동했음에도 못 지워 잔상이 남는 문제가 생김.

-> renderMap 함수를 호출해서 아예 화면을 새롭게 그리고 오브젝트를 그리는 방식을 채택하니 잘 그려짐, 다만

벽과 바닥 등의 충돌처리가 아직 미흡하기 때문에 중간에 캐릭터가 벽이나 바닥에 종종 끼는 현상이 나타남.
모서리를 제외한 나머지 부분에서는 충돌처리가 잘 되기 떄문에 예외처리만 잘 해주면 괜찮을 것으로 예상됨

기능 구현이 눈으로 보여야해서 급하게 main 코드를 작성한 관계로 OPP 따르지 못한 부분이 많음.
더하여 현재는 대부분의 매니저 클래스들의 메소드들을 static으로 선언했지만, 추후 싱글톤 패턴으로 재구현 예정

캐릭터 기능 구현이 끝나면 이제 개발 업무를 다시 분장할 예정. (애니메이션 파트, 스테이지 관리 파트, 퍼즐 파트, 씬 관리 파트 등)



*/