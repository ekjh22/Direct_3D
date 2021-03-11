#pragma once

// ��������Ʈ�� �⺻������ ����ִ� Ŭ����
class CSprite
{
public:
	CSprite();
	~CSprite();

public:
	LPDIRECT3DTEXTURE9 m_pTexture = NULL;
	D3DXIMAGE_INFO m_Info;

	Vec2 m_vAnchor = Vec2(0.5f,0.5f) ;
	Vec2 m_vFillAmount = Vec2(1.f,1.f);

public:
	float GetWidth() { return m_Info.Width; }
	float GetHeight() { return m_Info.Height; }
};

