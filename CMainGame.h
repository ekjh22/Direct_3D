#pragma once

// ���� �� ó���� ���۵Ǵ� �κ�
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

