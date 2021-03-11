#pragma once
#include "CComponent.h"

// Unity�� Transform�� �����
// ������Ʈ�� ��ġ���� ȸ���� ũ�Ⱚ�� ����ϱ� ���ϰ� ���ִ� ������Ʈ
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
	Vec2 m_vPos; // ��ġ��
	Vec2 m_vScale; // ũ�Ⱚ
	float m_vRot; // ȸ����

public:
	// �ڽ��� ������ǥ�� �޾ƿ�
	// ������ǥ : �ش� ���α׷����� ���Ǵ� ��ǥ ( ex : ���� ��ǥ )
	// ������ǥ : �ش� ���α׷��� �ִ� �ڽ��� �θ� ������Ʈ�� ���� ���ϴ� ��ǥ ( ex : �濡 �ִ� ħ���� ��ǥ [���� �θ�, ���� �����̸� ħ�뵵 ���� ������] )
	Vec2 GetWorldPos()
	{
		if (go->m_pParent)
			return m_vPos + go->m_pParent->tf->m_vPos;
		return m_vPos;
	}
};

