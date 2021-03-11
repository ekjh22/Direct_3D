#include "DXUT.h"
#include "CText.h"


CText::CText()
{
}


CText::~CText()
{
}

void CText::Awake()
{
}

void CText::Start()
{
}

void CText::Update()
{
}

void CText::LateUpdate()
{
}

void CText::OnRender()
{
	if(!m_Text.empty()) // �ؽ�Ʈ�� ������� �������
		GRAPHICS.Render_Font(m_Text, (Vec2)tf->m_vPos, (Vec2)tf->m_vScale, tf->m_vRot, m_Color, m_Mode); // �ؽ�Ʈ�� �׷���
}

void CText::OnDestroy()
{
}

void CText::OnCollisionEnter(CObject * _pObj)
{
}

void CText::OnCollisionStay(CObject * _pObj)
{
}

void CText::OnCollisionExit(CObject * _pObj)
{
}

void CText::Init(string _Text, SortingLayer _Layer, RenderMode _Mode, Color _Color)
{
	m_Text = _Text;
	m_Layer = _Layer;
	m_Mode = _Mode;
	m_Color = _Color;
}
