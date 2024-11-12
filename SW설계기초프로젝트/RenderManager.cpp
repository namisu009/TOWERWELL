#include "RenderManager.h"
#include "RenderStruct.h"

Map* RenderManager::m_map = nullptr;
vector<GameObject*> RenderManager::renderQueue;
Dialog * RenderManager::renderLog = NULL;
EventDispatcher* RenderManager::eventDispatcher;

void RenderManager::addObject(GameObject* object) {
    renderQueue.push_back(object); // 렌더링할 객체 추가
}

void RenderManager::removeObject(GameObject* object) {
    renderQueue.erase(std::remove(renderQueue.begin(), renderQueue.end(), object), renderQueue.end()); // 객체 제거
}

void RenderManager::setRenderDialog(Dialog* dialog) {
    renderLog = dialog;
}

void RenderManager::ClearRenderDialog() {
    renderLog = NULL;
}

void RenderManager::renderMap() {
    //DoubleBufferManager::ScreenClear();

    RenderArray& renderArray = m_map->getRenderArray();

    int init_x = cmdWidth / 2 - renderArray.width / 2;
    int init_y = cmdHeight - renderArray.height;

    COORD pos = { 0, 0 };

    for (int y = 0; y < renderArray.height; y++)
    {
        pos.Y = init_y + y;
        DoubleBufferManager::ScreenPrint(init_x, pos.Y, m_map->getRenderArray().ASCIIArtArr[y]);
    }
    //DoubleBufferManager::ScreenFlipping();
}

void RenderManager::clearObject() {
    for (const auto& object : renderQueue) {
        const auto& art = object->getRenderArray(); // ASCII 아트 가져오기
        int object_x = object->getX(); // X 좌표 가져오기
        int object_y = object->getY(); // Y 좌표 가져오기

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        int dx = abs(object->getDx()) > 5 ? object->getDx() : 5;
        int dy = abs(object->getDy()) > 5 ? object->getDy() : 5;
        // 객체의 ASCII 아트를 특정 위치에 렌더링

        int width = m_map->getRenderArray().width;
        int height = m_map->getRenderArray().height;
        for (int y = -abs(dy); y <= art->height + abs(dy); y++)
        {
            pos.Y = object_y + y;
            for (int x = -abs(dx); x <= art->width + abs(dx); x++)
            {
                pos.X = object_x + x;

                if (pos.X < 0 || pos.X >= width) continue;
                if (pos.Y < 0 || pos.Y >= height) continue;

                char buf[2] = { m_map->getRenderArray().ASCIIArtArr[pos.Y][pos.X], '\0'};
                DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //현재 화면이 캐릭터가 그려질 곳이 아니라면 맵 그리기
            }
        }
    }


}

void RenderManager::renderObject() {
    // 현재 게임 상태에 따라 필요한 객체를 렌더링 큐에 추가
    for (const auto& object : renderQueue) {
        const auto& art = object->getRenderArray(); // ASCII 아트 가져오기
        int object_x = object->getX(); // X 좌표 가져오기
        int object_y = object->getY(); // Y 좌표 가져오기

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        // 객체의 ASCII 아트를 특정 위치에 렌더링
        for (int y = 0; y < art->height; y++)
        {
            pos.Y = object_y + y;
            for (int x = 0; x < art->width; x++)
            {
                pos.X = object_x + x;
                char buf[2] = { art->ASCIIArtArr[y][x], '\0' };

                if (art->drawornotArr[y][x] == 1)
                    DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //현재 화면이 캐릭터가 그려질 곳이 아니라면 맵 그리기
             
            }
        }
    }
}

void RenderManager::renderDialog() {
    if (renderLog == NULL)
        return;

    const auto& art = renderLog->getRenderArray(); // ASCII 아트 가져오기
    int renderLog_x = renderLog->getX(); // X 좌표 가져오기
    int renderLog_y = renderLog->getY(); // Y 좌표 가져오기

    COORD pos = { 0, 0 };
    pos.X = renderLog_x;
    pos.Y = renderLog_y;

    // 객체의 ASCII 아트를 특정 위치에 렌더링
    for (int y = 0; y < art->height; y++)
    {
        pos.Y = renderLog_y + y;
        DoubleBufferManager::ScreenPrint(renderLog_x, pos.Y, art->ASCIIArtArr[y]);
    }
}

void RenderManager::render() {
    renderClear();
    renderMap();
    renderObject();
    renderDialog();
    DoubleBufferManager::ScreenFlipping();
}

void RenderManager::clear() {
    renderQueue.clear(); // 렌더링 큐 초기화
}

void RenderManager::renderClear() {
    DoubleBufferManager::ScreenClear();
}

void RenderManager::ScreenInit() {
    DoubleBufferManager::ScreenInit();
    DoubleBufferManager::ScreenClear();
}

void RenderManager::setRenderMap(Map* map) {
    m_map = map;
}


