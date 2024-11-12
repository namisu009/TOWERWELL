#ifndef _COMMAND_H
#define _COMMAND_H
#include <string>
#include <functional>
#include "GameObjectManager.h"


class Command
{
	GameObject* object;
	function<void()> cmd;
	int type;

public:
	Command() {
		object = 0;
		type = 0;
	}
	void addObject(GameObject* _object) {
		object = _object;
		type = object->getType();
	}
	void setAction(const function<void()>& action) {
		cmd = action;
	}
	int getType() {
		return type;
	}
	function<void()> getAction() {
		return cmd;
	}
	GameObject* getObject() {
		return object;
	}
};

#endif
