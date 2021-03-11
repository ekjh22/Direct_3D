#pragma once
#include "CComponent.h"

// CObjectManager�� �����ϴ� ������Ʈ�� ����� ���ؼ� ������� �θ� Ŭ����
// Unity�� �ִ� ������Ʈ�� ��ɰ� �����
class CObject
{
	friend class CObjectManager;
public:
	CObject();
	~CObject();

public:
	Tag m_Tag; // �ڽ��� �±�
	CScheduleAdmin * sa = nullptr; // �ش� ������Ʈ�� ������
	CTransform * tf = nullptr; // �ش� ������Ʈ�� Ʈ������

	CObject * m_pParent = nullptr; // �ش� ������Ʈ�� �θ� ������Ʈ
private:
	list<CComponent *> m_listComponent; // �ش� ������Ʈ�� ������Ʈ��
	
	list<CObject *> m_listChilds; // �ش� ������Ʈ�� �ڽ� ������Ʈ��

	bool m_bDestroy = false; // ������Ʈ�� �ı��Ǿ��°� ?
	bool m_bStart = false; // ������Ʈ�� �����Ͽ��°� ?

public:
	// �ڽ� ������Ʈ ��������
	list<CObject *>& GetChilds() { return m_listChilds; }

	// �ڽ� ������Ʈ �߰�
	void AddChild(CObject * _pChild)
	{
		m_listChilds.push_back(_pChild);
		_pChild->m_pParent = this;
	}

	// �θ� ������Ʈ ����
	void SetParent(CObject * _pParent)
	{
		m_pParent = _pParent;
		_pParent->m_listChilds.push_back(this);
	}

	// ������Ʈ �ı��ϱ�
	void Destroy()
	{
		m_bDestroy = true;
		for (auto iter : m_listChilds)
		{
			iter->m_bDestroy = true;
		}
		if (m_pParent)
			for (auto iter = m_pParent->m_listChilds.begin(); iter != m_pParent->m_listChilds.end(); )
			{
				if ((*iter) == this)
				{
					iter = m_pParent->m_listChilds.erase(iter);
				}
				else iter++;
			}
	}
	template<class T>
	T* ac() // AddComponent
	{
		if (gc<T>()) return gc<T>();

		CComponent * pComponent = new T();
		
		pComponent->tf = tf;

		pComponent->go = this;

		pComponent->Awake();

		m_listComponent.push_back(pComponent);

		return (T*)pComponent;
	}


	template<class T>
	T* gc() // GetComponent
	{
		for (auto iter : m_listComponent)
		{
			if (dynamic_cast<T*>(iter) != nullptr)
				return (T*)iter;
		}
		return nullptr;
	}
};

