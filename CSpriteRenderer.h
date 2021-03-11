#pragma once
#include "CRenderer2D.h"

// Unity의 SpriteRenderer와 비슷함
// 스프라이트를 그려주는걸 도와주는 컴포넌트
class CSpriteRenderer :
	public CRenderer2D
{
public:
	CSpriteRenderer();
	~CSpriteRenderer();

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
	/// 해당 컴포넌트를 초기화 해주는 함수 (다른 코드에서 사용하기 위함)
	/// </summary>
	/// <param name="_pSprite">그려줄 스프라이트</param>
	/// <param name="_Layer">현재 레이어는 어디로 할 것 인가 ?</param>
	/// <param name="_Mode">현재 렌더모드는 어떤 것으로 할 것 인가 ?</param>
	void Init(CSprite * _pSprite, SortingLayer _Layer, RenderMode _Mode);

	CSprite * m_pSprite = nullptr; // 그려줄 스프라이트
};

