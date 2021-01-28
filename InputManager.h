#pragma once
#include "singleton.h"

class Ray;
class InputManager :
	public singleton<InputManager>
{
public:
	InputManager() {}
	virtual ~InputManager() {}

	bool nowKey[256] = { 0 };
	bool oldKey[256] = { 0 };

	void Update();

	bool KeyDown(int i) { return nowKey[i] && !oldKey[i]; }
	bool KeyUp(int i) { return !nowKey[i] && oldKey[i]; }
	bool KeyPress(int i) { return nowKey[i] && oldKey[i]; }


	Vector2 GetMousePos()
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(DXUTGetHWND(), &pt);
		return Vector2(pt.x, pt.y);
	}

	/*Vector2 GetWorldMousePos()
	{
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(DXUTGetHWND(), &pt);
		Vector2 mousePos = Vector2(pt.x, pt.y);
		mousePos -= Vector2((WINSIZEX / 2 - CAMERA->cameraPos.x), (WINSIZEY / 2 - CAMERA->cameraPos.y));
		return mousePos;
	}*/
};


#define INPUT InputManager::GetInstance()
#define KEYDOWN(i) INPUT->KeyDown(i)
#define KEYUP(i) INPUT->KeyUp(i)
#define KEYPRESS(i) INPUT->KeyPress(i)