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
	// 요약 : 버튼에 마우스를 가져다댔을때
	if (PtInRect(&m_Rect, { (long)INPUT.GetMousePos().x,(long)INPUT.GetMousePos().y }))
	{
		// 색깔을 바꿔줌
		go->gc<CSpriteRenderer>()->m_Color = D3DCOLOR_ARGB(255, 100, 100, 100);
		//tf->m_vScale = Lerp(tf->m_vScale, m_vScale * 1.4f, dt * 4); // 크기값을 바꿔주는 이벤트
		//tf->m_vPos = Lerp(tf->m_vPos, m_vPos - Vec3(150, 0, 0), dt * 16); // 위치값을 움직여주는 이벤트
		if (INPUT.KeyDown(VK_LBUTTON)) // 클릭했을 경우
		{
			m_Action(); // 담아두는 함수 실행
		}
	}
	else // 마우스를 떼거나 아닐경우
	{
		// 원래 색깔로 바꿔줌
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

	// 렌더모드를 UI로 바꿔주고 렉트값 자동 설정
	go->ac<CSpriteRenderer>()->Init(_pSprite, SortingLayer::UI, RenderMode::UI);
	m_Rect = { (LONG)(_vPos.x - (_pSprite->GetWidth() * _vScale.x) / 2.f),
		(LONG)(_vPos.y - (_pSprite->GetHeight() * _vScale.y) / 2.f),
		(LONG)(_vPos.x + (_pSprite->GetWidth() * _vScale.x) / 2.f),
		(LONG)(_vPos.y + (_pSprite->GetHeight() * _vScale.y) / 2.f) };
}
