#pragma once
#include "CComponent.h"

class CPlayer :
    public CComponent
{
public:
	CPlayer();
	~CPlayer();

public:
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnRender() override;
	virtual void OnDestroy() override;
	virtual void OnCollisionEnter(CObject* _pObj) override;
	virtual void OnCollisionStay(CObject* _pObj) override;
	virtual void OnCollisionExit(CObject* _pObj) override;

public:
	void Move();
	void Draw();

public:
	bool m_draw = false;
};

