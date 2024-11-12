#ifndef _SCENE_H_
#define _SCENE_H_

#include "Command.h"
#include "RenderManager.h"
#include "queue"
#include <conio.h>

using namespace std;
class Scene
{
	queue<Command> commands;
public:
	void addCommand(Command command) {
		commands.push(command);
	}

	int getCmdSize() {
		return commands.size();
	}

	Command popCommand() {
		Command cmd = commands.front();
		commands.pop();
		return cmd;
	}

	void clearInputBuffer() {
		while (_kbhit()) { // 입력 버퍼에 남아있는 키가 있으면
			_getch(); // 해당 키를 소비하고 버림
		}
	}
	void display() {
		while (!commands.empty()) {
			Command cmd = popCommand();
			RenderManager::renderMap();
			RenderManager::renderObject();
			//RenderManager::renderDialog();
			if (cmd.getType() == TYPE_CHARACTER) {
				cmd.getAction()();
				Sleep(24);
				DoubleBufferManager::ScreenFlipping();
			}
			else if (cmd.getType() == TYPE_DIALOG) {

				RenderManager::setRenderDialog((Dialog*)cmd.getObject());
				RenderManager::renderDialog();
				DoubleBufferManager::ScreenFlipping();
				
				clearInputBuffer(); // 대화 시작 전 입력 버퍼 클리어
				int key = _getch();
				while (key != 27) { // 스페이스바를 누를 때까지 기다림
					key = _getch();
				}
			}

			
			RenderManager::setRenderDialog(nullptr);
			
		}
	}
};

#endif

