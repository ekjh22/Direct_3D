#pragma once
#include "CRenderer2D.h"

// Unity�� Text ������Ʈ�� �����
// Text�� ������ִ� ������Ʈ
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
	/// �ش� ������Ʈ�� �ʱ�ȭ ���ִ� �Լ� (�ٸ� �ڵ忡�� ����ϱ� ����)
	/// </summary>
	/// <param name="_Text">�� �ؽ�Ʈ</param>
	/// <param name="_Layer">���� ���̾ ���� �� �� �ΰ� ?</param>
	/// <param name="_Mode">�������� � ������ �� �� �ΰ� ?</param>
	/// <param name="_Color">�÷���</param>
	void Init(string _Text, SortingLayer _Layer, RenderMode _Mode, Color _Color = Color(1.f,1.f,1.f,1.f));

	string m_Text; // �ؽ�Ʈ ����
};

