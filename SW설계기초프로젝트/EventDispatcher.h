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
    // Ư�� �̺�Ʈ�� ������ �߰�
    void subscribe(const string& event, const function<void()>& listener) {
        listeners[event].push_back(listener);
    }

    // Ư�� �̺�Ʈ �߻� �� ��� ������ ȣ��
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
