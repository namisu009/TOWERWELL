#define _CRT_SECURE_NO_WARNINGS
#include "RenderManager.h"
#include "PuzzleMap.h"
#include <string>
#include <locale>
#include <codecvt>
#include <iostream>
#include <cstdlib>

Map* RenderManager::currentMap = nullptr;
unordered_map<string, GameObject*> RenderManager::objectMap;
unordered_map<string, Puzzle*> RenderManager::puzzleMap;
Dialog* RenderManager::renderLog = nullptr;
GameObject* RenderManager::renderDetail = nullptr;
EventDispatcher* RenderManager::eventDispatcher;

using namespace std;

std::wstring stringToWstring(const std::string& var)
{
    static std::locale loc("");
    auto& facet = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(loc);
    return std::wstring_convert<std::remove_reference<decltype(facet)>::type, wchar_t>(&facet).from_bytes(var);
}

void RenderManager::addObject(GameObject* object) {
    if (objectMap.find(object->getId()) == objectMap.end())
        objectMap[object->getId()] = object; // 렌더링할 객체 추가
}

void RenderManager::removeObject(GameObject* object) {
    if (objectMap.find(object->getId()) != objectMap.end())
        objectMap.erase(object->getId());
}

void RenderManager::addPuzzle(Puzzle* puzzle) {
    puzzleMap[puzzle->getId()] = puzzle; // 렌더링할 객체 추가
}

void RenderManager::removePuzzle(Puzzle* puzzle) {
    puzzleMap.erase(puzzle->getId());
}

void RenderManager::setRenderDetail(GameObject* object) {
    renderDetail = object;
}

void RenderManager::setRenderDetail(string key) {
    renderDetail = puzzleMap[key];
}

void RenderManager::setRenderDialog(Dialog* dialog) {
    renderLog = dialog;
}

void RenderManager::ClearRenderDialog() {
    renderLog = nullptr;
}

void RenderManager::ClearRenderDetail() {
    renderDetail = nullptr;
}

GameObject* RenderManager::getRenderDetail() {
    return renderDetail;
}

Map* RenderManager::getRenderMap() {
    return currentMap;
}

Dialog* RenderManager::getRenderDialog() {
    return renderLog;
}

GameObject* RenderManager::getRenderObject(string key) {
    if (objectMap.find(key) != objectMap.end())
        return objectMap[key];
    else
        return nullptr;
}


void RenderManager::renderMap() {
    //DoubleBufferManager::ScreenClear();

    RenderArray& renderArray = currentMap->getRenderArray();

    int init_x = cmdWidth / 2 - renderArray.width / 2;
    int init_y = cmdHeight - renderArray.height - 1;

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

        if (art == NULL) return;

        // 객체의 ASCII 아트를 특정 위치에 렌더링
        for (int y = 0; y < art->height; y++)
        {
            pos.Y = object_y + y;
            for (int x = 0; x < art->width; x++)
            {
                pos.X = object_x + x;
                char buf[2] = { art->ASCIIArtArr[y][x], '\0' };

                if (art->drawornotArr[y][x] == 1 && (
                    currentMap->getMapId() == "SCREEN" || (
                        currentMap->getMapId() != "SCREEN"
                        && currentMap->getScreenArray().MapInfo[pos.Y][pos.X] != MAP_FIRST_OBJECT))) {
                    COORD CursorPosition;
                    //SetConsoleCursorPosition(DoubleBufferManager::getHandle(), CursorPosition);
                    DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //현재 화면이 캐릭터가 그려질 곳이 아니라면 맵 그리기
                }
            }
        }

        /*

        char** buf;
        buf = (char**)malloc(sizeof(char*) * art->height);
        for (int y = 0; y < art->height; y++)
        {
            buf[y] = (char*)malloc(sizeof(char) * (art->width + 1));
            pos.Y = object_y + y;
            for (int x = 0; x < art->width; x++)
            {
                pos.X = object_x + x;
                buf[y][x] = art->ASCIIArtArr[y][x];

                if (art->drawornotArr[y][x] == 0) {
                    DWORD charsRead
                    COORD readCoord = { pos.X, pos.Y };
                    // 단일 문자를 읽으므로 &buf[y][x] 사용
                    ReadConsoleOutputCharacterA(DoubleBufferManager::getHandle(), &buf[y][x], 1, readCoord, &charsRead);
                }

            }

            pos.X = object_x;
            buf[y][art->width] = '\0';
            DoubleBufferManager::ScreenPrint(pos.X, pos.Y, buf[y]);
        }

        for (int y = 0; y < art->height; y++) {
            free(buf[y]);
        }
        free(buf);

        */

    }
}


void RenderManager::renderPuzzle() {
    for (const auto& o : puzzleMap) {
        Puzzle* object = o.second;
        const auto& art = object->getObjectArray(); // ASCII 아트 가져오기

        if (art == nullptr)
            continue;

        int object_x = object->getX() - art->width / 2; // X 좌표 가져오기
        int object_y = object->getY() - art->height; // Y 좌표 가져오기

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        char** buf;
        buf = (char**)malloc(sizeof(char*) * art->height);

        for (int y = 0; y < art->height; y++)
        {
            buf[y] = (char*)malloc(sizeof(char) * (art->width + 1));
            pos.Y = object_y + y;
            for (int x = 0; x < art->width; x++)
            {
                pos.X = object_x + x;
                buf[y][x] = art->ASCIIArtArr[y][x];
                if (art->drawornotArr[y][x] == 0 || currentMap->getScreenArray().MapInfo[y][x] == MAP_FIRST_OBJECT)
                {
                    RenderArray& renderArray = currentMap->getRenderArray();
                    buf[y][x] = renderArray.ASCIIArtArr[pos.Y][pos.X];
                }

            }

            pos.X = object_x;
            buf[y][art->width - 1] = '\0';
            DoubleBufferManager::ScreenPrint(pos.X, pos.Y, buf[y]);
            /*
            DWORD charsRead = 0;   // 읽은 문자 수

            COORD readCoord = { pos.X , pos.Y };
            ReadConsoleOutputCharacterA(hOutHandle, (LPSTR)buf[y][x], sizeof(char), readCoord, &charsRead);
            */
        }

    }
}

void RenderManager::renderScreenDetail() {
    if (renderDetail == nullptr)
        return;

    const auto& art = renderDetail->getDetailArray(); // ASCII 아트 가져오기
    int renderDetail_x = renderDetail->getX(); // X 좌표 가져오기
    int renderDetail_y = renderDetail->getY(); // Y 좌표 가져오기

    COORD pos = { 0, 0 };
    pos.X = renderDetail_x;
    pos.Y = renderDetail_y;

    // 객체의 ASCII 아트를 특정 위치에 렌더링
    for (int y = 0; y < art->height; y++)
    {
        pos.Y = renderDetail_y + y;
        DoubleBufferManager::ScreenPrint(renderDetail_x, pos.Y, art->ASCIIArtArr[y]);
    }
}

void RenderManager::renderDialog() {
    if (renderLog != nullptr)
    {
        const auto& art = renderLog->getRenderArray(); // ASCII 아트 가져오기
        int renderLog_x = renderLog->getX(); // X 좌표 가져오기
        int renderLog_y = renderLog->getY(); // Y 좌표 가져오기
        int renderLog_width = renderLog->getWidth(); // Y 좌표 가져오기
        int renderLog_height = renderLog->getHeight(); // Y 좌표 가져오기

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


        if (renderLog->getText() != "") {
            DoubleBufferManager::drawText(renderLog->getText().c_str(), renderLog_x, renderLog_y, renderLog_width, renderLog_height);
            while (1) {
                if (_kbhit()) { // 키 입력 확인
                    int key = _getch(); // 키 입력 읽기      
                    if (key == 32) {
                        break;
                    }
                }
            }
            //DoubleBufferManager::drawText(L"우선테스트", cmdWidth + renderLog_x, 1080);
        }

        

    }
    else {
        DoubleBufferManager::ScreenFlipping();
    }
}

void RenderManager::renderInputText(string& input, int x, int y, int height) {
    if (renderLog != nullptr)
    {
        renderDialog();
    }

    string my = "비밀번호를 입력하세요: ";
    my += input;

    const auto& art = renderLog->getRenderArray(); // ASCII 아트 가져오기
    int renderLog_x = renderLog->getX(); // X 좌표 가져오기
    int renderLog_y = renderLog->getY(); // Y 좌표 가져오기
    int renderLog_width = renderLog->getWidth(); // Y 좌표 가져오기
    int renderLog_height = renderLog->getHeight(); // Y 좌표 가져오기


    DoubleBufferManager::drawText(
        my.c_str(), // 입력 문자열을 렌더링
        renderLog_x, renderLog_y, renderLog_width, renderLog_height
    );
}

void RenderManager::render() {
    //renderClear();
    renderMap();

    if (currentMap->getType() == TYPE_PUZZLE)
        renderPuzzle();

    renderObject();

    if (renderDetail != nullptr) {
        renderScreenDetail();
        DoubleBufferManager::ScreenFlipping();
        renderScreenDetail();
        DoubleBufferManager::ScreenFlipping();

        //renderDialog();

        //return;
    }


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

    if (map->getType() == TYPE_PUZZLE)
        ((PuzzleMap*)map)->addRenderPuzzle();
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