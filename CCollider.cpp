#include "DXUT.h"
#include "CCollider.h"


CCollider::CCollider()
{
	// ������Ʈ �Ŵ������� �浹üũ ���ִ� �κ��� ����� ���ֵ��� ������
	OBJECT.RegisterCollider(this);
}


CCollider::~CCollider()
{
	// ������Ʈ �Ŵ������� �浹üũ ���ִ� �κ��� ����� ���ֵ��� ����������
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
