#pragma once

class Object;
class Collider
{
public:
	Object* parent = nullptr;
	Vector3 curPos = Vector3(0, 0, 0);

	float radius = 0.f;
	set<Object*> enterList;
public:
	virtual void OnCollision(Collider* _collider);

public:
	Collider();
	virtual ~Collider();
};

