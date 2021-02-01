#pragma once
#include "singleton.h"
class CameraManager :
	public singleton<CameraManager>
{
private:
	Vector3 basePos = Vector3(0, 300, 600);
	Vector3 at;
	Vector3 up;

	Vector2 curMousePos = Vector2(0, 0);

	Matrix  matView, matProj;

	Vector3 shakePos  = Vector3(0, 0, 0);
	Time    shakeTimer;
	float   shakeTime = 0.f, shakeScale = 0.f;
	bool    isShake   = false;

public:
	Vector3 curPos = Vector3(0, 0, 0), curRot = Vector3(0, 0, 0), curScale = Vector3(0, 0, 0);
	Object* followObj = nullptr;

public:
	void Update();
	void SetTransform();
	void CameraShake(float _time, float _scale);

	Vector2 GetScreenPos()
	{
		POINT point = { 0,0 };
		ClientToScreen(DXUTGetHWND(), &point);
		Vector2 vMousepos(point.x, point.y);
		return vMousepos;
	}

public:
	CameraManager();
	virtual ~CameraManager();
};

#define CAMERA CameraManager::GetInstance()