#pragma once
#include "CSingleton.h"

// Unity에 SceneManagement와 비슷함
// 씬을 나눠서 게임을 좀 더 어 거시기 좋게 해줌 ( ex : Title, Loading, InGame, Ending ) 이런식으로 게임의 단계를 나눠주도록 도와주는 매니저
class CSceneManager :
	public CSingleton< CSceneManager>
{
public:
	CSceneManager();
	~CSceneManager();

private:
	map<string, CScene *> m_mapScene; // 씬 값을 키 값과 함께 담아두는 맵 변수

	CScene * m_pCurScene = nullptr; // 현재 씬
	CScene * m_pNextScene = nullptr; // 다음 씬
public:
	// 매 프레임마다 실행되는 함수
	void Update();

	// 매 프레임마다 실행되는 함수
	void Render();

	/// <summary>
	/// 맵 변수에 씬을 추가해주는 함수
	/// </summary>
	/// <param name="_Key">키 값 (ex : Title, Loading)</param>
	/// <param name="_pScene">씬 값 (ex : new CLoadScene())</param>
	void AddScene(string _Key, CScene * _pScene);

	/// <summary>
	/// 키 값에 맞게 씬을 교체해주는 함수
	/// </summary>
	/// <param name="_Key">키 값 (ex : Title, Loading)</param>
	void ChangeScene(string _Key);
};

#define SCENE (*CSceneManager::GetInstance())