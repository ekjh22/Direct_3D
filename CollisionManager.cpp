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

void CollisionManager::Register(Collider* _collider)
{
	colliderList.push_back(_collider);
}

void CollisionManager::UnRegister(Collider* _collider)
{
	colliderList.remove(_collider);
}

bool CollisionManager::CheckColMap(Object* _object)
{
	//1-800 2-600
	D3DLOCKED_RECT lR;

	int posX = _object->pos.x / 10;
	int posY = _object->pos.z / 10;

	pixelMap->texturePtr->LockRect(0, &lR, nullptr, D3DLOCK_DISCARD);
	DWORD* dwColor = reinterpret_cast<DWORD*>(lR.pBits);

	if (_object->pos.x / 10 < 0 ||
		_object->pos.x / 10 > pixelMap->info.Width ||
		_object->pos.z / 10 < 0 ||
		_object->pos.z / 10 > pixelMap->info.Height)
	{
		_object->curColor = D3DXCOLOR(0, 0, 0, 0);
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
		_object->curColor = color;
		pixelMap->texturePtr->UnlockRect(0);
		if (_object->pos.y >= -600)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 0, 1))
	{
		_object->curColor = color;
		pixelMap->texturePtr->UnlockRect(0);
		if (_object->pos.y >= -700)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 1, 1))
	{
		_object->curColor = color;
		pixelMap->texturePtr->UnlockRect(0);
		return false;
	}

	_object->curColor = D3DXCOLOR(0, 0, 0, 0);
	pixelMap->texturePtr->UnlockRect(0);
	return false;
}

bool CollisionManager::CheckPosMap(Vector3* _position)
{
	D3DLOCKED_RECT lR;

	int posX = _position->x / 10;
	int posY = _position->z / 10;

	pixelMap->texturePtr->LockRect(0, &lR, nullptr, D3DLOCK_DISCARD);
	DWORD* dwColor = reinterpret_cast<DWORD*>(lR.pBits);

	if (_position->x / 10 < 0 ||
		_position->x / 10 > pixelMap->info.Width ||
		_position->z / 10 < 0 ||
		_position->z / 10 > pixelMap->info.Height)
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
		if (_position->y >= -600)
			return false;
		else
			return true;
	}
	else if (color == D3DXCOLOR(1, 1, 0, 1))
	{
		pixelMap->texturePtr->UnlockRect(0);
		if (_position->y >= -700)
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

			float length = sqrtf(D3DXVec3Length(&((iter1->parent->pos + iter1->curPos) - (iter2->parent->pos + iter2->curPos))));
			if (length < (iter1->radius + iter2->radius))
			{
				iter1->OnCollision(iter2);

				auto find = iter1->enterList.find(iter2->parent);
				if (find == iter1->enterList.end())
				{
					iter1->enterList.insert(iter2->parent);
				}

			}
		}
	}
}
