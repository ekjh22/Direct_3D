#include "DXUT.h"
#include "CGameScene.h"

CGameScene::CGameScene()
{
}

CGameScene::~CGameScene()
{
}

void CGameScene::Init()
{
	CObject* backObj = OBJECT.AddObject(Tag::Black);
	backObj->ac<CSpriteRenderer>()->Init(SPRITE("EX"), SortingLayer::Default, RenderMode::Default);
	backObj->tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	backObj->tf->m_vScale = Vec2(1, 1);

	/*for (int i = 0; i < WINSIZEY / 10; i++)
	{
		for (int j = 0; j < WINSIZEX / 10; j++)
		{
			CObject* blockObj = OBJECT.AddObject(Tag::Black);
			blockObj->ac<CBlock>();

			if (j != 0)
			{
				blockObj->gc<CBlock>()->tf->m_vPos.x = 25 * j;
				blockObj->gc<CBlock>()->tf->m_vPos.y = 25 * i;
			}
			else
			{
				blockObj->gc<CBlock>()->tf->m_vPos.y = 25 * i;
			}
			blockObj->gc<CBlock>()->target = playerObj;
			blockObj->gc<CBlock>()->numberX = j;
			blockObj->gc<CBlock>()->numberY = i;
		}
	}*/
	
	CObject* playerObj = OBJECT.AddObject(Tag::Player);
	playerObj->ac<CPlayer>();
}

void CGameScene::Update()
{
}

void CGameScene::Render()
{
}

void CGameScene::Release()
{
}
