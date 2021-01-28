#include "DXUT.h"
#include "FXManager.h"

FXManager::FXManager()
{
	DWORD dwShaderFlags = D3DXFX_NOT_CLONEABLE;

#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DXSHADER_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

#ifdef DEBUG_VS
	dwShaderFlags |= D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT;
#endif
#ifdef DEBUG_PS
	dwShaderFlags |= D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT;
#endif

	LPD3DXBUFFER errBuffer;
	ID3DXBuffer* pErrorMsgs;
	HRESULT hr = D3DXCreateEffectFromFile(gDevice, L"./Shader/CommonShader.fx", NULL, NULL, 0, NULL, &shadowEffect, &pErrorMsgs);
	if (FAILED(hr) && pErrorMsgs != 0 && pErrorMsgs->GetBufferPointer() != 0)
	{
		std::string str = (char*)pErrorMsgs->GetBufferPointer();
		int a = 5;
	}
}

FXManager::~FXManager()
{
	SAFE_RELEASE(shadowEffect);
}