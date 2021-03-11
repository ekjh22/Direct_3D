#include "DXUT.h"
#include "CBlock.h"

CBlock::CBlock()
{
}

CBlock::~CBlock()
{
}

void CBlock::Awake()
{
	if (go->m_Tag == Tag::White)
		ac<CSpriteRenderer>()->Init(SPRITE("White"), SortingLayer::Default, RenderMode::Default);
	else if (go->m_Tag == Tag::Black)	
		ac<CSpriteRenderer>()->Init(SPRITE("Black"), SortingLayer::Default, RenderMode::Default);

	tf->m_vScale = Vec2(0.1f, 0.1f);
	tf->m_vPos = Vec2(10, 10);
	tf->m_vRot = 0;
}

void CBlock::Start()
{
}

void CBlock::Update()
{
	if (target != NULL && go->m_Tag == Tag::Black)
	{
		/*float length = math::GetLength(tf->m_vPos, target->tf->m_vPos);
		if (length <= 15.f)
		{
			GAME.curNumX = numberX;
			GAME.curNumY = numberY;

			if (target->gc<CPlayer>()->m_draw)
			{
				gc<CSpriteRenderer>()->m_pSprite = SPRITE("White");
				go->m_Tag = Tag::White;

				GAME.map[numberY][numberX] = 1;
			}
		}*/
	}
}

void CBlock::LateUpdate()
{
}

void CBlock::OnRender()
{
}

void CBlock::OnDestroy()
{
}

void CBlock::OnCollisionEnter(CObject* _pObj)
{
}

void CBlock::OnCollisionStay(CObject* _pObj)
{
}

void CBlock::OnCollisionExit(CObject* _pObj)
{
}
