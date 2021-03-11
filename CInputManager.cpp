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
	// m_bLastInput���� m_bCurInput���� ��������
	memcpy(m_bLastInput, m_bCurInput, sizeof(m_bCurInput));

	for (int i = 0; i < 256; i++)
	{
		// ���� �������� m_bCurInput[i] ���� true �ƴϸ� false
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
