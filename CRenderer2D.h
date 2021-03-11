#pragma once
#include "CComponent.h"

// 2D �̹����� �������� �����ִ� Ŭ����
class CRenderer2D :
	public CComponent
{
public:
	CRenderer2D();
	virtual ~CRenderer2D();

public:
	virtual void Awake() PURE;
	virtual void Start() PURE;
	virtual void Update() PURE;
	virtual void LateUpdate() PURE;
	virtual void OnRender() PURE;
	virtual void OnDestroy() PURE;
	virtual void OnCollisionEnter(CObject * _pObj) PURE;
	virtual void OnCollisionStay(CObject * _pObj) PURE;
	virtual void OnCollisionExit(CObject * _pObj) PURE;

public:
	Color m_Color = Color(1.f,1.f,1.f,1.f);  // �÷���
	SortingLayer m_Layer; // ���̾�
	RenderMode m_Mode; // �������
};

