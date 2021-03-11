#pragma once

// �߻� Ŭ���� : �ش� Ŭ������ �ִٰ� ������ �� �ڷ����� �Լ��� ����� �� ����
class CTransform; 
class CObject;

// Unity���� ����ϴ� Component ���ϰ� �����
// ������Ʈ ������ ���ۿ� "C++ Coponent Pattern"�� �˻��غ��°� ��õ��
class CComponent
{
public:
	CComponent();
	virtual ~CComponent();

public:
	// virtual �� PURE�� ���� ���̸� ���������Լ���
	// �Ϲ����� �����Լ��� �������� ���������� ���������Լ��� �������� �پ� PUREŰ���尡 �پ��ٸ�
	// ����� ���� �� ������ �������������

	// ���� ��ó���� ����Ǵ� �Լ� ( ����ϴ� ����? : �⺻���� ���� ���� )
	virtual void Awake() PURE;

	// Awake�Ŀ� ����Ǵ� �Լ� ( ����ϴ� ����? : ������Ʈ ���� �� ���õ� ������ �̿��ϴ� ���� ���ôܰ� )
	virtual void Start() PURE;

	// �� �����Ӹ��� ��� ����Ǵ� �Լ� ( ����ϴ� ����? : �������� �κ��� �� �� ����� )
	virtual void Update() PURE;
	
	// Update�� ȣ��� �� �� �����Ӹ��� ��� ����Ǵ� �Լ� ( ����ϴ� ����? : Update�� ����� �� ����� �������� �κ��� �� �� ����� )
	virtual void LateUpdate() PURE;

	// �� �����Ӹ��� ��� ����Ǵ� �Լ� ( ����ϴ� ���� : �׷������� �κ��� �� �� ����� )
	virtual void OnRender() PURE;

	// �ı��� �� ȣ��Ǵ� �Լ� ( ����ϴ� ���� : �Ҵ�� ���� �������� �� ��� ���������� �ʰ� ��� ���α׷��� ��������ָ� �޸� ������ �߻��� ���α׷��� ���峯 �� ���� )
	virtual void OnDestroy() PURE;

	// �ݶ��̴��� ������ ��� �ش� _pObj�� �ش� ������Ʈ�� �浹���� �� ����� �ڵ带 ���� �Լ�
	virtual void OnCollisionEnter(CObject * _pObj) PURE;

	// �ݶ��̴��� ������ ��� �ش� _pObj�� �ش� ������Ʈ�� �浹���� �� ����� �ڵ带 ���� �Լ�
	virtual void OnCollisionStay(CObject * _pObj) PURE;

	// �ݶ��̴��� ������ ��� �ش� _pObj�� �ش� ������Ʈ�� �浹�� ������ �� ����� �ڵ带 ���� �Լ�
	virtual void OnCollisionExit(CObject * _pObj) PURE;

public:
	bool m_bEnable = true; // ���� ������ΰ� ?

	CTransform * tf = nullptr; // ������Ʈ�� �⺻���� �ڽ��� Ʈ������ ��ġ�� ( Unity���� �� ������Ʈ�� �����ϸ� �⺻������ Ʈ������ ������Ʈ�� ���� )
	CObject * go = nullptr; // ������Ʈ�� �⺻���� �ڱ� �ڽ��� ����Ű�� ������Ʈ ( Unity���� �����ϴ� ���͵��� ������Ʈ�̱� ������ ������ [ C++�� this, Unity�� gameObject�� �Ȱ��� ] )

	// AddComponent : �ڽ��� ������Ʈ�� �߰���
	template<class T>
	T* ac()
	{
		return go->ac<T>();
	}

	// GetComponent : �ڽ��� ������Ʈ�� ������
	template<class T>
	T* gc()
	{
		return go->gc<T>();
	}
};

