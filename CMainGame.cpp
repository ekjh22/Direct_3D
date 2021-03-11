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
	// �̰����� �⺻������ ���� �߰�����
	SCENE.AddScene("LOAD", new CLoadScene());
	SCENE.AddScene("TITEL", new CTitleScene());
	SCENE.AddScene("GAME", new CGameScene());

	// �ؽ��ĸ� �ε��ؾ��ϱ� ������ �ε������� ������
	SCENE.ChangeScene("LOAD");
}

void CMainGame::Update()
{
	// �Ŵ����� ������Ʈ �Լ� ȣ��

	INPUT.Update();

	OBJECT.Update();

	CAMERA.Update();
	
	SCENE.Update();
}

void CMainGame::Render()
{
	// �Ŵ����� ���� �Լ� ȣ��
	GRAPHICS.Begin();

	CAMERA.SetTransform();

	OBJECT.Render();

	SCENE.Render();
	
	GRAPHICS.End();
}

void CMainGame::Release()
{
	// �̱������� ������� �ν��Ͻ��� �ʱ�ȭ
	CObjectManager::ReleaseInstance();
	CSceneManager::ReleaseInstance();
	CCameraManager::ReleaseInstance();
	CInputManager::ReleaseInstance();
	CGraphicsManager::ReleaseInstance();
	CGameManager::ReleaseInstance();
}

void CMainGame::OnResetDevice()
{
	// �̱������� ������� �ν��Ͻ��� �ʱ�ȭ

	GRAPHICS.ReleaseInstance();
}

void CMainGame::OnLostDevice()
{
	// �̱������� ������� �ν��Ͻ��� �ʱ�ȭ

	GRAPHICS.OnLostDevice();
}
