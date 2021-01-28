#include "DXUT.h"
#include "ImageManager.h"
#include "MeshLoader.h"

ImageManager::ImageManager()
{
	Init();
}

ImageManager::~ImageManager()
{
	for (auto iter : mImage)
	{
		SAFE_RELEASE(iter.second->texturePtr);
		SAFE_DELETE(iter.second);
	}
	mImage.clear();
	for (auto iter : mMesh)
	{
		iter.second->Destroy();
		SAFE_RELEASE(iter.second->m_pMesh);
		SAFE_DELETE(iter.second);
	}
	mMesh.clear();

	SAFE_RELEASE(lFont);
	SAFE_RELEASE(lSprite);
}

void ImageManager::Init()
{
	D3DXCreateSprite(gDevice, &lSprite);
	D3DXCreateFont(gDevice, 40, 0, 0, 5, false, HANGUL_CHARSET, 0, 0, 0, L"¸¼Àº °íµñ Bold", &lFont);
}

void ImageManager::Destroy()
{
}

texture* ImageManager::GetTexture(wstring key, wstring path)
{
	auto find = mImage.find(key);

	if (find != mImage.end())
		return find->second;

	LPDIRECT3DTEXTURE9 lTexture;
	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(path.c_str(), &info);
	if (D3DXCreateTextureFromFileEx(gDevice, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &lTexture) == S_OK)
	{
		texture* tex = new texture(lTexture, info);
		mImage.insert(make_pair(key, tex));
		return tex;
	}
	return nullptr;
}

vector<texture*> ImageManager::GetVecTexture(wstring key, wstring path, int count)
{
	vector<texture*> result;
	for (int i = 0; i <= count; ++i)
	{
		wstring newKey = key + L"__" + to_wstring(i);
		wchar_t ch[256];
		wsprintf(ch, path.c_str(), i);
		result.push_back(GetTexture(newKey, ch));
	}
	return result;
}

vector<texture*> ImageManager::GetVec1Texture(wstring key, wstring path, int count)
{
	vector<texture*> result;
	for (int i = 1; i <= count; ++i)
	{
		wstring newKey = key + L"__" + to_wstring(i);
		wchar_t ch[256];
		wsprintf(ch, path.c_str(), i);
		result.push_back(GetTexture(newKey, ch));
	}
	return result;
}

CMeshLoader* ImageManager::GetMesh(wstring key, wstring path)
{
	auto find = mMesh.find(key);

	if (find != mMesh.end())
		return find->second;
	CMeshLoader* mesh = new CMeshLoader();

	mesh->Create(gDevice, path);
	if (mesh)
	{
		mMesh.insert(make_pair(key, mesh));
		return mesh;
	}
	return nullptr;
}

vector<CMeshLoader*> ImageManager::GetVecMesh(wstring key, wstring path, int count)
{
	vector<CMeshLoader*> result;
	for (int i = 1; i <= count; ++i)
	{
		wstring newKey = key + L"__" + to_wstring(i);
		wchar_t ch[256];
		wsprintf(ch, path.c_str(), i);
		result.push_back(GetMesh(newKey, ch));
	}
	return result;
}

void ImageManager::Render(CMeshLoader* mesh, Matrix matWorld, Vector4 lineColor, float lineSize, bool IsRenderOutline)
{
	if (IsRenderOutline)
	{
		HRESULT hr;
		UINT iPass, cPasses;

		D3DXMATRIXA16 mWorldView = matWorld;
		D3DXMatrixMultiply(&mWorldView, &mWorldView, &CAMERA->matView);
		FX(SHADOW)->SetMatrix((D3DXHANDLE)"g_mWorldView", &mWorldView);
		FX(SHADOW)->SetMatrix((D3DXHANDLE)"g_mProj", &CAMERA->matProj);

		gDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
		gDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		gDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		gDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		gDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);
		FX(SHADOW)->SetTechnique(FX(SHADOW)->GetTechniqueByName("RenderOutline"));
		FX(SHADOW)->SetFloat((D3DXHANDLE)"LineSize", lineSize);
		FX(SHADOW)->SetVector((D3DXHANDLE)"LineColor", &lineColor);
		FX(SHADOW)->Begin(&cPasses, 0);
		for (UINT p = 0; p < cPasses; ++p)
		{
			FX(SHADOW)->BeginPass(p);

			for (DWORD i = 0; i < mesh->GetNumMaterials(); ++i)
			{
				mesh->GetMesh()->DrawSubset(i);
			}
			FX(SHADOW)->EndPass();
		}
		FX(SHADOW)->End();
		gDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
		gDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		gDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	}
	//gDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	//gDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	//gDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA); 
	//gDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	//gDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	//gDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_TFACTOR);
	//gDevice->SetRenderState(D3DRS_TEXTUREFACTOR, D3DCOLOR_ARGB(255, 255, 255, 255));




	gDevice->SetTransform(D3DTS_WORLD, &matWorld);
	for (int i = 0; i < mesh->GetNumMaterials(); ++i)
	{
		gDevice->SetTexture(0, mesh->GetMaterial(i)->pTexture);
		mesh->GetMesh()->DrawSubset(i);
	}
}

void ImageManager::Render(texture* tex, Vector3 pos, Vector3 size, float rot, D3DCOLOR color)
{
	Matrix matworld;
	gDevice->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matworld));
	Matrix mSize, mPos, mRot;
	D3DXMatrixScaling(&mSize, size.x, size.y, size.z);
	D3DXMatrixTranslation(&mPos, pos.x, pos.y, pos.z);
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(rot));

	lSprite->SetTransform(&(mSize * mRot * mPos));
	lSprite->Draw(tex->texturePtr, NULL, NULL, NULL, color);
}

void ImageManager::CenterRender(texture* tex, Vector3 pos, Vector3 size, float rot, D3DCOLOR color)
{
	Matrix matworld;
	gDevice->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matworld));
	Matrix mSize, mPos, mRot;
	D3DXMatrixScaling(&mSize, size.x, size.y, size.z);
	D3DXMatrixTranslation(&mPos, pos.x, pos.y, pos.z);
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(rot));

	lSprite->SetTransform(&(mSize * mRot * mPos));
	lSprite->Draw(tex->texturePtr, NULL, &Vector3(tex->info.Width / 2, tex->info.Height / 2, 0), NULL, color);
}

void ImageManager::CropRender(texture* tex, Vector2 pos, Vector3 size, RECT rect)
{
	Matrix matworld;
	gDevice->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matworld));
	Matrix mSize, mPos, mRot;
	D3DXMatrixScaling(&mSize, size.x, size.y, size.z);
	D3DXMatrixTranslation(&mPos, pos.x, pos.y, 0);
	D3DXMatrixIdentity(&mRot);

	lSprite->SetTransform(&(mSize * mRot * mPos));
	lSprite->Draw(tex->texturePtr, &rect, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
}

void ImageManager::PrintText(wstring text, Vector3 pos, D3DCOLOR color)
{
	Matrix mat;
	D3DXMatrixTranslation(&mat, pos.x, pos.y, pos.z);
	lSprite->SetTransform(&mat);
	lFont->DrawTextW(lSprite, text.c_str(), text.size(), NULL, DT_CENTER, color);
}

void ImageManager::Begin(bool isUi, bool isBill)
{
	if (isBill)
	{
		lSprite->SetWorldViewLH(NULL, &CAMERA->matView);
		lSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE | D3DXSPRITE_BILLBOARD);
	}
	else
	{
		if (!isUi)
			lSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		else
			lSprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
}

void ImageManager::ReBegin(bool isUi, bool isBill)
{
	End(); Begin(isUi, isBill);
}

void ImageManager::End()
{
	lSprite->End();
}

void ImageManager::LostDevice()
{
	lSprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	lSprite->OnResetDevice();
}
