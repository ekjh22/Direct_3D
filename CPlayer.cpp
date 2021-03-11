#include "DXUT.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
	srand(time(nullptr));
}

CPlayer::~CPlayer()
{
}

void CPlayer::Awake()
{
	ac<CSpriteRenderer>()->Init(SPRITE("Player"), SortingLayer::UI, RenderMode::Default);
	tf->m_vScale = Vec2(0.1f, 0.1f);
	tf->m_vPos = Vec2(WINSIZEX / 2, WINSIZEY / 2);
	tf->m_vRot = 0;
}

void CPlayer::Start()
{
}

void CPlayer::Update()
{
	// 업데이트 함수는 최대한 깔끔하게
	Move();
}

void CPlayer::LateUpdate()
{
}

void CPlayer::OnRender()
{
}

void CPlayer::OnDestroy()
{
}

void CPlayer::OnCollisionEnter(CObject* _pObj)
{
}

void CPlayer::OnCollisionStay(CObject* _pObj)
{
}

void CPlayer::OnCollisionExit(CObject* _pObj)
{
}

void CPlayer::Move()
{
	if (m_draw)
	{
		RECT r;
		r.left = tf->m_vPos.x - 1;
		r.top = tf->m_vPos.y - 1;
		r.right = tf->m_vPos.x + 1;
		r.bottom = tf->m_vPos.y + 1;

		D3DLOCKED_RECT lr;
		CObject* target = OBJECT.Find(Tag::Black);

		target->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->LockRect(0, &lr, &r, D3DLOCK_DISCARD);
		DWORD* textureColor = (DWORD*)lr.pBits;
		for (int i = (r.right - r.left) * (r.bottom - r.top); i != 0; --i)
		{
			D3DXCOLOR targetPixel = textureColor[i];
			targetPixel.r = 0;
			targetPixel.g = 0;
			targetPixel.b = 0;

			textureColor[i] = targetPixel;
			GAME.map[r.top + 1][r.left + 1] = 1;
			//GAME.map[r.bottom][r.right] = 1;

			/*GAME.curNumX = r.left + i;
			GAME.curNumY = r.top + i;*/
		}
		target->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->UnlockRect(0);
	}

	Vec2 vDir = Vec2(0, 0);
	if (INPUT.KeyPress(VK_UP))
		vDir.y = -1;
	else if (INPUT.KeyPress(VK_DOWN))
		vDir.y = 1;
	else if (INPUT.KeyPress(VK_LEFT))
		vDir.x = -1;
	else if (INPUT.KeyPress(VK_RIGHT))
		vDir.x = 1;

	tf->m_vPos += Vec2(vDir.x, vDir.y);

	if (INPUT.KeyDown('Q'))
		m_draw = true;
	if (INPUT.KeyUp('Q'))
		m_draw = false;

	if (INPUT.KeyDown('Z'))
	{
		GAME.curNumX = tf->m_vPos.x;
		GAME.curNumY = tf->m_vPos.y;
	}

	if (INPUT.KeyDown('P'))
		GAME.PrintFill();
	if (INPUT.KeyDown('F'))
		GAME.FloodFill(GAME.curNumX, GAME.curNumY);
}

void CPlayer::Draw()
{
	if (INPUT.KeyDown('Q'))
	{
		m_draw = true;
	}
	if (INPUT.KeyUp('Q'))
	{
		m_draw = false;
	}

	if (INPUT.KeyDown('E'))
		GAME.PrintFill();

	if (INPUT.KeyDown('R'))
	{
		GAME.FloodFill(GAME.curNumX, GAME.curNumY);
	}
}
