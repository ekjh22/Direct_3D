#include "DXUT.h"
#include "Object.h"
#include "Collider.h"

Object::Object()
{
}

Object::~Object()
{
	DestroyCollider();
}

void Object::DestroyCollider()
{
	if (collider)
	{
		COLLISION->UnRegister(collider);
		collider->colEnterList.clear();
		SAFE_DELETE(collider);
	}
	if (sche)
		SAFE_DELETE(sche);
}

void Object::TransformUpdate()
{
	Matrix scale, rotation[3], position;
	D3DXMatrixScaling(&scale, size.x, size.y, size.z);
	D3DXMatrixTranslation(&position, pos.x, pos.y, pos.z);

	if (isUseQuaAllRot)
	{
		D3DXMatrixRotationX(&rotation[0], D3DXToRadian(rot.x));
		D3DXMatrixRotationY(&rotation[1], D3DXToRadian(rot.y));
		D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(rot.z));
	}
	else
	{
		if (isUseQua)
		{
			D3DXMatrixRotationX(&rotation[0], D3DXToRadian(0));
			D3DXMatrixRotationY(&rotation[1], D3DXToRadian(rot.y));
			D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(0));
		}
		else
		{
			D3DXMatrixRotationX(&rotation[0], D3DXToRadian(rot.x));
			D3DXMatrixRotationY(&rotation[1], D3DXToRadian(rot.y));
			D3DXMatrixRotationZ(&rotation[2], D3DXToRadian(rot.z));
		}
	}

	Matrix R = rotation[0] * rotation[1] * rotation[2];
	if (isUseQua || isUseQuaAllRot)
	{
		D3DXQUATERNION curQ;
		D3DXQuaternionIdentity(&curQ);
		D3DXQuaternionRotationMatrix(&curQ, &R);
		D3DXQuaternionSlerp(&resultQ, &resultQ, &curQ, 8.f * DeltaTime);
		D3DXMatrixRotationQuaternion(&R, &resultQ);
	}

	matWorld = scale * R * position;
}
