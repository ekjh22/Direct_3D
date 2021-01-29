#include "DXUT.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Object.h"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::Register(Collider* col)
{
	colliderList.push_back(col);
}

void CollisionManager::UnRegister(Collider* col)
{
	colliderList.remove(col);
}

bool CollisionManager::CheckColMap(Object* obj)
{
	//1-800 2-600
	D3DLOCKED_RECT lR;

	int posX = obj->pos.x / 10;
	int posY = obj->pos.z / 10;

	pixelMap->texturePtr->LockRect(0, &lR, nullptr, D3DLOCK_DISCARD);
	DWORD* dwColor = reinterpret_cast<DWORD*>(lR.pBits);


	if (obj->pos.x / 10 < 0 ||
		obj->pos.x / 10 > pixelMap->info.Width ||
		obj->pos.z / 10 < 0 ||
		obj->pos.z / 10 > pixelMap->info.Height)
	{
		obj->curColor = D3DXCOLOR(0, 0, 0, 0);
		pixelMap->texturePtr->UnlockRect(0);
		return true;
	}

	D3DCOLOR color = dwColor[posY * pixelMap->info.Width + posX];

	if (color == D3DXCOLOR(1, 0, 1, 1))
	{
		pixelMap->texturePtr->UnlockRect(0);
		return true;
	}
	else if (color == D3DXCOLOR(0, 1, 1, 1))
	{
		obj->curColor = color;
		pixelMap->texturePtr->UnlockRect(0);
		if (obj->pos.y >= -600)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 0, 1))
	{
		obj->curColor = color;
		pixelMap->texturePtr->UnlockRect(0);
		if (obj->pos.y >= -700)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 1, 1))
	{
		obj->curColor = color;
		pixelMap->texturePtr->UnlockRect(0);
		return false;
	}


	obj->curColor = D3DXCOLOR(0, 0, 0, 0);
	pixelMap->texturePtr->UnlockRect(0);
	return false;
}

bool CollisionManager::CheckPosMap(Vector3* pos)
{
	D3DLOCKED_RECT lR;

	int posX = pos->x / 10;
	int posY = pos->z / 10;

	pixelMap->texturePtr->LockRect(0, &lR, nullptr, D3DLOCK_DISCARD);
	DWORD* dwColor = reinterpret_cast<DWORD*>(lR.pBits);

	if (pos->x / 10 < 0 ||
		pos->x / 10 > pixelMap->info.Width ||
		pos->z / 10 < 0 ||
		pos->z / 10 > pixelMap->info.Height)
	{
		pixelMap->texturePtr->UnlockRect(0);
		return true;
	}

	D3DCOLOR color = dwColor[posY * pixelMap->info.Width + posX];

	if (color == D3DXCOLOR(1, 0, 1, 1))
	{
		pixelMap->texturePtr->UnlockRect(0);
		return true;
	}
	else if (color == D3DXCOLOR(0, 1, 1, 1))
	{
		pixelMap->texturePtr->UnlockRect(0);
		if (pos->y >= -600)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 0, 1))
	{
		pixelMap->texturePtr->UnlockRect(0);
		if (pos->y >= -700)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 1, 1))
	{
		pixelMap->texturePtr->UnlockRect(0);
		return false;
	}

	pixelMap->texturePtr->UnlockRect(0);
	return false;
}

void CollisionManager::Update()
{
	if (colliderList.size() < 2)
		return;

	for (auto iter1 : colliderList)
	{
		for (auto iter2 : colliderList)
		{
			if (iter1 == iter2)
				continue;
			if (iter1->parent->isDestroy || iter2->parent->isDestroy)
				continue;

			float length = sqrtf(D3DXVec3Length(&((iter1->parent->pos + iter1->colPos) - (iter2->parent->pos + iter2->colPos))));
			if (length < (iter1->fRadius + iter2->fRadius))
			{
				iter1->OnCollision(iter2);

				auto find = iter1->colEnterList.find(iter2->parent);
				if (find == iter1->colEnterList.end())
				{
					iter1->colEnterList.insert(iter2->parent);
				}

			}
		}
	}
}
