#ifndef _ITEM_H
#define _ITEM_H

#include <string>
using namespace std; // std 네임스페이스 사용

class Item
{
	string itemName;
	int useCount;
public:
	Item(string name = "", int count = 0) {
		itemName = name;
		useCount = count;
	}
	void setItem(string name, int count) {
		itemName = name;
		useCount = count;
	}
	void useItem() {
		if(useCount > 0)
			useCount--;
	}
	string getItemName() {
		return itemName;
	}
	int getUseCount() {
		return useCount;
	}
};

#endif