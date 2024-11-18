#ifndef _ITEMMANAGER_H
#define _ITEMMANAGER_H

#include <unordered_map>
#include <string>
#include "Item.h"
using namespace std;
class ItemMananger
{
	static unordered_map<string, Item> items;

public:
	static void addItems(string key, int cnt = 1) {
		Item item(key, cnt);
		items[key] = item;
	}

	static Item* getItems(string key) {
		if (items.find(key) != items.end()) {
			return &items[key];
		}
		return nullptr; //존재하지 않음
	}
};

#endif
