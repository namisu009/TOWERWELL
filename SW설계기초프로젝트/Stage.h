#ifndef _STAGE_H
#define _STAGE_H

#include <unordered_map>
#include "Puzzle.h"
#include "Map.h"
using namespace std;

class Stage {
private:
    int stageId; // 스테이지 ID
    Map* map;// 해당 스테이지의 맵
    bool isCleared; // 스테이지 클리어 여부 //퍼즐이 다 풀렸을 때
    bool playedScene; //해당 스테이지의 씬이 이미 보여졌는지
    //EventDispatcher& eventDispatcher; // 이벤트 디스패처 참조

public:
    Stage(int id, string sceneId, string mapid); // 생성자  EventDispatcher& dispatcher
    void addPuzzle(Puzzle* puzzle); // 퍼즐 추가
    bool getIsCleared() {
        return isCleared;
    }
    void playScene() {
        
    }
    void onPuzzleSolved(); // 퍼즐 해결 이벤트 핸들링
};

#endif