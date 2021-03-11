#include "DXUT.h"
#include "CLoadScene.h"


CLoadScene::CLoadScene()
{
}


CLoadScene::~CLoadScene()
{
}

void CLoadScene::Init()
{
	LoadSprite("EX", "ex");
	LoadSprite("Back", "Back");
	LoadSprite("White", "White");
	LoadSprite("Black", "Black");
	LoadSprite("Player", "Player");
}

void CLoadScene::Update()
{
	if (m_listLoadData.empty() == true)
	{
		// 로딩이 끝나면 타이틀 씬으로 넘어가기
		SCENE.ChangeScene("TITEL");
	}
	else
	{
		// 리스트 앞 부분을 가져와서 스프라이트들을 추가 후 리스트에서 빼주기
		auto data = m_listLoadData.front();
		if (data.m_Type == 1)
		{
			GRAPHICS.AddSprite(data.m_Key, data.m_Path);
		}
		m_listLoadData.pop_front();
	}
}

void CLoadScene::Render()
{
}

void CLoadScene::Release()
{
}

void CLoadScene::LoadSprite(string _Key, string _Path, int _iCount)
{
	if (_iCount == 0)
	{
		LoadData data;
		data.m_Key = _Key;
		data.m_Path = "./resource/" + _Path + ".png";
		data.m_Type = 1;
		m_listLoadData.push_back(data);
	}
	else
	{
		for (int i = 0; i < _iCount; i++)
		{
			LoadData data;
			data.m_Key = _Key + " (" + to_string(i + 1) + ")";
			data.m_Path = "./resource/" + _Path + " (" + to_string(i + 1) + ")" + ".png";
			data.m_Type = 1;
			m_listLoadData.push_back(data);
		}
	}

}