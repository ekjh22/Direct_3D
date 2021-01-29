#pragma once
#include "Scene.h"
class CGame :
    public Scene
{
public:
	CGame();
	virtual ~CGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
};

