#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <queue>
#include "Command.h"
#include "GameObjectManager.h"
#include "RenderManager.h"

#include <thread>

class Puzzle; // 전방 선언

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

	void setDialog(string key) {
		Command cmd;
		cmd.setObject(GameObjectManager::getDialog(key));
		commands.push(cmd);
	}

	void setAction(string key, ActionType command, int dt, int repeat) { //setDx, setDy, dx, dy
		for(int i = 0; i < repeat; i++)
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
		else if (command == ACTION_MOVE_Y){
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

	Command popCommand() {
		Command cmd = commands.front();
		commands.pop();

		if (sceneLoop)
			commands.push(cmd);

		return cmd;
	}

	void clearInputBuffer() {
		while (_kbhit()) { // 입력 버퍼에 남아있는 키가 있으면
			_getch(); // 해당 키를 소비하고 버림
		}
	}

	void display() {

		int size = commands.size();
		while (size) {
			Command cmd = popCommand();
			
			if (cmd.getType() == TYPE_CHARACTER) {
				cmd.getAction()();
				Sleep(10);
			}
			else if (cmd.getType() == TYPE_DIALOG) {
				RenderManager::setRenderDialog((Dialog*)cmd.getObject());
				clearInputBuffer();
			}

			RenderManager::render();
			size--;
		}
	}
};

#endif

