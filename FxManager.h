#pragma once
#include "singleton.h"

enum EffectType : char
{
	NONE,
	SHADOW,
};

class FXManager :
	public singleton<FXManager>
{
public:
	LPD3DXEFFECT shadowEffect = NULL;

public:
	FXManager();
	virtual ~FXManager();

	LPD3DXEFFECT GetEffect(EffectType type)
	{
		switch (type)
		{
		case NONE:
			return nullptr;
		case SHADOW:
			return shadowEffect;
		}
	}
};

#define FXMANAGER FXManager::GetInstance()
#define FX(_type) FXManager::GetInstance()->GetEffect(_type)