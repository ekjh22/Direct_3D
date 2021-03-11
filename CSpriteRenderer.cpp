#include "DXUT.h"
#include "CSpriteRenderer.h"


CSpriteRenderer::CSpriteRenderer()
{
}


CSpriteRenderer::~CSpriteRenderer()
{
}

void CSpriteRenderer::Awake()
{
}

void CSpriteRenderer::Start()
{
}

void CSpriteRenderer::Update()
{
}

void CSpriteRenderer::LateUpdate()
{
}

void CSpriteRenderer::OnRender()
{
	if(m_pSprite) // 스프라이트가 nullptr이 아닐경우
		GRAPHICS.Render_Sprite(m_pSprite, tf->m_vPos, tf->m_vScale, tf->m_vRot, m_Color, m_Mode); // 그려준다
}

void CSpriteRenderer::OnDestroy()
{
}

void CSpriteRenderer::OnCollisionEnter(CObject * _pObj)
{
}

void CSpriteRenderer::OnCollisionStay(CObject * _pObj)
{
}

void CSpriteRenderer::OnCollisionExit(CObject * _pObj)
{
}

void CSpriteRenderer::Init(CSprite * _pSprite, SortingLayer _Layer, RenderMode _Mode)
{
	m_pSprite = _pSprite;
	m_Layer = _Layer;
	m_Mode = _Mode;
}
