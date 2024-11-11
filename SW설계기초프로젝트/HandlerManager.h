#ifndef _HANDLEMANAGER_H
#define _HANDLEMANAGER_H
#include<unordered_map>
#include <functional>

using namespace std;

class HandlerManager {
private:
    unordered_map<int, function<void()>> keyMap;// 입력 키 - 함수 매핑
public:
    void bindInput(int key, const function<void()>& action) {
        keyMap[key] = action;
    }
    void clearKeyMap() {
        keyMap.clear();
    }
    void processInput(int key) {
        if (keyMap.find(key) != keyMap.end()) {
            keyMap[key](); // 해당 키에 매핑된 함수 실행
        }
    }
};

#endif

