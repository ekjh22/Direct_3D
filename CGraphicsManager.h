#pragma once
#include "CSingleton.h"

// DXUT���� �����ϴ� ��������Ʈ ������ �Լ��� �̿��ؼ� �̹��� ����� �� �� �ֵ��� ���ִ� �Ŵ���
// ��� ������ �ʿ� ���� �ǹ̸� �����ϰ� ������ �� ���⿡ ���� �𸣴� �ܾ���� �˻��غ��� ����
class CGraphicsManager
	: public CSingleton<CGraphicsManager>
{
public:
	CGraphicsManager();
	~CGraphicsManager();

public:
	void OnResetDevice(); // ����̽� ����
	void OnLostDevice();  // ����̽� ����

	void Begin();
	void End();

private:
	LPD3DXSPRITE m_pSprite = NULL; // ��������Ʈ ���� ( �̹��� ����� �����ִ� ���� [���α׷��� ��ȭ�� �� ������ �װ��� ����] )
	LPD3DXFONT m_pFont = NULL; // ��Ʈ ���� ( �ؽ�Ʈ ����� �����ִ� ���� [���α׷��� ��ȭ�� �� ������ �װ��� ����] )
	Matrix m_mat;

	map<string, CSprite *> m_mapSprite; // ��������Ʈ���� Ű���� �°� ��Ƶδ� �� ����
public:
	/// <summary>
	/// ����� �� �������� Ű ���� �´� ��������Ʈ�� ã���ִ� �Լ�
	/// </summary>
	/// <param name="_Key">�� ������ ����� ��������Ʈ Ű ��</param>
	/// <returns></returns>
	CSprite * FindSprite(string _Key);

	/// <summary>
	/// �ش� �ּҰ����� ��������Ʈ�� ã�Ƽ� �ش� �ʺ����� Ű ���� �Բ� �������ִ� �Լ�
	/// </summary>
	/// <param name="_Key">�� ������ ������ ��������Ʈ Ű �� (EX : Player1)</param>
	/// <param name="_Path">�ش� ���ҽ��� ��ġ�ϰ� �ִ� �ּҰ� (EX : ./resource/Player1.png)</param>
	/// <returns></returns>
	CSprite * AddSprite(string _Key, string _Path);

	/// <summary>
	/// ��������Ʈ�� ������ ���ִ� �Լ�
	/// </summary>
	/// <param name="_pSprite">������ ���� ��������Ʈ</param>
	/// <param name="_matWorld">�������</param>
	/// <param name="_Color">�÷���</param>
	/// <param name="_RenderMode">���� ���</param>
	void Render_Sprite(CSprite * _pSprite, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color,RenderMode _RenderMode);
	
	/// <summary>
	/// �ؽ�Ʈ�� ������ ���ִ� �Լ�
	/// </summary>
	/// <param name="_string">���ٳ���</param>
	/// <param name="_matWorld">�������</param>
	/// <param name="_Color">�÷���</param>
	/// <param name="_RenderMode">���� ���</param>
	void Render_Font(string _string, Vec2 _Pos, Vec2 _Scale, float _Rot, Color _Color, RenderMode _RenderMode);
};

#define GRAPHICS (*CGraphicsManager::GetInstance())

// FindSprite �Լ��� ���� ����� �� �ֵ��� �ص� define
#define SPRITE GRAPHICS.FindSprite
