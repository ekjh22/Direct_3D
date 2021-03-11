#pragma once

// 가장 맨 처음에 시작되는 부분
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
	
	void Init();
	void Update();
	void Render();
	void Release();

	void OnResetDevice();
	void OnLostDevice();
};

