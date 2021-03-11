#include "DXUT.h"
#include "CGraphicsManager.h"


CGraphicsManager::CGraphicsManager()
{
	D3DXCreateSprite(g_Device, &m_pSprite); // m_pSprite값 할당
	D3DXCreateFont(g_Device, 40, 0, 0, 1, 0, HANGUL_CHARSET, 0, 0, 0, L"Impact", &m_pFont); // m_pFont값 할당 L"Impact" 부분이 폰트
}

CGraphicsManager::~CGraphicsManager()
{
	// 사용한 포인터 변수들 초기화
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
	// 디바이스 리셋
	m_pSprite->OnResetDevice();
	m_pFont->OnResetDevice();
}

void CGraphicsManager::OnLostDevice()
{
	// 디바이스 셋팅
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
	// 해당 키값이 맵변수에 있는지 체크
	auto find = m_mapSprite.find(_Key);

	// 만약에 있다면 맵 변수의 second값인 Sprite값을 반환
	if (find != m_mapSprite.end())
		return find->second;

	// 없다면 nullptr값을 반환
	return nullptr;
}

CSprite * CGraphicsManager::AddSprite(string _Key, string _Path)
{
	// 위에 제작한 함수를 통해 해당 키 값이 있는지 체크
	if (FindSprite(_Key))
	{
		// 키값이 존재한다면 키 값에 맞는 스프라이트값 반환
		return FindSprite(_Key);
	}

	// 스프라이트 변수 셋팅하는 부분 (외우세요 ~)
	LPDIRECT3DTEXTURE9 pTexture; // 텍스쳐 변수
	D3DXIMAGE_INFO info; // 텍스쳐 정보 변수
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
	{ // D3DXCreateTextureFromFileExA 함수 : pTexture와 info 변수를 _Path값에 있는 경로에 따라가서 그 스프라이트 이미지의 정보를 토대로 변수를 할당해주는 함수
		CSprite * pSprite = new CSprite(); // 스프라이트 변수
		pSprite->m_pTexture = pTexture;    // 스프라이트 변수에 있는 m_pTexture에 아까 함수를 통해 할당받은 pTexture 값을 넣어줌
		pSprite->m_Info = info;			   // 스프라이트 변수에 있는 m_Info에 아까 함수를 통해 할당받은 info 값을 넣어줌
		
		m_mapSprite.insert(make_pair(_Key, pSprite)); // 맵 변수에 할당해줌

		return pSprite; // 스프라이트값 반환
	}
	return nullptr; // 할당 실패했으면 nullptr
}

void CGraphicsManager::Render_Sprite(CSprite * _pSprite, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color, RenderMode _RenderMode)
{
	// 센터값 및 렉트값 설정
	Vec2 vCenter = Vec2(_pSprite->GetWidth() * _pSprite->m_vAnchor.x, _pSprite->GetHeight() * _pSprite->m_vAnchor.y);
	
	D3DXMatrixTransformation2D(&m_mat, &vCenter, 0, &_Scale, &vCenter, D3DXToRadian(_Rot), &(_Pos - vCenter));
	m_mat *= CAMERA.m_matInversed;
	if (_RenderMode == RenderMode::UI)
		m_mat._43 = 0.1;
	else
		m_mat._43 = 0.5;
	// 렌더모드 셋팅

	m_pSprite->SetTransform(&m_mat); // 월드 행렬에 따라 스프라이트 그려줄 위치값 셋팅
	// 그려주는 함수
	m_pSprite->Draw(
		_pSprite->m_pTexture,
		nullptr,
		nullptr,
		nullptr,
		_Color
	);

	// 그리기 종료
	//m_pSprite->End();
}

void CGraphicsManager::Render_Font(string _string, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color, RenderMode _RenderMode)
{
	D3DXMatrixTransformation2D(&m_mat, NULL, 0, &_Scale, NULL, D3DXToRadian(_Rot), &(_Pos));
	
	// 렌더모드 셋팅 (그리기 시작)
	D3DXMatrixTransformation2D(&m_mat, NULL, 0, &_Scale, NULL, D3DXToRadian(_Rot), &(_Pos));
	m_mat *= CAMERA.m_matInversed;
	if (_RenderMode == RenderMode::UI)
		m_mat._43 = 0.1;
	else
		m_mat._43 = 1;
	// 렌더모드 셋팅

	m_pSprite->SetTransform(&m_mat); // 월드 행렬에 따라 스프라이트 그려줄 위치값 셋팅
	// 그려주는 함수
	m_pFont->DrawTextA(
		m_pSprite,
		_string.c_str(),
		_string.length(),
		nullptr,
		DT_CENTER | DT_NOCLIP,
		_Color
	);

	// 그리기 종료
	m_pSprite->End();
}
