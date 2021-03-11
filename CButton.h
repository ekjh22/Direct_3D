#pragma once
#include "CComponent.h"

// Unity의 Button 컴포넌트와 비슷함
// 그 위치에 렉트값에 맞는 부분을 눌렀을 때 함수를 실행시키는 컴포넌트
class CButton :
	public CComponent
{
public:
	CButton();
	~CButton();

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
	/// <param name="_vPos">버튼의 위치</param>
	/// <param name="_vScale">버튼의 크기</param>
	/// <param name="_pSprite">버튼의 이미지</param>
	/// <param name="_Action">버튼에 담아둘 람다함수</param>
	void Init(Vec2 _vPos, Vec2 _vScale, CSprite * _pSprite, function<void()> _Action);

public:
	Vec2 m_vScale; // 크기
	Vec2 m_vPos;   // 위치값
	function<void()> m_Action; // void 자료형 함수를 담아둘 수 있는 변수 (function : 람다식을 간단하게 만든 자료형)
	RECT m_Rect; // Rect값 Rect = 사각형
};

