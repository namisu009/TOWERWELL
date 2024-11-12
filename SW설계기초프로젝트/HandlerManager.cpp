#include "HandlerManager.h"

unordered_map<int, function<void()>> HandlerManager::keyMap;
EventDispatcher* HandlerManager::eventDispatcher;