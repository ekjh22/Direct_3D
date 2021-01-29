#pragma once
#include "singleton.h"
class GameManager :
    public singleton<GameManager>
{
public:
    bool isUpdate = false;

    float playerMoveSpeed = 50.f;
public:
    GameManager();
    virtual ~GameManager();

    void Init();
    void Update();
};

#define GAME GameManager::GetInstance()