#pragma once
#include "singleton.h"
class GameManager :
    public singleton<GameManager>
{
public:
    GameManager();
    virtual ~GameManager();

    void Init();
    void Update();
};

#define GAME GameManager::GetInstance()