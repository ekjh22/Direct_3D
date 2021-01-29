#include "DXUT.h"
#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Destroy();
}

Scene* SceneManager::AddScene(wstring key, Scene* scenePtr)
{
	auto find = mScene.find(key);

	if (find != mScene.end())
		return find->second;
	mScene[key] = scenePtr;
	return scenePtr;
}

Scene* SceneManager::ChangeScene(wstring key)
{
	auto find = mScene.find(key);

	if (find != mScene.end())
	{
		nextScene = find->second;
		return nextScene;
	}
	return nullptr;
}

void SceneManager::Update()
{
	if (nextScene)
	{
		Lerp<float>(&rgb, rgb, 255.f, 7 * DeltaTime);
		if (rgb > 253)
		{
			rgb = 255;
			if (nowScene)
			{
				nowScene->Destroy();
				OBJECT->Destroy();
			}
			nextScene->Init();
			nowScene = nextScene;
			nextScene = nullptr;
		}
	}
	else if (nowScene)
	{
		Lerp<float>(&rgb, rgb, 0, 7 * DeltaTime);
		if (rgb < 2)
		{
			rgb = 0;
			nowScene->Update();
			OBJECT->Update();
		}
	}
}

void SceneManager::Render()
{
	if (nowScene)
	{
		nowScene->Render();
		OBJECT->Render();
	}

	/*IMAGE->ReBegin(true, false);
	IMAGE->Render(IMAGE->GetTexture(L"black", L"./Resource/UI/black.png"), Vector3(0, 0, 0), Vector3(1, 1, 1), 0, D3DCOLOR_ARGB((LONG)rgb, 255, 255, 255));
	IMAGE->ReBegin(false, false);*/
}

void SceneManager::Destroy()
{
	if (nowScene)
	{
		//OBJECT->Destroy();
		nowScene->Destroy();
	}
	for (auto iter : mScene)
	{
		iter.second->Destroy();
		SAFE_DELETE(iter.second);
	}
	mScene.clear();
}
