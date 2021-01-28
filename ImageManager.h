#pragma once
#include "singleton.h"

class texture
{
public:
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr), info(info)
	{

	}
};
class CMeshLoader;

class ImageManager :
	public singleton<ImageManager>
{
public:
	LPD3DXSPRITE lSprite;
	LPD3DXFONT lFont;


	map<wstring, texture*> mImage;
	map<wstring, CMeshLoader*> mMesh;
public:
	ImageManager();
	virtual ~ImageManager();

	void Init();
	void Destroy();

	texture* GetTexture(wstring key, wstring path);
	vector<texture*> GetVecTexture(wstring key, wstring path, int count);
	vector<texture*> GetVec1Texture(wstring key, wstring path, int count);

	CMeshLoader* GetMesh(wstring key, wstring path);
	vector<CMeshLoader*> GetVecMesh(wstring key, wstring path, int count);

	void Render(CMeshLoader* mesh, Matrix matWorld, Vector4 lineColor = Vector4(0, 0, 0, 1), float lineSize = 1.f, bool IsRenderOutline = false);
	void Render(texture* tex, Vector3 pos, Vector3 size, float rot, D3DCOLOR color);
	void CenterRender(texture* tex, Vector3 pos, Vector3 size, float rot, D3DCOLOR color);
	void CropRender(texture* tex, Vector2 pos, Vector3 size, RECT rect);

	void PrintText(wstring text, Vector3 pos, D3DCOLOR color);

	void Begin(bool isUi, bool isBill);
	void ReBegin(bool isUi, bool isBill);
	void End();

	void LostDevice();
	void ResetDevice();
};

#define IMAGE ImageManager::GetInstance()