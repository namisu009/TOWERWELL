#ifndef _ANIMATIONMANAGER_H
#define _ANIMATIONMANAGER_H

#include "RenderStruct.h"
#include "ArtLoadManager.h"

#include <unordered_map>
#include <string>

using namespace std;

class AnimationManager
{
	unordered_map <string, RenderArray*[2]> Animations;
	ArtLoadManager* artLoadManager;

	string id;
	int animationToggle;
	int animationCounter = 0;
public:
	AnimationManager() {
		artLoadManager->GetInstance();
		animationToggle = 0;
	}
	
	void addAnimaion(string _id, const char* filename1, const char* filename2) {
		RenderArray* renderArray1 = new RenderArray();
		artLoadManager->RenderArrayLoad(renderArray1, filename1);
		RenderArray* renderArray2 = new RenderArray();
		artLoadManager->RenderArrayLoad(renderArray2, filename2);
  		Animations[_id][0] = renderArray1;
		Animations[_id][1] = renderArray2;
	}

	void setAnimation(string _id, int toggle, const char* filename) {
		artLoadManager->RenderArrayLoad(Animations[_id][toggle], filename);
	}

	void setAnimationToggle(int t) {
		animationToggle = t;
	}

	RenderArray* getRenderArray(string _id) {

		if(_id != "IDLE")
			animationCounter++;
		else
		{
			if (id == "RIGHT") {
				animationToggle = 0;
			}
			else if (id == "LEFT") {
				animationToggle = 1;
			}
			animationCounter = 0;
		}

		id = _id;

		if (animationCounter >= 8)
		{
			if (animationToggle == 0)
				animationToggle = 1;
			else
				animationToggle = 0;
			animationCounter = 0;
		}

		return Animations[id][animationToggle];
	}

};

#endif