#pragma once
#include "CScene.h"

// 효율적으로 데이터들을 로드하기 위해서 만든 것
struct LoadData
{
public:
	string m_Key;		// 데이터의 키 값
	string m_Path;		// 데이터의 주소 값
	int m_Type;			// 데이터의 타입
};

class CLoadScene :
	public CScene
{
public:
	CLoadScene();
	~CLoadScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	list<LoadData> m_listLoadData; // 로드할 데이터들

private:
	/// <summary>
	/// 스프라이트 로딩해주는 함수
	/// </summary>
	/// <param name="_Key">키 값</param>
	/// <param name="_Path">주소 값 (ex : Player)</param>
	/// <param name="_iCount">개수 (애니메이션 일경우 개수 추가)</param>
	void LoadSprite(string _Key, string _Path, int _iCount = 0);
};

