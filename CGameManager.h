#pragma once
#include "CSingleton.h"

// Unity�� GameManager�� �����
// �������� ����� �������� ���⼭ �����
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