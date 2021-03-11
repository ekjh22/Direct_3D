#include "DXUT.h"
#include "CTitleScene.h"


CTitleScene::CTitleScene()
{
}


CTitleScene::~CTitleScene()
{
}

void CTitleScene::Init()
{
	GAME.Reset();
}

void CTitleScene::Update()
{
	if (INPUT.KeyDown(VK_SPACE))
	{
		SCENE.ChangeScene("GAME");
	}
}

void CTitleScene::Render()
{
}

void CTitleScene::Release()
{
}
