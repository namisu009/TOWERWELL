#include "DoubleBufferManager.h"


int DoubleBufferManager::g_nScreenIndex = 0;
HANDLE DoubleBufferManager::g_hScreen[2] = {};