#pragma once
#include "CComponent.h"

// Unity�� �ִϸ��̼� ������Ʈ�� �����
// vector������ ��Ƶ� sprite������ �������� �ִϸ��̼�ó�� ��������ִ� ������Ʈ
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
	/// �ش� ������Ʈ �ʱ�ȭ�ϴ� �Լ� (�ٸ� �ڵ忡�� ����ϴ� �Լ�)
	/// </summary>
	/// <param name="_Key">��������Ʈ�� Ű��</param>
	/// <param name="_fDelay">�ִϸ��̼� ������ �Ѿ�� ������</param>
	/// <param name="_bRepeat">�ݺ��� ���ΰ� ?</param>
	void Init(string _Key, float _fDelay, bool _bRepeat);

private:
	CSpriteRenderer * m_pRenderer = nullptr; // �ִϸ��̼��� ����ϴ� ��������Ʈ�� �׷��ִ� ������
	float m_fDelay;	// �������� �Ѿ�� ������ (ƽ ����)
	float m_fTime = 0.f; // ���� ������ Ÿ��

	bool m_bRepeat = false; // �ݺ��� ���ΰ� ?
	int m_iCurFrame = 0; // ���� ������ ��
	int m_iMaxFrame = 0; // �ִ� ������ ��
	vector<CSprite*> m_vecSprite; // �ִϸ��̼ǿ� ����� ��������Ʈ���� ��Ƶδ� vector����
};

