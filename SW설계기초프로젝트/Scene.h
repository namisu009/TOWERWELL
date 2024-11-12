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

	void display() {
		while (!commands.empty()) {
			Command cmd = popCommand();

			if (cmd.getType() == TYPE_CHARACTER) {
				cmd.getAction()();
				Sleep(24);
			}
			else if (cmd.getType() == TYPE_DIALOG) {
				RenderManager::setRenderDialog((Dialog*)cmd.getObject());
				RenderManager::render();
				int key = 0;
				while (key != 32) {
					key = _getch();
				}
			}

			RenderManager::render();
			RenderManager::setRenderDialog(nullptr);
		}
	}
};

#endif

