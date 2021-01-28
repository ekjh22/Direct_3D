#pragma once
#include "singleton.h"

class Collider;
class CollisionManager :
	public singleton<CollisionManager>
{
public:
	list<Collider*> colliderList;

	texture* pixelMap;
public:
	CollisionManager();
	virtual ~CollisionManager();

	void Register(Collider* col);
	void UnRegister(Collider* col);

	bool CheckColMap(Object* obj);
	bool CheckPosMap(Vector3* pos);

	void Update();
};

#define COLLISION CollisionManager::GetInstance()