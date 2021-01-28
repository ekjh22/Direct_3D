#pragma once
#include "singleton.h"
class CameraManager :
	public singleton<CameraManager>
{
public:
	CameraManager();
	virtual ~CameraManager();

	Object* player;

	Vector3 cameraPos;
	Vector3 at;
	Vector3 up;

	Vector3 saveTemp = Vector3(0.0f, 300, 600.f);

	Vector3 cameraRot = Vector3(0, 0, 0);
	Vector2 nowMouse = Vector3(0, 0, 0);

	Matrix matView, matProj;

	bool isBoss = false;
	bool isLoad = false;

	Vector3 Shakepos = Vector3(0, 0, 0);
	float shakeScale = 0.f;
	bool isShake = false;
	float shakeTime = 0;
	system_clock::time_point shTime;


	void Update();
	void SetTransform();
	void CameraShake(float time, float Scale);

	Vector2 GetScreenPos()
	{
		POINT point = { 0,0 };
		ClientToScreen(DXUTGetHWND(), &point);
		Vector2 v_mousepos(point.x, point.y);
		return v_mousepos;
	}
};

#define CAMERA CameraManager::GetInstance()