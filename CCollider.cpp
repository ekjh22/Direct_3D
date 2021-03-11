#include "DXUT.h"
#include "CCollider.h"


CCollider::CCollider()
{
	// 오브젝트 매니저에서 충돌체크 해주는 부분의 기능을 해주도록 가입함
	OBJECT.RegisterCollider(this);
}


CCollider::~CCollider()
{
	// 오브젝트 매니저에서 충돌체크 해주는 부분의 기능을 해주도록 가입해제함
	OBJECT.UnRegisterCollider(this);
}

void CCollider::Awake()
{
}

void CCollider::Start()
{
}

void CCollider::Update()
{
}

void CCollider::LateUpdate()
{
}

void CCollider::OnRender()
{
}

void CCollider::OnDestroy()
{
}

void CCollider::OnCollisionEnter(CObject * _pObj)
{
}

void CCollider::OnCollisionStay(CObject * _pObj)
{
}

void CCollider::OnCollisionExit(CObject * _pObj)
{
}

void CCollider::Init(float _fRadius)
{
	m_fRadius = _fRadius;
}
