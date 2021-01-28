#pragma once

class Object;
class Collider
{
public:
	Object* parent = nullptr;
	Vector3 colPos = Vector3(0, 0, 0);
	float fRadius = 0;
	std::set<Object*> colEnterList;

	Collider();
	virtual ~Collider();

	virtual void OnCollision(Collider* col);
};

