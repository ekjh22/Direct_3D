#pragma once

class Collider;
class Schedule;
class Object
{
public:
	CMeshLoader* mesh;

	Vector3 pos = Vector3(0, 0, 0);

	Vector3 size = Vector3(1, 1, 1);
	Vector3 rot = Vector3(0, 0, 0);
	Vector3 hitDir = Vector3(0, 0, 0);

	Matrix matWorld;

	Quaternion resultQ = Quaternion(0, 0, 0, 1);
	Collider* collider = nullptr;
	Schedule* sche = nullptr;
	Schedule* jumpSche;

	bool isDestroy = false;
	bool isDead = false;
	bool isJump = false;
	bool isGround = false;

	bool isUseQua = false;
	bool isUseQuaAllRot = false;

	float yGravity = 300;

	D3DXCOLOR curColor = D3DXCOLOR(1, 1, 1, 1);
	D3DXCOLOR oldColor = D3DXCOLOR(1, 1, 1, 1);

	Tag tag;

	Time dieTime;
	Time blendTime;
	Time hitTime;

public:
	Object();
	virtual ~Object();

	virtual void Init() {};
	virtual void Update() {};
	virtual void Render() {};
	virtual void Destroy() {};

	virtual void OnCollision(Collider* col) {};

	virtual void DestroyCollider();
	virtual void TransformUpdate();
	virtual void ObjectDead() {};

};

