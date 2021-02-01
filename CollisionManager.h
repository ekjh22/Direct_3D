#pragma once
#include "singleton.h"

class Collider;
class CollisionManager :
	public singleton<CollisionManager>
{
private:
	list<Collider*> colliderList;
	texture* pixelMap;

public:
	void Register(Collider* _collider);
	void UnRegister(Collider* _collider);

	bool CheckColMap(Object* _object);
	bool CheckPosMap(Vector3* _position);

	void Update();

public:
	CollisionManager();
	virtual ~CollisionManager();
};

#define COLLISION CollisionManager::GetInstance()