#pragma once
#include "CSingleton.h"

// 추상 클래스
class CRenderer2D;
class CRenderer3D;
class CCollider;
// 추상 클래스

// 현재 프로그램에 있는 오브젝트들을 렌더 및 충돌처리를 해주는 매니저
class CObjectManager :
	public CSingleton< CObjectManager>
{
public:
	CObjectManager();
	~CObjectManager();

public:

	// list로 하는 이유 ObjectPool 패턴을 사용하지 않아서 연산을 하는데 많은 비용을 소비하기 때문에
	// 비교적 STL에서 연산이 빠른 list를 사용해서 연산 비용을 줄이는 것
	// list가 연산이 빠른 이유는 추가 삭제가 빨라서
	list<CObject *> m_listObject; // 모든 오브젝트들
	list<CRenderer2D *> m_listRenderer2D; // 렌더링 해주는 오브젝트들
	list<CCollider *> m_listCollider; // 충돌처리 해주는 오브젝트들

public:
	// 해당 컴포넌트를 가지고 있는 오브젝트를 오브젝트 매니저에서 렌더링 해줄 수 있도록 가입함
	void RegisterRenderer2D(CRenderer2D * _pRenderer) { m_listRenderer2D.push_back(_pRenderer); }

	// 해당 컴포넌트를 가지고 있는 오브젝트를 오브젝트 매니저에서 렌더링 해줄 수 없도록 가입해제함
	void UnRegisterRenderer2D(CRenderer2D * _pRenderer) { m_listRenderer2D.remove(_pRenderer); }

	// 해당 컴포넌트를 가지고 있는 오브젝트를 오브젝트 매니저에서 충돌처리 해줄 수 있도록 가입함
	void RegisterCollider(CCollider * _pCollider);

	// 해당 컴포넌트를 가지고 있는 오브젝트를 오브젝트 매니저에서 충돌처리 해줄 수 없도록 가입해제함
	void UnRegisterCollider(CCollider * _pCollider);

	// 현재 _pPrev와 _pNext는 충돌했는가 ? 를 판단하는 함수
	bool IsCollision(CCollider * _pPrev, CCollider * _pNext);

public:
	// 태그에 맞는 오브젝트를 추가함
	CObject * AddObject(Tag _Tag = Tag::Untagged);
	
	// 태그에 맞는 오브젝트를 찾음
	CObject * Find(Tag _Tag);

	// 태그에 맞는 오브젝트들을 찾음
	list<CObject *> Finds(Tag _Tag);

public:
	// 매 프레임마다 실행시키는 함수
	void Update();

	// 매 프레임마다 실행시키는 함수
	void Render();

	// 오브젝트 초기화
	void ClearObjects();
};
#define OBJECT (*CObjectManager::GetInstance())

