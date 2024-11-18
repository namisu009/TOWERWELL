#define _

#include "RenderManager.h"

#include <cstdlib> // for mbstowcs

Map* RenderManager::currentMap = nullptr;
unordered_map<string, GameObject*> RenderManager::objectMap;
unordered_map<string, Puzzle*> RenderManager::puzzleMap;
Dialog* RenderManager::renderLog = nullptr;
Puzzle * RenderManager::renderPzl = nullptr;
EventDispatcher* RenderManager::eventDispatcher;

wstring stringToWstring(const std::string& str) {
    size_t size = str.size() + 1;
    std::wstring wstr(size, L'\0');
    size_t convertedSize = 0;
    mbstowcs_s(&convertedSize, &wstr[0], size, str.c_str(), size - 1);
    //wstr.resize(convertedSize - 1);
    return wstr;
};

void RenderManager::addObject(GameObject* object) {
    objectMap[object->getId()] = object; // �������� ��ü �߰�
}

void RenderManager::removeObject(GameObject* object) {
    objectMap.erase(object->getId());
}

void RenderManager::addPuzzle(Puzzle* puzzle) {
    puzzleMap[puzzle->getId()] = puzzle; // �������� ��ü �߰�
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
    // ���� ���� ���¿� ���� �ʿ��� ��ü�� ������ ť�� �߰�
    for (const auto& o : objectMap) {
        GameObject* object = o.second;
        const auto& art = object->getRenderArray(); // ASCII ��Ʈ ��������

        int object_x = object->getX(); // X ��ǥ ��������
        int object_y = object->getY(); // Y ��ǥ ��������

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        // ��ü�� ASCII ��Ʈ�� Ư�� ��ġ�� ������
        for (int y = 0; y < art->height; y++)
        {
            pos.Y = object_y + y;
            for (int x = 0; x < art->width; x++)
            {
                pos.X = object_x + x;
                char buf[2] = { art->ASCIIArtArr[y][x], '\0' };

                if (art->drawornotArr[y][x] == 1)
                    DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //���� ȭ���� ĳ���Ͱ� �׷��� ���� �ƴ϶�� �� �׸���
            }
        }
    }
}


void RenderManager::renderPuzzle() {
    // ���� ���� ���¿� ���� �ʿ��� ��ü�� ������ ť�� �߰�
    for (const auto& o : puzzleMap) {
        Puzzle* object = o.second;
        const auto& art = object->getObjectArray(); // ASCII ��Ʈ ��������

        if (art == nullptr)
            continue;

        int object_x = object->getX(); // X ��ǥ ��������
        int object_y = object->getY(); // Y ��ǥ ��������

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        // ��ü�� ASCII ��Ʈ�� Ư�� ��ġ�� ������
        for (int y = 0; y < art->height; y++)
        {
            pos.Y = object_y + y;
            for (int x = 0; x < art->width; x++)
            {
                pos.X = object_x + x;
                char buf[2] = { art->ASCIIArtArr[y][x], '\0' };

                if (art->drawornotArr[y][x] == 1)
                    DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //���� ȭ���� ĳ���Ͱ� �׷��� ���� �ƴ϶�� �� �׸���

            }
        }
    }
}


void RenderManager::renderPuzzleDetail () {
    if (renderPzl == nullptr)
        return;

    const auto& art = renderPzl->getDetailArray(); // ASCII ��Ʈ ��������
    int renderPzl_x = renderPzl->getX(); // X ��ǥ ��������
    int renderPzl_y = renderPzl->getY(); // Y ��ǥ ��������

    COORD pos = { 0, 0 };
    pos.X = renderPzl_x;
    pos.Y = renderPzl_y;

    // ��ü�� ASCII ��Ʈ�� Ư�� ��ġ�� ������
    for (int y = 0; y < art->height; y++)
    {
        pos.Y = renderPzl_y + y;
        DoubleBufferManager::ScreenPrint(renderPzl_x, pos.Y, art->ASCIIArtArr[y]);
    }

}

void RenderManager::renderDialog() {
    if (renderLog != nullptr)
    {
        const auto& art = renderLog->getRenderArray(); // ASCII ��Ʈ ��������
        int renderLog_x = renderLog->getX(); // X ��ǥ ��������
        int renderLog_y = renderLog->getY(); // Y ��ǥ ��������

        COORD pos = { 0, 0 };
        pos.X = renderLog_x;
        pos.Y = renderLog_y;

        // ��ü�� ASCII ��Ʈ�� Ư�� ��ġ�� ������
        for (int y = 0; y < art->height; y++)
        {
            pos.Y = renderLog_y + y;
            DoubleBufferManager::ScreenPrint(renderLog_x, pos.Y, art->ASCIIArtArr[y]);
        }

        DoubleBufferManager::ScreenFlipping();
        Sleep(10);
        //DoubleBufferManager::ScreenFlipping();

        // ����� �Է� ���
        while (_kbhit()) {
            _getch();  // �Է� ���� ����
        }

        while (1) {
            if (_kbhit()) { // Ű �Է� Ȯ��
                int key = _getch(); // Ű �Է� �б�
                if (key == VK_SPACE) { // ESC Ű�� ����
                    break;
                }
            }
            DoubleBufferManager::drawText(
                stringToWstring(renderLog->getText()), cmdWidth + renderLog_x, 1080
            );
        }

        setRenderDialog(nullptr);  // ��ȭâ ���� �ʱ�ȭ
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
    objectMap.clear(); // ������ ť �ʱ�ȭ
}

void RenderManager::puzzleClear() {
    puzzleMap.clear(); // ������ ť �ʱ�ȭ
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
        const auto& art = object->getRenderArray(); // ASCII ��Ʈ ��������
        int object_x = object->getX(); // X ��ǥ ��������
        int object_y = object->getY(); // Y ��ǥ ��������

        COORD pos = { 0, 0 };
        pos.X = object_x;
        pos.Y = object_y;

        int dx = abs(object->getDx()) > 5 ? object->getDx() : 5;
        int dy = abs(object->getDy()) > 5 ? object->getDy() : 5;
        // ��ü�� ASCII ��Ʈ�� Ư�� ��ġ�� ������

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
                DoubleBufferManager::ScreenprintAtPosition(pos.X, pos.Y, buf); //���� ȭ���� ĳ���Ͱ� �׷��� ���� �ƴ϶�� �� �׸���
            }
        }
    }

}
*/