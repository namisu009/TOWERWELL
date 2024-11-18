#ifndef _DIALOG_H
#define _DIALOG_H
#include "GameObject.h"

class Dialog : public GameObject
{
	string text;
public:
	Dialog(string _id, string _text) : GameObject(_id) {
		text = _text;
	}

	string getText() {
		return text;
	}
};

#endif