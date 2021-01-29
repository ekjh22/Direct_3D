#pragma once
#include <future>
#include "Scene.h"

class CLoading :
    public Scene
{
public:
	thread thr1, thr2, thr3, thr4, thr5, thr6;
	bool thr1B, thr2B, thr3B, thr4B, thr5B, thr6B;
public:
	CLoading();
	virtual ~CLoading();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;

};

