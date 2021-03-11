#pragma once
#include "CSingleton.h"

// DXUT에서 제공하는 스프라이트 렌더링 함수를 이용해서 이미지 출력을 할 수 있도록 해주는 매니저
// 깊게 이해할 필요 없고 의미만 이해하고 있으면 됨 여기에 사용된 모르는 단어들은 검색해보면 좋음
class CGraphicsManager
	: public CSingleton<CGraphicsManager>
{
public:
	CGraphicsManager();
	~CGraphicsManager();

public:
	void OnResetDevice(); // 디바이스 리셋
	void OnLostDevice();  // 디바이스 셋팅

	void Begin();
	void End();

private:
	LPD3DXSPRITE m_pSprite = NULL; // 스프라이트 변수 ( 이미지 출력을 도와주는 변수 [프로그램이 도화지 이 변수는 붓같은 개념] )
	LPD3DXFONT m_pFont = NULL; // 폰트 변수 ( 텍스트 출력을 도와주는 변수 [프로그램이 도화지 이 변수는 붓같은 개념] )
	Matrix m_mat;

	map<string, CSprite *> m_mapSprite; // 스프라이트들을 키값에 맞게 담아두는 맵 변수
public:
	/// <summary>
	/// 저장된 맵 변수에서 키 값에 맞는 스프라이트를 찾아주는 함수
	/// </summary>
	/// <param name="_Key">맵 변수에 저장된 스프라이트 키 값</param>
	/// <returns></returns>
	CSprite * FindSprite(string _Key);

	/// <summary>
	/// 해당 주소값에서 스프라이트를 찾아서 해당 맵변수에 키 값과 함께 저장해주는 함수
	/// </summary>
	/// <param name="_Key">맵 변수에 저장할 스프라이트 키 값 (EX : Player1)</param>
	/// <param name="_Path">해당 리소스가 위치하고 있는 주소값 (EX : ./resource/Player1.png)</param>
	/// <returns></returns>
	CSprite * AddSprite(string _Key, string _Path);

	/// <summary>
	/// 스프라이트를 렌더링 해주는 함수
	/// </summary>
	/// <param name="_pSprite">렌더링 해줄 스프라이트</param>
	/// <param name="_matWorld">월드행렬</param>
	/// <param name="_Color">컬러값</param>
	/// <param name="_RenderMode">렌더 모드</param>
	void Render_Sprite(CSprite * _pSprite, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color,RenderMode _RenderMode);
	
	/// <summary>
	/// 텍스트를 렌더링 해주는 함수
	/// </summary>
	/// <param name="_string">해줄내용</param>
	/// <param name="_matWorld">월드행렬</param>
	/// <param name="_Color">컬러값</param>
	/// <param name="_RenderMode">렌더 모드</param>
	void Render_Font(string _string, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color, RenderMode _RenderMode);
};

#define GRAPHICS (*CGraphicsManager::GetInstance())

// FindSprite 함수를 빨리 사용할 수 있도록 해둔 define
#define SPRITE GRAPHICS.FindSprite
