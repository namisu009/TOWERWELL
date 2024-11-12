#ifndef _EVENTDISPATCHER_H_
#define _EVENTDISPATCHER_H_

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class EventDispatcher {
private:
    unordered_map<string, vector<function<void()>>> listeners;

public:
    // 특정 이벤트에 리스너 추가
    void subscribe(const string& event, const function<void()>& listener) {
        listeners[event].push_back(listener);
    }

    // 특정 이벤트 발생 시 모든 리스너 호출
    void dispatch(const string& event) {
        if (listeners.find(event) != listeners.end()) {
            for (const auto& listener : listeners[event]) {
                listener();
            }
        }
    }

    void unsubscribe(const string& event) {
        listeners.erase(event);
    }
};

#endif
