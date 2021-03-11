#pragma once
#include "CComponent.h"

// Unity�� Button ������Ʈ�� �����
// �� ��ġ�� ��Ʈ���� �´� �κ��� ������ �� �Լ��� �����Ű�� ������Ʈ
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
	/// �ش� ������Ʈ �ʱ�ȭ�ϴ� �Լ� (�ٸ� �ڵ忡�� ����ϴ� �Լ�)
	/// </summary>
	/// <param name="_vPos">��ư�� ��ġ</param>
	/// <param name="_vScale">��ư�� ũ��</param>
	/// <param name="_pSprite">��ư�� �̹���</param>
	/// <param name="_Action">��ư�� ��Ƶ� �����Լ�</param>
	void Init(Vec2 _vPos, Vec2 _vScale, CSprite * _pSprite, function<void()> _Action);

public:
	Vec2 m_vScale; // ũ��
	Vec2 m_vPos;   // ��ġ��
	function<void()> m_Action; // void �ڷ��� �Լ��� ��Ƶ� �� �ִ� ���� (function : ���ٽ��� �����ϰ� ���� �ڷ���)
	RECT m_Rect; // Rect�� Rect = �簢��
};

