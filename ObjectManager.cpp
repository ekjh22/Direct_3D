#include "DXUT.h"
#include "ObjectManager.h"
#include "Object.h"
#include "Collider.h"
#include "Schedule.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Destroy();
}

Object* ObjectManager::CreateObject(ObjectTag tag, Object* obj)
{
	if (!obj) return nullptr;
	Object* temp = obj;
	temp->tag = tag;
	temp->Init();
	objectList[tag].push_back(temp);
	return temp;
}

void ObjectManager::Update()
{
	for (int i = 0; i < ObjectTag::END; i++)
	{
		/*if (!GAME->isUpdate)
			if (i < ObjectTag::SKUI)
				continue;*/

		for (auto& iter = objectList[i].begin(); iter != objectList[i].end();)
		{
			if (!(*iter)->isDestroy)
			{
				(*iter)->Update();
				iter++;
			}
			else
			{
				for (auto& collision : COLLISION->colliderList)
				{
					auto find = collision->colEnterList.find((*iter));

					if (find != collision->colEnterList.end())
						collision->colEnterList.erase(find);
				}

				(*iter)->DestroyCollider();
				(*iter)->Destroy();
				SAFE_DELETE(*iter);
				iter = objectList[i].erase(iter);
			}
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < ObjectTag::END; i++)
	{
		for (auto& iter = objectList[i].begin(); iter != objectList[i].end();)
		{
			if (!(*iter)->isDestroy)
			{
				(*iter)->TransformUpdate();
				(*iter)->Render();
			}
			iter++;
		}
	}
}

void ObjectManager::Destroy()
{
	for (int i = 0; i < ObjectTag::END; i++)
	{
		for (auto& iter = objectList[i].begin(); iter != objectList[i].end();)
		{
			(*iter)->DestroyCollider();
			(*iter)->Destroy();
			SAFE_DELETE(*iter);
			iter = objectList[i].erase(iter);
		}
		objectList[i].clear();
	}
}
