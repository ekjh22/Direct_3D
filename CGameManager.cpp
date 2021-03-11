#include "DXUT.h"
#include "CGameManager.h"

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
}

void CGameManager::Reset()
{
}

void CGameManager::FloodFill(int x, int y)
{
    if (map[y][x] == 0)
    {
        map[y][x] = 2;
        FloodFill(x + 1, y);
        FloodFill(x, y + 1);
        FloodFill(x - 1, y);
        FloodFill(x, y - 1);
    }
}

void CGameManager::PrintFill()
{
	for (int i = 0; i < WINSIZEY; i++)
	{
		for (int j = 0; j < WINSIZEX; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 1)
			{
				RECT r;
				r.left = j - 1;
				r.top = i - 1;
				r.right = j + 1;
				r.bottom = i + 1;

				D3DLOCKED_RECT lr;
				CObject* target = OBJECT.Find(Tag::Black);

				target->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->LockRect(0, &lr, &r, D3DLOCK_DISCARD);
				DWORD* textureColor = (DWORD*)lr.pBits;
				for (int i = (r.right - r.left) * (r.bottom - r.top); i != 0; --i)
				{
					D3DXCOLOR targetPixel = textureColor[i];
					targetPixel.a = 0;

					textureColor[i] = targetPixel;
				}
				target->gc<CSpriteRenderer>()->m_pSprite->m_pTexture->UnlockRect(0);
			}
		}
	}
}
