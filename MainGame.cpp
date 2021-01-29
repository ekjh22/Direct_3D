#include "DXUT.h"
#include "MainGame.h"
#include "CLoading.h"
#include "CGame.h"

void MainGame::Init()
{
	ShowCursor(false);

	srand(time(NULL));
	
	SCENE->AddScene(L"Loading", new CLoading());
	SCENE->AddScene(L"Game", new CGame());

	SCENE->ChangeScene(L"Loading");
	GAME->Init();
}

void MainGame::Update()
{
	INPUT->Update();
	GAME->Update();
	SCENE->Update();
	if (GAME->isUpdate)
	{
		COLLISION->Update();
		CAMERA->Update();
	}
}

void MainGame::Render()
{
	CAMERA->SetTransform();

	IMAGE->Begin(false, false);
	SCENE->Render();

	IMAGE->End();
}

void MainGame::Destroy()
{
	CameraManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	//SoundManager::ReleaseInstance();
	CollisionManager::ReleaseInstance();
	GameManager::ReleaseInstance();
	FXManager::ReleaseInstance();

	ShowCursor(true);
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDeivce()
{
	IMAGE->ResetDevice();
}
