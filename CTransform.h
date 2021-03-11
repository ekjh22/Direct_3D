#pragma once
#include "CComponent.h"

// Unity의 Transform과 비슷함
// 오브젝트의 위치값을 회전값 크기값을 사용하기 편리하게 해주는 컴포넌트
class CTransform :
	public CComponent
{
public:
	CTransform();
	~CTransform();

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
	Vec2 m_vPos; // 위치값
	Vec2 m_vScale; // 크기값
	float m_vRot; // 회전값

public:
	// 자신의 월드좌표를 받아옴
	// 월드좌표 : 해당 프로그램에서 사용되는 좌표 ( ex : 방의 좌표 )
	// 로컬좌표 : 해당 프로그램에 있는 자신의 부모 오브젝트에 따라 변하는 좌표 ( ex : 방에 있는 침대의 좌표 [방이 부모, 방이 움직이면 침대도 같이 움직임] )
	Vec2 GetWorldPos()
	{
		if (go->m_pParent)
			return m_vPos + go->m_pParent->tf->m_vPos;
		return m_vPos;
	}
};

