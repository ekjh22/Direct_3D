#pragma once
#include "CScene.h"

class CGameScene :
    public CScene
{
public:
	CGameScene();
	~CGameScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

