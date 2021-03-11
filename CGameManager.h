#pragma once
#include "CSingleton.h"

// Unity의 GameManager와 비슷함
// 전역으로 사용할 변수들을 여기서 사용함
// Score, PlayerName ...
class CGameManager :
    public CSingleton<CGameManager>
{
public:
    CGameManager();
    ~CGameManager();

public:
    void Reset();
    void FloodFill(int x, int y);
    void PrintFill();

public:
    int map[WINSIZEY][WINSIZEX] = { 0, };

    int putBlock = 0;
    int oldNumX, oldNumY;
    int curNumX, curNumY;
};

#define GAME (*CGameManager::GetInstance())