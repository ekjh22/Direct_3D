#include "DXUT.h"
#include "CObjectManager.h"


CObjectManager::CObjectManager()
{
}


CObjectManager::~CObjectManager()
{
	// 할당된 포인터 변수들 초기화
	for (auto iter : m_listObject)
	{
		SAFE_DELETE(iter);
	}
	m_listObject.clear();
}

void CObjectManager::RegisterCollider(CCollider * _pCollider)
{
	m_listCollider.push_back(_pCollider); // list 변수에 추가
}

void CObjectManager::UnRegisterCollider(CCollider * _pCollider)
{
	m_listCollider.remove(_pCollider); // list 변수에서 삭제
}

bool CObjectManager::IsCollision(CCollider * _pPrev, CCollider * _pNext)
{
	// 충돌했으면 true 아니면 false 반환
	return GetLength(_pPrev->tf->GetWorldPos(), _pNext->tf->GetWorldPos()) < _pPrev->m_fRadius + _pNext->m_fRadius;
}

CObject * CObjectManager::AddObject(Tag _Tag)
{
	CObject * pObject = new CObject(); // 오브젝트 변수 선언 및 할당
	pObject->m_Tag = _Tag; // 태그 셋팅
	pObject->tf = pObject->ac<CTransform>(); // 트랜스폼 추가
	pObject->tf->tf = pObject->tf; // 트랜스폼 설정

	m_listObject.push_back(pObject); // 오브젝트 리스트에 추가
	return pObject; // 반환
}

CObject * CObjectManager::Find(Tag _Tag)
{
	// 범위기반 반복문 foreach와 동일한 기능 m_listObject를 begin부터end까지 탐색하는 기능
	// auto는 자동으로 형변환을 해주는 반환자 컴파일러가 auto iter : m_listObject라면 iter의 반환자는 CObject* / auto test = 1 이라면 test의 반환자는 int
	for (auto iter : m_listObject)
	{
		// iter의 태그와 매개변수의 태그가 동일하다면 리턴
		if (iter->m_Tag == _Tag)
			return iter;
	}
	// 아니면 nullptr
	return nullptr;
}

list<CObject*> CObjectManager::Finds(Tag _Tag)
{
	// 하나가아닌 여러개의 오브젝트들을 반환해야하기 때문에 list변수 선언
	list<CObject*> listObject;

	// 범위기반 반복문 foreach와 동일한 기능 m_listObject를 begin부터end까지 탐색하는 기능
	// auto는 자동으로 형변환을 해주는 반환자 컴파일러가 auto iter : m_listObject라면 iter의 반환자는 CObject* / auto test = 1 이라면 test의 반환자는 int
	for (auto iter : m_listObject)
	{
		// iter의 태그와 매개변수의 태그가 동일하다면 추가해줌
		if (iter->m_Tag == _Tag)
		{
			listObject.push_back(iter);
		}
	}
	// listObject를 반환 값이 없다면 nullptr
	return listObject;
}

void CObjectManager::Update()
{
	// 컴포넌트들을 실행시켜주는 부분
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
	// 컴포넌트들을 실행시켜주는 부분

	// 오브젝트들의 충돌처리를 해주는 부분
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
	// 오브젝트들의 충돌처리를 해주는 부분

	// LateUpdate 호출해주는 부분
	for (auto iter : m_listObject)
	{
		for (auto comp : iter->m_listComponent)
		{
			if (comp->m_bEnable)
				comp->LateUpdate();
		}
	}
	// LateUpdate 호출해주는 부분

	// 오브젝트에서 m_bDestroy가 true라면 파괴를 해주는 부분
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
	// 오브젝트에서 m_bDestroy가 true라면 파괴를 해주는 부분
}

void CObjectManager::Render()
{
	//  SortingLayer에 맞게 리스트 변수를 정렬
	m_listRenderer2D.sort([](CRenderer2D * _pPrev, CRenderer2D * _pNext) { return (int)_pPrev->m_Layer < (int)_pNext->m_Layer; });

	// 그 후 렌더링
	for (auto iter : m_listRenderer2D)
	{
		iter->OnRender();
	}
}

void CObjectManager::ClearObjects()
{
	// 오브젝트 초기화~
	for (auto iter : m_listObject)
	{
		// 할당해제
		SAFE_DELETE(iter);
	}
	m_listObject.clear();
}
