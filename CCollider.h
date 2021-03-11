#pragma once
#include "CComponent.h"

// Unity�� Collider ������Ʈ�� �����
// �浹ó���� üũ���ִ� ������Ʈ
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
	/// �ش� ������Ʈ�� �ʱ�ȭ�ϴ� �Լ�
	/// </summary>
	/// <param name="_fRadius">�浹 ����</param>
	void Init(float _fRadius);

public:
	float m_fRadius = 0.f; // �浹 ����
	map<CCollider*, bool>m_mapCollider; // Collider���� ��Ƶδ� �� ����
};

