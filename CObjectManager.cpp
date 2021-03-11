#include "DXUT.h"
#include "CObjectManager.h"


CObjectManager::CObjectManager()
{
}


CObjectManager::~CObjectManager()
{
	// �Ҵ�� ������ ������ �ʱ�ȭ
	for (auto iter : m_listObject)
	{
		SAFE_DELETE(iter);
	}
	m_listObject.clear();
}

void CObjectManager::RegisterCollider(CCollider * _pCollider)
{
	m_listCollider.push_back(_pCollider); // list ������ �߰�
}

void CObjectManager::UnRegisterCollider(CCollider * _pCollider)
{
	m_listCollider.remove(_pCollider); // list �������� ����
}

bool CObjectManager::IsCollision(CCollider * _pPrev, CCollider * _pNext)
{
	// �浹������ true �ƴϸ� false ��ȯ
	return GetLength(_pPrev->tf->GetWorldPos(), _pNext->tf->GetWorldPos()) < _pPrev->m_fRadius + _pNext->m_fRadius;
}

CObject * CObjectManager::AddObject(Tag _Tag)
{
	CObject * pObject = new CObject(); // ������Ʈ ���� ���� �� �Ҵ�
	pObject->m_Tag = _Tag; // �±� ����
	pObject->tf = pObject->ac<CTransform>(); // Ʈ������ �߰�
	pObject->tf->tf = pObject->tf; // Ʈ������ ����

	m_listObject.push_back(pObject); // ������Ʈ ����Ʈ�� �߰�
	return pObject; // ��ȯ
}

CObject * CObjectManager::Find(Tag _Tag)
{
	// ������� �ݺ��� foreach�� ������ ��� m_listObject�� begin����end���� Ž���ϴ� ���
	// auto�� �ڵ����� ����ȯ�� ���ִ� ��ȯ�� �����Ϸ��� auto iter : m_listObject��� iter�� ��ȯ�ڴ� CObject* / auto test = 1 �̶�� test�� ��ȯ�ڴ� int
	for (auto iter : m_listObject)
	{
		// iter�� �±׿� �Ű������� �±װ� �����ϴٸ� ����
		if (iter->m_Tag == _Tag)
			return iter;
	}
	// �ƴϸ� nullptr
	return nullptr;
}

list<CObject*> CObjectManager::Finds(Tag _Tag)
{
	// �ϳ����ƴ� �������� ������Ʈ���� ��ȯ�ؾ��ϱ� ������ list���� ����
	list<CObject*> listObject;

	// ������� �ݺ��� foreach�� ������ ��� m_listObject�� begin����end���� Ž���ϴ� ���
	// auto�� �ڵ����� ����ȯ�� ���ִ� ��ȯ�� �����Ϸ��� auto iter : m_listObject��� iter�� ��ȯ�ڴ� CObject* / auto test = 1 �̶�� test�� ��ȯ�ڴ� int
	for (auto iter : m_listObject)
	{
		// iter�� �±׿� �Ű������� �±װ� �����ϴٸ� �߰�����
		if (iter->m_Tag == _Tag)
		{
			listObject.push_back(iter);
		}
	}
	// listObject�� ��ȯ ���� ���ٸ� nullptr
	return listObject;
}

void CObjectManager::Update()
{
	// ������Ʈ���� ��������ִ� �κ�
	for (auto iter : m_listObject)
	{
		if (iter->m_bStart == false)
		{
			iter->m_bStart = true;
			for (auto comp : iter->m_listComponent)
			{
				comp->Start();
			}
		}
		for (auto comp : iter->m_listComponent)
		{
			if (comp->m_bEnable)
				comp->Update();
		}
	}
	// ������Ʈ���� ��������ִ� �κ�

	// ������Ʈ���� �浹ó���� ���ִ� �κ�
	for (auto iter = m_listCollider.begin(); iter != m_listCollider.end(); iter++)
	{
		if ((*iter)->m_bEnable == true)
			for (auto iter2 = std::next(iter, 1); iter2 != m_listCollider.end(); iter2++)
			{
				if ((*iter2)->m_bEnable == true && (*iter)->go->m_Tag != (*iter2)->go->m_Tag)
					if (IsCollision(*iter, *iter2))
					{
							for (auto comp : (*iter)->go->m_listComponent)
							{
								comp->OnCollisionEnter((*iter2)->go);
							}
							for (auto comp : (*iter2)->go->m_listComponent)
							{
								comp->OnCollisionEnter((*iter)->go);
							}
					}

			}
	}
	// ������Ʈ���� �浹ó���� ���ִ� �κ�

	// LateUpdate ȣ�����ִ� �κ�
	for (auto iter : m_listObject)
	{
		for (auto comp : iter->m_listComponent)
		{
			if (comp->m_bEnable)
				comp->LateUpdate();
		}
	}
	// LateUpdate ȣ�����ִ� �κ�

	// ������Ʈ���� m_bDestroy�� true��� �ı��� ���ִ� �κ�
	for (auto iter = m_listObject.begin(); iter != m_listObject.end(); )
	{
		auto obj = (*iter);

		if (obj->m_bDestroy == true)
		{
			SAFE_DELETE(obj);
			iter = m_listObject.erase(iter);
		}
		else iter++;
	}
	// ������Ʈ���� m_bDestroy�� true��� �ı��� ���ִ� �κ�
}

void CObjectManager::Render()
{
	//  SortingLayer�� �°� ����Ʈ ������ ����
	m_listRenderer2D.sort([](CRenderer2D * _pPrev, CRenderer2D * _pNext) { return (int)_pPrev->m_Layer < (int)_pNext->m_Layer; });

	// �� �� ������
	for (auto iter : m_listRenderer2D)
	{
		iter->OnRender();
	}
}

void CObjectManager::ClearObjects()
{
	// ������Ʈ �ʱ�ȭ~
	for (auto iter : m_listObject)
	{
		// �Ҵ�����
		SAFE_DELETE(iter);
	}
	m_listObject.clear();
}
