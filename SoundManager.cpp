#include "DXUT.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	Init();
}

SoundManager::~SoundManager()
{
	Destroy();
}

void SoundManager::AddSound(wstring key, wstring path)
{
	CSound* sound;
	manager->Create(&sound, (LPWSTR)path.c_str());
	mSound[key] = sound;
}

void SoundManager::SoundPlay(wstring key, bool isLoop)
{
	mSound[key]->Reset();
	mSound[key]->Play(0, isLoop);
}

void SoundManager::DuplPlay(wstring key)
{
	LPDIRECTSOUNDBUFFER buf;
	manager->GetDirectSound()->DuplicateSoundBuffer(mSound[key]->GetBuffer(0), &buf);
	buf->SetCurrentPosition(0);
	buf->Play(0, 0, 0);
}

void SoundManager::SoundStop(wstring key)
{
	auto find = mSound.find(key);
	if (find == mSound.end())
		return;
	if (mSound[key]->IsSoundPlaying())
		mSound[key]->Stop();
}

void SoundManager::Init()
{
	manager = new CSoundManager();
	manager->Initialize(DXUTGetHWND(), 2);
}

void SoundManager::Destroy()
{
	for (auto iter : mSound)
	{
		if (iter.second)
			SAFE_DELETE(iter.second);
	}
	mSound.clear();
	SAFE_DELETE(manager);
}
