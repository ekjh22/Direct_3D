#include "DXUT.h"
#include "CSceneManager.h"


CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
	// 포인터 변수들 할당해제
	for (auto iter : m_mapScene)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapScene.clear();
}

void CSceneManager::Update()
{
	// 현재 씬의 값이 존재할 경우 업데이트 함수 호출
	if (m_pCurScene)
		m_pCurScene->Update();

	// 다음 씬의 값이 존재할 경우
	if (m_pNextScene)
	{
		// 현재씬을 초기화해줌
		if (m_pCurScene)
			m_pCurScene->Release();
		OBJECT.ClearObjects(); // 현재 씬의 오브젝트들 초기화
		m_pNextScene->Init();  // 다음 씬을 셋팅해줌
		m_pCurScene = m_pNextScene; // 현재 씬을 다음 씬 값으로 할당해줌
		m_pNextScene = nullptr; // 다음 씬 값 초기화
	}
}

void CSceneManager::Render()
{
	// 현재 씬의 값이 존재할 경우 렌더 함수 호출
	if (m_pCurScene)
		m_pCurScene->Render();
}

void CSceneManager::AddScene(string _Key, CScene * _pScene)
{
	// 맵 변수에 값 추가 ~
	m_mapScene.insert(make_pair(_Key, _pScene));
}

void CSceneManager::ChangeScene(string _Key)
{
	// 키 값에 맞는 씬 값 다음 씬 값에 넣어줌
	m_pNextScene = m_mapScene[_Key];
}
