#pragma once
#include "CSingleton.h"

// DXUT에서 제공하는 카메라 함수를 이용해서 Unity에 있는 카메라 처럼 사용할 수 있도록 도와주는 매니저
// 깊게 이해할 필요 없고 의미만 이해하고 있으면 됨 여기에 사용된 모르는 단어들은 검색해보면 좋음
class CCameraManager :
	public CSingleton< CCameraManager>
{
public:
	CCameraManager();
	~CCameraManager();

public:
	Matrix m_matView; // 뷰 행렬 카메라가 보는 시점을 해당함
	Matrix m_matInversed;

	Vec2  m_vPos;	// 카메라의 위치값
	float m_Scale;
	float m_ScaleTo;

	Vec2  m_vShakePos;
	float m_ShakeForce;
	float m_ShakeTime;
public:
	// 행렬 재셋팅
	void SetTransform();

	// 매 프레임마다 실행되는 함수
	void Update();

	void SetScale(float _Scale);
};

#define CAMERA (*CCameraManager::GetInstance())

