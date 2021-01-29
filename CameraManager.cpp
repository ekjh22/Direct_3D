#include "DXUT.h"
#include "CameraManager.h"

CameraManager::CameraManager()
	:cameraPos(0, 4, 6), at(0, 150, 0), up(0, 1, 0), player(NULL)
{
	cameraRot.y = 230.f;
}

CameraManager::~CameraManager()
{
}

void CameraManager::Update()
{
	if (player != NULL)
	{
		D3DXVec3Lerp(&cameraPos, &cameraPos, &(player->pos + Vector3(0, 8, -8)), GAME->playerMoveSpeed * DeltaTime);
		D3DXVec3Lerp(&at, &at, &(player->pos), 1 * DeltaTime);
		at.y = 150;
	}

	POINT cur;
	GetCursorPos(&cur);
	nowMouse = Vector2(cur.x, cur.y);

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

	Matrix XMat, YMat, XYMat;
	D3DXMatrixRotationX(&XMat, D3DXToRadian(cameraRot.y));
	D3DXMatrixRotationY(&YMat, D3DXToRadian(cameraRot.x));

	XYMat = XMat * YMat;

	Vector3 temp = saveTemp;

	D3DXVec3TransformCoord(&(temp), &(temp), &XYMat);

	cameraPos = at + temp;

	if (isLoad)
	{
		float saveZ = 0.f;
		float saveY = 0.f;
		bool isOkay = true;
		while (isOkay)
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
	}

	SetCursorPos(GetScreenPos().x + WINSIZEX / 2, GetScreenPos().y + WINSIZEY / 2);

	if (isShake)
	{
		duration<float > sec = GetNowTime - shTime;
		if (sec.count() > shakeTime)
			isShake = false;
		float xS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		float yS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		float zS = rand() % 2 == 0 ? shakeScale : -shakeScale;
		Shakepos += Vector3(xS, yS, zS);
	}
	D3DXVec3Lerp(&Shakepos, &Shakepos, &Vector3(0, 0, 0), 3 * DeltaTime);

}

void CameraManager::SetTransform()
{
	D3DXMatrixLookAtLH(&matView, &(cameraPos + Shakepos), &(at + Shakepos), &up);
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 16.f / 9.f, 1.f, 50000.f);

	gDevice->SetTransform(D3DTS_VIEW, &matView);
	gDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void CameraManager::CameraShake(float time, float Scale)
{
	isShake = true;
	shakeTime = time;
	shakeScale = Scale;
	shTime = GetNowTime;
}
