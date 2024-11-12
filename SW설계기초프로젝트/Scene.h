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
		while (_kbhit()) { // �Է� ���ۿ� �����ִ� Ű�� ������
			_getch(); // �ش� Ű�� �Һ��ϰ� ����
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
				
				clearInputBuffer(); // ��ȭ ���� �� �Է� ���� Ŭ����
				int key = _getch();
				while (key != 27) { // �����̽��ٸ� ���� ������ ��ٸ�
					key = _getch();
				}
			}

			
			RenderManager::setRenderDialog(nullptr);
			
		}
	}
};

#endif

