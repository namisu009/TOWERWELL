#define _CRT_SECURE_NO_WARNINGS
#include "RenderManager.h"
#include <string>
#include <locale>
#include <codecvt>
#include <iostream>
#include <cstdlib>

Map* RenderManager::currentMap = nullptr;
unordered_map<string, GameObject*> RenderManager::objectMap;
unordered_map<string, Puzzle*> RenderManager::puzzleMap;
Dialog* RenderManager::renderLog = nullptr;
Puzzle * RenderManager::renderPzl = nullptr;
EventDispatcher* RenderManager::eventDispatcher;

using namespace std;

std::wstring stringToWstring(const std::string& var)
{
    static std::locale loc("");
    auto& facet = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(loc);
    return std::wstring_convert<std::remove_reference<decltype(facet)>::type, wchar_t>(&facet).from_bytes(var);
}

void RenderManager::addObject(GameObject* object) {
    objectMap[object->getId()] = object; // 렌더링할 객체 추가
}

void RenderManager::removeObject(GameObject* object) {
    objectMap.erase(object->getId());
}

void RenderManager::addPuzzle(Puzzle* puzzle) {
    puzzleMap[puzzle->getId()] = puzzle; // 렌더링할 객체 추가
}

void RenderManager::removePuzzle(Puzzle* puzzle) {
    puzzleMap.erase(puzzle->getId());
}

void RenderManager::setRenderPuzzleDetail(string key) {
    renderPzl = puzzleMap[key];
}

void RenderManager::setRenderDialog(Dialog* dialog) {
    renderLog = dialog;
}

void RenderManager::ClearRenderDialog() {
    renderLog = nullptr;
}

void RenderManager::ClearRenderPuzzleDetail() {
    renderPzl = nullptr;
}

void RenderManager::renderMap() {
    //DoubleBufferManager::ScreenClear();

    RenderArray& renderArray = currentMap->getRenderArray();

    int init_x = cmdWidth / 2 - renderArray.width / 2;
    int init_y = cmdHeight - renderArray.height;

    COORD pos = { 0, 0 };

    for (int y = 0; y < renderArray.height; y++)
    {
        pos.Y = init_y + y;
        DoubleBufferManager::ScreenPrint(init_x, pos.Y, currentMap->getRenderArray().ASCIIArtArr[y]);
    }
    //DoubleBufferManager::ScreenFlipping();
}

void RenderManager::renderObject() {
    // 현재 게임 상태에 따라 필요한 객체를 렌더링 큐에 추가
    for (const auto& o : objectMap) {
        GameObject* object = o.second;
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


void RenderManager::renderPuzzle() {
    // 현재 게임 상태에 따라 필요한 객체를 렌더링 큐에 추가
    for (const auto& o : puzzleMap) {
        Puzzle* object = o.second;
        const auto& art = object->getObjectArray(); // ASCII 아트 가져오기

        if (art == nullptr)
            continue;

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


void RenderManager::renderPuzzleDetail () {
    if (renderPzl == nullptr)
        return;

    const auto& art = renderPzl->getDetailArray(); // ASCII 아트 가져오기
    int renderPzl_x = renderPzl->getX(); // X 좌표 가져오기
    int renderPzl_y = renderPzl->getY(); // Y 좌표 가져오기

    COORD pos = { 0, 0 };
    pos.X = renderPzl_x;
    pos.Y = renderPzl_y;

    // 객체의 ASCII 아트를 특정 위치에 렌더링
    for (int y = 0; y < art->height; y++)
    {
        pos.Y = renderPzl_y + y;
        DoubleBufferManager::ScreenPrint(renderPzl_x, pos.Y, art->ASCIIArtArr[y]);
    }

}

void RenderManager::renderDialog() {
    if (renderLog != nullptr)
    {
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

        DoubleBufferManager::ScreenFlipping();
        Sleep(10);
        //DoubleBufferManager::ScreenFlipping();

        // 사용자 입력 대기
        while (_kbhit()) {
            _getch();  // 입력 버퍼 비우기
        }

        while (1) {
            if (_kbhit()) { // 키 입력 확인
                int key = _getch(); // 키 입력 읽기
                if (key == VK_SPACE) { // ESC 키로 종료
                    break;
                }
            }
            DoubleBufferManager::drawText(stringToWstring(renderLog->getText()), cmdWidth + renderLog_x, 1085, RGB(200, 200, 200), 60);
            //DoubleBufferManager::drawText(L"우선테스트", cmdWidth + renderLog_x, 1080);
        }

        setRenderDialog(nullptr);  // 대화창 내용 초기화
    }
    else {
        DoubleBufferManager::ScreenFlipping();
    }

}

void RenderManager::render() {
    renderClear();
    renderMap();

    if (currentMap->getType() == TYPE_PUZZLE)
        renderPuzzle();

    renderObject();
    renderPuzzleDetail();
    renderDialog();


}

void RenderManager::objectClear() {
    objectMap.clear(); // 렌더링 큐 초기화
}

void RenderManager::puzzleClear() {
    puzzleMap.clear(); // 렌더링 큐 초기화
}

void RenderManager::renderClear() {
    DoubleBufferManager::ScreenClear();
}

void RenderManager::ScreenInit() {
    DoubleBufferManager::ScreenInit();
    DoubleBufferManager::ScreenClear();
}

void RenderManager::setRenderMap(Map* map) {
    currentMap = map;
}


/*
void RenderManager::clearObject() {
    for (const auto& o : objectMap) {
        GameObject* object = o.second;
        const auto& art = object->getRenderArray(); // ASCII 아트 가져오기
        int object_x = object->getX(); // X 좌표 가져오기
        int object_y = object->getY(); // Y 좌표 가져오기

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        int dx = abs(object->getDx()) > 5 ? object->getDx() : 5;
        int dy = abs(object->getDy()) > 5 ? object->getDy() : 5;
        // 객체의 ASCII 아트를 특정 위치에 렌더링

        int width = currentMap->getRenderArray().width;
        int height = currentMap->getRenderArray().height;
        for (int y = -abs(dy); y <= art->height + abs(dy); y++)
        {
            pos.Y = object_y + y;
            for (int x = -abs(dx); x <= art->width + abs(dx); x++)
            {
                pos.X = object_x + x;

                if (pos.X < 0 || pos.X >= width) continue;
                if (pos.Y < 0 || pos.Y >= height) continue;

                char buf[2] = { currentMap->getRenderArray().ASCIIArtArr[pos.Y][pos.X], '\0' };
                DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //현재 화면이 캐릭터가 그려질 곳이 아니라면 맵 그리기
            }
        }
    }

}
*/