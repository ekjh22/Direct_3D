#pragma once
#include "CSingleton.h"

// DXUT���� �����ϴ� ī�޶� �Լ��� �̿��ؼ� Unity�� �ִ� ī�޶� ó�� ����� �� �ֵ��� �����ִ� �Ŵ���
// ��� ������ �ʿ� ���� �ǹ̸� �����ϰ� ������ �� ���⿡ ���� �𸣴� �ܾ���� �˻��غ��� ����
class CCameraManager :
	public CSingleton< CCameraManager>
{
public:
	CCameraManager();
	~CCameraManager();

public:
	Matrix m_matView; // �� ��� ī�޶� ���� ������ �ش���
	Matrix m_matInversed;

	Vec2  m_vPos;	// ī�޶��� ��ġ��
	float m_Scale;
	float m_ScaleTo;

	Vec2  m_vShakePos;
	float m_ShakeForce;
	float m_ShakeTime;
public:
	// ��� �����
	void SetTransform();

	// �� �����Ӹ��� ����Ǵ� �Լ�
	void Update();

	void SetScale(float _Scale);
};

#define CAMERA (*CCameraManager::GetInstance())

