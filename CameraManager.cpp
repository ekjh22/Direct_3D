#include "DXUT.h"
#include "CameraManager.h"

CameraManager::CameraManager()
	: curPos(0, 150, 0), curRot(0, 0, 0), curScale(1, 1, 1), at(0, 0, 0), up(0, 0, 0)
{
	basePos = curPos;
}

CameraManager::~CameraManager()
{
}

void CameraManager::Update()
{
	POINT point;
	GetCursorPos(&point);
	curMousePos = Vector2(point.x, point.y);

	if (followObj != NULL)
		D3DXVec3Lerp(&curPos, &curPos, &(followObj->pos + basePos), GAME->playerMoveSpeed * DeltaTime);

	Matrix XMat, YMat, XYMat;
	D3DXMatrixRotationX(&XMat, D3DXToRadian(curRot.y));
	D3DXMatrixRotationY(&YMat, D3DXToRadian(curRot.x));

	XYMat = XMat * YMat;	
	D3DXMatrixScaling(&XYMat, curScale.x, curScale.y, curScale.z);

	Vector3 temp = basePos;
	D3DXVec3TransformCoord(&(temp), &(temp), &XYMat);

	curPos = temp;

	if (isShake) 
	{
		duration<float> sec = GetNowTime - shakeTimer;
		if (sec.count() > shakeTime) isShake = false;
		
		float xS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		float yS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		float zS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		shakePos += Vector3(xS, yS, zS);
		
		D3DXVec3Lerp(&shakePos, &shakePos, &basePos, (shakeScale * sec.count()) * DeltaTime);
	}

	/*if (isLoad)
	{
		float saveZ = 0.f, saveY = 0.f;
		bool isDone = true;
		while (isDone)
		{
			if (COLLISION->CheckPosMap(&cameraPos))
			{
				saveZ -= 300 * DeltaTime;
				saveY -= 15 * DeltaTime;
				if (saveZ <= -600)
					isOkay = false;

				temp = saveTemp + Vector3(0, saveY, saveZ);
				D3DXVec3TransformCoord(&(temp), &(temp), &XYMat);
				cameraPos = at + temp;
			}
			else
			{
				isOkay = false;
			}
		}
	}*/

	/*if (player != NULL)
	{
		D3DXVec3Lerp(&cameraPos, &cameraPos, &(player->pos + Vector3(0, 8, -8)), GAME->playerMoveSpeed * DeltaTime);
		D3DXVec3Lerp(&at, &at, &(player->pos), 1 * DeltaTime);
		at.y = 150;
	}*/

	/*if (nowMouse != GetScreenPos() + Vector2(WINSIZEX / 2, WINSIZEY / 2))
	{
		if (nowMouse.x > GetScreenPos().x + WINSIZEX / 2)
		{
			cameraRot.x += (nowMouse.x - GetScreenPos().x + WINSIZEX / 2) * 0.17 * DeltaTime;
			if (cameraRot.x > 360.f)
				cameraRot.x = 0.f;
		}
		if (nowMouse.x < GetScreenPos().x + WINSIZEX / 2)
		{
			cameraRot.x -= (nowMouse.x - GetScreenPos().x + WINSIZEX / 2) * 0.17 * DeltaTime;
			if (cameraRot.x < 0.f)
				cameraRot.x = 360.f;
		}
		if (nowMouse.y > GetScreenPos().y + WINSIZEY / 2)
		{
			cameraRot.y += (nowMouse.y - GetScreenPos().y + WINSIZEY / 2) * 0.17 * DeltaTime;
			if (cameraRot.y > 240.f)
				cameraRot.y -= (nowMouse.y - GetScreenPos().y + WINSIZEY / 2) * 0.17 * DeltaTime;
		}
		if (nowMouse.y < GetScreenPos().y + WINSIZEY / 2)
		{
			cameraRot.y -= (nowMouse.y - GetScreenPos().y + WINSIZEY / 2) * 0.17 * DeltaTime;
			if (cameraRot.y < 220.f)
				cameraRot.y += (nowMouse.y - GetScreenPos().y + WINSIZEY / 2) * 0.17 * DeltaTime;
		}

	}*/
}

void CameraManager::SetTransform()
{
	D3DXMatrixLookAtLH(&matView, &(curPos + shakePos), &(at + shakePos), &up);
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 16.f / 9.f, 1.f, 50000.f);

	gDevice->SetTransform(D3DTS_VIEW, &matView);
	gDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void CameraManager::CameraShake(float _time, float _scale)
{
	shakeTimer = GetNowTime;
	shakeTime  = _time;
	shakeScale = _scale;
	isShake	   = true;
}
