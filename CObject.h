#pragma once
#include "CComponent.h"

// CObjectManager가 관리하는 오브젝트를 만들기 위해서 만들어진 부모 클래스
// Unity에 있는 오브젝트의 기능과 비슷함
class CObject
{
	friend class CObjectManager;
public:
	CObject();
	~CObject();

public:
	Tag m_Tag; // 자신의 태그
	CScheduleAdmin * sa = nullptr; // 해당 오브젝트의 스케쥴
	CTransform * tf = nullptr; // 해당 오브젝트의 트랜스폼

	CObject * m_pParent = nullptr; // 해당 오브젝트의 부모 오브젝트
private:
	list<CComponent *> m_listComponent; // 해당 오브젝트의 컴포넌트들
	
	list<CObject *> m_listChilds; // 해당 오브젝트의 자식 오브젝트들

	bool m_bDestroy = false; // 오브젝트가 파괴되었는가 ?
	bool m_bStart = false; // 오브젝트가 시작하였는가 ?

public:
	// 자식 오브젝트 가져오기
	list<CObject *>& GetChilds() { return m_listChilds; }

	// 자식 오브젝트 추가
	void AddChild(CObject * _pChild)
	{
		m_listChilds.push_back(_pChild);
		_pChild->m_pParent = this;
	}

	// 부모 오브젝트 설정
	void SetParent(CObject * _pParent)
	{
		m_pParent = _pParent;
		_pParent->m_listChilds.push_back(this);
	}

	// 오브젝트 파괴하기
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

