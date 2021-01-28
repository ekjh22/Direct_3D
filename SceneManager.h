#pragma once
#include "singleton.h"

class Scene;
class SceneManager :
	public singleton<SceneManager>
{
public:
	texture* img;
	float rgb = 255;

	map<wstring, Scene*> mScene;
	Scene* nowScene = nullptr;
	Scene* nextScene = nullptr;
public:
	SceneManager();
	virtual ~SceneManager();

	Scene* AddScene(wstring key, Scene* scenePtr);
	Scene* ChangeScene(wstring key);

	void Update();
	void Render();
	void Destroy();
};

#define SCENE SceneManager::GetInstance()