#include "DXUT.h"
#include "CSprite.h"


CSprite::CSprite()
{
}


CSprite::~CSprite()
{
	SAFE_RELEASE(m_pTexture);
}
