#include "DXUT.h"
#include "CGame.h"
#include "CPlayer.h"

CGame::CGame()
{
}

CGame::~CGame()
{
}

void CGame::Init()
{
	DEBUG_LOG("���Ӿ�");
	ObjectAdd(ObjectTag::PLAYER, CPlayer());
}

void CGame::Update()
{
}

void CGame::Render()
{
}

void CGame::Destroy()
{
}
