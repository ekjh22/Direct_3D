#include "DXUT.h"
#include "CInputManager.h"


CInputManager::CInputManager()
{
}


CInputManager::~CInputManager()
{
}

void CInputManager::Update()
{
	// m_bLastInput값에 m_bCurInput값을 복사해줌
	memcpy(m_bLastInput, m_bCurInput, sizeof(m_bCurInput));

	for (int i = 0; i < 256; i++)
	{
		// 만약 눌렀으면 m_bCurInput[i] 값이 true 아니면 false
		m_bCurInput[i] = GetAsyncKeyState(i);
	}
}

bool CInputManager::KeyDown(int _Key)
{
	return m_bCurInput[_Key] == true && m_bLastInput[_Key] == false;
}

bool CInputManager::KeyPress(int _Key)
{
	return m_bCurInput[_Key] == true && m_bLastInput[_Key] == true;
}

bool CInputManager::KeyUp(int _Key)
{
	return m_bCurInput[_Key] == false && m_bLastInput[_Key] == true;
}

Vec2 CInputManager::GetMousePos()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(DXUTGetHWND(), &ptMouse);

	return Vec2(ptMouse.x,ptMouse.y);
}
