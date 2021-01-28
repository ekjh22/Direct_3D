#pragma once
#include "singleton.h"
class SoundManager :
	public singleton<SoundManager>
{
public:
	CSoundManager* manager;
	map<wstring, CSound*> mSound;
public:
	SoundManager();
	virtual ~SoundManager();

	void AddSound(wstring key, wstring path);
	void SoundPlay(wstring key, bool isLoop = false);
	void DuplPlay(wstring key);
	void SoundStop(wstring key);

	void Init();
	void Destroy();
};

#define SOUND SoundManager::GetInstance()