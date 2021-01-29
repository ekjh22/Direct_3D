#include "DXUT.h"
#include "CLoading.h"

CLoading::CLoading()
{
}

CLoading::~CLoading()
{
}

void CLoading::Init()
{
	DEBUG_LOG("로딩씬");

	IMAGE->GetVecMesh(L"IDLE", L"./resource/Player/Model/Idle/Idle (%d).obj", 41);

	thr1 = thread([&]() {
		thr1B = true;
		});

	thr2 = thread([&]() {
		thr2B = true;
		});

	thr3 = thread([&]() {
		thr3B = true;
		});
	thr4 = thread([&]() {
		thr4B = true;
		});
}

void CLoading::Update()
{
	Sleep(1);
	DEBUG_LOG("로딩중...");

	if (thr1B && thr2B && thr3B && thr4B)
	{
		if (thr1.joinable())
			thr1.join();
		if (thr2.joinable())
			thr2.join();
		if (thr3.joinable())
			thr3.join();
		if (thr4.joinable())
			thr4.join();
		
		DEBUG_LOG("로딩완료");
		GAME->isUpdate = true;

		SCENE->ChangeScene(L"Game");
	}
}

void CLoading::Render()
{
}

void CLoading::Destroy()
{
}
