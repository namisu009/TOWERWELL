#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <queue>
#include "Command.h"
#include "GameObjectManager.h"
#include "RenderManager.h"
#include "StageManager.h"
#include <thread>

class Puzzle; // 전방 선언
class MapManager;

using namespace std;
class Scene
{
	bool sceneLoop;
	queue<Command> commands;
public:
	Scene() {
		sceneLoop = true;
	}

	void setSceneLoop(bool _b) {
		sceneLoop = _b;
	}

	int getCmdSize() {
		return commands.size();
	}

	void setRenderCharacter(string key) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key]() mutable { RenderManager::addObject(GameObjectManager::getCharacter(key)); });
		commands.push(cmd);
	}

	void removeRenderCharacter(string key) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key]() mutable { RenderManager::removeObject(GameObjectManager::getCharacter(key)); });
		commands.push(cmd);

	}

	void setDialog(string key) {
		Command cmd;
		cmd.setObject(GameObjectManager::getDialog(key));
		commands.push(cmd);
	}

	void setDeath(string key, bool t) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key, t]() mutable { 
			GameObjectManager::getCharacter(key)->setDeathState(t);
			int _y = GameObjectManager::getCharacter("Hero")->getY();
			_y += GameObjectManager::getCharacter("Hero")->getHeight();
			_y = _y - GameObjectManager::getCharacter("Sister")->getHeight();
			GameObjectManager::getCharacter(key)->setY(_y);
		});
		commands.push(cmd);
	}

	void setCarry(string key, bool t) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key, t]() mutable {
			GameObjectManager::getCharacter(key)->setCarryState(t);
			});
		commands.push(cmd);
	}

	void setVKSPACE() {
		Command cmd;
		cmd.setType(TYPE_SCREEN);
		cmd.setAction([cmd]() mutable {
			while (_kbhit()) { // 입력 버퍼에 남아있는 키가 있으면
				_getch(); // 해당 키를 소비하고 버림
			}
			while (1) {
				if (_kbhit()) { // 키 입력 확인
					int key = _getch(); // 키 입력 읽기      
					if (key == 32) {
						break;
					}
				}
			}
		});
		commands.push(cmd);
	}


	/*
	void setClearedPuzzle(string key) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter("Hero"));
		MapManager::getPuzzleMap(key);
		cmd.setAction([cmd, key]() mutable {

			});
		commands.push(cmd);
	}
	*/

	void setScreen(const char* key) {
		Command cmd;

		Map* map;
		map = new Map();
		map->initializeFromASCII(key);
		map->setMapId("SCREEN");

		cmd.setMap(map);
		cmd.setType(TYPE_SCREEN);

		cmd.setAction([cmd]() mutable {
			RenderManager::setRenderMap(cmd.getMap());
			});

		commands.push(cmd);
	}

	void setDetail(const char* key) {
		Command cmd;

		GameObject* obj = nullptr;

		if (key != "")
		{
			obj = new GameObject("Detail");
			obj->initializeFromASCII(key);
			obj->SetStartPosition(0, 0);
			obj->setType(TYPE_DETAIL);
			cmd.setObject(obj);
		}

		cmd.setType(TYPE_DETAIL);
		commands.push(cmd);
	}


	void setCharacterPositionX(string key, int x) {
		Command cmd;

		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key, x]() mutable {
			if (x >= 0)
				cmd.getObject()->setX(x);
			});
		commands.push(cmd);
	}

	void setCharacterStartPosition(string key, string map, int x) {
		Command cmd;

		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key, map, x]() mutable {
			int ix = MapManager::getMap(map)->getInitX();
			int iy = MapManager::getMap(map)->getInitY();
			GameObjectManager::getCharacter(key)->SetStartPosition(ix, iy);
			GameObjectManager::getCharacter(key)->setX(x);


		});
	

		commands.push(cmd);
	}
	void setCharacterPosition(string key, int x, int y) {
		Command cmd;

		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key, x, y]() mutable {
			if (y == 0 && key == "Hood")
			{
				int _y = GameObjectManager::getCharacter("Hero")->getY();
				_y += GameObjectManager::getCharacter("Hero")->getHeight();

				y = _y - GameObjectManager::getCharacter("Hood")->getHeight();
			}
			else if (y == 0)
				y = GameObjectManager::getCharacter(key)->getY();
			

			if(y >= 0)
				cmd.getObject()->setY(y);

			if(x >= 0)
				cmd.getObject()->setX(x);

			});

		commands.push(cmd);
	}

	void setAction(string key, ActionType command, int dt, int repeat) { //setDx, setDy, dx, dy
		for (int i = 0; i < repeat; i++)
			setAction(key, command, dt);
	}

	void setAction(string key, ActionType command, int dt) { //setDx, setDy, dx, dy
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		if (command == ACTION_MOVE_X)
			cmd.setAction([cmd, dt]() mutable {cmd.getObject()->setDx(dt); });
		else if (command == ACTION_MOVE_Y)
			cmd.setAction([cmd, dt]() mutable {cmd.getObject()->setDy(dt); });
		else
			return;

		commands.push(cmd);

		cmd.setAction([cmd, dt]() mutable {cmd.getObject()->move(); });
		commands.push(cmd);
	}

	void setAction(string key1, string key2, ActionType command, int dt) { //setDx, setDy, dx, dy
		Command cmd1, cmd2;
		cmd1.setObject(GameObjectManager::getCharacter(key1));
		cmd2.setObject(GameObjectManager::getCharacter(key2));
		if (command == ACTION_MOVE_X)
		{
			cmd1.setAction([cmd1, dt]() mutable {cmd1.getObject()->setDx(dt); });
			cmd2.setAction([cmd2, dt]() mutable {cmd2.getObject()->setDx(dt); });
		}
		else if (command == ACTION_MOVE_Y) {
			cmd1.setAction([cmd1, dt]() mutable {cmd1.getObject()->setDy(dt); });
			cmd2.setAction([cmd2, dt]() mutable {cmd2.getObject()->setDy(dt); });
		}
		else
			return;

		commands.push(cmd1);
		commands.push(cmd2);

		cmd1.setAction([cmd1, dt]() mutable {cmd1.getObject()->move(); });
		cmd2.setAction([cmd2, dt]() mutable {cmd2.getObject()->move(); });

		commands.push(cmd1);
		commands.push(cmd2);
	}

	void setAction(string key1, string key2, ActionType command, int dt, int repeat) { //setDx, setDy, dx, dy
		for (int i = 0; i < repeat; i++)
			setAction(key1, key2, command, dt);
	}

	void setDelay(string key, int time) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, time]() mutable { Sleep(time); });
		commands.push(cmd);
	}

	void setRenderHood(string key, bool t) {
		Command cmd;
		cmd.setObject(GameObjectManager::getCharacter(key));
		cmd.setAction([cmd, key, t]() mutable {
			GameObjectManager::getCharacter(key)->setHood(t);
		});
		commands.push(cmd);
	}

	Command popCommand() {
		Command cmd = commands.front();
		commands.pop();

		if (sceneLoop) {
			commands.push(cmd);
		}

		return cmd;
	}

	void clearInputBuffer() {
		while (_kbhit()) { // 입력 버퍼에 남아있는 키가 있으면
			_getch(); // 해당 키를 소비하고 버림
		}
	}

	void display() {
		int size = commands.size();
		clearInputBuffer();

		while (size) {
			Command cmd = popCommand();

			if (cmd.getType() == TYPE_CHARACTER || cmd.getType() == TYPE_SCREEN) {
				if (!sceneLoop && cmd.getType() == TYPE_SCREEN && RenderManager::getRenderMap()->getMapId() == "SCREEN")
				{
					//delete RenderManager::getRenderMap();
				}

				cmd.getAction()();
				Sleep(10);
			}
			else if (cmd.getType() == TYPE_DIALOG) {
				RenderManager::setRenderDialog((Dialog*)cmd.getObject());
				clearInputBuffer();
			}
			else if (cmd.getType() == TYPE_DETAIL) {
				if (cmd.getObject() == nullptr && !sceneLoop)
				{
					//delete RenderManager::getRenderDetail();
				}
				RenderManager::setRenderDetail(cmd.getObject());
				Sleep(100);
			}

			RenderManager::render();
			RenderManager::setRenderDialog(nullptr);  // 대화창 내용 초기화

			/*
			if (!sceneLoop) {
				if (cmd.getType() == TYPE_DIALOG)
					delete cmd.getObject();
			}
			*/
			size--;
		}
		clearInputBuffer();
		
	}
};

#endif

