#pragma once
#include "CRenderer2D.h"

// Unity의 Text 컴포넌트와 비슷함
// Text를 출력해주는 컴포넌트
class CText :
	public CRenderer2D
{
public:
	CText();
	~CText();

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
	/// <param name="_Text">쓸 텍스트</param>
	/// <param name="_Layer">현재 레이어를 어디로 할 것 인가 ?</param>
	/// <param name="_Mode">렌더모드는 어떤 것으로 할 것 인가 ?</param>
	/// <param name="_Color">컬러값</param>
	void Init(string _Text, SortingLayer _Layer, RenderMode _Mode, Color _Color = Color(1.f,1.f,1.f,1.f));

	string m_Text; // 텍스트 내용
};

