#include "DXUT.h"
#include "CButton.h"

CButton::CButton()
{
}

CButton::~CButton()
{
}

void CButton::Awake()
{
}

void CButton::Start()
{
}

void CButton::Update()
{
	// ��� : ��ư�� ���콺�� �����ٴ�����
	if (PtInRect(&m_Rect, { (long)INPUT.GetMousePos().x,(long)INPUT.GetMousePos().y }))
	{
		// ������ �ٲ���
		go->gc<CSpriteRenderer>()->m_Color = D3DCOLOR_ARGB(255, 100, 100, 100);
		//tf->m_vScale = Lerp(tf->m_vScale, m_vScale * 1.4f, dt * 4); // ũ�Ⱚ�� �ٲ��ִ� �̺�Ʈ
		//tf->m_vPos = Lerp(tf->m_vPos, m_vPos - Vec3(150, 0, 0), dt * 16); // ��ġ���� �������ִ� �̺�Ʈ
		if (INPUT.KeyDown(VK_LBUTTON)) // Ŭ������ ���
		{
			m_Action(); // ��Ƶδ� �Լ� ����
		}
	}
	else // ���콺�� ���ų� �ƴҰ��
	{
		// ���� ����� �ٲ���
		go->gc<CSpriteRenderer>()->m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);
		//tf->m_vScale = Lerp(tf->m_vScale, m_vScale, dt * 4);
		//tf->m_vPos = Lerp(tf->m_vPos, m_vPos , dt * 16);
	}
}

void CButton::LateUpdate()
{
}

void CButton::OnRender()
{
}

void CButton::OnDestroy()
{
}

void CButton::OnCollisionEnter(CObject * _pObj)
{
}

void CButton::OnCollisionStay(CObject * _pObj)
{
}

void CButton::OnCollisionExit(CObject * _pObj)
{
}

void CButton::Init(Vec2 _vPos, Vec2 _vScale, CSprite * _pSprite, function<void()> _Action)
{
	m_Action = _Action;
	tf->m_vPos =  _vPos;
	m_vPos = _vPos;

	tf->m_vScale = _vScale;
	m_vScale = _vScale;

	// ������带 UI�� �ٲ��ְ� ��Ʈ�� �ڵ� ����
	go->ac<CSpriteRenderer>()->Init(_pSprite, SortingLayer::UI, RenderMode::UI);
	m_Rect = { (LONG)(_vPos.x - (_pSprite->GetWidth() * _vScale.x) / 2.f),
		(LONG)(_vPos.y - (_pSprite->GetHeight() * _vScale.y) / 2.f),
		(LONG)(_vPos.x + (_pSprite->GetWidth() * _vScale.x) / 2.f),
		(LONG)(_vPos.y + (_pSprite->GetHeight() * _vScale.y) / 2.f) };
}
