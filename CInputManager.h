#pragma once
#include "CSingleton.h"

// Unity의 Input. 과 비슷함
// 키값을 받아오는걸 도와주는 매니저
class CInputManager :
	public CSingleton< CInputManager>
{
public:
	CInputManager();
	~CInputManager();

private:

	// 256인 이유는 키 값이 총 256개 있어서
	bool m_bCurInput[256] = { 0, };  // 현재 입력된 키 값 배열 변수
	bool m_bLastInput[256] = { 0, }; // 과거에 입력된 키 값 배열 변수

public:
	// 매 프레임마다 실행시키는 함수
	void Update();

	// 키를 눌렀을 때를 판단해주는 함수 (조건이 맞으면 한 번 호출함)
	bool KeyDown(int _Key);

	// 키를 누르고 있을 때를 판단해주는 함수 (조건이 맞으면 계속 호출함)
	bool KeyPress(int _Key);
	
	// 키를 뗏을 때를 판단해주는 함수 (조건이 맞으면 한 번 호출함)
	bool KeyUp(int _Key);

	// 마우스 좌표값을 얻어오는 함수
	Vec2 GetMousePos();
};

#define INPUT (*CInputManager::GetInstance())