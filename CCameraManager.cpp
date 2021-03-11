#include "DXUT.h"
#include "CCameraManager.h"


CCameraManager::CCameraManager()
{
	// 기본적인 카메라 초기화
	m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	m_vShakePos = Vec2(0, 0);
	m_Scale = m_ScaleTo = 1;

	// 투영행렬 뷰행렬 셋팅
	//D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4.f, 16.f/9.f,1.f,10000000000.f); // 왼손좌표계를 기준으로 원근투영행렬을 셋팅함
	//D3DXMatrixLookAtLH(&m_matView, &m_vPos, &m_vLookAt, &m_vUp); // 왼손좌표계를 기준으로 뷰행렬을 셋팅함
}


CCameraManager::~CCameraManager()
{
}

void CCameraManager::SetTransform()
{
	g_Device->SetTransform(D3DTS_VIEW, &m_matView); // 뷰행렬 프로그램에 적용
	//g_Device->SetTransform(D3DTS_PROJECTION, &m_matProj); // 투영행렬 프로그램에 적용
}

void CCameraManager::Update()
{
	if (m_ShakeForce != 0)
	{
		m_ShakeForce -= m_ShakeTime * dt;
		if (m_ShakeForce <= 0)
		{
			m_ShakeForce = 0;
			m_vShakePos = Vec2(0, 0);
		}
		else
		{
			m_vShakePos = Vec2(RandRange(-m_ShakeForce, m_ShakeForce), RandRange(-m_ShakeForce, m_ShakeForce));
		}
	}
	if (m_ScaleTo != m_Scale)
	{
		m_Scale = Lerp<float>(m_Scale, m_ScaleTo, 0.15f * 60.f * dt);
		if (abs(m_Scale - m_ScaleTo) <= 0.001f)
		{
			m_Scale = m_ScaleTo;
		}
	}
	Matrix p, s;
	D3DXMatrixTranslation(&p, -m_vPos.x + WINSIZEX / m_Scale + m_vShakePos.x, -m_vPos.y + WINSIZEY / m_Scale + m_vShakePos.y, 0);
	D3DXMatrixScaling(&s, m_Scale, m_Scale, 1);
	m_matView = p * s;
	D3DXMatrixInverse(&m_matInversed, NULL, &m_matView);

	//D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4.f, 16.f/9.f,1.f,100000000.f); // 왼손좌표계를 기준으로 원근투영행렬을 셋팅함
	//D3DXMatrixLookAtLH(&m_matView, &m_vPos, &m_vLookAt, &m_vUp); // 왼손좌표계를 기준으로 뷰행렬을 셋팅함
}

void CCameraManager::SetScale(float _Scale)
{
	m_Scale = _Scale;
	m_ScaleTo = _Scale;
}
