#pragma once
#include "singleton.h"
class GameManager :
    public singleton<GameManager>
{
public:
    bool isUpdate = false;
    float playerMoveSpeed = 50.f;

public:
    void Init();
    void Update();

public:
    GameManager();
    virtual ~GameManager();
};

#define GAME GameManager::GetInstance()