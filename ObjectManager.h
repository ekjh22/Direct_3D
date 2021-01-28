#pragma once
#include "singleton.h"

enum ObjectTag : char
{
	PLAYER,
	END
};
class Object;
class ObjectManager :
	public singleton<ObjectManager>
{
public:
	list<Object*> objectList[ObjectTag::END];
	long objectId = 0;
public:
	ObjectManager();
	virtual ~ObjectManager();

	Object* CreateObject(ObjectTag tag, Object* obj);

	void Update();
	void Render();
	void Destroy();

	list<Object*>& GetObjectList(ObjectTag tag)
	{
		return objectList[tag];
	}
	Object* GetPlayer()
	{
		return objectList[ObjectTag::PLAYER].front();
	}

};

#define OBJECT ObjectManager::GetInstance()
#define ObjectAdd(tag, obj) OBJECT->CreateObject(tag, new obj)