#include "DXUT.h"
#include "CGraphicsManager.h"


CGraphicsManager::CGraphicsManager()
{
	D3DXCreateSprite(g_Device, &m_pSprite); // m_pSprite�� �Ҵ�
	D3DXCreateFont(g_Device, 40, 0, 0, 1, 0, HANGUL_CHARSET, 0, 0, 0, L"Impact", &m_pFont); // m_pFont�� �Ҵ� L"Impact" �κ��� ��Ʈ
}

CGraphicsManager::~CGraphicsManager()
{
	// ����� ������ ������ �ʱ�ȭ
	for (auto iter : m_mapSprite)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapSprite.clear();

	SAFE_RELEASE(m_pFont);
	SAFE_RELEASE(m_pSprite);
}

void CGraphicsManager::OnResetDevice()
{
	// ����̽� ����
	m_pSprite->OnResetDevice();
	m_pFont->OnResetDevice();
}

void CGraphicsManager::OnLostDevice()
{
	// ����̽� ����
	m_pFont->OnLostDevice();
	m_pSprite->OnLostDevice();
}

void CGraphicsManager::Begin()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
}

void CGraphicsManager::End()
{
	m_pSprite->End();
}

CSprite * CGraphicsManager::FindSprite(string _Key)
{
	// �ش� Ű���� �ʺ����� �ִ��� üũ
	auto find = m_mapSprite.find(_Key);

	// ���࿡ �ִٸ� �� ������ second���� Sprite���� ��ȯ
	if (find != m_mapSprite.end())
		return find->second;

	// ���ٸ� nullptr���� ��ȯ
	return nullptr;
}

CSprite * CGraphicsManager::AddSprite(string _Key, string _Path)
{
	// ���� ������ �Լ��� ���� �ش� Ű ���� �ִ��� üũ
	if (FindSprite(_Key))
	{
		// Ű���� �����Ѵٸ� Ű ���� �´� ��������Ʈ�� ��ȯ
		return FindSprite(_Key);
	}

	// ��������Ʈ ���� �����ϴ� �κ� (�ܿ켼�� ~)
	LPDIRECT3DTEXTURE9 pTexture; // �ؽ��� ����
	D3DXIMAGE_INFO info; // �ؽ��� ���� ����
	if (S_OK ==
		D3DXCreateTextureFromFileExA(
			g_Device,
			_Path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			0,
			0,
			D3DFMT_A8B8G8R8,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&info,
			nullptr,
			&pTexture))
	{ // D3DXCreateTextureFromFileExA �Լ� : pTexture�� info ������ _Path���� �ִ� ��ο� ���󰡼� �� ��������Ʈ �̹����� ������ ���� ������ �Ҵ����ִ� �Լ�
		CSprite * pSprite = new CSprite(); // ��������Ʈ ����
		pSprite->m_pTexture = pTexture;    // ��������Ʈ ������ �ִ� m_pTexture�� �Ʊ� �Լ��� ���� �Ҵ���� pTexture ���� �־���
		pSprite->m_Info = info;			   // ��������Ʈ ������ �ִ� m_Info�� �Ʊ� �Լ��� ���� �Ҵ���� info ���� �־���
		
		m_mapSprite.insert(make_pair(_Key, pSprite)); // �� ������ �Ҵ�����

		return pSprite; // ��������Ʈ�� ��ȯ
	}
	return nullptr; // �Ҵ� ���������� nullptr
}

void CGraphicsManager::Render_Sprite(CSprite * _pSprite, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color, RenderMode _RenderMode)
{
	// ���Ͱ� �� ��Ʈ�� ����
	Vec2 vCenter = Vec2(_pSprite->GetWidth() * _pSprite->m_vAnchor.x, _pSprite->GetHeight() * _pSprite->m_vAnchor.y);
	
	D3DXMatrixTransformation2D(&m_mat, &vCenter, 0, &_Scale, &vCenter, D3DXToRadian(_Rot), &(_Pos - vCenter));
	m_mat *= CAMERA.m_matInversed;
	if (_RenderMode == RenderMode::UI)
		m_mat._43 = 0.1;
	else
		m_mat._43 = 0.5;
	// ������� ����

	m_pSprite->SetTransform(&m_mat); // ���� ��Ŀ� ���� ��������Ʈ �׷��� ��ġ�� ����
	// �׷��ִ� �Լ�
	m_pSprite->Draw(
		_pSprite->m_pTexture,
		nullptr,
		nullptr,
		nullptr,
		_Color
	);

	// �׸��� ����
	//m_pSprite->End();
}

void CGraphicsManager::Render_Font(string _string, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color, RenderMode _RenderMode)
{
	D3DXMatrixTransformation2D(&m_mat, NULL, 0, &_Scale, NULL, D3DXToRadian(_Rot), &(_Pos));
	
	// ������� ���� (�׸��� ����)
	D3DXMatrixTransformation2D(&m_mat, NULL, 0, &_Scale, NULL, D3DXToRadian(_Rot), &(_Pos));
	m_mat *= CAMERA.m_matInversed;
	if (_RenderMode == RenderMode::UI)
		m_mat._43 = 0.1;
	else
		m_mat._43 = 1;
	// ������� ����

	m_pSprite->SetTransform(&m_mat); // ���� ��Ŀ� ���� ��������Ʈ �׷��� ��ġ�� ����
	// �׷��ִ� �Լ�
	m_pFont->DrawTextA(
		m_pSprite,
		_string.c_str(),
		_string.length(),
		nullptr,
		DT_CENTER | DT_NOCLIP,
		_Color
	);

	// �׸��� ����
	m_pSprite->End();
}
