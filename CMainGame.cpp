#include "DXUT.h"
#include "CMainGame.h"
#include "CLoadScene.h"
#include "CTitleScene.h"
#include "CGameScene.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Init()
{
	// 이곳에선 기본적으로 씬을 추가해줌
	SCENE.AddScene("LOAD", new CLoadScene());
	SCENE.AddScene("TITEL", new CTitleScene());
	SCENE.AddScene("GAME", new CGameScene());

	// 텍스쳐를 로드해야하기 때문에 로딩씬으로 먼저감
	SCENE.ChangeScene("LOAD");
}

void CMainGame::Update()
{
	// 매니저들 업데이트 함수 호출

	INPUT.Update();

	OBJECT.Update();

	CAMERA.Update();
	
	SCENE.Update();
}

void CMainGame::Render()
{
	// 매니저들 렌더 함수 호출
	GRAPHICS.Begin();

	CAMERA.SetTransform();

	OBJECT.Render();

	SCENE.Render();
	
	GRAPHICS.End();
}

void CMainGame::Release()
{
	// 싱글톤으로 만들어진 인스턴스들 초기화
	CObjectManager::ReleaseInstance();
	CSceneManager::ReleaseInstance();
	CCameraManager::ReleaseInstance();
	CInputManager::ReleaseInstance();
	CGraphicsManager::ReleaseInstance();
	CGameManager::ReleaseInstance();
}

void CMainGame::OnResetDevice()
{
	// 싱글톤으로 만들어진 인스턴스들 초기화

	GRAPHICS.ReleaseInstance();
}

void CMainGame::OnLostDevice()
{
	// 싱글톤으로 만들어진 인스턴스들 초기화

	GRAPHICS.OnLostDevice();
}
