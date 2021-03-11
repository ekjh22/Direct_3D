#pragma once
#include "CComponent.h"

// Unity에 애니메이션 컴포넌트와 비슷함
// vector변수로 모아둔 sprite변수를 렌더러로 애니메이션처럼 실행시켜주는 컴포넌트
class CAnimation :
	public CComponent
{
public:
	CAnimation();
	~CAnimation();

public:
	virtual void Awake() override;
	virtual void Start() override;
	virtual void Update() override;
	virtual void LateUpdate() override; 
	virtual void OnRender() override; 
	virtual void OnDestroy() override;
	virtual void OnCollisionEnter(CObject * _pObj) override;
	virtual void OnCollisionStay(CObject * _pObj) override;
	virtual void OnCollisionExit(CObject * _pObj) override;

public:
	/// <summary>
	/// 해당 컴포넌트 초기화하는 함수 (다른 코드에서 사용하는 함수)
	/// </summary>
	/// <param name="_Key">스프라이트의 키값</param>
	/// <param name="_fDelay">애니메이션 프레임 넘어가는 딜레이</param>
	/// <param name="_bRepeat">반복할 것인가 ?</param>
	void Init(string _Key, float _fDelay, bool _bRepeat);

private:
	CSpriteRenderer * m_pRenderer = nullptr; // 애니메이션을 사용하는 스프라이트를 그려주는 렌더러
	float m_fDelay;	// 프레임이 넘어가는 딜레이 (틱 단위)
	float m_fTime = 0.f; // 현재 딜레이 타임

	bool m_bRepeat = false; // 반복할 것인가 ?
	int m_iCurFrame = 0; // 현재 프레임 수
	int m_iMaxFrame = 0; // 최대 프레임 수
	vector<CSprite*> m_vecSprite; // 애니메이션에 사용할 스프라이트들을 담아두는 vector변수
};

