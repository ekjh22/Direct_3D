#pragma once
#include "CComponent.h"

// Unity의 Collider 컴포넌트와 비슷함
// 충돌처리를 체크해주는 컴포넌트
class CCollider :
	public CComponent
{
public:
	CCollider();
	~CCollider();

public:
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnRender() override;
	virtual void OnDestroy() override;
	virtual void OnCollisionEnter(CObject * _pObj) override;
	virtual void OnCollisionStay(CObject * _pObj) override;
	virtual void OnCollisionExit(CObject * _pObj) override;

public:
	/// <summary>
	/// 해당 컴포넌트를 초기화하는 함수
	/// </summary>
	/// <param name="_fRadius">충돌 범위</param>
	void Init(float _fRadius);

public:
	float m_fRadius = 0.f; // 충돌 범위
	map<CCollider*, bool>m_mapCollider; // Collider들을 담아두는 맵 변수
};

