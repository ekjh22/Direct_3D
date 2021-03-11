#pragma once
#include "CSingleton.h"

// Unity�� Input. �� �����
// Ű���� �޾ƿ��°� �����ִ� �Ŵ���
class CInputManager :
	public CSingleton< CInputManager>
{
public:
	CInputManager();
	~CInputManager();

private:

	// 256�� ������ Ű ���� �� 256�� �־
	bool m_bCurInput[256] = { 0, };  // ���� �Էµ� Ű �� �迭 ����
	bool m_bLastInput[256] = { 0, }; // ���ſ� �Էµ� Ű �� �迭 ����

public:
	// �� �����Ӹ��� �����Ű�� �Լ�
	void Update();

	// Ű�� ������ ���� �Ǵ����ִ� �Լ� (������ ������ �� �� ȣ����)
	bool KeyDown(int _Key);

	// Ű�� ������ ���� ���� �Ǵ����ִ� �Լ� (������ ������ ��� ȣ����)
	bool KeyPress(int _Key);
	
	// Ű�� ���� ���� �Ǵ����ִ� �Լ� (������ ������ �� �� ȣ����)
	bool KeyUp(int _Key);

	// ���콺 ��ǥ���� ������ �Լ�
	Vec2 GetMousePos();
};

#define INPUT (*CInputManager::GetInstance())