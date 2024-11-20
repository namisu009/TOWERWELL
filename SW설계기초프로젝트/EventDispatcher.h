#ifndef _EVENTDISPATCHER_H_
#define _EVENTDISPATCHER_H_

#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

using namespace std;

enum EventType {
    PUZZLE_SOLVED,
    STAGE_COMPLETED,
    MOVE_MAP,
    CHANGE_MAP_HANDLE,
    RENDER,
};

class EventDispatcher {
public:
    using EventCallback = std::function<void()>;

    void subscribe(EventType eventType, EventCallback callback) {
        listeners[eventType].push_back(callback);
    }

    void dispatch(EventType eventType) {
        if (listeners.count(eventType)) {
            for (auto& callback : listeners[eventType]) {
                callback();
            }
        }
    }

private:
    std::unordered_map<EventType, std::vector<EventCallback>> listeners;
};

#endif
