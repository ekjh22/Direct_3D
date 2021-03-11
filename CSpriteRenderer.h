#pragma once
#include "CRenderer2D.h"

// Unity�� SpriteRenderer�� �����
// ��������Ʈ�� �׷��ִ°� �����ִ� ������Ʈ
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
	/// �ش� ������Ʈ�� �ʱ�ȭ ���ִ� �Լ� (�ٸ� �ڵ忡�� ����ϱ� ����)
	/// </summary>
	/// <param name="_pSprite">�׷��� ��������Ʈ</param>
	/// <param name="_Layer">���� ���̾�� ���� �� �� �ΰ� ?</param>
	/// <param name="_Mode">���� �������� � ������ �� �� �ΰ� ?</param>
	void Init(CSprite * _pSprite, SortingLayer _Layer, RenderMode _Mode);

	CSprite * m_pSprite = nullptr; // �׷��� ��������Ʈ
};

