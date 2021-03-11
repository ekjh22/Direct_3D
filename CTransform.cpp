#include "DXUT.h"
#include "CTransform.h"


CTransform::CTransform()
{
}


CTransform::~CTransform()
{
}

void CTransform::Awake()
{
	// 기본적인 초기화
	m_vPos = Vec2(0, 0);
	m_vRot = 0.f;
	m_vScale = Vec2(1, 1);	
	this->tf = this;
}

void CTransform::Start()
{
}

void CTransform::Update()
{
	go->sa->Update();
}

void CTransform::LateUpdate()
{
}

void CTransform::OnRender()
{
}

void CTransform::OnDestroy()
{
}

void CTransform::OnCollisionEnter(CObject * _pObj)
{
}

void CTransform::OnCollisionStay(CObject * _pObj)
{
}

void CTransform::OnCollisionExit(CObject * _pObj)
{
}

